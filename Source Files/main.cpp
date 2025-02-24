#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* printFileBruteForce
* Parameters: string fileName
* Type: void
* 1. Concatenate the file name into the input.
* 2. Retrieve the source file.
* 3. If the file is not open, return an error message.
* 4. Individually, retrieve each line from the file.
*/
void printFileBruteForce(string fileName){
		cout << fileName + ".cpp";
		ifstream f(fileName + ".cpp");
		if (!f.is_open()) {
			cerr << "Error: Could not open the file." << endl;
		}

		string line;
		while (getline(f, line)) {
			cout << line << endl;
		}

	f.close();
}

void printFileMostEfficient(string fileName){
		ifstream f(fileName);
		if (!f.is_open()) {
			cerr << "Error: Could not open the file." << endl;
		}

		string line;
		while (getline(f, line)) {
			cout << line << endl;
		}

	f.close();
}

int checkProblemName(string problemName){
	string prob;
 	if (problemName == "WordSearchII" || problemName == "maximalRectangle"){
 		cout << "Is the problem name " << problemName << "? Answer true or false.";
 		cin >> prob;
 		if (prob == "true" || prob == "True"){
 			return 0;
 		}
 		else {
 	 		cout << "Please re-enter a different problem name.";
 	 		return 1;
 		}
 	}
 	else {
 		cout << "Sorry, we don't have that problem in storage. Better luck next time!" << endl;
 		return 1;
 	}
}


int checkAnswerCharacteristics(int answerCharacteristics, string problemName){
	if (answerCharacteristics == 1){
		printFileBruteForce(problemName);
		return 0;
	}
	else if (answerCharacteristics == 2){
		printFileMostEfficient(problemName);
		return 0;
	}
	else {
		return 1;
	}
}

int main(){
	string problemName;
	int answerCharacteristics;

	cout << "Welcome to the LeetCode Chatbot. Please enter the problem name: ";
	cin >> problemName;

	/*Check to see if the problem is in the chatbot*/
    if (checkProblemName(problemName) == 1){
    	cout << " Let's start over." << endl;
    	return 0;
    }

    cout << "Would you like a brute force answer or the most efficient answer? Choose 1 or 2.";
    cin >> answerCharacteristics;

    checkAnswerCharacteristics(answerCharacteristics, problemName);
	return 0;
}
