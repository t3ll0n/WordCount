//Tellon Smith
//CMPS 3013 - Program 2
//Point.h
//This file declares a sorted doubly linked list to store words and count the number of
//times the words appear.

#pragma once

#include <string>

using namespace std;

struct WordNode
{
	string word;
	int count;
	WordNode * next;
	WordNode * prev;
};


class WordList
{
public:
	//default constructor
	WordList();

	//copy constructor
	WordList(WordList & otherList);

	//destructor
	~WordList();

	bool isEmpty();
	//Purpose: checks to see if list is empty
	//Requires: head pointer
	//Returns: true of false

	void insertWord(string wordName);
	//Purpose: inserts a new word into the sorted doubly linked list (increments count if 
	//         word already exist)
	//Requires: doubly linked list initialized, new word to insert
	//Returns: doubly linked list with new word inserted or count incremented

	void removeWord(string WordName);
	//Purpose: removes a word from the doubly linked list
	//Requires: doubly linked list initialized, word to be removed
	//Returns: doubly linked list with specified word removed

	int getLength();
	//Purpose: returns the of length the double linked list
	//Requires: none
	//Returns: length

	void resetList();
	//Purpose: resets the current pointer to the head pointer
	//Requires: head pointer initialized
	//Returns: current pointer as head pointer

	string getWordName();
	//Purpose: returns the word of the current pointer
	//Requires: current pointer initialized
	//Returns: the word of the current position

	int getWordCount();
	//Purpose: returns the word count of the current pointer
	//Requires: current pointer initialized
	//Returns: the word count of the current position

	void advancePosition();
	//Purpose: advances the position of the current pointer
	//Requires: current pointer initialized
	//Returns: current point at next position

	bool atEnd();
	//Purpose: checks to see if the current pointer is at the end of the list
	//Requires: current pointer initialized
	//Returns: true or false

private:

	WordNode * head;
	WordNode * tail;
	WordNode * current;
	int length;
};