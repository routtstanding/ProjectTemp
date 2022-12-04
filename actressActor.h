#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

struct ActressActor //publicly accessible
{
	int year;
	string award;
	int winner;
	string name;
	string film;

	//add a constructor
	explicit ActressActor(vector<string> data)
	{
		year = stoi(data[0]);
		award = data[1];
		winner = stoi(data[2]);
		name = data[3];
		film = data[4];

	}

	friend ostream& operator << (ostream& out, ActressActor& actor)
	{
		//spits out information of the particular actor

		out << "Name: " << actor.name << endl;
		out << "Film: " << actor.film << endl;
		out << "Year: " << actor.year << endl;
		out << "Award: " << actor.award << endl;
		out << "Winner: " << actor.winner << endl;

		return out;
	}

	//for the bst
	bool operator < (const ActressActor& actor) const
	{
		return (this->name < actor.name);
	}


};