#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

struct Picture
{
	string name;
	int year;
	int nominations;
	int rating;
	float duration;
	string genre1;
	string genre2;
	string release;
	int metacritic;
	string synopsis;

	//constructor
	explicit Picture(vector<string> data)
	{
		name = data[0];
		year = stoi(data[1]);
		
		//this is the problem child
		nominations = stoi(data[2]);
		
		rating = stoi(data[3]);
		duration = stof(data[4]);
		genre1 = data[5];
		genre2 = data[6];
		release = data[7];

		//problem child
		metacritic = stoi(data[8]);
		
		synopsis = data[9];
	}

	friend ostream& operator << (ostream& out, Picture& pic)
	{
		//spits out information of the particular actor

		out << "**************************************" << endl;

		out << "Name: " << pic.name << endl;
		out << "Year: " << pic.year << endl;
		out << "Nominations: " << pic.year << endl;
		out << "Rating: " << pic.rating << endl;
		out << "Duration: " << pic.duration << endl;
		out << "Genre 1: " << pic.genre1 << endl;
		out << "Genre 2: " << pic.genre2 << endl;
		out << "Release: " << pic.release << endl;

		return out;
	}

	//for the bst
	bool operator < (const Picture& pic) const
	{
		return (this->name < pic.name);
	}

	//create an "add" function for adding to the database
	//prompt user to supply the fields
	//then append to the list

};