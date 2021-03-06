// AssignmentDSA.cpp : Defines the entry point for the console application.
//
// TEAM DETAILS
// TEAM: Lucas & RAYNER
// Lucas:
// Rayner: S10177641K
//
//Features
//
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "List.h"
#include <conio.h>
#define DICTIONARY "dictionary.txt"     //put the name of file representing the dictionary here

using namespace std;

List dict;
List txtfile;
List newfile;
void loaddictionary()
{
	string path;
	string getcontent;
	ifstream inFile("dictionary.txt");
	//inFile.open(path);
	if (inFile.is_open())
	{
		int i = 0;
		while (getline(inFile,getcontent))
		{
			dict.add(getcontent);
		}
	}
	else
	{
		cout << "Could not find file\n";
	}
	inFile.close();
}

//This method allows user to spellcheck his/her work
void CheckWord() {
	//User key in word
	string word;
	cout << "Please enter a word: ";
	cin >> word;
	// Program to check through array O(N) | Iterative Search
	
	//BinarySearch | log2(n)
	bool found = false;
	for (int i = 1; i < dict.getLength() + 1; i++)
	{
		if (word == dict.get(i))
		{
			found = true;
			break;
		}
		else {
			found = false;
		}
	}
	if (found) {
		cout << word + " is found in the Dictionary!" << endl;
	}
	if (found == false)
	{
		cout << word + " can't be found in the Dictionary!" << endl;
	}
}

bool checkWord(string w) {
	for (int i = 1; i < dict.getLength() + 1; i++)
	{
		if (w == dict.get(i))
		{
			return true;
		}
	}
	return false;
}

//Spell check a file
void CheckFile() {
	string file;
	string getcontent;
	cout << "Enter format of file (csv or txt): ";
	cin >> file;

	if (file == "csv") {
		ifstream inFile("dictionary10K.csv");
		if (inFile.is_open())
		{
			cout << "Found CSV file!" << endl;
		}

	}
	else if (file == "txt") {
		ifstream inFile("dictionary10K.txt");
		if (inFile.is_open())
		{
			int count = 0;
			cout << "Found TXT file!" << endl;
			while (getline(inFile,getcontent)) {
				
				if (checkWord(getcontent) == false) {
					cout << getcontent << endl;
				}
				
			}
		}
		inFile.close();
	}

}
//Add a word to dictionary
void AddWord() {
	string word;
	cout << "Please enter a word: ";
	cin >> word;
	bool found = false;
	
	//Searching algorithm to improve
	for (int i = 1; i < dict.getLength() + 1; i++)
	{
		if (word == dict.get(i))
		{
			cout << "Word already exists in Dictionary" << endl;
			found = true;
			break;
		}
		else {
			found = false;
		}
	}
	if (found == false) {
		//Write to file
		cout << "COOL! Your word will be added" << endl;
		ofstream myfile;
		myfile.open("dictionary.txt", ios_base::app);
		
		myfile << word; //
		dict.add(word); //O(1)
		//Add to list
		myfile.close();
	}
}

//Display all words in the dictionary that starts with certain letter(s) specified by the user
//O(N)
void displayWordstart() {
	//User key in character
	char letter;
	cout << "Please enter a letter(small caps): ";
	cin >> letter;
	bool success = (letter == 'a' || letter == 'b' || letter == 'c' || letter == 'd' || letter == 'e' || letter == 'f' || letter == 'g' || letter == 'h' || letter == 'i' || letter == 'j' || letter == 'k' || letter == 'l' || letter == 'm' || letter == 'n' || letter == 'o' || letter == 'p' || letter == 'q' || letter == 'r' || letter == 's' || letter == 't' || letter == 'u' || letter == 'v' || letter == 'w' || letter == 'x' || letter == 'y' || letter == 'z');

	if (success) {
		for (int i = 1; i < dict.getLength() + 1; i++) {
			if (letter == dict.get(i)[0])
			{
				cout << dict.get(i) << endl;
			}
		}
	}
	else {
		cout << "No such word in the dictuonary starts with this letter, please try again!" << endl;
	}
}
void idk() {
	cout << dict.getLength();
}

//This method is an interface for the user to select his/her options adding a new word/ checking a word to dictionary
void UserProgam() {
	/*The program gives a menu to user where he/she can choose either to
	check an existing file,
	create a new file or
	to add a word in the dictionary
	*/
	int choice;
	system("cls");
	loaddictionary(); // Load Dictionary
	while (true)
	{
		cout << "1. Check a word\n2. Spell Check a File\n3. Add Word\n4. NULL\n5. Display word that start with a certain letter\n6. Exit\n";
		cout << "Enter your choice:";
		cin >> choice;


		if (choice == 1) {

			CheckWord();
		}
		if (choice == 2) {
			CheckFile();
		}
		if (choice == 3) {
			AddWord();
		}
		if (choice == 4) {
			idk();
		}

		if (choice == 5) {
			displayWordstart();
		}
		if (choice == 6) {
			cout << "Thank you for using this program!" << endl;
			break;

		}
	}





}

int main()
{

	UserProgam();
	system("PAUSE");
	return 0;
}


