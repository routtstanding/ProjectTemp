#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "Visitor.h"
#include "actressActor.h"

class ActorOutputVisitor: public Visitor<ActressActor>
{
public:
	//constructor
	explicit ActorOutputVisitor(ostream& out) : _out(out)
	{
		

	}

	void header(ActressActor ent)
	{
		//write header line

		_out << "Year" << ",";
		_out << "Award" << ",";
		_out << "Winner" << ",";
		_out << "Name" << ",";
		_out << "Film" << endl;
	}

	void visit(ActressActor entity) const override
	{

		
		
		//write out each field one at a time, if contains a comma put a " around it

		_out << entity.year << ",";

		_out << checkComma(entity.award) << ",";

		_out << entity.winner << ",";

		_out << checkComma(entity.name) << ",";

		_out << checkComma(entity.film) << endl;

	
	}
	
protected:
	//extension without modification

	ostream& _out;

private:
	
	string checkComma(string str) const
	{
		if (str.find(',') != std::string::npos)
		{
			return "\"" + str + "\"";
		}
		else
		{
			return str;
		}
	}

};

class ActorSearchVisitor : public Visitor<ActressActor>
{
public:

	//constructor
	explicit ActorSearchVisitor(string strn, vector<ActressActor> results): searchTerm(strn), searchResults(results)
	{

	}

	void visit(ActressActor entity) const override
	{
		//does the bst nodes contain the searchterm
		//look at the entity, if it matches, add to results

		if (to_string(entity.year).find(searchTerm) != std::string::npos)
		{
			searchResults.push_back(entity);
			return;
		}

		if (entity.award.find(searchTerm) != std::string::npos)
		{
			searchResults.push_back(entity);
			return;
		}

		//deliberately skipping "winner"

		if (entity.name.find(searchTerm) != std::string::npos)
		{
			searchResults.push_back(entity);
			return;
		}

		if (entity.film.find(searchTerm) != std::string::npos)
		{
			searchResults.push_back(entity);
			return;
		}

	}

	void searchPrint(vector<ActressActor> input)
	{
		
		for (int i = 0; i < searchResults.size(); i++)
		{
			cout << searchResults.at(i) << ' ';
		}
	}

	

	/*
	
	int main()
	{
	std::vector<int> input = { 1, 2, 3, 4, 5 };
	VisitPrint(searchResults);

	return 0;
	}

	*/

protected:
	string& searchTerm;

	vector<ActressActor>& searchResults;

private:
};

//************************************ movies ************************

class PictureOutputVisitor : public Visitor<Picture>
{
public:
	//constructor
	explicit PictureOutputVisitor(ostream& out) : _out(out)
	{


	}

	void visit(Picture entity) const override
	{
		//write header line
		
		/*_out << "Name" << ",";
		_out << "Year" << ",";
		_out << "Nominations" << ",";
		_out << "Rating" << ",";
		_out << "Duration" << ",";
		_out << "Genre1" << ",";
		_out << "Genre2" << ",";
		_out << "Release" << ",";
		_out << "Metacritic" << ",";
		_out << "Synopsis" << endl;*/

		//write out each field one at a time, if contains a comma put a " around it

		_out << checkComma(entity.name) << ",";

		_out << entity.year << ",";

		_out << entity.nominations << ",";

		_out << entity.rating << ",";

		_out << entity.duration << ",";

		_out << checkComma(entity.genre1) << ",";

		_out << checkComma(entity.genre2) << ",";

		_out << checkComma(entity.release) << ",";

		_out << entity.metacritic << ",";

		_out << checkComma(entity.synopsis) << endl;


	}

protected:
	//extension without modification

	ostream& _out;

private:

	string checkComma(string str) const
	{
		if (str.find(',') != std::string::npos)
		{
			return "\"" + str + "\"";
		}
		else
		{
			return str;
		}
	}

};