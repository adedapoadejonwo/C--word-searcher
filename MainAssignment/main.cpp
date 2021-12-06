#include "Header.h"

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <fstream>
#include <vector>
#include <string>


using namespace std;
// this file contains the main method of the program
//the libaries above are for added functionality to the program
int main() {

	// these are the variables created for the program
	
	string file;
	string menuChoice;
	string search;
	Search searching;
	int wordCount = 0;
	string continueInput;
	
	//these are the vectors that the words from the text file are stored in
	vector<string> wordsFromFile;
	vector<string> wordsFromFile2;

	bool looking = false;

	cout << "Please enter the Name of the file that you would like to Search (enter file path): " << endl; //this prompts the user to enter the file path for the selected text file
	cin >> file;

	Storage store(file);//this creates an object of the Storage class


	if (store.input.fail()){//if the file is not found the user is prompted to restart the program
		cout << endl;
		cout << "Error, File you have entered does not exist or is the wrong file type" << endl;
		cout << "Please restart the program" << endl;
		
		
	}
	else if(!store.input.fail())// if the file is found then the program continues
	{
		looking = true;
		cout << endl;
		store.storeFile(file, wordsFromFile, wordsFromFile2); //this stores the words from the text file in two vectors
		cout << endl;

	}

	
	
	while(looking) //This while loop is used to allow the user to go back to the menu after choosing a menu option
	{
		cout << "-------------------------------------------------" << endl;
		cout << endl;
		cout << "Here is the Menu for the Word Serach Application " << endl;
		cout << endl;

		looking = false;

		//this is the menu for the application
		cout << "a) Search for Word within file (Case Sensitive) " << endl;
		cout << "b) Search for Word within file (Case Insensitive) " << endl;
		cout << "c) WordCount of Text File " << endl;
		cout << "d) Find Last Word in text file" << endl;
		cout << "e) Find first word in text file" << endl;
		cout << "x) Close the Application" << endl;
		cout << endl;
		cout << "Enter Menu Option: " << endl;// the user is prompted to enter a menu option
		cin >> menuChoice;

		if (menuChoice == "a" || menuChoice == "A") // this is the case sensitive search option
		{
			cout << endl;
			cout << "Please enter the search word" << endl;
			cin >> search;			
			searching.setSearchWord(search);
			searching.normalSearch(search, wordsFromFile); 
			searching.continueApp(looking);

		}

		else if (menuChoice == "b" || menuChoice == "B") {//This is the case insensitive search option 

			for (int i = 0; i < wordsFromFile2.size(); i++) {//this for loop goes through every element in the vector

				transform(wordsFromFile2.at(i).begin(), wordsFromFile2.at(i).end(), wordsFromFile2.at(i).begin(), tolower);//this is used to turn every word in the vector to lowercase
			}
			cout << endl;
			cout << "Please enter the search word" << endl;// user is prompted for their word choice
			cin >> search;
			transform(search.begin(), search.end(), search.begin(), tolower);
			searching.setSearchWord(search);// this sets the serach word as the word that the user inputted
			searching.normalSearch(search, wordsFromFile2);//this calls the method to search through the vector
			searching.continueApp(looking); //this is used to ask the user if they would like to continue using the application 

			
		}

		else if (menuChoice == "C" || menuChoice == "c") {//this menu choice is used to shoe the word count of the text file

			wordCount = 0; //initializes the value 

			for (int i = 0; i < wordsFromFile.size(); i++) {//this forloop counts all the words in the vector 
				wordCount++;			
			}
			cout << endl;
			cout << "Word Count of Text File is: " << wordCount << endl;
			cout << endl;
			searching.continueApp(looking);
		}
		else if (menuChoice == "d" || menuChoice == "D") {//this option is used to find the last word in the program
			cout << endl;
			cout << "last Word in text file is " << wordsFromFile.back() << endl;
			cout << endl;
			searching.continueApp(looking);
		}
		else if (menuChoice == "e" || menuChoice == "E") {//this option is used to find the first word in the text file
			cout << endl;
			cout << "First Word in text file is " << wordsFromFile.front() << endl;
			cout << endl;
			searching.continueApp(looking);
		}
		else if (menuChoice == "x" || menuChoice == "X") //this option is used to eit the program
		{
			cout << endl;
			cout << "You have chosen to Quit the program" << endl;
			looking = false;
		}
		else { //if the user enters an option not on the menu then they are told that it is unavailable
			cout << endl;
			cout << "Error search option not available, please search again" << endl;
			cout << endl;
			looking = true;
			searching.continueApp(looking);
		}
		
	} ;

	
	
	system("pause");



};