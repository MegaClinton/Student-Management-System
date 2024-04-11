#include"binaryTree.h"
#include <iostream>
//#include<windows.h> windows
#include<unistd.h>	//linux


#include"readIN.h"
//#include"binaryTree.h"

using namespace std;

int main(){
    BST binaryTree;
    readIn();
    char menu;  //for main menu
    char submenu;   //for submenu if needed
	
	int tempID = -1;
	string tempName = "NONE";
	string tempDOB = "0000-00-00";
	string tempAddress = "no address";
	bool tempCheck = false;
	

    cout << "Welcome Administrator" << endl;
    cout << endl;
    do{
        /*Print Menu*/
        cout << "Main Menu" << endl;
        cout << "a - Add Student" << endl;
        cout << "d - Delete Student" << endl;
        cout << "s - Search Student[With ID]" << endl;
        cout << "n - Search Student[With NAME]" << endl;
        cout << "u - Update Student Information" << endl;
        cout << "q - Quit" << endl;
        cout << "Choose an Option: ";
        cin >> menu;

        switch(menu){
            /*Main Menu Choices*/
            case 'a':
            case 'A':
                cout << endl;
                cout << "You are in the add student section" << endl;
				cout << "Enter ID of New Student: ";
				cin >> tempID;
				cout << "You entered: " << tempID << endl;
				if(tempID == 0 || tempID<1){
					cout << "Sorry that Input is invalid!!!" << endl;
					usleep(2000000);
					break;
				}
				tempCheck = binaryTree.ifNodeExists(tempID);
				if(tempCheck == false){
					cout << "Sorry that ID already exists" << endl;
					break;
				}
                //Sleep(2000); windows.h 
				usleep(2000000);	//unistd.h 
                cout << endl;
                break;
            
            case 'd':
            case 'D':
                cout << endl;
                cout << "You are in the delete student section" << endl;
                //Sleep(2000);
				usleep(2000000);
                cout << endl;
                break;
            case 's':
            case 'S':
                cout << endl;
                cout << "You are in the search[ID] student section" << endl;
                //Sleep(2000);
				usleep(2000000);
                cout << endl;
                break;
            case 'n':
            case 'N':
                cout << endl;
                cout << "You are in the search[NAME] student section" << endl;
                //Sleep(2000);
				usleep(2000000);
                cout << endl;
                break;
            case 'u':
            case 'U':
                cout << endl;
                cout << "You are in the Update student section" << endl;
                //Sleep(2000);
				usleep(2000000);
                cout << endl;
                break;
            case 'q':
            case 'Q':
                cout << endl;
                cout << "Quitting..." << endl;
                //Sleep(1000);
				usleep(2000000);

                cout << endl;
                break;
            default:
                cout << "Sorry wrong input, please try again, Once Menu Pops Up Again!!!" << endl;
                //Sleep(3000);
				usleep(2000000);
                cout << endl;
                break;

        }

    }while( !( (menu == 'q') || (menu == 'Q') ));
    
    return 0;
}