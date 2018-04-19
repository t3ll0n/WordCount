//-----------------------------------------------------------------------------------------------------
//
// Name: Tellon Smith
//
// Course: CS 3013 - Advanced Structures and Algorithms, Spring 16, Dr. Johnson
//
// Program Assignment : #2
//
// Due Date: Thursday, Jan. 25, 2016, 2PM
//
// Purpose: This program stores words from an input file into a sorted doubly linked list. It also 
//          counts the number of times the words appear.
//
//-----------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "WordList.h"

using namespace std;

void openFiles(ifstream & infile, ofstream & outfile);
//Purpose: open input and ouput streams
//Requires: infile and outfile
//Returns: an opened input and output stream

void printHeading(ofstream & outfile);
//Purpose: prints headings
//Requires: opened output stream
//Returns: outfile with headings appended to it

void printWelcomeMessage(ofstream & outfile);
//Purpose: prints a welcome message
//Requires: opened output stream
//Returns: outfile with welcome message appended to it

void printExitMessage(ofstream & outfile);
//Purpose: prints an exit message
//Requires: opened output stream
//Returns: outfile with exit message appended to it

void readInput(ifstream & infile, WordList & wordList);
//Purpose: reads the words from the input file into a sorted doubly linked list
//Requires: opened input stream, sorted dooubly linked list
//Returns: sorted double linked list with words from the input file

string modifyWord(string input);
//Purpose: modifies a word by removing non-alphanumeric characters and converting to lower case 
//Requires: string input
//Returns: modified string

void printWordList(ofstream & outfile, WordList wordList);
//Purpose: prints the words stored in the sorted doubly linked list
//Requires: opened output stream, sorted doubly linked list
//Returns: output stream with words appended to it

void main()
{
	//variable declarations
	ifstream infile;
	ofstream outfile;
	WordList wordList;

	//begin process
	openFiles(infile, outfile); //open input and output files
	printHeading(outfile);
	printWelcomeMessage(outfile);
	readInput(infile, wordList); //read words from input file
	printWordList(outfile, wordList); //prints list of words
	printExitMessage(outfile);

	//close files 
	infile.close();
	outfile.close();

	system("pause");
}


void openFiles(ifstream & infile, ofstream & outfile)
{
	char inFileName[40];
	char outFileName[40];

	//open input stream
	cout << "\nPlease enter the input file name: ";
	cin >> inFileName;
	infile.open(inFileName);

	//display error message if the specified file cannot be opened
	if (!infile)
	{
		cout << "\nERROR: cannot open the specified file. please run the program again." << endl;
		system("pause");
		exit(1);
	}

	//open output stream
	cout << "Enter the output file name: ";
	cin >> outFileName;
	outfile.open(outFileName);
}


void printHeading(ofstream & outfile)
{
	outfile << "\nName: Tellon Smith" << endl;
	outfile << "Course: CS 3013 - Advanced Structures and Algorithms, Spring 16, Dr. Johnson" << endl;
	outfile << "Program Assignment: #2" << endl;
	outfile << "Due Date: Thursday, Jan. 25, 2016, 2PM" << endl;
	outfile << "Purpose: This program stores words from an input file into a sorted doubly " << endl;
	outfile << "linked list. It also counts the number of times the words appear." << endl;
}

void printWelcomeMessage(ofstream & outfile)
{
	outfile << "\nWelcome to the Word Count Program!" << endl;
	outfile << "\n----------------------------------------------------------------------" << endl;
	outfile << "                      Word Count Program" << endl;
	outfile << "----------------------------------------------------------------------" << endl;
}

void printExitMessage(ofstream & outfile)
{
	outfile << "\nThank you for using the Welcome to the Word Count Program... Goodbye!" << endl;
}


void readInput(ifstream & infile, WordList & wordList)
{
	string input;

	//read word into variable
	while (infile >> input)
	{
		input = modifyWord(input); //modify input
		wordList.insertWord(input); //insert word into sorted doubly linked list
	}
}

string modifyWord(string input)
{
	string modifiedInput;
	int length = input.length();

	//remove any non-alphanumeric characters
	for (int i = 0; i < length; i++)
	{
		if (isalnum(input[i]))
		{
			modifiedInput += input[i];
		}
	}

	//convert to lower case
	for (int j = 0; j < length; j++)
	{
		modifiedInput[j] = tolower(modifiedInput[j]);
	}

	return modifiedInput;
}

void printWordList(ofstream & outfile, WordList wordList)
{
	string word;
	int count;

	//set current pointer to head
	wordList.resetList();

	outfile << "\nList of Words:" << endl;

	//print word and count
	while (!wordList.atEnd())
	{
		word = wordList.getWordName();
		count = wordList.getWordCount();
		outfile << word << " - " << count << endl;
		wordList.advancePosition(); //advances current to the next word
	}
}