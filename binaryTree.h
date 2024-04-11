#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include<string>
#include<windows.h> 

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
        

        void insertPrivate(int studentID, string name, string DOB, string studentAddress, node* Ptr);
        void deletePrivate(int studentID, node* Ptr);
        int findSmallestPrivate(node* Ptr);
        void removeMatch(node* root, node* match, bool left);
        /*Creating new Node*/
        node* createNode(int studentID, string name, string DOB, string studentAddress);
        void RemoveTree(node* Ptr);
        node* findNodeID(int studentID);
        node* findNodeIDPrivate(int studentID, node* Ptr);
        node* searchByName(string name);
        node* searchByNamePrivate(string name, node* Ptr);

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





};

#endif