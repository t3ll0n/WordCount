//Tellon Smith
//CMPS 3013 - Program 2
//WordList.cpp
//Implements WordList class in WordList.h


#include "WordList.h"
#include <iostream>
#include <fstream>
using namespace std;

WordList::WordList()
{
	//initialize the list
	head = new WordNode;
	tail = new WordNode;
	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = head;
	length = 0;
}

WordList::WordList(WordList & otherList)
{
	//initialize the list
	head = new WordNode;
	tail = new WordNode;
	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = head;
	length = 0;

	//reset head and advance position
	otherList.resetList();
	otherList.advancePosition();

	//copy from otherList
	while (!otherList.atEnd())
	{
		int count = otherList.current->count;

		if (count > 1)
		{
			for (int i = 0; i < count; i++)
			{
				insertWord(otherList.current->word);
			}
		}
		else
		{
			insertWord(otherList.current->word);
		}
		otherList.advancePosition();
	}
}

WordList::~WordList()
{
	WordNode * garbage;

	resetList();

	//delete nodes
	while (head->next != tail)
	{
		garbage = head->next;
		head->next = garbage->next;
		delete garbage;
	}
}

bool WordList::isEmpty()
{
	if (head->next == tail)
		return true;
	else
		return false;
}

void WordList::insertWord(string wordName)
{
	{
		bool inserted = false;

		//set current to head
		if (current != head)
		{
			resetList();
		}

		while (!inserted)
		{
			//list is empty (first word to be inserted)
			if (isEmpty())
			{
				WordNode *tempNode = new WordNode;
				tempNode->word = wordName;
				tempNode->count = 1;
				tempNode->next = head->next;
				tempNode->prev = head;
				head->next = tempNode;
				inserted = true;
				length++;
			}
			//word is already exist in the list (increment count)
			else if (current->word == wordName)
			{
				current->count++;
				inserted = true;
			}
			//insert word between other words (sorted)
			else if ((current->word < wordName && current->next == tail) || (current->word < wordName
				&& current->next->word > wordName) || (atEnd()))
			{
				WordNode *tempNode = new WordNode;
				tempNode->word = wordName;
				tempNode->count = 1;
				tempNode->next = current->next;
				tempNode->prev = current;
				current->next = tempNode;
				tempNode->next->prev = tempNode;
				inserted = true;
				length++;
			}
			//insert word at the front
			else if (current->word > wordName)
			{
				WordNode *tempNode = new WordNode;
				tempNode->word = wordName;
				tempNode->count = 1;
				tempNode->next = head->next;
				tempNode->prev = head;
				head->next = tempNode;
				tempNode->next->prev = tempNode;
				inserted = true;
				length++;
			}
			else
			{
				advancePosition();
			}

		}
	}
}


void WordList::removeWord(string wordName)
{
	bool found = false;
	WordNode * removeItem = NULL;

	//set current to head
	if (current != head)
	{
		resetList();
	}

	//seach list for specified word to be deleted
	while (!found && !atEnd())
	{
		if (current->word == wordName)
		{
			found = true;
			removeItem = current;
		}
		else
		{
			advancePosition();
		}
	}

	//delete node and decrement list
	if (found == true)
	{
		current->prev->next = current->next;
		current->prev->next->prev = current->prev;
		delete current;
		resetList();
		length--;
	}
}

int WordList::getLength()
{
	return length;
}

void WordList::resetList()
{
	//set current to head
	current = head;
}

string WordList::getWordName()
{
	string wordName;

	//advance position if currently at head
	if (current == head)
	{
		advancePosition();
	}

	wordName = current->word;

	return wordName;
}

int WordList::getWordCount()
{
	int wordCount;

	//advance position if currently at head 
	if (current == head)
	{
		advancePosition();
	}

	wordCount = current->count;

	return wordCount;
}


void WordList::advancePosition()
{
	if (!atEnd())
	{
		current = current->next; //move to next pointer
	}
}

bool WordList::atEnd()
{
	if (current == tail)
	{
		return true;
	}
	else
		return false;
}

