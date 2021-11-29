/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Gabrielle Jackson
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

//Name_Value function
class Name_Value{
public:
	// data members
	std::string name;
	int score;

	// constructors
	Name_Value();
	Name_Value(std::string& n, int s) : name(n), score(s){}

	// used in Sort()
	bool operator< (const Name_Value& rhs) const {
		return name < rhs.name; 
	}
}//end of class

//declaring functions
void Populate_Vector(std::vector<Name_Value>&);
bool All_Unique(const std::vector<Name_Value>&);
void Print_Vector(const std::vector<Name_Value>&);

int main(){
	// data structure holding names and scores
	std::vector<Name_Value> pairs;

	// read input and store in vector
	Populate_Vector(pairs);
	 
	// check if all names unique and print
	if (All_Unique(pairs)){
		 Print_Vector(pairs);
	}
	else {
		std::cout <<"Name occuring more than once!\n";
	}
	getchar();
}//end of main

//Populate_Vector fucntion
void Populate_Vector(std::vector<Name_Value>& v){
	std::string prompt = "Please type a name, followed by score:\n>>"; 
	std::string sentinel = "No more";
	std::string line;

	// input loop
	std::cout << prompt;
	while (getline(std::cin, line) && line != sentinel){
		std::stringstream ss(line);

		std::string name;
		int score = 0;

		// check input format
		if (ss >> name >> score){
			v.emplace_back(Name_Value(name, score));
		}
		else {
			std::cout <<"Wrong input format!\n";
		}
		std::cout << prompt;
	}
}//end of Populate_Vector

//All_Unique function
bool All_Unique(const std::vector<Name_Value>& v){
	std::vector<Name_Value> temp(v);
	sort(temp.begin(), temp.end());

	for (size_t i = 0; i < temp.size() - 1; ++i){
		if (temp[i].name == temp[i+1].name)
		{
			return false;
		}
	}
	return true;
}//end of All_Unqiue

//Print_Vector function
void Print_Vector(const std::vector<Name_Value>& v){
	for (unsigned int i = 0; i < v.size(); ++i){
		std::cout << v[i].name <<" "<< v[i].score <<'\n';
	}
}//end of Print_Vector