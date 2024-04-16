#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include<string>
//#include<windows.h>
#include<unistd.h> 

using namespace std;
class BST{

    private:
        struct node{
            int studentID;
            string name;
            string DOB;
            string studentAddress;
            node* left;
            node* right;
        };

        node* root;
        
	/*Creates Nodes from input of user*/
        void insertPrivate(int studentID, string name, string DOB, string studentAddress, node* Ptr);
	/*Deletes Nodes Chosen*/
        void deletePrivate(int studentID, node* Ptr);
	/*Finds smallest value node for delete function*/
        int findSmallestPrivate(node* Ptr);
	/*Function */
        void removeMatch(node* root, node* match, bool left);
        /*Creating new Node*/
        node* createNode(int studentID, string name, string DOB, string studentAddress);
	/*Removes any children and the node inserted*/
        void RemoveTree(node* Ptr);
	/*Goes through tree to find node by ID search*/
        node* findNodeID(int studentID);
        node* findNodeIDPrivate(int studentID, node* Ptr);
	/*goes through tree to find node by name search*/
        node* searchByName(string name);
        node* searchByNamePrivate(string name, node* Ptr);
	/*For displaying node content to user after search is done*/
	void returnNodePrivate(int studentID, node* Ptr);
	/*For updating nodes by user request*/
	void updateNodePrivate(int studentID, string name, string DOB, string studentAddress, node*Ptr);
	/*Displaying node content by NAME search*/
	void returnNodeNamePrivate(string studentName, node*Ptr);	

    public:
        /*Default Constructor*/
        BST();
        /*Default Deconstuctor*/
        ~BST();
        /*Insert Function*/
        void Insert(int studentID, string name, string DOB, string studentAddress);
        /*Delete Function*/
        void Delete(int studentID);
        /*Finding Smallest ID number in subtree*/
        int findSmallest();
	/*Check if node already exists*/
	bool ifNodeExists(int studentID);
	/*For updating nodes by user request*/
	void updateNode(int studentID, string name, string DOB, string studentAddress);
	/*For displaying node content to user after search is done*/
	void returnNodeContent(int studentID);
	/*Displaying node content by NAME search*/
	void returnNodeNameContent(string studentName);
	/*For cheking if name exists in tree*/
	bool ifNodeNameExists(string studentName);




};

#endif
