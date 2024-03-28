#ifndef READIN_H
#define READIN_H

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

void readIn(){
    ifstream inputFile;
    inputFile.open("testStudents.csv");
    string line = "";

    while(getline(inputFile, line)){

        int studentID;
        string name;
        string DOB;
        string studentAddress;
        string tempString = "";

        stringstream inputString(line);

        getline(inputString, tempString, ',');
        studentID = atoi(tempString.c_str());
        getline(inputString, name, ',');
        getline(inputString, DOB, ',');
        getline(inputString, studentAddress);

        cout << studentID << " " << name << " " << DOB << " " << studentAddress << endl;

        line = "";

    }


}

#endif