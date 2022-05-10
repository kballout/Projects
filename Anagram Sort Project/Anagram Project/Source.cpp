
// Kassim Ballout
// Programming Project 1

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//Desc: Prints to the output the class size and words.
//Pre: Anagrams are grouped and sent as a parameter. 
//Post: The class size and words are printed to the output.
void printSizeAndWords(vector<string> words) {
	sort(words.begin(), words.end());
	cout << "Class of size " << words.size() << ": ";
	for (int i = 0; i < words.size(); i++) {
		cout << words.at(i) << " ";
	}
	cout << endl;
}
//Remove words which have already been printed to the output from the main word list.
//Pre: The print function was already called. This takes the word list and the words to remove as parameters.
//Post: The already printed words are removed from the main word list. 
void removeWords(vector<string>& wordList, vector<string> wordsToRemove) {
	for (int i = 0; i < wordsToRemove.size(); i++) {
		for (int j = 0; j < wordList.size(); j++) {
			if (wordsToRemove.at(i) == wordList.at(j)) {
				wordList.erase(wordList.begin() + j);
				break;
			}
			else {
				continue;
			}
		}
	}
}
//Desc: The next set of anagrams are grouped, printed out, and removed from the main list. returns true to gather the next set of words.
//Pre: This takes the word list, the next word to check anagrams for, and the current highest class size as parameters.
//Post: If the correct current class of words (correct size) is found, it returns true which allows to print to the output.
bool groupWords(vector<string>& wordList, string wordToCheck, int highestNumber) {
	vector<string> groupedWords;
	groupedWords.push_back(wordToCheck);
	for (int i = 0; i < wordList.size(); i++) {
		if (groupedWords.size() == highestNumber) {
			break;
		}
		if (wordToCheck.length() == wordList.at(i).length() && wordToCheck != wordList.at(i)) {
			for (int j = 0; j < wordToCheck.length(); j++) {
				if (wordList.at(i).find(wordToCheck.at(j)) == string::npos) {
					break;
				}
				if (j == wordToCheck.length() - 1) {
					groupedWords.push_back(wordList.at(i));
					break;
				}
				continue;
			}
		}
	}
	if (groupedWords.size() == highestNumber) {
		printSizeAndWords(groupedWords);
		removeWords(wordList, groupedWords);
		return true;
	}
	return false;
}
//Desc: Checks for the max number of anagrams currently available in the main list.
//Pre: The word list and the word to check anagrams for are sent as parameters.
//Post: The highest number of anagrams found for a particular group is returned.
int checkHighestNumOfClasses(vector<string> wordList, string wordToCheck) {
	int numOfAnagrams = 1;
	for (int i = 0; i < wordList.size(); i++) {
		if (wordToCheck.length() == wordList.at(i).length() && wordToCheck != wordList.at(i)) {
			for (int j = 0; j < wordToCheck.length(); j++) {
				if (wordList.at(i).find(wordToCheck.at(j)) == string::npos) {
					break;
				}
				if (j == wordToCheck.length() - 1) {
					numOfAnagrams++;
					break;
				}
				continue;
			}
		}
	}
	return numOfAnagrams;
}
//Desc: Sorts the main word list in order of length
//Pre: The word in the main list are sent as parameters and compared by size
//Post: returns true if the first word is larger than the second. otherwise returns false
bool compare(string first, string second) {
	if (first.size() > second.size()) {
		return true;
	}
	else {
		return false;
	}
}

void main() {
	ifstream inputFileStream;
	vector<string> wordList;
	int numberOfWords = 0;
	int numberOfClasses = 0;
	int counter = 0;
	int currentHighestClass = 0;

	inputFileStream.open("Charades.txt");
	if (!inputFileStream.is_open()) {
		cout << "Cannot open file!" << endl;
		exit(0);
	}
	else {
		inputFileStream >> numberOfWords;
		inputFileStream >> numberOfClasses;
		while (!inputFileStream.eof()) {
			string word;
			getline(inputFileStream, word);
			if (word == "") {
				getline(inputFileStream, word);
			}
			wordList.push_back(word);
		}
		inputFileStream.close();
	}
	sort(wordList.begin(), wordList.end(), compare);
	
	int temp = 1;
	bool maxClassHasBeenSet = false;
	for (int i = 0; i < wordList.size(); i++) {
		if (counter == numberOfClasses) {
			break;
		}
		if (maxClassHasBeenSet == false) {
			for (int j = 0; j < wordList.size(); j++) {
				temp = checkHighestNumOfClasses(wordList, wordList.at(j));
				if (temp > currentHighestClass) {
					currentHighestClass = temp;
				}
				maxClassHasBeenSet = true;
			}
		}
		if (groupWords(wordList, wordList.at(i), currentHighestClass)) {
			counter++;
			i = 0;
			currentHighestClass = 1;
			maxClassHasBeenSet = false;
		}
	}

	system("pause");
}