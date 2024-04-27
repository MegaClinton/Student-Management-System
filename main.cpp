#include <iostream>
#include "readIN.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node
{
public:
    //Student information
    int ID = 0;
    string name = "";
    string dob = "";
    string address = "";
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
        Node* current = head;
        while (current->next != nullptr) // Traverse to the end of the list
        {
            current = current->next;
        }
        current->next = node; // Link the new node to the last node
        node->next = nullptr;
    }

    void deleteStudent(int ID) // deletes student
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        // If head node is the one to delete
        if (head->ID == ID)
        {
            Node* temp = head;
            head = head->next; // Update head to the next node
            delete temp; // Delete the original head
            cout << "Student deleted." << endl;
            return;
        }

        // For other nodes in the list
        Node* previous = head;
        Node* current = head->next;

        while (current)
        {
            if (current->ID == ID) {
                previous->next = current->next;
                delete current;
                cout << "Student deleted." << endl;
                return;
            }
            else {
                previous = current;
                current = current->next;
            }
        }

        // If the student is not found
        cout << "Student not found." << endl;
    }

    void display()
    {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void search(int ID) //search for student
    {
        Node* temp = head;
        while(temp)
        {
            if(temp->ID == ID)
            {
                cout << "Name: " << temp->name << endl;
                cout << "ID: " << temp->ID << endl;
                cout << "Date of Birth: " << temp->dob << endl;
                cout << "Address: " << temp->address << endl;
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        cout << "Student not found." << endl;
    }

    void searchName(string name) //search for student
    {
        Node* temp = head;
        while(temp)
        {
            if(temp->name == name)
            {
                cout << "Name: " << temp->name << endl;
                cout << "ID: " << temp->ID << endl;
                cout << "Date of Birth: " << temp->dob << endl;
                cout << "Address: " << temp->address << endl;
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        cout << "Student not found." << endl;
    }

    void updateStudent(int ID)
    {
        auto start = high_resolution_clock::now();
        Node* temp = head;
        while (temp)
        {
            if (temp->ID == ID) {
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Current Information:" << endl;
                cout << "Name: " << temp->name << endl;
                cout << "ID: " << temp->ID << endl;
                cout << "Date of Birth: " << temp->dob << endl;
                cout << "Address: " << temp->address << endl;
                cout << endl;

                // Provide options to modify information
                cout << "Enter new information (press enter to keep current):" << endl;
                cout << "New Name: ";
                string newName;
                cin.ignore();
                getline(cin, newName);
                if (!newName.empty())
                {
                    temp->name = newName;
                }

                cout << "New Date of Birth: ";
                string newDOB;
                getline(cin, newDOB);
                if (!newDOB.empty())
                {
                    temp->dob = newDOB;
                }

                cout << "New Address: ";
                string newAddress;
                getline(cin, newAddress);
                if (!newAddress.empty())
                {
                    temp->address = newAddress;
                }

                cout << "Information updated successfully." << endl;
                cout << "Student successfully updated after " << duration.count() << " microseconds." << endl;
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Search took " << duration.count() << " microseconds." << endl;
        cout << "Student not found." << endl;
    }

};

void displayMenu()
{
    cout << "\n==== Student Management System ====\n";
    cout << "1. Insert Student\n";
    cout << "2. Delete Student\n";
    cout << "3. Search student with ID\n";
    cout << "4. Search student with name\n";
    cout << "5. Update student\n";
    cout << "6. Display Students\n";
    cout << "7. Exit\n";
    cout << "==================================\n";
}

int main() {
    LinkedList studentList;

    ifstream inputFile;
    inputFile.open("testStudentswithLastName.csv");
    string line = "";

    cout << "Inserting students into Linked List.." << endl;
    while(getline(inputFile, line))
    {

        int studentID;
        string name;
        string DOB;
        string studentAddress;
        string tempString;

        stringstream inputString(line);

        getline(inputString, tempString, ',');
        studentID = atoi(tempString.c_str());
        getline(inputString, name, ',');
        getline(inputString, DOB, ',');
        getline(inputString, studentAddress);

        Node* student = new Node;
        student->name = name;
        student->dob = DOB;
        student->address = studentAddress;
        student->ID = studentID;
        studentList.insertStudent(student);
    }
    cout << "Inserting finished." << endl;

    while (true)
    {
        displayMenu();

        char choice;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) //Corresponds to user's input
        {
            case '1': {
                Node *newNode = new Node;
                cout << "Enter student ID: ";
                cin >> newNode->ID;
                cout << "Enter student name: ";
                getline(cin >> ws, newNode->name);
                //cin >> newNode->name;
                cout << "Enter student date of birth: ";
                getline(cin >> ws, newNode->dob);
                //cin >> newNode->dob;
                cout << "Enter student address: ";
                getline(cin >> ws, newNode->address);
                //cin >> newNode->address;
                auto start = high_resolution_clock::now();
                studentList.insertStudent(newNode);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Student inserted successfully after " << duration.count() << " microseconds." << endl; 
                break;
            }
            case '2': {
                int ID;
                cout << "Enter student ID to delete: ";
                cin >> ID;
                auto start = high_resolution_clock::now();
                studentList.deleteStudent(ID);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Student successfully deleted after " << duration.count() << " microseconds." << endl;
                break;
            }
            case '3': {
                int ID;
                cout << "Enter student ID to search: ";
                cin >> ID;
                auto start = high_resolution_clock::now();
                studentList.search(ID);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Student successfully searched after " << duration.count() << " microseconds." << endl;
                break;
            }
            case '4': {
                string name;
                cout << "Enter student name to search: ";
                getline(cin >> ws, name);
                //cin >> name;
                auto start = high_resolution_clock::now();
                studentList.searchName(name);
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Student successfully searched after " << duration.count() << " microseconds." << endl;
                break;
            }
            case '5': {
                int ID;
                cout << "Enter student ID to update: ";
                cin >> ID;

                studentList.updateStudent(ID);
                break;
            }
            case '6': {
                studentList.display();
                break;
            }
            case '7':
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7.\n";
                break;
        }
    }
}
