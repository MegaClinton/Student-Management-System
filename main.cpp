#include <iostream>
#include<windows.h> 


#include"readIN.h"
#include"binaryTree.h"

using namespace std;

class Node
{
public:
    //Student information
    int ID = 0;
    string name = "";
    string dob = "";
    Node* next;
};

class LinkedList
{
private:
    //head node
    Node* head;

public:
    //default constructor
    LinkedList() : head(nullptr){}
    //destructor
    ~LinkedList()
    {
        Node* temp = head;
        while(temp)
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    void insertStudent(Node* node) //inserting new student
    {
        if(head == nullptr)
        {
            node->next = nullptr;
            head = node;
            return;
        }
        node->next = head;
        head = node;
    }

    void deleteStudent(string name) //deletes student
    {
        Node* previous = head;
        Node* current = head;
        //searches for student
        while(current)
        {
            if(current->name == name)
            {
                Node* temp = current;
                previous->next = current->next;
                delete temp;
                cout << "Student deleted." << endl;
                return;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
    }

    void display() //display linked list
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void search(string name) //search for student
    {
        Node* temp = head;
        while(temp)
        {
            if(temp->name == name)
            {
                cout << "Name: " << temp->name << endl;
                cout << "ID: " << temp->ID << endl;
                cout << "Date of Birth: " << temp->dob << endl;
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        cout << "Student not found." << endl;
    }

    int getSize() //traverse through list and get size
    {
        int size = 0;
        Node* temp = head;
        while(temp)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }

    void findMiddle()
    {
        //calculate middle index
        int midIndex = (getSize() - 1) / 2;
        Node* temp = head;
        int count = 0; //variable to keep track of index
        while(temp)
        {
            if(count != midIndex)
            {
                temp = temp->next;
                count++;
            }
            else
            {
                cout << "Middle element: " << temp->name << endl;
                return;
            }
        }
    }

    void reverseList()
    {
        //Create 3 nodes
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = NULL;

        while(curr) //traverse
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

        cout << "Reversal finished." << endl;
    }

};

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