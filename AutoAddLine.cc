#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

string ConvertToLower(string input) {
	for (int i=0; i<input.length();i++) {
		input[i] = tolower(input[i]);
	}
	return input;
}


int main(int argc, char* argv[]) {
	vector<string> name;
	string number, line, output, filename;
	ofstream file, myCCfile;
	file.open("README.md", ios_base::app);
	try {
	  if (argc==3) {
		line = argv[1];
		number = argv[2];
		int counter = 0;
		for (int i=0; i<line.length();i++) {
			if (line[i]=='-') {
				name.push_back(line.substr(counter, i-counter));
				counter = i+1;
			}
			if (i==line.length()-1) {
				name.push_back(line.substr(counter));
			}
		}
		output = " " + number + " | [";
		for (int i=0; i<name.size(); i++) {
			if (i==name.size()-1) output += name[i];
			else output += name[i] + " ";
		}
		output += "](https://leetcode.com/problems/";
		for (int i=0; i<name.size(); i++) {
			if (i==name.size()-1) output += ConvertToLower(name[i]);
			else output += ConvertToLower(name[i]) + "-";
		}
		output += "/) | [";

		for (int i=0; i<name.size(); i++) filename += name[i];
		filename += ".cc";
		output += filename + "] (./solutions/" + filename + ") |";
		file << output << endl;
		cout << output << endl;
		myCCfile.open("./solutions/" + filename);
		myCCfile <<  "// Yifei Wang" << endl;
		myCCfile << "// LeetCode Question " + number << endl;
		myCCfile.close();
	  }
	}
	catch(const string& msg) {
    	cerr << msg << endl;
  	}
  	file.close();
}




