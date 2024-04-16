#include"binaryTree.h"
//#include<iostream>

using namespace std;

/*Default Constructor*/
BST::BST(){
    root = NULL;
}

/*Creates node only accessed by insertPrivate function*/
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

/*What user interacts with when inserting new students*/
void BST::Insert(int studentID, string name, string DOB, string studentAddress){
    insertPrivate(studentID, name, DOB, studentAddress, root);	//Sends data to insertPrivate
}

/*Takes data from Insert function*/
void BST::insertPrivate(int studentID, string name, string DOB, string studentAddress, node* Ptr){
    /*Adds root node if not one has been made*/
    if(root==NULL){
        root = createNode(studentID, name, DOB, studentAddress);
    }
    /*Adds Node to Left[Smaller Value]*/
    else if(studentID < Ptr->studentID){
        if(Ptr->left != NULL){
            insertPrivate(studentID, name, DOB, studentAddress, Ptr->left); //recursive call until finds an empty node
        }
        else{
            Ptr->left = createNode(studentID, name, DOB, studentAddress); //Creates new node
        }
    }
    /*Adds Node to the Right[Bigger Value]*/
    else if(studentID > Ptr->studentID){
        if(Ptr->right != NULL){
            insertPrivate(studentID, name, DOB, studentAddress, Ptr->right); //recursive call until finds an empty node
        }
        else{
            Ptr->right = createNode(studentID, name, DOB, studentAddress); //Creates new node
        }
    }
    /*Catches ID value that is equal to one already in the tree*/
    else{
        cout << "The student ID: " << studentID << " has been alread been added to the database." << endl;
    }
}

/*What user interacts with when inserting deleting students*/
void BST::Delete(int studentID){
    deletePrivate(studentID, root);
}

/*Takes data delete function*/
void BST::deletePrivate(int studentID, node* Ptr){
    
    if(root != NULL){	//Checks if binary tree is empty
		/*This is for if the root is the node that is goind to be deleted*/
        if(root->studentID == studentID){
            node* delPTR = root;
            int smallestInRight;	//place holder to keep items in for the new root that is going to be made after the original root is deleted

            /*Node has 0 children*/
            if(root->left == NULL && root->right == NULL){
                root = NULL;	//empties node before deletion
                delete delPTR;	//Deletes the node
            }

            /*Node has 1 child*/
            else if(root->left == NULL && root->right != NULL){
                root = root->right;	//assigns new root node with right child values
                delPTR->right = NULL;	//empties node before deletion
                delete delPTR;	//Deletes old root
                cout<< endl;
                cout << "The student ID: " << studentID << " was deleted." << endl;	//Displays to user that node is now deleted
                //Sleep(2000);
				usleep(2000000);
                cout << endl;
            }
            else if(root->left != NULL && root->right == NULL){
                root = root->left;	//assigns new root node with left child values
                delPTR->left = NULL;	//empties node before deletion
                delete delPTR;	//Deletes old root
                cout<< endl;
                cout << "The student ID: " << studentID << " was deleted." << endl;	//Displays to user that node is now deleted
                //Sleep(2000);
				usleep(2000000);
                cout << endl;
            }

            /*Node has 2 children*/
            else{
                smallestInRight = findSmallestPrivate(root->right);	//Finds smallest node in right subtree that is going to be new root node
				node* tempNode = findNodeID(smallestInRight);
				int tempID = tempNode->studentID;
				string tempName = tempNode->name;
				string tempDOB = tempNode->DOB;
				string tempAddress = tempNode->studentAddress;
                deletePrivate(smallestInRight, root);	//Deletes the smallest node in the right subtree
				cout << "Deleted but will be new root" << endl;
				/*Overides root with new root info*/
                root->studentID = tempID;
				root->name = tempName;
				root->DOB = tempDOB;
				root->studentAddress = tempAddress;
                cout << endl;
                cout << "The student ID: " << studentID << " was deleted." << endl;	//Displays to user that node is now deleted
                //Sleep(2000);
				usleep(2000000);
                cout << endl;
            }

        }
		
		/*This is for if another node that is not the root is going to be deleted*/
        else{
            if(studentID < Ptr->studentID && Ptr->left != NULL){	//Checks left subtree of root
				/*Check left child key for a match to input*/
                Ptr->left->studentID == studentID ?
				/*If input matches current node then sends(current node pointed, pointer to left child, bool to specify if left child is the one being sent)*/
                removeMatch(Ptr, Ptr->left, true):
				/*Recursive function to keep looking*/
                deletePrivate(studentID, Ptr->left);
            }

            else if(studentID > Ptr->studentID && Ptr->right != NULL){	//Checks right subtree of root
				/*Checks right child for key match to user input*/
                Ptr->right->studentID == studentID ?
				/*If input matches current node then sends(current node pointed, pointer to right child, bool to specify that right child is the one being sent)*/
                removeMatch(Ptr, Ptr->right, false):
				/*Recursive function to keep looking in right subtree*/
                deletePrivate(studentID, Ptr->right);
            }

            else{	//Does not find the ID of student entered by user
                cout << endl;
                cout << "The student ID: " << studentID << " does not exist." << endl;
                //Sleep(2000);
				usleep(2000000);
                cout << endl;
            }
        }
    }
    else{
        cout << endl;
        cout << "The database is empty." << endl;
        //Sleep(2000);
		usleep(2000000);
        cout << endl;
    }
}

/*Searches for and returns node to user*/
BST::node* BST::findNodeID(int studentID){
    return findNodeIDPrivate(studentID, root);
}

/*Accesses private & Searches for and returns node*/
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

/*Boolean Check to see if node exists*/
bool BST::ifNodeExists(int studentID){
	if(findNodeID(studentID)==NULL){
		return false;
	}
	else{
		return true;
	}
}

/*Finds and returns pointer to user from Name*/
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
            //Sleep(2000);
			usleep(2000000);
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
            //Sleep(2000);
			usleep(2000000);
            cout << endl;
        }
        else if(match->left != NULL && match->right == NULL){
            left == true ? Ptr->left = match->left : Ptr->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << endl;
            cout << "The student ID: " << matchKey << " was deleted." << endl;
            //Sleep(2000);
			usleep(2000000);
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

/*For the Search function to display all the info to user*/
void BST::returnNodeContent(int studentID){
	returnNodePrivate(studentID, root);
}

void BST::returnNodePrivate(int studentID, node* Ptr){
	if(Ptr != NULL){
		Ptr = findNodeIDPrivate(studentID, Ptr);
		cout << "Student ID: " << Ptr->studentID << endl;
		cout << "Student Name: " << Ptr->name << endl;
		cout << "Student DOB: " << Ptr->DOB << endl;
		cout << "Student Address: " << Ptr->studentAddress << endl;
	}
	else{
		cout << "ID not in sytem" << endl;
	}
}

void BST::updateNode(int studentID, string updateName, string updateDOB, string updateStudentAddress){
	updateNodePrivate(studentID, updateName, updateDOB, updateStudentAddress, root);
}

void BST::updateNodePrivate(int studentID, string updateName, string updateDOB, string updateStudentAddress, node* Ptr){
	node* tempNode = findNodeID(studentID);
	tempNode->name = updateName;
	tempNode->DOB = updateDOB;
	tempNode->studentAddress = updateStudentAddress;
}

/*Deconstructor*/
BST::~BST(){
    RemoveTree(root);
}

/*Deletes SubTree from Node chosen in Post-Order Traversal*/
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