#include"binaryTree.h"
//#include<iostream>

using namespace std;

BST::BST(){
    root = NULL;
}

BST::node* BST::createNode(int studentID, string name, string DOB, string studentAddress){
    node* n = new node;
    n->studentID = studentID;
    n->name = name;
    n->DOB = DOB;
    n->studentAddress = studentAddress;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void BST::Insert(int studentID, string name, string DOB, string studentAddress){
    insertPrivate(studentID, name, DOB, studentAddress, root);
}

void BST::insertPrivate(int studentID, string name, string DOB, string studentAddress, node* Ptr){
    /*Adds root node if not one has been made*/
    if(root==NULL){
        root = createNode(studentID, name, DOB, studentAddress);
    }
    /*Adds Node to Left[Smaller Value]*/
    else if(studentID < Ptr->studentID){
        if(Ptr->left != NULL){
            insertPrivate(studentID, name, DOB, studentAddress, Ptr->left);
        }
        else{
            Ptr->left = createNode(studentID, name, DOB, studentAddress);
        }
    }
    /*Adds Node to the Right[Bigger Value]*/
    else if(studentID > Ptr->studentID){
        if(Ptr->right != NULL){
            insertPrivate(studentID, name, DOB, studentAddress, Ptr->right);
        }
        else{
            Ptr->right = createNode(studentID, name, DOB, studentAddress);
        }
    }
    /*Catches ID value that is equal to one already in the tree*/
    else{
        cout << "The student ID: " << studentID << " has been alread been added to the database." << endl;
    }
}

void BST::Delete(int studentID){
    deletePrivate(studentID, root);
}

void BST::deletePrivate(int studentID, node* Ptr){
    
    if(root != NULL){
        if(root->studentID == studentID){
            //RemoveRootMatch();    //might take code below in its own function
            node* delPTR = root;
            int rootKey = root->studentID;
            int smallestInRight;

            /*Node has 0 children*/
            if(root->left == NULL && root->right == NULL){
                root = NULL;
                delete delPTR;
            }

            /*Node has 1 child*/
            else if(root->left == NULL && root->right != NULL){
                root = root->right;
                delPTR->right = NULL;
                delete delPTR;
                cout<< endl;
                cout << "The student ID: " << rootKey << " was deleted." << endl;
                Sleep(2000);
                cout << endl;
            }
            else if(root->left != NULL && root->right == NULL){
                root = root->left;
                delPTR->left = NULL;
                delete delPTR;
                cout<< endl;
                cout << "The student ID: " << rootKey << " was deleted." << endl;
                Sleep(2000);
                cout << endl;
            }

            /*Node has 2 children*/
            else{
                smallestInRight = findSmallestPrivate(root->right);
                deletePrivate(smallestInRight, root);
                root->studentID = smallestInRight;
                cout << endl;
                cout << "The student ID: " << rootKey << " was deleted." << endl;
                Sleep(2000);
                cout << endl;
            }

        }
        else{
            if(studentID < Ptr->studentID && Ptr->left != NULL){
                Ptr->left->studentID == studentID ?
                removeMatch(Ptr, Ptr->left, true):
                deletePrivate(studentID, Ptr->left);
            }

            else if(studentID > Ptr->studentID && Ptr->right != NULL){
                Ptr->right->studentID == studentID ?
                removeMatch(Ptr, Ptr->right, false):
                deletePrivate(studentID, Ptr->right);
            }

            else{
                cout << endl;
                cout << "The student ID: " << studentID << " does not exist." << endl;
                Sleep(2000);
                cout << endl;
            }
        }
    }
    else{
        cout << endl;
        cout << "The database is empty." << endl;
        Sleep(2000);
        cout << endl;
    }
}

BST::node* BST::findNodeID(int studentID){
    return findNodeIDPrivate(studentID, root);
}
BST::node* BST::findNodeIDPrivate(int studentID, node* Ptr){
    if(Ptr != NULL){
        if(Ptr->studentID == studentID){
            return Ptr;
        }
        else{
            /*Search is greater than root*/
            if(studentID < Ptr->studentID){
                return findNodeIDPrivate(studentID, Ptr->left);
            }
            /*Search is less than root*/
            else{
                return findNodeIDPrivate(studentID, Ptr->right);
            }
        }
    }
    else{
        return NULL;    //Returns if nothing is found
    }
}

BST::node* BST::searchByName(string name){
    return searchByNamePrivate(name, root);
}
BST::node* BST::searchByNamePrivate(string name, node* Ptr){
    if (root == nullptr || Ptr->name == name) {
            return Ptr;
        }

        node* leftResult = searchByNamePrivate(name, Ptr->left);
        if (leftResult) {
            return leftResult;
        }

        return searchByNamePrivate(name, Ptr->right);
}




int BST::findSmallest(){
    return findSmallestPrivate(root);
}

int BST::findSmallestPrivate(node* Ptr){
    if(root == NULL){
        return 0;   //Might have to change
    }
    else{
        if(Ptr->left != NULL){
            return findSmallestPrivate(Ptr->left);
        }
        else{
            return Ptr->studentID;
        }

    }

}

void BST::removeMatch(node* Ptr, node* match, bool left){
    if(root != NULL){
        node* delPtr;
        int matchKey = match->studentID;
        int smallestInRightSubTree;

        /*Node has 0 children*/
        if(match->left == NULL && match->right == NULL){
            delPtr = match;
            left == true ? Ptr->left = NULL : Ptr->right = NULL;
            delete delPtr;
            cout << endl;
            cout << "The student ID: " << matchKey << " was deleted." << endl;
            Sleep(2000);
            cout << endl;
        }

        /*Node has 1 Child*/
        else if(match->left == NULL && match->right != NULL){
            left == true ? Ptr->left = match->right : Ptr->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout << endl;
            cout << "The student ID: " << matchKey << " was deleted." << endl;
            Sleep(2000);
            cout << endl;
        }
        else if(match->left != NULL && match->right == NULL){
            left == true ? Ptr->left = match->left : Ptr->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << endl;
            cout << "The student ID: " << matchKey << " was deleted." << endl;
            Sleep(2000);
            cout << endl;
        }

        /*Node has 2 Children*/
        else{
            smallestInRightSubTree = findSmallestPrivate(match->right);
            deletePrivate(smallestInRightSubTree, match);
            match->studentID = smallestInRightSubTree;
            
        }
    }
}

/*Deconstructor*/
BST::~BST(){
    RemoveTree(root);
}

/*Deletes SubTree from Node chosen*/
void BST::RemoveTree(node* Ptr){
    if(Ptr != NULL){
        if(Ptr->left != NULL){
            RemoveTree(Ptr->left);
        }
        if(Ptr->right != NULL){
            RemoveTree(Ptr->right);
        }
        delete Ptr;
    }
}