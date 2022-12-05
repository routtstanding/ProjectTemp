//a helper h file to process the files and data

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "BST.h"
#include "actressActor.h"
#include "pictures.h"

using namespace std;

//michelle routt rewrite base tokenizer from henok
void tokenize(std::string const& str, const char delim, std::vector<std::string>& tokens)
{
	//we are creating collection of tokens as a vector

	//create the tokens to be put into the collection
	int tokenStart = 0;

	bool inQuotes = 0;

	for (int cursorPos = 0; cursorPos < str.length(); cursorPos++)
	{
		char current = str[cursorPos]; //the current char we are examining in the string

		//our behavior will change depending on what we find in that []
		switch (current)
		{
			case '"':
				inQuotes = !inQuotes; //assign the inquotes to the opposite of what the inquotes is - only in booleans
				break;
			case ',':
				if (!inQuotes)
				{
					//make it a token if it's not in quotes
					string substr = str.substr(tokenStart,cursorPos - tokenStart);

					//remove the quotes from the substring
					if (substr[0] == '"')
					{
						substr.erase(0,1);
						substr.erase(substr.length()-1,1);
					}

					tokens.push_back(substr);

					tokenStart = cursorPos + 1;
				}
				break;
		}
	}

	string substr = str.substr(tokenStart);


	//remove the quotes from the substring
	if (substr[0] == '"')
	{
		substr.erase(0,1);
		substr.erase(substr.length() - 1,1);
	}

	tokens.push_back(substr);
}

//pass the bst by reference

void ReadActorActressFile(std::string& filepath, BinarySearchTree<ActressActor>& bst)
{
	std::ifstream file(filepath);

	//error if no file
	if (!file.is_open())
	{
		cerr << "file not found. Try again: " << filepath << endl;
		exit(EXIT_FAILURE);
	}

	//read in the content of the file
	string line;

	while (getline(file, line))
	{
		//skip the col header
		if (line == "Year,Award,Winner,Name,Film")
		{
			continue;
		}

		vector<string> lineTokens;

		tokenize(line, ',', lineTokens);
		

		ActressActor actressActor(lineTokens);

		/*
		//printing for debug
		cout << actressActor << endl;
		cout << " -------------------" << endl;
		*/

		bst.Insert(actressActor); //insert the actors object into the bst
	}

}

BinarySearchTree<ActressActor>ReadActorActressFile(string& filepath)
{
	BinarySearchTree<ActressActor> temp;

	return temp;
}

//**** attempting to print csv

/*
		year
		award
		winner
		name 
		film
*/

// *****

// ********************************** for the movies ***********************************

void ReadPictures(string& picturesFilePath, BinarySearchTree<Picture>& pictures)
{
	std::ifstream file(picturesFilePath);

	//error if no file
	if (!file.is_open())
	{
		cerr << "file not found. Try again: " << picturesFilePath << endl;
		exit(EXIT_FAILURE);
	}

	string line;

	while (getline(file, line))
	{
		//skip the first line
		if (line.find("nominations,rating,duration,genre1") == 13)
		{
			continue;
		}

		vector<string> lineTokens;

		tokenize(line, ',', lineTokens);


		Picture picture(lineTokens);

		//printing for debug
		/*cout << picture << endl;
		cout << " -------------------" << endl;*/

		pictures.Insert(picture);


		//testing

	/*	for (auto item : lineTokens)
		{
			cout << item << endl;
		}*/


		//cout << " ***************** " << endl;

		/*cout << line << endl;
		cout << " *************************** " << endl;*/
	}

}