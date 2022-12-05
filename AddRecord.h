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

void AddUserActorObj(BinarySearchTree<ActressActor> actress_actor)
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
    actress_actor.Insert(userActor);

    actress_actor.PrintTree();
};

// ******************************************

void AddUserPictureObj(BinarySearchTree<Picture> pictures)
{


    //this is for adding a record
    string userPictureInput;

    vector<string> userPictureTokens;

    cout << "name: ";
    cin >> userPictureInput;
       
    userPictureTokens.push_back(userPictureInput);

    //

    cout << endl << "year: ";
    cin >> userPictureInput;

    //check if int
    while (!checkNumber(userPictureInput))
    {
        cout << "invalid, try again: " << endl;
        cin >> userPictureInput;
    }

    userPictureTokens.push_back(userPictureInput);

    //

    cout << endl << "nominations: ";
    cin >> userPictureInput;

    //check if int
    while (!checkNumber(userPictureInput))
    {
        cout << "invalid, try again: " << endl;
        cin >> userPictureInput;
    }

    userPictureTokens.push_back(userPictureInput);

    //

    cout << endl << "rating: ";
    cin >> userPictureInput;

    //check if int
    while (!checkNumber(userPictureInput))
    {
        cout << "invalid, try again: " << endl;
        cin >> userPictureInput;
    }

    userPictureTokens.push_back(userPictureInput);

    //

    cout << endl << "duration: ";
    cin >> userPictureInput;
    //validate float!!!!

    //check if int
    while (!checkNumber(userPictureInput))
    {
        cout << "invalid, try again: " << endl;
        cin >> userPictureInput;
    }

    userPictureTokens.push_back(userPictureInput);

    //

    cout << endl << "genre1: ";
    cin >> userPictureInput;

    userPictureTokens.push_back(userPictureInput);

    //

    cout << endl << "genre2: ";
    cin >> userPictureInput;

    userPictureTokens.push_back(userPictureInput);

    //

    cout << endl << "release: ";
    cin >> userPictureInput;

    userPictureTokens.push_back(userPictureInput);

    //

    cout << endl << "metacritic score: ";
    cin >> userPictureInput;

    //check if int
    while (!checkNumber(userPictureInput))
    {
        cout << "invalid, try again: " << endl;
        cin >> userPictureInput;
    }

    userPictureTokens.push_back(userPictureInput);

    //

    cout << endl << "synopsis: ";
    cin >> userPictureInput;
    
    userPictureTokens.push_back(userPictureInput);

    //
    Picture userPicture(userPictureTokens); //we've created a user movie obj

    //insert into tree
    pictures.Insert(userPicture);

    pictures.PrintTree();
};