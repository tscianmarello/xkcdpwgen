#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#define LEN_LIST 58111

using namespace std;
void printHelp();
void printWords(int, int, int, int);
int randInd();

/*The main initializes the password to 4 words, but this can be modified to size password, just simply change the totalWords number.
This program outputs a randomly generated password from a wordlist provided. It then allows to make the password much more reliable 
by inserting the number of capital letters in the word, numbers, and symbols. The program can be run from the command line. */
int main (int argc, char **argv)
{
	//Initialized to 4, but can be changed.
	int totalWords = 4;
	int capWords = 0;
	int numbers = 0;
	int symbols = 0;
	if(argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			//Prints the help options. 
			if(argv[i] == std::string("-h"))
			{
				printHelp();
			}
			//This sets the number of words used, if not it defaults to 4.
			else if ((argv[i] == std::string("-w") || argv[i] == std::string("--words")))
			{
				i++;
				totalWords = stoi(argv[i]);
			}
			//This sets the number of capitalized letters, if not it defaults to 0.
			else if ((argv[i] == std::string("-c") || argv[i] == std::string("--caps")))
			{
				i++;
				totalWords = stoi(argv[i]);
			}
			//This sets the number of numbers inputted in the word, if not it defaults to 0.
			else if ((argv[i] == std::string("-n") || argv[i] == std::string("--numbers")))
			{
				i++;
				totalWords = stoi(argv[i]);
			}
			//This sets the number of symbols inputted. If not it defaults to 0.
			else if ((argv[i] == std::string("-s") || argv[i] == std::string("--symbols")))
			{
				i++;
				totalWords = stoi(argv[i]);
			}

		}
	}
	printWords(totalWords, capWords, numbers, symbols);
}
//Function that provides the information on each of the options.
void printHelp()
{
	cout << "usage: xkcdpwgen [-h] [-w WORDS] [-c CAPS] [-n NUMBERS] [-s SYMBOLS]\n\n";
	cout << "Generate a secure, memorable password using the XKCD method\n\n";
	cout << "Optional arguments:\n";
	cout << "-h, --help		show this help message and exit\n";
	cout << "-w WORDS, --words WORDS\n";
	cout << "include WORDS words in the password (default = 4)\n";
	cout << "-c CAPS< --caps CAPS	capitalize the first letter of CAPS random words\n";
	cout << "			(default = 0)\m";
	cout << "-n NUMBERS< --numbers NUMBERS\n";
	cout << "insert NUMBERS random numbers in the password\n";
	cout << "(default = 0)\n";
	cout << "-s SYMBOLS, --symbols SYMBOLS\n";
	cout << "insert SYMBOLS random symbols in the password\n";
	cout << "(default = 0)\n";
}
//Function that prints the words with the conditions passed.
void printWords(int totWords, intcWords, int numbers, int symbs)
{
	srand(time(NULL));
	string pwarr[LEN_LIST];
	string pwarr1[1000];
	//These are the symbols selected, this list can be expanded. Also, this would require changing the symbolsArr[value]
	string symbolsArr[12] = {"~", "!", "@", "#", "$", "%", "^", "&", "*", ".", ":", ";"};
	//These are the numbers inputted.
	string symbolNum[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	
	//Place the address of the textfile here.
	ifstream file("corncob_lowercase.txt");
	//Checks condition if words are less than 0. Cannot produce a password with 0 or less words. 
	if(totWords <= 0)
	{
		cout << "Error: the number of total words selected is less than or equal to 0.\n";
		return;
	}
	for(int i = 0; i < LEN_LIST; i++_
	{
		file >> pwarr[i];
	}
	file.close();
	int randomSel = 0;
	for(int j = 0; j < totWords; j++)
	{
		pwarr1[j] = pwarr[randInd()];
	}
	//Checks condition if the number of capital letters selected are less than 0. 
	if(cWords < 0)
	{
		cout << "Error: total capital letters selected is less than 0.\n";
		return;
	}
	//If the number of capital letters exceed the words, then they are set to the number of words selected. Cannot have more 
	//capital letters than words.
	else if(cWords > totWords)
	{
		cWords = totWords;
	}
	//Randomly capitalizes the letters in the words. 
	for(; 0 < cWords; cWords--)
	{
		do
		{
			randomSel = rand()%totWords;
		}while(isupper((int)pwarr1[randomSel][0]));
		pwarr1[randomSel][0] = toupper(pwarr1[randomSel][0]);
	}
	//String created to store password.
	string password = "";
	//Adds the changes to the password string.
	for(int j = 0; j < totWords; j++)
	{
		password += pwarr1[j];
	}
	//Checks condition if number inputted is negative. Cannot place a negative number of numbers in password.
	if(nums < 0)
	{
		cout << "Error: negative number inputted.\n";
		return;
	}
	string s;
	//Randomly inserts the number of numbers selected in the password. 
	for(; 0 < nums; nums--)
	{
		s = symbolNum[rand() % 10];
		password.insert((rand()%(password.length())), s);
	}
	//Checks condition if the number of symbols is negative. Cannot input negative number of symbols in password.
	if(symbs < 0)
	{
		cout << "Error: negative number of symbols detected.\n";
		return;
	}
	//Randomly inserts number of symbols into the password at random locations. 
	for(; 0 < symbs; symbs--)
	{
		password.insert(rand() % password.length(), symbolArr[rand() % 12])'
	}
	
	cout << password << "n";
}
//Function for random value. 
int randInd()
{
	return (rand()%2) * (LEN_LIST/2) + rand() % (LEN_LIST/2);
}

	

	






































