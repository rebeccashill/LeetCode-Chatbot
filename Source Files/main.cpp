#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printFile(string fileName){
		std::ifstream f(fileName);
		if (!f.is_open()) {
			std::cerr << "Error: Could not open the file." << std::endl;
		}

		std::string line;
		while (std::getline(f, line)) {
			std::cout << line << std::endl;
		}

	f.close();
}

int checkProblemName(string problemName){
	bool prob;
 	if (problemName == "WordSearchII" or problemName == "maximalRectangle"){
 		cout << "Is the problem name " << problemName << "? Answer true or false.";
 		cin >> prob;
 		if (prob == true){
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


/*void checkAnswerCharacteristics(string answerCharacteristics, string problemName){
	if (answerCharacteristics == "brute force"){
		checkProblemNameBruteForce(problemName);
	}
	else if (answerCharacteristics == "fastest" or answerCharacteristics == "fastest + with the least amount of memory"){
		checkProblemNameBest(problemName);
	}
}*/

int main(){
	string problemName;
	string isProblemName;
	string answerCharacteristics;

	cout << "Welcome to the LeetCode Chatbot. Please enter the problem name: ";
	cin >> problemName;

	/*Check to see if the problem is in the chatbot*/
    	checkProblemName(problemName);

    	cout << "Would you like a brute force answer or the fastest + with the least amount of memory?";
   	cin >> answerCharacteristics;

    	//checkAnswerCharacteristics(answerCharacteristics, problemName);
	return 0;
}
