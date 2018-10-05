//
//  main.cpp
//  Assignment2_ChuckList
//
//  Created by Derrick Marshall on 4/13/17.
//  Copyright © 2017 Derrick Marshall. All rights reserved.
//
// ?? Questions InPutFile? and GetNextItem suppose to be the array or just point to next link? and restlsit 

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "ChunkList.h"

using namespace std;

void PrintList(ofstream &outFile, ChunkList list);

int main() {
	
	string inFileName, outFileName, outPutLabel, command, message;
	ifstream inFile;
	ofstream outFile;
	
	int num = 0, numCommands = 0;
	bool found;
	
	ChunkList list;
	ItemType item;

	try {
		cout << "Enter name of input command file: ";
		cin >> inFileName;
		
		inFile.open(inFileName.c_str());
		if(inFile.fail()){
			message = "Bad\n";
			throw message;
		}
		
		cout << "Enter name of ouput command file: ";
		cin >> outFileName;
		
		outFile.open(outFileName.c_str());
		if(inFile.fail()){
			message = "Bad\n";
			throw message;
		}
		
	} catch (string message) {
		cout << message;
		return 1;
	}
	
	inFile >> command;
	
	while(command != "Quit"){
		outFile << command << " ";
		
		if (command == "PutItem") {
			inFile >> num;
			
			item.Initialize(num);
			list.PutItem(item);
			item.Print(outFile);
			outFile << " is inserted" << endl;
		}
		else if (command == "DeleteItem"){
			inFile >> num;
			
			item.Initialize(num);
			list.DeleteItem(item);
			item.Print(outFile);
			outFile << " is deleted" << endl;
		}
		else if (command == "GetItem"){
			inFile >> num;
			
			item.Initialize(num);
			found = list.GetItem(item);
			
			if(found)
				outFile << num << " found in list." << endl;
			else
				outFile << num << " not in list." << endl;
		}
		else if (command == "GetLenght"){
			outFile << "Lenght is " << list.GetLenght() << endl;
		}
		else if (command == "IsFull"){
			if(list.isFull())
				outFile << "List is full." << endl;
			else
				outFile << "List is not full." << endl;
		}
		else if (command == "MakeEmpty"){
			list.MakeEmpty();
		}
		else if(command == "PrintList"){
			PrintList(outFile, list);
		}
		else
			cout << "Command not recognized." << endl;
		
		
		numCommands++;
		cout << "Command number " << numCommands << " completed." << endl;
		inFile >> command;
	
	}
	

	
	cout << "Quit" << endl << "Testing completed." << endl;
	inFile.close();
	outFile.close();
    return 0;
}



void PrintList(ofstream &dataFile, ChunkList list){
	int lenght;
	ItemType item;
	
	list.ResetList();
	lenght = list.GetLenght();
	
	for(int index = 1; index <= lenght; index++){
		item = list.GetNextItem();
		item.Print(dataFile);
		
		dataFile << " ";
	}
	dataFile << endl;
}
