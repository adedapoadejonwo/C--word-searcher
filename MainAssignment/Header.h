#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//This is the header file for the program,
//libaries are added to the program above for increased functionality


class Search // This class is for searching for words in the vector 
{

	//these are the class attributes
	private:
		string searchWord;
		int occurence ;
		bool wordFound;
	
	//Theses are the class methods
	public:
		Search(); // class constructer
		int getOccurence();
		void setSearchWord(string word);		
		string getSearchWord();
		void normalSearch(string word, vector<string>&list);		
		void continueApp(bool &cont);
};


class Storage  //This class is for saving words from the text file into a Vector
{
	//these are the attributes of the class
	private:		
		string fileName;
		vector<string> wordList;


	//these are the class methods
	public:				
		ifstream input;

		void storeFile(string name, vector<string>&word, vector<string>&words);
		Storage();//class constructor
		Storage(string in);//overloaded class constructor
		
};

#endif