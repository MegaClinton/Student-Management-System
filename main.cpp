
#include <iostream>
#include<windows.h>

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
=======
=======
>>>>>>> parent of 1fc1c9b (Add files via upload)
#include <iostream>
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

void displayMenu()
{
    cout << "\n==== Student Management System ====\n";
    cout << "1. Insert Student\n";
    cout << "2. Delete Student\n";
    cout << "3. Display Students\n";
    cout << "4. Search for Student\n";
    cout << "5. Find Middle Student\n";
    cout << "6. Reverse list\n";
    cout << "7. Exit\n";
    cout << "==================================\n";
}

int main() {
    LinkedList studentList;

    while (true) {
        displayMenu();

        int choice;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) //Corresponds to user's input
        {
            case 1: {
                Node *newNode = new Node;
                cout << "Enter student ID: ";
                cin >> newNode->ID;
                cout << "Enter student name: ";
                cin >> newNode->name;
                cout << "Enter student date of birth: ";
                cin >> newNode->dob;
                studentList.insertStudent(newNode);
                cout << "Student inserted successfully." << endl;
                break;
            }
            case 2: {
                string nameToDelete;
                cout << "Enter student name to delete: ";
                cin >> nameToDelete;
                studentList.deleteStudent(nameToDelete);
                break;
            }
            case 3:
                studentList.display();
                break;
            case 4: {
                string nameToSearch;
                cout << "Enter student name to search: ";
                cin >> nameToSearch;
                studentList.search(nameToSearch);
                break;
            }
            case 5:
                studentList.findMiddle();
                break;
            case 6:
                studentList.reverseList();
                break;
            case 7:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    }
}