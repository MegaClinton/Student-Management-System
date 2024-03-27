#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include<string>

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
        

        void insertPrivate(int studentID, string DOB, string studentAddress, node* Ptr);

    public:
        /*Default Constructor*/
        BST();
        /*Creating new Node*/
        node* createNode(int studentID, string DOB, string studentAddress);
        /*Insert Function*/
        void Insert(int studentID, string DOB, string studentAddress);
        /*DeleteFunction*/    //Not Yet Implemented
        /*Search Function*/    //Not Yet Implemented
        //Search based on studentID
        //Search based on name
        /*Update Function*/    //Not Yet Implemented





};

#endif
