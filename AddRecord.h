#include <string>
#include <vector>
#include <fstream>
#include <utility>

using namespace std;

bool checkNumber(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

bool checkBool(string strr)
{

    if (strr == "0")
    {
        //cout << "it's a zero";
        return true;
    }
    else if (strr == "1")
    {
        //cout << "it's a one";
        return true;
    }
    else {
        //cout << "it is neither one nor zero";
        return false;
    }

}

// *********************************************************

BinarySearchTree<ActressActor> AddUserActorObj()
{
    //this is for adding a record
    string userActorInput;

    vector<string> userActorTokens;

    cout << "year: ";
    cin >> userActorInput;

    //check if int
    while (!checkNumber(userActorInput))
    {
        cout << "invalid, try again: " << endl;
        cin >> userActorInput;
    }


    userActorTokens.push_back(userActorInput);

    cout << endl << "award: ";
    cin >> userActorInput;

    userActorTokens.push_back(userActorInput);

    cout << endl << "winner: ";
    cin >> userActorInput;

    //check if 1 or 0
    while (!checkBool(userActorInput))
    {
        cout << "invalid, try again: " << endl;
        cin >> userActorInput;
    }

    userActorTokens.push_back(userActorInput);

    cout << endl << "name: ";
    cin >> userActorInput;

    userActorTokens.push_back(userActorInput);

    cout << endl << "film: ";
    cin >> userActorInput;

    userActorTokens.push_back(userActorInput);

    ActressActor userActor(userActorTokens); //we've created a user actor obj

    

    //insert into tree
    /*actress_actor.Insert(userActor);

    actress_actor.PrintTree();*/
};