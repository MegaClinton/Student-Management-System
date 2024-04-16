#include"binaryTree.h"
#include <iostream>
//#include<windows.h> windows
#include<unistd.h>	//linux
#include<fstream>
#include<sstream>


//#include"readIN.h"
//#include"binaryTree.h"

using namespace std;


int main(){
	BST binaryTree;
	
	
	int tempInt;
	string tString;
	string tAddString;
	
	ifstream inputFile;
    inputFile.open("testStudents.csv");
    //inputFile.open("testStudents_prev.csv");
    string line = "";

    while(getline(inputFile, line)){

        int studentID;
        string name;
        string DOB;
        string studentAddress;
        string tempString = "";

        stringstream inputString(line);

        getline(inputString, tempString, ',');
        studentID = atoi(tempString.c_str());
        getline(inputString, name, ',');
        getline(inputString, DOB, ',');
        getline(inputString, studentAddress, ',');
		/*cout << "Student: " << studentID << " should be in database." << endl;
		cout << "Student: " << name << " should be in database." << endl;
		cout << "Student: " << DOB << " should be in database." << endl;
		cout << "Student: " << studentAddress << " should be in database." << endl;*/
        //binaryTree.Insert(studentID, name, DOB, studentAddress);
		tempInt = studentID;
		tString = studentAddress;
		tAddString = "\"";
		tString.append(tAddString);
		/*cout << "Student: " << tempInt << " should be in database." << endl;
		cout << "Student:-" << tString << "-should be in database." << endl;*/
		
		binaryTree.Insert(studentID, name, DOB, tString);
        

        //cout << studentID << " " << name << " " << DOB << " " << tString << endl;    //FOR TESTING PURPOSES

        line = "";

    }
    //BST binaryTree;
    //readIn();
    char menu;  //for main menu
    //char submenu;   //for submenu if needed
	
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
					cout << endl;
					cout << "Sorry that Input is invalid!!!" << endl;
					cout << endl;
					break;
				}
				tempCheck = binaryTree.ifNodeExists(tempID);
				//cout << "This is what tempCheck has: " << tempCheck << endl;
				if(tempCheck == true){
					cout << "Sorry that ID already exists" << endl;
					break;
				}
				else{
					cout << "Enter name: ";
					getline(cin >> ws, tempName);
					cout << "Name entered: "<< tempName << endl;
					cout << "Enter DOB[Date of Birth][ex. 2000-12-20]: ";
					getline(cin >> ws, tempDOB);
					cout << "DOB entered: " << tempDOB << endl;
					cout << "Enter student Address[ex. 200 mulberry st, Denton, TX 76201]: ";
					getline(cin >> ws, tempAddress);
					cout << "Address entered: " << tempAddress << endl;
					binaryTree.Insert(tempID, tempName, tempDOB, tempAddress);
				}
                //Sleep(2000); windows.h 
					//unistd.h
                cout << endl;
                break;
            
            case 'd':
            case 'D':
                cout << endl;
                cout << "You are in the delete student section" << endl;
				cout << "Enter student ID: ";
				cin >> tempID;
				cout << "You entered: " << tempID << endl;
				binaryTree.Delete(tempID);
                //Sleep(2000);


                cout << endl;
                break;
            case 's':
            case 'S':
                cout << endl;
                cout << "You are in the search[ID] student section" << endl;
				cout << "Enter student ID: ";
				cin >> tempID;
				cout << "You entered: " << tempID << endl;
				tempCheck = binaryTree.ifNodeExists(tempID);
				//cout << "This is what tempCheck has: " << tempCheck << endl;
				if(tempCheck == true){
					cout << endl;
					binaryTree.returnNodeContent(tempID);
					cout << endl;
					cout << endl;
					
					break;
				}
				else{
					cout << "Sorry that student is not in the database." << endl;
					cout << endl;
					break;
				}
                //Sleep(2000);

                cout << endl;
                break;
            case 'n':
            case 'N':
                cout << endl;
                cout << "You are in the search[NAME] student section" << endl;
		cout << "Enter name of student: ";
		getline(cin >> ws, tempName);
		cout << "Name entered: "<< tempName << endl;
		tempCheck = binaryTree.ifNodeNameExists(tempName);
		if(tempCheck == true){
			cout << endl;
			binaryTree.returnNodeNameContent(tempName);
			cout << endl;
			cout << endl;
					
			//usleep(2000000);
			break;
		}
		else{
			cout << "Sorry that student is not in the database." << endl;
			cout << endl;
			//usleep(2000000);
			break;
		}
				
                //Sleep(2000);
		//usleep(2000000);
                cout << endl;
                break;
            case 'u':
            case 'U':
                cout << endl;
                cout << "You are in the Update student section" << endl;
				cout << "Enter student ID: ";
				cin >> tempID;
				cout << "You entered: " << tempID << endl;
				tempCheck = binaryTree.ifNodeExists(tempID);
				//cout << "This is what tempCheck has: " << tempCheck << endl;
				if(tempCheck == true){
					cout << endl;
					binaryTree.returnNodeContent(tempID);
					cout << endl;
					cout << endl;
					cout << "Enter name: ";
					getline(cin >> ws, tempName);
					cout << "Name entered: "<< tempName << endl;
					cout << "Enter DOB[Date of Birth][ex. 2000-12-20]: ";
					getline(cin >> ws, tempDOB);
					cout << "DOB entered: " << tempDOB << endl;
					cout << "Enter student Address[ex. 200 mulberry st, Denton, TX 76201]: ";
					getline(cin >> ws, tempAddress);
					cout << "Address entered: " << tempAddress << endl;
					binaryTree.updateNode(tempID, tempName, tempDOB, tempAddress);
					cout << endl;
					cout << "Updated information----" << endl;
					binaryTree.returnNodeContent(tempID);
					cout << endl;
					cout << endl;
					break;
				}
				else{
					cout << "Sorry that student is not in the database." << endl;
					cout << endl;
					break;
				}
				
				
                //Sleep(2000);

                cout << endl;
                break;
            case 'q':
            case 'Q':
                cout << endl;
                cout << "Quitting..." << endl;
                //Sleep(1000);


                cout << endl;
                break;
            default:
                cout << "Sorry wrong input, please try again, Once Menu Pops Up Again!!!" << endl;
                //Sleep(3000);

                cout << endl;
                break;

        }

    }while( !( (menu == 'q') || (menu == 'Q') ));
    
    return 0;
}
