#pragma once

const int bitsInByte = 16;

#ifndef WordClass_H
#define WordClass_H

class WordClass
{
public:

	

	WordClass();					//Default contructor, inizalize to all bits = 1 (clear state)
	WordClass(bool nBitsToAdd[bitsInByte]);	//Spesified constructor, inizalize with a spesific value, defined by caller.
	~WordClass();					//Delete the entire word, *NOT CLEAR*

	bool WriteToWord(bool nWordToWrite[bitsInByte]);	//BOOL TO TELL IF WRITE WAS SUCSESSFUL: Writes new value to myWord[Array]. (CAN ONLY WRITE OVER IF ALL BITS IT WANTS TO WRITE TOO ARE 1)
	void ClearWord();				//Sets myWord[Array] To all 1's (Clear in flash memory)

	WordClass ReadWord();			//Returns the Entire Word in question for reading and manipulating purposes.
	bool ReadBit(int intID);
	

	bool myBits[16];					//This class's spesific word

};

WordClass::WordClass(){

	for (int i = 0; i < bitsInByte; i++)
	{
		myBits[i] = 1;
	}
}

WordClass::WordClass(bool nBitsToAdd[bitsInByte]){

	for (int i = 0; i < bitsInByte; i++) {
		myBits[i] = nBitsToAdd[i];
	}
}

WordClass::~WordClass()
{
}


bool WordClass::WriteToWord(bool nWordToWrite[bitsInByte]) {
	
	bool  noErrorFlag = 1;



	for (int i = 0; i < bitsInByte; i++) {
		if ((myBits[i] == 0) && (nWordToWrite[i] == 1)) {
			return(0);		//Error Found
		}
	}

	for (int i = 0; i < bitsInByte; i++) {
		myBits[i] = nWordToWrite[i];
	}

	return(1);

}

void WordClass::ClearWord() {

	for (int i = 0; i < bitsInByte; i++)
	{
		myBits[i] = 1;
	}
}

WordClass WordClass::ReadWord() {
	WordClass wordToReturn = WordClass(myBits);
	return wordToReturn;
}

bool WordClass::ReadBit(int bitToReadID) {
	return(myBits[bitToReadID]);
}

#endif // WordClass_H

