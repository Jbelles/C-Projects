#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	ifstream cipher("Cipher.txt"); //open input stream

	vector<char> values; //create 
	string word; //empty string to compare txt length to

	while (cipher >> word) { //grab a word from the cipher, if succesful, loop
		values.push_back(word[0]);
	}
	cipher.close();

	int key; 

	while (cin >> key) {//grab the first key from the input, if succesful, loop
		cout << values[key - 1];
		cin.ignore(2);
	}
}