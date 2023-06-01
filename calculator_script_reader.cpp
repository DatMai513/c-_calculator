//Name: Dat Mai
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

// Function Prototypes
int factorial(int num);
string strtolower(string str);
string trim(string str);
void ExitProgram();
void ProcessCommand(string cmd);

// Class Definitions
class EZFileRead {
	// Fields
private:
	vector<string> v;

	// Constructor
public:
	EZFileRead(string);

	// Functions
	size_t GetNumLines();
	string GetLine(size_t);
};

class Tokenizer {
	// Fields
private:
	vector <string> tokens;

	// Constructor
public:
	Tokenizer(string, char);

	// Functions
	int GetNumTokens();
	bool HasMoreTokens();
	string NextToken();
};

// Main Function
int main()
{
	// Introduction
	cout << "Hello, welcome to Dat's command interpeter." << endl << endl;

	// variable to hold keyboard input
	string str;

	// infinite loop
	while (1)
	{
		// prompt the user
		cout << "Enter a command to proccess: ";
		// get input
		getline(cin, str);
		ProcessCommand(str);
	}
	return 0;
}

// Functions
void ProcessCommand(string raw)
{
	// class object where we set our delimiter to ':' because it will give us the first token
	// the first token is the operator/command (like add, sub, or mul)
	Tokenizer strToken(raw, ':');
	string cmd = strToken.NextToken();
	cmd = strtolower(cmd);
	cmd = trim(cmd);

	// create all variables needed
	int firstInteger;
	int secondInteger;
	int thirdInteger;
	int answer;

	string firstOperand;
	string secondOperand;
	string thirdOperand;

	// now check what the user entered
	if (cmd == "quit")
	{
		ExitProgram();
	}
	else if (cmd == "project")
	{
		cout << "This is the final project for CISP 400" << endl << endl;
	}
	else if (cmd == "points")
	{
		cout << "This assignment is worth 250 points" << endl << endl;
	}
	else if (cmd == "display")
	{
		// all that is left after tokenizing the command should be the message to display
		string displayStr = strToken.NextToken();
		displayStr = trim(displayStr);
		
		cout << displayStr << endl << endl;
	}
	else if (cmd == "sqrt")
	{
		// only one token after command so will only need to get first integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);

		cout << "The sqrt of " << firstInteger << " is: " << sqrt(firstInteger) << endl << endl;
	}
	else if (cmd == "log2")
	{
		// only one token after command so will only need to get first integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);

		cout << "The log2 of " << firstInteger << " is: " << log2(firstInteger) << endl << endl;
	}
	else if (cmd == "add")
	{
		// two tokens after command so need first and second integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);

		secondOperand = strToken2.NextToken();
		secondOperand = trim(secondOperand);
		secondInteger = stoi(secondOperand);

		answer = (firstInteger + secondInteger);
		cout << firstInteger << " + " << secondInteger << " = " << answer << endl << endl;
	}
	else if (cmd == "sub")
	{
		// two tokens after command so need first and second integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);

		secondOperand = strToken2.NextToken();
		secondOperand = trim(secondOperand);
		secondInteger = stoi(secondOperand);

		answer = (firstInteger - secondInteger);
		cout << firstInteger << " - " << secondInteger << " = " << answer << endl << endl;
	}
	else if (cmd == "mul")
	{
		// two tokens after command so need first and second integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);

		secondOperand = strToken2.NextToken();
		secondOperand = trim(secondOperand);
		secondInteger = stoi(secondOperand);

		answer = (firstInteger * secondInteger);
		cout << firstInteger << " * " << secondInteger << " = " << answer << endl << endl;
	}
	else if (cmd == "div")
	{
		// two tokens after command so need first and second integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);

		secondOperand = strToken2.NextToken();
		secondOperand = trim(secondOperand);
		secondInteger = stoi(secondOperand);

		// must check for division by zero
		if (secondInteger == 0)
		{
			cout << "Dividing by zero is undefined!" << endl << endl;
		}
		else
		{
			answer = (firstInteger / secondInteger);
			cout << firstInteger << " / " << secondInteger << " = " << answer << endl << endl;
		}
	}
	else if (cmd == "mod")
	{
		// two tokens after command so need first and second integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);

		secondOperand = strToken2.NextToken();
		secondOperand = trim(secondOperand);
		secondInteger = stoi(secondOperand);

		if (secondInteger == 0)
		{
			cout << "Dividing by zero is undefined!" << endl << endl;
		}
		else
		{
			answer = (firstInteger % secondInteger);
			cout << firstInteger << " % " << secondInteger << " = " << answer << endl << endl;
		}
	}
	else if (cmd == "shr")
	{
		// two tokens after command so need first and second integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);

		secondOperand = strToken2.NextToken();
		secondOperand = trim(secondOperand);
		secondInteger = stoi(secondOperand);

		cout << firstInteger << ">>" << secondInteger << " = ";
		thirdInteger = firstInteger >> secondInteger;
		cout << thirdInteger << endl << endl;
	}
	else if (cmd == "shl")
	{
		// two tokens after command so need first and second integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);

		secondOperand = strToken2.NextToken();
		secondOperand = trim(secondOperand);
		secondInteger = stoi(secondOperand);

		cout << firstInteger << "<<" << secondInteger << " = ";
		thirdInteger = firstInteger << secondInteger;
		cout << thirdInteger << endl << endl;
	}
	else if (cmd == "add3")
	{
		// three tokens after command so need first, second, and third integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);

		secondOperand = strToken2.NextToken();
		secondOperand = trim(secondOperand);
		secondInteger = stoi(secondOperand);

		thirdOperand = strToken2.NextToken();
		thirdOperand = trim(thirdOperand);
		thirdInteger = stoi(thirdOperand);

		answer = (firstInteger + secondInteger + thirdInteger);
		cout << firstInteger << " + " << secondInteger << " + " << thirdInteger << " = " << answer << endl << endl;
	}
	else if (cmd == "mul3")
	{
		//three tokens after command so need first, second, and third integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);
	
		secondOperand = strToken2.NextToken();
		secondOperand = trim(secondOperand);
		secondInteger = stoi(secondOperand);

		thirdOperand = strToken2.NextToken();
		thirdOperand = trim(thirdOperand);
		thirdInteger = stoi(thirdOperand);

		answer = (firstInteger * secondInteger * thirdInteger);
		cout << firstInteger << " * " << secondInteger << " * " << thirdInteger << " = " << answer << endl << endl;
	}
	else if (cmd == "fact")
	{
		// only one token after command so will only need to get first integer
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);
		firstInteger = stoi(firstOperand);

		cout << "Factorial " << firstInteger << "! is: ";
		firstInteger = factorial(firstInteger);
		cout << firstInteger << endl << endl;
	}
	else if (cmd == "load")
	{
		// only one token after command so will only need to get first string
		Tokenizer strToken2(strToken.NextToken(), ',');
		firstOperand = strToken2.NextToken();
		firstOperand = trim(firstOperand);

		// class object
		EZFileRead ezr(firstOperand);

		// variable that will hold how many lines are in a file
		size_t amountOfLines;
		// use the class function to get how many lines
		amountOfLines = ezr.GetNumLines();

		// variable that will hold a line that was read from the file
		string stringInFile;
		
		cout << "Proccessing Script..." << endl;

		// loop will step through each line in the file starting from 0
		for (size_t k = 0; k < amountOfLines; k++)
		{
			// each step will read what is in the file 
			stringInFile = ezr.GetLine(k);
			ProcessCommand(stringInFile);
		}
	}
	else
	{
		// at this point something invalid is entered so must display an error message
		cout << "Unknown Command. Try again." << endl << endl;
	}
}

int factorial(int num)
{
	int ans;
	if (num > 1)
	{
		ans = num * factorial(num - 1);
		return ans;
	}
	else
	{
		ans = 1;
		return ans;
	}
}

/* Returns a lower case string */
string strtolower(string str) {
	string ret = str;
	for (size_t i = 0; i < str.size(); i++) {
		ret.at(i) = tolower(str.at(i));
	}
	return ret;
}

/* Returns a string without the leading and trailing whitespace */
string trim(string str) {
	size_t first = str.find_first_not_of(' ');
	if (first == string::npos)
		return "";
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

// Will exit the program when "quit" is entered
void ExitProgram() {
	exit(EXIT_SUCCESS);
}

// Constructors

// File input
EZFileRead::EZFileRead(string filename) {
	ifstream f;
	f.open(filename);
	if (!f.is_open()) {
		cout << "File not successfully opened...operation aborted." << endl;
		return;
	}
	// Read in the file (if there is anything to read)
	string inp;
	while (getline(f, inp))
		v.push_back(inp);
	f.close();
}

size_t EZFileRead::GetNumLines() {
	return v.size();
}

string EZFileRead::GetLine(size_t index) {
	if (index >= v.size())			return "NO SUCH ELEMENT";
	return v.at(index);
}

// Tokenizer
Tokenizer::Tokenizer(string raw, char delimiter) {
	if (raw.size() == 0)			return;
	size_t start = 0;
	size_t end = 0;
	for (size_t i = 0; i < raw.size(); i++) {
		char c = raw.at(i);
		// Acquire tokens
		if (c == delimiter) {
			end = i;
			int len = end - start;
			if (len > 0) {
				string token = raw.substr(start, len);
				tokens.push_back(token);
			}
			start = i + 1;
		}
	}
	// Acquire the final token
	end = raw.size();
	int len = end - start;
	if (len > 0) {
		string token = raw.substr(start, len);
		tokens.push_back(token);
	}
}

/* Return how many tokens are in token buffer */
int Tokenizer::GetNumTokens() {
	return tokens.size();
}

/* Returns whether there are any more tokens in buffer */
bool Tokenizer::HasMoreTokens() {
	return tokens.size() != 0;
}

/* Gets the next token available in the token buffer */
string Tokenizer::NextToken() {
	string ret = "NULL";
	if (HasMoreTokens()) {
		ret = tokens.front();
		tokens.erase(tokens.begin());
	}
	return ret;
}

