#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "actressActor.h"
#include "fileIO.h"
#include "BST.h"
#include "AddRecord.h"
#include "OutputVisitor.h"
#include "Visitor.h"

using namespace std;

void searchModifyPictureDB(const std::string& pictureName)
{
    cout << "entering movie: " << pictureName << endl;
}


int mainMenu(BinarySearchTree<ActressActor> actress_actor, BinarySearchTree<Picture> pictures)
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
            //cout << "menu 1 movie db - add(1)" << endl;
            
            //call a function to add an item
            AddUserPictureObj(pictures);

            //return to main
            mainMenu(actress_actor, pictures);

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


                cout << "Do you want to modify or delete the record?" << endl;
                cout << "1. Modify" << endl;
                cout << "2. Delete" << endl;
                cout << "3. Main Menu" << endl;
            }
            else
            {
                mainMenu(actress_actor, pictures);
            }

            
        }
        else if (inputMovieDB == 3)
        {
            //cout << "menu 1 movie db - print csv (3)" << endl;
          
            //call a function to print
            //**
            //configures the ofstream

            //ask for filename
            string userPictureFileName;
            cout << "enter a file name (movies):" << endl;
            cin >> userPictureFileName;
            userPictureFileName = userPictureFileName + ".csv";

            //open the file
            ofstream outFile;
            outFile.open(userPictureFileName, ios::out | ios::trunc);

            //write to the file
            PictureOutputVisitor pictureVisitor = PictureOutputVisitor(outFile);
            pictures.Accept(pictureVisitor);

            //close the file
            outFile.close();

            //**

            //return to main
            mainMenu(actress_actor, pictures);

        }
        else if (inputMovieDB == 4)
        {
            mainMenu(actress_actor, pictures);
        }
        else
        {
            mainMenu(actress_actor, pictures);
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
            AddUserActorObj(actress_actor);

            //return to main
            mainMenu(actress_actor, pictures);
            
        }

        else if (inputActorDB == 2)
        {

            cout << "Partial search or Complete?" << endl;
            cout << "1. Partial" << endl;
            cout << "2. Complete [unavailable]" << endl;

            int inputSearchType = 0;

            cin >> inputSearchType;

            if (inputSearchType == 1)
            {
                int subSearchPartialActor = 0;

                //prompt user to enter the information
                string inputSearchTermActor;

                cout << "what are you searching for?" << endl;
                cin >> inputSearchTermActor;

                //call the search visitor
                ActorSearchVisitor actorVisitorSearch = ActorSearchVisitor(inputSearchTermActor, actress_actor);

                
                
                //****

                cout << "Do you want to modify or delete the record?" << endl;
                cout << "1. Modify" << endl;
                cout << "2. Delete" << endl;
                cout << "3. Main Menu" << endl;

                if (subSearchPartialActor == 1)
                {
                    cout << "modify" << endl;
                    mainMenu(actress_actor, pictures);
                }
                else if (subSearchPartialActor == 2)
                {
                    cout << "delete" << endl;
                    mainMenu(actress_actor, pictures);
                }
                else
                {
                    mainMenu(actress_actor, pictures);
                }

            }
            //else if (inputSearchType == 2)
            //{
            //    cout << "actor db - search 2 - complete(2)" << endl;

            //    //prompt the user to enter information and then have it do something

            //    cout << "Do you want to modify or delete the record?" << endl;
            //    cout << "1. Modify" << endl;
            //    cout << "2. Delete" << endl;
            //    cout << "3. Main Menu" << endl;
            //}
            else
            {
                mainMenu(actress_actor, pictures);
            }

          
            
        }

        else if (inputActorDB == 3)
        {

            //call a function to print
            //**
            //configures the ofstream

            //ask for filename
            string userActorFileName;
            cout << "enter a file name (actor):" << endl;
            cin >> userActorFileName;
            userActorFileName = userActorFileName + ".csv";

            //open the file
            ofstream outFile;
            outFile.open(userActorFileName, ios::out | ios::trunc);

            //write to the file
            ActorOutputVisitor actorVisitor = ActorOutputVisitor(outFile);
            actress_actor.Accept(actorVisitor);

            //close the file
            outFile.close();

            //**

            //return to main
            mainMenu(actress_actor, pictures);
        }

        else if (inputActorDB == 4)
        {
            mainMenu(actress_actor, pictures);
        }

        else
        {
            mainMenu(actress_actor, pictures);
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

bool checkString(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

int main()
{
    BinarySearchTree<ActressActor> actress_actor;
    BinarySearchTree<Picture> pictures;

    string actressActorFilePath = "actor_actress.csv";
    string picturesFilePath = "pictures.csv";


    //reads the input file path and does processing
    ReadActorActressFile(actressActorFilePath, actress_actor);
    ReadPictures(picturesFilePath, pictures);

    

    //! ************** ! uncomment when done testing
    cout << mainMenu(actress_actor, pictures) << endl;

    
    //testing area
    //actress_actor.PrintTree();

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