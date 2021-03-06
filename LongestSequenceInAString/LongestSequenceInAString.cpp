// LongestSequenceInAString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int Table[10][2] = { 0 };

void UpdateTable(char* _pChar, int _iCount)
{
	int iFree = 0;
	// find it in the table, if it isn't found, find next empty
	for (int x = 0; x < 10; x++) {
		if (((int)(*_pChar)) == Table[x][0]) {
			if (Table[x][1] < _iCount) {
				Table[x][1] = _iCount;
				return;
			}
		}
		else if (Table[x][0] != 0) {
			iFree++;
		}
	}

	Table[iFree][0] = (int)(*_pChar);
	Table[iFree][1] = _iCount;
}


void GetLongestSequence(char* _Char, int* _iCount)
{
	char cCurChar = (char)Table[0][0];
	int iCurCount = Table[0][1];

	for (int x = 0; x <= 10; x++) {
		if (iCurCount < Table[x][1]) {
			iCurCount = Table[x][1];
			cCurChar = (char)Table[x][0];
		}
	}

	(*_Char) = cCurChar;
	(*_iCount) = iCurCount;
}

void DummyFunc()
{

}

int DetermineLongestSequence(char* _String, int _iLen)
{
	char cCurChar = '\0';
	int iCurCount = 0;

	for (int i = 0; i < _iLen; i++) {
		if (_String[i] == cCurChar) {
			iCurCount++;
		}
		else {
			if (cCurChar != '\0') {
				// update table, get new char
				UpdateTable(&cCurChar, iCurCount);
			}
			iCurCount = 1;
			cCurChar = _String[i];
		}
	}
	UpdateTable(&cCurChar, iCurCount);

	GetLongestSequence(&cCurChar, &iCurCount);
	printf("\n %c longest span was %d", cCurChar, iCurCount);

	return iCurCount;
}
 
int main()
{
    std::cout << "Hello World!\n"; 

	char String[] = "abbcccdddddeefffffffffgggg";
	DetermineLongestSequence(String, strlen(String));
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
