#include<binaryTree.h>

/*HAVE NOT FULLY TESTED JUST WRITTEN IT SO FAR*/

using namespace std;

BST::BST(){
    root = NULL;
}

BST::node* BST::createNode(int studentID, string DOB, string studentAddress){
    node* n = new node;
    n->studentID = studentID;
    n->DOB = DOB;
    n->studentAddress = studentAddress;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void BST::Insert(int studentID, string DOB, string studentAddress){
    insertPrivate(studentID, DOB, studentAddress, root);
}

void BST::insertPrivate(int studentID, string DOB, string studentAddress, node* Ptr){
    /*Adds root node if not one has been made*/
    if(root==NULL){
        root = createNode(studentID, DOB, studentAddress);
    }
    /*Adds Node to Left[Smaller Value]*/
    else if(studentID < Ptr->studentID){
        if(Ptr->left != NULL){
            insertPrivate(studentID, DOB, studentAddress, Ptr->left);
        }
        else{
            Ptr->left = createNode(studentID, DOB, studentAddress);
        }
    }
    /*Adds Node to the Right[Bigger Value]*/
    else if(studentID > Ptr->studentID){
        if(Ptr->right != NULL){
            insertPrivate(studentID, DOB, studentAddress, Ptr->right);
        }
        else{
            Ptr->right = createNode(studentID, DOB, studentAddress);
        }
    }
    /*Catches ID value that is equal to one already in the tree*/
    else{
        cout << "The id " << studentID << " has been alread been added to the database." << endl;
    }
}
