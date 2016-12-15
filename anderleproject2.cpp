#include <iostream>
#include <cstdlib>
#include "dsexceptions.h"
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <stack>
#include <queue>
#include <algorithm>
#include "RedBlackTree.h"
#include <list>
using namespace std;


/*********************************************
 * Class responsible for cleanly obtaining
 * data from text files. Contains the
 * trimLine() and skipBlank() methods which
 * will respectively trim leading and trailing
 * whitespace from each line of text and skip
 * over blank lines that do not contain text.
 *********************************************/
class cleanData{
		
	public:

		string trimLine(const string& str, const string& whitespace);
		bool skipBlank(const string& str);
};

/*********************************************
 * Class responsible for the 5 data structures
 * that will be tested for relative time
 * efficiency.
 *********************************************/
class Structures{

	public:

		void callStructure();
		void callSearch();

	private:
			
			cleanData data;
			string NEG_INF = " ";
			
			//Structures storing the x100 file for search queries
			vector<string> vSearch;
			stack<string> sSearch;
			RedBlackTree<string> rbtSearch{NEG_INF};
			queue<string> qSearch;
			list<string> lSearch;

			//Filepaths and search queries
			string str;	
			string RandJ = "/Users/nathan/Documents/CIS263/263Project2/RomeoAndJuliet.txt";
			string RandJ10 = "/Users/nathan/Documents/CIS263/263Project2/RomeoAndJulietx10";
			string RandJ100 = "/Users/nathan/Documents/CIS263/263Project2/RomeoAndJulietx100";
			string searchOne = "THE TRAGEDY OF ROMEO AND JULIET";
			string searchTwo = "Rom. Tush, thou art deceiv'd.";
			string searchThree = "THE END";
		
			//Primary functions that carry out most of the program
			int readInVect(const string& str);
			int searchVect(const string& str, const vector<string>& vect);
			void setSearchVector(const vector<string>& vect);

			int readInStack(const string& str);
			int searchStack(const string& str,  const stack<string>& stck);
			void setSearchStack(const stack<string>& stck);

			int readInRedBlackTree(const string& str);
			int searchRedBlackTree(const string& str, const RedBlackTree<string>& rbt);
			void setSearchRedBlackTree( const RedBlackTree<string>& rbt);

			int readInQueue(const string& str);
			int searchQueue(const string& str, const queue<string>& que);
			void setSearchQueue(const queue<string>& que);

			int readInList(const string& str);
			int searchList(const string& str, const list<string>& lst);
			void setSearchList(const list<string>& lst);
};

/*********************************************
 * Effectively trims leading and trailing
 * whitespce from every line by making a 
 * substring
 *********************************************/
string cleanData::trimLine(const string& str, const string& whitespace = " \t"){
	
	int  strBegin = str.find_first_not_of(whitespace);
	int  strEnd = str.find_last_not_of(whitespace);
	int  strRange = strEnd - strBegin + 1;
	
	return str.substr(strBegin, strRange);
}

/*********************************************
 * Skips over a line if it is blank. Determines
 * if all of the words in a line start with a 
 * space character. If they do, the line is blank
 *********************************************/
bool cleanData::skipBlank(const string& str){

	 if (str.find_first_not_of(" \t\v\r\n") == string::npos ){   
			return true;
		 }

	 else{
			 return false;           
	 }
}

/*********************************************
 * Method that the main() uses to call all of
 * the structures in their gathering data phase.
 *********************************************/
void Structures::callStructure(){

	cout << "Vector time:      " << readInVect(RandJ) << " milliseconds \n";
	cout << "Vector time x10:  " << readInVect(RandJ10) << " milliseconds \n";
	cout << "Vector time x100: " << readInVect(RandJ100) << " milliseconds \n\n";
		
	cout << "Stack time:      " << readInStack(RandJ) << " milliseconds \n";
	cout << "Stack time x10:  " << readInStack(RandJ10) << " milliseconds \n";
	cout << "Stack time x100: " << readInStack(RandJ100) << " milliseconds \n\n";

	cout << "RedBlackTree time:      " << readInRedBlackTree(RandJ) << " milliseconds \n";
	cout << "RedBlackTree time x10:  " << readInRedBlackTree(RandJ10) << " milliseconds \n";
	cout << "RedBlackTree time x100: " << readInRedBlackTree(RandJ100) << " milliseconds \n\n";

	
	cout << "Queue time:      " << readInQueue(RandJ) << " milliseconds \n";
	cout << "Queue time x10:  " << readInQueue(RandJ10) << " milliseconds \n";
	cout << "Queue time x100: " << readInQueue(RandJ100) << " milliseconds \n\n";
	

	cout << "List time:      " << readInList(RandJ) << " milliseconds \n";
	cout << "List time x10:  " << readInList(RandJ10) << " milliseconds \n";
	cout << "List time x100: " << readInList(RandJ100) << " milliseconds \n\n";
}

/*********************************************
 * Method that the main() uses to conduct all
 * of the search queries in the structures
 *********************************************/
void Structures::callSearch(){

	cout << "Vector time search for " << searchOne << ": " << searchVect(searchOne, vSearch) << " milliseconds\n";
	cout << "Vector time search for " << searchTwo << ": " << searchVect(searchTwo, vSearch) << " milliseconds\n";
	cout << "Vector time search for " << searchThree << ": " << searchVect(searchThree, vSearch) << " milliseconds\n\n";

	cout << "Stack time search for " << searchOne << ": " << searchStack(searchOne, sSearch) << " milliseconds\n";
	cout << "Stack time search for " << searchTwo << ": " << searchStack(searchTwo, sSearch) << " milliseconds\n";
	cout << "Stack time search for " << searchThree << ": " << searchStack(searchThree, sSearch) << " milliseconds\n\n";
	
	cout << "RedBlackTree time search for " << searchOne << ": " << searchRedBlackTree(searchOne, rbtSearch) << " milliseconds\n";
	cout << "RedBlackTree time search for " << searchTwo << ": " << searchRedBlackTree(searchTwo, rbtSearch) << " milliseconds\n";
	cout << "RedBlackTree time search for "<< searchThree <<": " << searchRedBlackTree(searchThree, rbtSearch) << " milliseconds\n\n";
	
	cout << "Queue time search for " << searchOne << ": " << searchQueue(searchOne, qSearch) << " milliseconds\n";
	cout << "Queue time search for " << searchTwo << ": " << searchQueue(searchTwo, qSearch) << " milliseconds\n";
	cout << "Queue time search for " << searchThree << ": " << searchQueue(searchThree, qSearch) << " milliseconds\n\n";
	
	cout << "List time search for " << searchOne << ": " << searchList(searchOne, lSearch) << " milliseconds\n";
	cout << "List time search for " << searchTwo << ": " << searchList(searchTwo, lSearch) << " milliseconds\n";
	cout << "List time search for " << searchThree << ": " << searchList(searchThree, lSearch) << " milliseconds\n\n";
}
/*********************************************
 * Sets the x100 vector equal to a vector that
 * is accessible by the search query function.
 *********************************************/
void Structures::setSearchVector(const vector<string>& vect){

	vSearch = vect; 
}

/*********************************************
 * Sets the x100 stack equal to a stack that
 * is accessible by the search query function.
 *********************************************/
void Structures::setSearchStack(const stack<string>& stck){

	sSearch = stck; 
}

/*********************************************
 * Sets the x100 RedBlackTree equal to a 
 * RedBlackTree that is accessible by the search
 * query function.
 *********************************************/
void Structures:: setSearchRedBlackTree( const RedBlackTree<string>& rbt){

	rbtSearch = rbt;
}
/*********************************************
 * Sets the x100 queue equal to a queue that is
 * accessible by the search query function.
 *********************************************/
void Structures:: setSearchQueue( const queue<string>& que){

	qSearch = que;
}

/*********************************************
 * Sets the x100 list equal to a list that is 
 * accessible by the search query function.
 *********************************************/
void Structures:: setSearchList( const list<string>& lst){

	lSearch = lst;
}

/*********************************************
 * Reads the various Romeo and Juliet files
 * into vectors and times how long it takes
 * to load each file using the vector structure
 *********************************************/
int Structures::readInVect(const string& filepath){

	vector<string> vect;
	ifstream file; 
	file.open(filepath);
	
	chrono::time_point<std::chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	while(getline(file,str)){

		if (data.skipBlank(str)) {
			
			continue;
		}
		else{
			vect.push_back(data.trimLine(str));
				
		}
		
	}
	end = std::chrono::system_clock::now();
	int elapsed_seconds = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	time_t end_time = chrono::system_clock::to_time_t(end);

	//Sends the x100 vector to the vector setter to be used later in search queueries.
	if (filepath == (RandJ100)){

			setSearchVector(vect);
	}
		
	return elapsed_seconds;
}

/*********************************************
 * Searches the x100 vector for given search
 * terms and times how long it takes to find
 * them.
 *********************************************/
int Structures::searchVect(const string& str, const vector<string>& vect){


	chrono::time_point<std::chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	find(vect.begin(), vect.end(), str);

	end = std::chrono::system_clock::now();
	int elapsed_seconds = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	time_t end_time = chrono::system_clock::to_time_t(end);
	
	return elapsed_seconds;

}

/*********************************************
 * Reads the various Romeo and Juliet files
 * into a stack and times how long it takes
 * to do so.
 *********************************************/
int Structures::readInStack(const string& filepath){

	stack<string> stck;
	ifstream file; 
	file.open(filepath);
	
	chrono::time_point<std::chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	while(getline(file,str)){

		if (data.skipBlank(str)) {
			
			continue;
		}
		else{
			stck.push(data.trimLine(str));
			
		}
			
	}
	end = std::chrono::system_clock::now();
	int elapsed_seconds = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	time_t end_time = chrono::system_clock::to_time_t(end);
	
	if(filepath == RandJ100){
			setSearchStack(stck);
	}

	return elapsed_seconds;
}
/*********************************************
 * Searches the x100 stack for given search terms
 * and times how long it takes for this given
 * structure to find them.
 *********************************************/
int Structures::searchStack(const string& str,  const stack<string>& stck){


	stack<string> temp = stck;
	
	chrono::time_point<std::chrono::system_clock> start, end;
	start = chrono::system_clock::now();


	while(!temp.empty()){

		if(temp.top() == str)
			break;
		else
		 temp.pop();
	}
	end = std::chrono::system_clock::now();
	int elapsed_seconds = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	time_t end_time = chrono::system_clock::to_time_t(end);
	
	return elapsed_seconds;

}

/*********************************************
 * Reads the various Romeo and Juliet files
 * into RedBlackTrees and times how long it 
 * takes to build each one.
 *********************************************/
int Structures::readInRedBlackTree(const string& filepath){

	RedBlackTree<string> rbt{NEG_INF};
	ifstream file; 
	file.open(filepath);
	
	chrono::time_point<std::chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	while(getline(file,str)){

		if (data.skipBlank(str)) {
			
			continue;
		}
		else{
			rbt.insert(data.trimLine(str));
		}
	}
	end = std::chrono::system_clock::now();
	int elapsed_seconds = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	time_t end_time = chrono::system_clock::to_time_t(end);
	
	if(filepath == RandJ100){
			setSearchRedBlackTree(rbt);
	}
	
	return elapsed_seconds;
}
/*********************************************
 * Searches the x100 RedBlackTree and times
 * how long it takes to find given search
 * terms.
 *********************************************/
int Structures::searchRedBlackTree(const string& str,const RedBlackTree<string>& rbt){


	chrono::time_point<std::chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	//contains() appears to be inexplicably broken
	if( rbt.contains(str)){
	end = std::chrono::system_clock::now();
	}

	int	elapsed_seconds = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	time_t end_time = chrono::system_clock::to_time_t(end);
	return elapsed_seconds;
}

/*********************************************
 * Takes the various Romeo and Juliet files
 * and reads them into queues and times how
 * long this structure takes to do so.
 *
 *
 *********************************************/
int Structures::readInQueue(const string& filepath){

	queue<string> que;
	ifstream file; 
	file.open(filepath);
	
	chrono::time_point<std::chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	while(getline(file,str)){

		if (data.skipBlank(str)) {
			
			continue;
		}
		else{
			que.push(data.trimLine(str));
			
		}
			
	}
	end = std::chrono::system_clock::now();
	int elapsed_seconds = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	time_t end_time = chrono::system_clock::to_time_t(end);
	
	if(filepath == RandJ100){
			setSearchQueue(que);
	}

	return elapsed_seconds;
}

/*********************************************
 * Searches the x100 queue for given search 
 * terms and times how long it takes to 
 * navigate through the structure to find them
 *********************************************/
int Structures::searchQueue(const string& str,  const queue<string>& que){


	queue<string> temp = que;
	
	chrono::time_point<std::chrono::system_clock> start, end;
	start = chrono::system_clock::now();


	while(!temp.empty()){

		if(temp.front() == str)
			break;
		else
		 temp.pop();
	}
	end = std::chrono::system_clock::now();
	int elapsed_seconds = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	time_t end_time = chrono::system_clock::to_time_t(end);
	
	return elapsed_seconds;

}

/*********************************************
 * Takes the various Romeo and Juliet files and
 * reads them into lists and times how long it
 * takes for this structure to build.
 *********************************************/
int Structures::readInList(const string& filepath){

	list<string> lst;
	ifstream file; 
	file.open(filepath);
	
	chrono::time_point<std::chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	while(getline(file,str)){

		if (data.skipBlank(str)) {
			
			continue;
		}
		else{
			lst.push_back(data.trimLine(str));
				
		}
		
	}
	end = std::chrono::system_clock::now();
	int elapsed_seconds = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	time_t end_time = chrono::system_clock::to_time_t(end);

	if (filepath == (RandJ100)){

			setSearchList(lst);
	}
		
	return elapsed_seconds;
}

/*********************************************
 * Searches the x100 list for given search 
 * terms and times how long it takes to 
 * navigate through the list to the desired terms.
 *********************************************/
int Structures::searchList(const string& str,  const list<string>& lst){

	
	chrono::time_point<std::chrono::system_clock> start, end;
	start = chrono::system_clock::now();

	find(lst.begin(), lst.end(), str);

	end = std::chrono::system_clock::now();
	int elapsed_seconds = chrono::duration_cast<chrono::milliseconds> (end-start).count();
	time_t end_time = chrono::system_clock::to_time_t(end);
	
	return elapsed_seconds;

}
/*********************************************
 * Clears the terminal screen by printing a
 * bunch of new lines.
 *********************************************/
void clearScreen(){

	for(int i = 0; i <= 100; i++){

		cout << "\n";
	}
}

/*********************************************
 * Main function that drives the program.
 *********************************************/
int main(){

	clearScreen();	
	Structures strct;
	strct.callStructure();
	strct.callSearch();

}
