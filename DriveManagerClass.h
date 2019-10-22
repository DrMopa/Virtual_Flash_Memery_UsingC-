#pragma once

#include "WordClass.h"
#include "SectorClass.h"
#include <vector>

using namespace std;

#ifndef DriveManagerClass_H
#define DriveManagerClass_H

int const sectorsInDrive = 20;

class DriveManagerClass
{
public:
	DriveManagerClass();								//Initalize All Sectors as Default values
	DriveManagerClass(SectorClass nSectorsToAdd[sectorsInDrive]);		//Initalize All Sectors, with an unknown number of Sectors, to be added to mySectors[Array]
	~DriveManagerClass();								//Delete this Drive manager. *NOT CLEAR*

	void EraseAllSectors();								//Clear all words within all Sectors, setting all values to 1.
	void EraseSpesificSector(int SectorID);				//Clear all words within a Sector

	bool WriteToSector(int SectorID, SectorClass nSectorToAdd);				//THIS RETURNS BOOL FOR IF IT WAS SUCSESSFUL! Writes a spesific sector to mySectors[Array] given ID
	bool WriteToSector(int SectorID, int WordID, WordClass nWordToAdd);		//THIS RETURNS BOOL FOR IF IT WAS SUCSESSFUL! Writes a spesific word, to a spesific wordID, to a spesific Sector. Given that Word is able to be written to without clearing entire sector.
	bool WriteWord(int TotalInt, WordClass nWordToAdd);

	bool ReadBit(int SectorID, int WordID, int BitID);	//Read a spesific bit, from a spesific word, from a spesific vector.
	WordClass ReadWord(int SectorID, int WordID);		//Read a spesific word, from a spesific sector. 
	WordClass ReadWord(int TotalPosition);
	SectorClass ReadSector(int SectorID);				//Read a spesific Sector

	bool CompareSectors(SectorClass sector1, SectorClass sector2);		// Compares 2 Sectors against eachother, RETURNS BOOL IF ITEMS MATCH
	bool CompareWords(WordClass word1, WordClass word2);				// compares 2 words against eachother, RETURNS BOOL IF ITEMS MATCH


	vector <SectorClass> mySectors;
};

DriveManagerClass::DriveManagerClass(){


	for (int i = 0; i < sectorsInDrive; i++){
		mySectors.push_back(SectorClass());
	}
}

DriveManagerClass::DriveManagerClass(SectorClass nSectorsToAdd[sectorsInDrive]) {
	for (int i = 0; i < sectorsInDrive; i++) {
		mySectors[i] = nSectorsToAdd[i];
	}
}

DriveManagerClass::~DriveManagerClass(){

}

void DriveManagerClass::EraseAllSectors() {
	for (int i = 0; i < sectorsInDrive; i++) {
		mySectors[i] = SectorClass();
	}
}

void DriveManagerClass::EraseSpesificSector(int SectorID) {
	mySectors[SectorID] = SectorClass();
}

bool DriveManagerClass::WriteToSector(int SectorID, SectorClass nSectorToAdd) {
	bool responce = true;
	bool temp = true;

	for (int i = 0; i < wordsPerSector; i++) {
		temp = WriteToSector(SectorID, i, nSectorToAdd.myWords[i]);
		responce = (responce && temp);
	}

	return(responce);
}

bool DriveManagerClass::WriteWord(int TotalInt, WordClass nWordToAdd) {

	int SectorID = (int)(TotalInt / wordsPerSector);		// Determin the Sector the word is in
	int WordID = TotalInt % wordsPerSector;				// Determin the Words Position inside that Sector

	WriteToSector(SectorID, WordID, nWordToAdd);

	bool returnValue = CompareWords(nWordToAdd, ReadWord(SectorID, WordID));

	return (returnValue);

}


bool DriveManagerClass::WriteToSector(int SectorID, int WordID, WordClass nWordToAdd) {
	bool responce = mySectors[SectorID].WriteToSector(WordID, nWordToAdd);
	return(responce);
}

bool DriveManagerClass::ReadBit(int SectorID, int WordID, int BitID) {
	bool ReturnBit = mySectors[SectorID].myWords[WordID].myBits[BitID];
	return (ReturnBit);
}

WordClass DriveManagerClass::ReadWord(int SectorID, int WordID) {
	WordClass returnWord = mySectors[SectorID].myWords[WordID];
	return (returnWord);
}

WordClass DriveManagerClass::ReadWord(int TotalPosition) {

	int SectorID = (int)(TotalPosition / wordsPerSector);		// Determin the Sector the word is in
	int WordID = TotalPosition % wordsPerSector;				// Determin the Words Position inside that Sector

	WordClass returnWord = ReadWord(SectorID, WordID);
	return (returnWord);
}

SectorClass DriveManagerClass::ReadSector(int SectorID) {
	SectorClass returnSector = mySectors[SectorID];
	return(returnSector);
}

bool DriveManagerClass::CompareSectors(SectorClass sector1, SectorClass sector2) {
	bool record = true;

	for (int i = 0; i < wordsPerSector; i++) {
		if (!CompareWords(sector1.myWords[i], sector2.myWords[i])) {
			record = false;
			break;
		}
	}

	return (record);
}
bool DriveManagerClass::CompareWords(WordClass word1, WordClass word2) {

	bool record = true;

	for (int i = 0; i < bitsInByte; i++) {
		if (word1.myBits[i] != word2.myBits[i]) {
			record = false;
			break;
		}
	}

	return (record);
}

#endif // !DriveManagerClass_H
