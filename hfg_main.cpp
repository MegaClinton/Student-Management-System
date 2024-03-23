#include <iostream>
#include<windows.h> 


#include"readIN.h"
#include"binaryTree.h"

/*CODE I AM STILL WORKING ON TO TEST COMPONENTS*/

using namespace std;

int main(){
    readIn();
    char menu;  //for main menu
    char submenu;   //for submenu if needed

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
                Sleep(2000);
                cout << endl;
                break;
            
            case 'd':
            case 'D':
                cout << endl;
                cout << "You are in the delete student section" << endl;
                Sleep(2000);
                cout << endl;
                break;
            case 's':
            case 'S':
                cout << endl;
                cout << "You are in the search[ID] student section" << endl;
                Sleep(2000);
                cout << endl;
                break;
            case 'n':
            case 'N':
                cout << endl;
                cout << "You are in the search[NAME] student section" << endl;
                Sleep(2000);
                cout << endl;
                break;
            case 'u':
            case 'U':
                cout << endl;
                cout << "You are in the Update student section" << endl;
                Sleep(2000);
                cout << endl;
                break;
            case 'q':
            case 'Q':
                cout << endl;
                cout << "Quitting..." << endl;
                Sleep(1000);

                cout << endl;
                break;
            default:
                cout << "Sorry wrong input, please try again, Once Menu Pops Up Again!!!" << endl;
                Sleep(3000);
                cout << endl;
                break;

        }

    }while( !( (menu == 'q') || (menu == 'Q') ));
    

    return 0;
}
