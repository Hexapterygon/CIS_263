#include <iostream>
#include <cstdlib>
#include "RedBlackTree.h"
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/********************************************
* Class responsible for reading in the three
* separate plays and storing them in a 
* red-black tree word by word.
********************************************/
class readIn {

		private:

			string word;
			//NEG_INF is a value that is smaller than all other values.
			//the 'space' character is the smallest string.
			string NEG_INF = " ";

		public:

				RedBlackTree<string> hamlet{NEG_INF};
				RedBlackTree<string> tempest{NEG_INF};
				RedBlackTree<string> romeojuliet{NEG_INF};
				void readHamlet(const string& filepath);
				void readTempest(const string& filepath1);
				void readRomeoJuliet(const string& filepath2);
				vector<string> hasTerm(const string& term);
				int countTerm(const string& term);
};

/********************************************
* Reads in all words in Hamlet. Accepts a 
* string file path as a constant reference
* from the main function. Words are stored
* in a red black tree
********************************************/
void readIn::readHamlet(const string& filepath ){
	
	ifstream file;
	file.open(filepath);

	//delimits the text file word-by-word using whitespace
	while(file >> word){
	
		//converts all words to lowercase			
		transform(word.begin(),word.end(),word.begin(), ::tolower);		
		hamlet.insert(word);		
		word.clear();
	}
};

/********************************************
* Reads in all words in The Tempest. Accepts
* a string file path as a constant reference
* from the main function. Words are stored
* in a red-black tree. 
********************************************/
void readIn::readTempest(const string& filepath1 ){

	ifstream file1;
	file1.open(filepath1);

	//delimits the text file word-by-word using whitespace
	while(file1 >> word){
	

		transform(word.begin(),word.end(),word.begin(), ::tolower);		
		tempest.insert(word);		
		word.clear();
	}
};

/********************************************
* Reads in all words in Romeo and Juliet.
* Accepts a string file path as a constant
* reference from the main function. Words
* are stored in a red-black tree. 
********************************************/
void readIn::readRomeoJuliet(const string& filepath2 ){

	ifstream file2;
	file2.open(filepath2);

	//delimits the text file word-by-word using whitespace
	while(file2 >> word){
	

		transform(word.begin(),word.end(),word.begin(), ::tolower);		
		romeojuliet.insert(word);		
		word.clear();
	}
};

/********************************************
* Takes a given term and determines if a play
* contains the term by traversing the
* red-black tree and checking to see if the
* term exists in a node. Term is user entered
* and passed as a constant reference. If a
* play contains the term, the title of the
* play is added to a vector<string>.
********************************************/
vector<string> readIn::hasTerm(const string& term){

vector<string> plays;

	if(hamlet.contains(term))
				plays.push_back("Hamlet");

	if(tempest.contains(term))
				plays.push_back("TheTempest");

	if(romeojuliet.contains(term))
				plays.push_back("RomeoAndJuliet");

	//If none of the plays contain the term, "none" is entered.
	if(plays.size() == 0)
				plays.push_back("None");

				return plays;
}

/********************************************
* Takes a given term and determines if a play
* contains the term by traversing the
* red-black tree and checking to see if the
* term exists in a node. Term is user entered
* and passed as a constant reference. If a
* play contains the term, the title of the
* play is added to a vector<string>.
********************************************/
int readIn::countTerm(const string& term){

int numplays = 0;

	if(hamlet.contains(term))
				numplays++;

	if(tempest.contains(term))
				numplays++;

	if(romeojuliet.contains(term))
				numplays++;

				return numplays;
}
/********************************************
* Main function that drives the program 
********************************************/
int main(){

	readIn read;

	//Reads in all the plays from their specific file paths.
	read.readHamlet("/Users/nathan/Documents/CIS263/Homework/CIS263_Project_1/Hamlet(1).txt");
	read.readTempest("/Users/nathan/Documents/CIS263/Homework/CIS263_Project_1/TheTempest(1).txt");
	read.readRomeoJuliet("/Users/nathan/Documents/CIS263/Homework/CIS263_Project_1/RomeoAndJuliet(2).txt");
	string term;
	int count;

	//Allows user to repeatedly check for terms until -1 is entered
	do{
		cout << "\n\nEnter a term to determine which plays the term occurs in(-1 to quit): ";
		cin >> term;
		transform(term.begin(),term.end(),term.begin(), ::tolower);		
		vector<string> results = read.hasTerm(term);

		if(term != "-1"){
			cout << "\n" << "'" << term<< "'" << " occurs in ";

			//Uses STL copy algorithm to print the resuts element-by-element separated by whitespace.
			copy(results.begin(), results.end(),ostream_iterator<string>(cout, " "));
			cout << "\n\n";
		}	

	}while(term != "-1");

	do{
		cout << "\n\nEnter a term to count how many of the plays a term occurs in (-1 to quit): ";
		cin >> term;	
		transform(term.begin(),term.end(),term.begin(), ::tolower);		
		count  = read.countTerm(term);

		if(term != "-1"){
			cout << "\n" << "'" << term<< "'" << " occurs in " << count << " of the plays.";
			cout << "\n\n";
		}
	}while(term != "-1");	
};
