//Flash drive memery system brought to you by da Best Team!
//William Oswald (J00574334), Kalyn Alfred (J00566821), Tommi Redd (J00578397)




/*
This program is going to imitate the strange behavior of flash memory.
This will be achieved by using Boolean’s as bits (1’s and 0’s)
Using 16 bits, we will construct a word.
Using 32000 Words, we will construct 64kilobytes sectors.
Using 20 sectors, we will construct our theoretical hard drive, for a capacity of 1.28 megabytes.

The high level logic of the hard drive, such as keeping track of open sectors and open sectors to be deleted will be handled in the DriveManagerClass,
whereas simpler imitation logic will be handled within the SectorClass, and WordClass respectively.
*/
#include <iostream>
#include <string>
#include <vector>
#include "DriveManagerClass.h"
#include "SectorClass.h"
#include "WordClass.h"
#include "BinaryFileControllerClass.h"

using namespace std;

void UserOptions();
int getIntFromUser();
bool getBoolFromUser();

DriveManagerClass myDrive = DriveManagerClass();


WordClass getWordFromUser();

int main() {

	UserOptions();
	

	cout << "Thank you for your service" << endl;

	system("pause");

	return 0;
}

void UserOptions() {
	int choice;
	bool exit = false;

	WordClass tempWord;
	unsigned int nAdress;
	int sizeOfnWord = 0;
	bool didWork = false;

	while (!exit) {

		system("cls");

		cout << "1. Clear All Sectors \n"
			"2. Clear Sector \n"
			"3. Read a Word \n"
			"4. Write a Word \n"
			"5. Exit \n"
			"\nPlease enter your choice: ";
		cin >> choice;


		switch (choice)
		{

		case 1:
			myDrive.EraseAllSectors();
			cout << "\nAll sectors have been cleared \n" << endl;
			system("pause");
			break;

		case 2:
			cout << "What Sector Do You Want to Erase?" << endl;
			myDrive.EraseSpesificSector(getIntFromUser());
				cout << "\nSector has been cleared \n" << endl;
				system("pause");
			break;

		case 3:
			cout << "What Word Do you want to read?" << endl;
			nAdress = getIntFromUser();

			tempWord = myDrive.ReadWord(nAdress);


			/**
			if (nAdress % 2 != 0) //if address is aligned
				{
					cerr << "Invalid Address" << endl; //display error
				}

			else if (nAdress > myDrive.mySectors.size()) //if address is within range
				{
					cerr << "Address Out of Bounds" << endl; //display error
				}
			else
				{
				*/
			cout << "Here is The Word you requested: " << endl;

			for (int i = 0; i < bitsInByte; i++) {
				cout << tempWord.myBits[i];
			}

			cout << "\nWord has been read from address \n" << endl;
			system("pause");
			break;

		case 4:
			cout << "What word to you want to write?" << endl;
			tempWord = getWordFromUser();

			cout << "What Adress do you want to write this word?" << endl;
			nAdress = getIntFromUser();

			didWork = myDrive.WriteWord(nAdress, tempWord);

			if (didWork) {
				cout << "\nWord has been written from address \n" << endl;
			}
			else {
				cout << "\nThere was an error with the formatting, check your inputs and try again." << endl;
			}

			system("pause");
			break;

				
				//for (int i = 0; i < bitsInByte; i++) { //loop until length

				/*	sizeOfnWord++; // increment

					if (sizeOfnWord != 2)
					{
						cerr << "Incorrect Word Size" << endl;
					}

					else if (nAdress % 2 != 0) //address aligned
					{
						cerr << "Invalid Address" << endl;

					}

					else if (nAdress > bitsInByte || nAdress < 0)
					{
						cerr << "Address Out of Bounds" << endl;
					}

					else
					{

					*/
						 //theWord the user wants to write);
				
					
				

		case 5:
			exit = true;
			break;

		default:
			cout << "\nInvalid command. Please enter again. \n" << endl;
		}
	}
}

int getIntFromUser() {
	cin.ignore();
	cin.clear();

	int returnInt;

	cin >> returnInt;
	return returnInt;
}

WordClass getWordFromUser() {
	cout << "**PLEASE ONLY INCERT 0'S AND 1'S TO CREATE THIS WORD**" << endl << "ONE BIT AT A TIME, (1, (enter) 0, (enter))" << endl << "do this 16 times to create the new word" << endl;

	bool temp[bitsInByte];

	for (int i = 0; i < bitsInByte; i++) {
		temp[i] = getBoolFromUser();
		cout << endl;
	}

	WordClass WordToReturn(temp);

	return WordToReturn;
}

bool getBoolFromUser() {
	cin.ignore();
	cin.clear();

	bool returnBool;

	cin >> returnBool;
	return returnBool;
}

/*
Working with my drive. 

Global Constant Values:
	bitsInByte = 16				This is the value for how many bits are in a WordClass
	wordsPerSector = 32000		How many Words Per Sector
	sectorsInDrive = 20			Sectors in myDrive

Compare Sector 0 against Sector 1, and see if they are clones:
	 myDrive.CompareSectors(myDrive.mySectors[0], myDrive.mySectors[1]);

Compare Sector 0, Word 5 against Sector 1 Word 5;
	myDrive.CompareWords(myDrive.mySectors[0].myWords[5], myDrive.mySectors[1].myWords[5]);

Find the Length of the Drive:      Return how many sectors the drive currently has:
	int len = myDrive.mySectors.size();

Read Sector 0, Word 5, bit 19
	myDrive.mySectors[0].myWords[5].myBits[19];

Erease All Sectors:
	myDrive.EraseAllSectors();

Erase Spesific Sector:
	myDrive.EraseSpesificSector(int SectorID);

Write to Sector 0, Word 5, all 0 bits;
	bool tempWord[bitsInByte];

	for(int i = 0; i < bitsInByte; i++){
	tempWord[i] = 0
	}

	myDrive.WriteToSector(0, 5, tempWord[]);

*/
