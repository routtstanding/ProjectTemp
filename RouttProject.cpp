#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "actressActor.h"
#include "fileIO.h"
#include "BST.h"
#include "AddRecord.h"

using namespace std;


//bool checkNumber(string str)
//{
//    for (int i = 0; i < str.length(); i++)
//        if (isdigit(str[i]) == false)
//            return false;
//    return true;
//}
//
//bool checkBool(string strr)
//{
//
//    if (strr == "0")
//    {
//        //cout << "it's a zero";
//        return true;
//    }
//    else if (strr == "1")
//    {
//        //cout << "it's a one";
//        return true;
//    }
//    else {
//        //cout << "it is neither one nor zero";
//        return false;
//    }
//
//}

// *********************************************************

int mainMenu()
{
    int mainMenuInput;
 
    //for all these first need to prompt the user which db - movie or actor
    //menu should probably loop back to main

    cout << "Which database?" << endl;
    
    cout << "1. Movies" << endl;
    cout << "2. Actors" << endl;
    cout << "3. Exit Program" << endl;

    cin >> mainMenuInput;

    if (mainMenuInput == 1)
    {
        int inputMovieDB = 0;
        cout << "1. Movie Database Options" << endl;

        cout << "1. Add Record" << endl;
        cout << "2. Search records" << endl;
        cout << "3. Print database to csv" << endl;
        cout << "4. Return to main menu" << endl;

        cin >> inputMovieDB;

        if (inputMovieDB == 1)
        {
            cout << "menu 1 movie db - add(1)" << endl;
            //add a record function          

        }
        else if (inputMovieDB == 2)
        {

            cout << "menu 1 movie - search(2)" << endl;

            cout << "Partial search or Complete?" << endl;
            cout << "1. Partial" << endl;
            cout << "2. Complete" << endl;

            int inputSearchType = 0;

            cin >> inputSearchType;

            if (inputSearchType == 1)
            {
                cout << "movie db - search 2 - partial(1)" << endl;

                //prompt user to enter the information

                cout << "Do you want to modify or delete the record?" << endl;
                cout << "1. Modify" << endl;
                cout << "2. Delete" << endl;
                cout << "3. Main Menu" << endl;

            }
            else if (inputSearchType == 2)
            {
                cout << "movie db - search 2 - complete(2)" << endl;

                //prompt the user to enter information and then have it do something

                cout << "Do you want to modify or delete the record?" << endl;
                cout << "1. Modify" << endl;
                cout << "2. Delete" << endl;
                cout << "3. Main Menu" << endl;
            }
            else
            {
                mainMenu();
            }

            
        }
        else if (inputMovieDB == 3)
        {
            cout << "menu 1 movie db - print csv (3)" << endl;
            //print the movie db csv       

        }
        else if (inputMovieDB == 4)
        {
            mainMenu();
        }
        else
        {
            mainMenu();
        }
    }
    //****** actor db menu *****

    else if (mainMenuInput == 2)
    {
        int inputActorDB = 0;
        cout << "Actor Database Options: " << endl;

        cout << "1. Add Record" << endl;
        cout << "2. Search records" << endl;
        cout << "3. Print database to csv" << endl;
        cout << "4. Return to main menu" << endl;

        cin >> inputActorDB;

        if (inputActorDB == 1)
        {
            cout << "actor db - add record 1" << endl;

            //call a function to add an item
            AddUserActorObj();
        }

        else if (inputActorDB == 2)
        {
            cout << "actor db - search records" << endl;

            cout << "Partial search or Complete?" << endl;
            cout << "1. Partial" << endl;
            cout << "2. Complete" << endl;

            int inputSearchType = 0;

            cin >> inputSearchType;

            if (inputSearchType == 1)
            {
                cout << "actor db - search 2 - partial(1)" << endl;

                //prompt user to enter the information

                cout << "Do you want to modify or delete the record?" << endl;
                cout << "1. Modify" << endl;
                cout << "2. Delete" << endl;
                cout << "3. Main Menu" << endl;

            }
            else if (inputSearchType == 2)
            {
                cout << "actor db - search 2 - complete(2)" << endl;

                //prompt the user to enter information and then have it do something

                cout << "Do you want to modify or delete the record?" << endl;
                cout << "1. Modify" << endl;
                cout << "2. Delete" << endl;
                cout << "3. Main Menu" << endl;
            }
            else
            {
                mainMenu();
            }

          
            
        }

        else if (inputActorDB == 3)
        {
            cout << "actor db - print csv 3" << endl;

            //call a function to print
        }

        else if (inputActorDB == 4)
        {
            mainMenu();
        }

        else
        {
            mainMenu();
        }

    }
    
        
    else if (mainMenuInput == 3)
    {
        //this works
        exit(0);
    }
    else
    {
        cout << "Invalid, try again: " << endl;
        cin >> mainMenuInput;
    }


    return 0;
};

//*******************************************************************************


int main()
{
    BinarySearchTree<ActressActor> actress_actor;
    BinarySearchTree<Picture> pictures;

    string actressActorFilePath = "actor_actress.csv";
    string picturesFilePath = "pictures.csv";

    cout << mainMenu() << endl;

    //reads the input file path and does processing
    ReadActorActressFile(actressActorFilePath, actress_actor);
    ReadPictures(picturesFilePath, pictures);

    

    //testing area
    //actress_actor.PrintTree();

    ////this is for adding a record
    //string userActorInput;

    //vector<string> userActorTokens;

    //cout << "year: ";
    //cin >> userActorInput;

    ////check if int
    //while (!checkNumber(userActorInput))
    //{
    //    cout << "invalid, try again: " << endl;
    //    cin >> userActorInput;
    //}


    //userActorTokens.push_back(userActorInput);

    //cout << endl << "award: ";
    //cin >> userActorInput;

    //userActorTokens.push_back(userActorInput);

    //cout << endl << "winner: ";
    //cin >> userActorInput;

    ////check if 1 or 0
    //while (!checkBool(userActorInput))
    //{
    //    cout << "invalid, try again: " << endl;
    //    cin >> userActorInput;
    //}

    //userActorTokens.push_back(userActorInput);

    //cout << endl << "name: ";
    //cin >> userActorInput;

    //userActorTokens.push_back(userActorInput);

    //cout << endl << "film: ";
    //cin >> userActorInput;

    //userActorTokens.push_back(userActorInput);

    //ActressActor userActor(userActorTokens); //we've created a user actor obj

    //insert into tree
    /*actress_actor.Insert(userActor);

    actress_actor.PrintTree();*/

    

    return 0;
}

//notes

/*

make a record search
the search needs to output each record as a row with a number (display search results: "1: [info from record]")
vector of search results against the object, when they pick the number, checks the index of that record within that vector

after the search is working, allow user to go "into the record" - pick 1, 2, 3, etc; if hit empty go back to menu
once inside record, give the delete and modify options
if want delete, call "remove" from BST and pull it out
and if modify, just modify the actressactor obj
ask which field to modify

for partial search, "tree scan" - iterate the tree in order, compile a vector of anything that matches

complete search also is a "tree scan"



*/