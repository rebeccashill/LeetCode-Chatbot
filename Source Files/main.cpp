#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int printWordSearchIIBruteForce(){
		std::ifstream f("WordSearchII.cpp");
	    if (!f.is_open()) {
	        std::cerr << "Error: Could not open the file." << std::endl;
	        return 1;
	    }

	    std::string line;
	    while (std::getline(f, line)) {
	        std::cout << line << std::endl;
	    }

	    f.close();
	    return 0;
}

int printWordSearchIIBest(){
		std::ifstream f("WordSearchII.cpp");
	    if (!f.is_open()) {
	        std::cerr << "Error: Could not open the file." << std::endl;
	        return 1;
	    }

	    std::string line;
	    while (std::getline(f, line)) {
	        std::cout << line << std::endl;
	    }

	    f.close();
	    return 0;
}

int printmaximalRectangleBruteForce(){
		std::ifstream f("maximalRectangle.cpp");
	    if (!f.is_open()) {
	        std::cerr << "Error: Could not open the file." << std::endl;
	        return 1;
	    }

	    std::string line;
	    while (std::getline(f, line)) {
	        std::cout << line << std::endl;
	    }

	    f.close();
	    return 0;
}

int printmaximalRectangleBest(){
		std::ifstream f("maximalRectangle.cpp");
	    if (!f.is_open()) {
	        std::cerr << "Error: Could not open the file." << std::endl;
	        return 1;
	    }

	    std::string line;
	    while (std::getline(f, line)) {
	        std::cout << line << std::endl;
	    }

	    f.close();
	    return 0;
}

int checkProblemName(string problemName){
 	if (problemName == "WordSearchII" or problemName == "maximalRectangle"){
 		return 0;
 	}
 	else {
 		cout << "Sorry, we don't have that problem in storage. Better luck next time!" << endl;
 		return 1;
 	}
}

int checkProblemNameBruteForce(string problemName){
 	if (problemName == "WordSearchII"){
 		printWordSearchIIBruteForce();
 		return 0;
 	}
 	else (problemName == "maximalRectangle"){
 		printmaximalRectangleBruteForce();
 		return 0;
 	}
}

int checkProblemNameBest(string problemName){
 	if (problemName == "WordSearchII"){
 		printWordSearchIIBest();
 		return 0;
 	}
 	else {
 		printmaximalRectangleBest();
 		return 0;
 	}
}


void checkAnswerCharacteristics(string answerCharacteristics, string problemName){
	if (answerCharacteristics == "brute force"){
		checkProblemNameBruteForce(problemName);
	}
	else if (answerCharacteristics == "fastest" or answerCharacteristics == "fastest + with the least amount of memory"){
		checkProblemNameBest(problemName);
	}
}

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

    checkAnswerCharacteristics(answerCharacteristics, problemName);
	return 0;
}


