#pragma once

#include <iostream>
#include <string>
#include "DriveManagerClass.h"
#include "SectorClass.h"
#include "WordClass.h"

using namespace std;
/*
#ifndef BinaryFileControllerClass_H
#define BinaryFileControllerClass_H

class BinaryFileControllerClass
{
public:
	BinaryFileControllerClass();
	~BinaryFileControllerClass();

	bool SaveDrive(string FileName, DriveManagerClass driveToSave);					//Returns BOOL for if save was sucsessful!	Saves drive to a binary file with the given name
	DriveManagerClass LoadDrive(string FileName);									//Loads the Drive off the binary file with the given name: 

private:

};

BinaryFileControllerClass::BinaryFileControllerClass()
{
	
}

BinaryFileControllerClass::~BinaryFileControllerClass()
{
}


bool BinaryFileControllerClass::SaveDrive(string fileName, DriveManagerClass driveToSave) {
	ofstream myfile;
	myfile.open("savefile.txt", binary);

		for (int i = 0; i < 20; i++;) {
			for (int j = -0; j < 3200; j++) {
				for (int k = 0; k < 16; k++) {
					myfile << myDrive.mysector[i].myword[j].mybits[k];
				}
			}
		}

	
	
	//Save the DriveManagerClass into a binary file, 
}

DriveManagerClass BinaryFileControllerClass::LoadDrive(string fileName) {

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 3200; j++) {
			for (int k = 0; k < 16; k++) {

			}
		}
	}
	//Load the DriveManagerClass off the binary file, and store it in ram to be manipulated.
}



#endif // !BinaryFileControllerClass_H
*/