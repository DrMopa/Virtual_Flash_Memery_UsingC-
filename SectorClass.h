#pragma once

#include "WordClass.h"

#ifndef SectorClass_H
#define SectorClass_H

const int wordsPerSector = 32000;

class SectorClass
{
public:
	SectorClass();								//Create new sector with all words created as defaults (call WordClass Default constructor)
	SectorClass(WordClass myInitalWords[wordsPerSector]);		//Create a Sector with an unknown number of words, to be added to the myWords[Array]
	SectorClass(WordClass myInitalWord, int WordID);					
	~SectorClass();								//Delete this Sector *NOT CLEAR*

	void ClearSector();							//Set all myWords[Array] to 1's.
	bool WriteToSector(int nAdress, WordClass nWord);	//THIS FUNCTION IS A BOOL, it will return a bool value depending on if the write was sucsessful.

	SectorClass ReadSector();					//Return This sector to the caller.
	WordClass ReadSpesific(int WordID);	//Return a spesific word from myWords[Array]


	WordClass myWords[wordsPerSector];
};

SectorClass::SectorClass() {

	for (int i = 0; i < wordsPerSector; i++) {
		myWords[i] = WordClass();
	}

}

SectorClass::SectorClass(WordClass myInitalWords[wordsPerSector]) {
	for (int i = 0; i < wordsPerSector; i++) {
		myWords[i] = myInitalWords[i];
	}
}

SectorClass::SectorClass(WordClass myInitalWords, int WordID) {
	myWords[WordID] = myInitalWords;
}

SectorClass::~SectorClass() {

}

void SectorClass::ClearSector() {
	for (int i = 0; i < wordsPerSector; i++) {
		myWords[i] = WordClass();
	}

}
bool SectorClass::WriteToSector(int nAdress, WordClass nWord) {

	if (myWords[nAdress].ReadBit(0) != NULL) {
		myWords[nAdress] = nWord;
		return 1;
	}

	return 0;
}

SectorClass SectorClass::ReadSector() {
	SectorClass tempSector = SectorClass(myWords);
	return (tempSector);
}

WordClass SectorClass::ReadSpesific(int NWordToRead) {
	WordClass tempWord = myWords[NWordToRead];
	return tempWord;
}


#endif 
