#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <fstream>
#include <vector>
#include <string>

#include "Header.h"

//This file contains all the methods for the definitions written in the header file

void Storage::storeFile(string file, vector<string>&word, vector<string>&words) {//this method is used to store the words from the text file into two vectors
	string line;
	
	
	while (input >> line)//this loop puts the words from the text file into two seperate vectors
	{
		word.push_back(line);
		words.push_back(line);
	}
	

	input.close();


}

Storage::Storage(string in) {//this is the overloade construtor for the Storage class
	input.open(in);
}



Storage::Storage() { //this is the default constructor for the storage class
	fileName = "";
}
 
void Search::normalSearch(string word, vector<string>&list) {//this method is used to search for a word that has been stored in the vector
	searchWord = word;

	occurence = 0; //this is to initialize the value for very time the program is restarted

	for (int i =0; i < list.size(); i++)//this for loop looks through every element in a vector for a word that matches what the user inputs
	{
		if (list[i] == searchWord) // this if statement increases the variable used to count the amount of times a word appears
		{
			occurence++;
		}		
	}

	if (occurence == 0) {//if the occurence variable is 0 then the user is prompted that the word has not been found in the file
		cout << endl;
		cout << "Word not found, please search again" << endl;
		cout << endl;
	}
	else if (occurence != 0) {//This tells the user that the search word was found in the textfile and how many times it occured
		cout << endl;
		cout << "Word " << searchWord << " was found." << endl;
		cout << endl;
		cout<< "The word " << searchWord << " appears in the file " << occurence << " time(s)" << endl;
		cout << endl;
	}

}

void Search::continueApp(bool &cont) {// this method is used to ask the user if they want to continue usinf the application
	
	string input;
	cout << endl;
	cout << "Do You want to continue using this App (Enter true or false): " << endl;
	cin >> input;

	if (input == "True" || input == "true") {
		cont = true;
	}
	else if (input == "False" || input == "false") {
		cont = false;
	}
	else
	{
		cout << endl;
		cout << "Invalid Input" << endl;
		cout << endl;

	}


}


void Search::setSearchWord(string word) {//this mehtod is used to set the search word
	searchWord = word;
}

string Search::getSearchWord() {//this mehtod returns the search word
	return searchWord;
}

int Search::getOccurence()//this method gets the value for the occurence variable
{
	return occurence;
}

Search::Search()// this is the default constructor for the Search Class
{
	searchWord = "";
	occurence = 0;
}
