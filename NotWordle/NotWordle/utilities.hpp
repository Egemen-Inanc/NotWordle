#include <iostream>
#include<windows.h>
#include <vector>
#include <fstream>
#include<string>
#include <map>
#include <fstream>
std::vector <std::string> wordList = { "which", "there", "their", "about", "would", "these", "other", "words", "could", "write", "first", "water", "after", "where", "right", "think", "three", "years", "place", "sound", "great", "again", "still", "every", "small", "found", "those", "never", "under", "might", "while", "house", "world", "below", "asked", "going", "large", "until", "along", "shall", "being", "often", "earth", "began", "since", "study", "night", "light", "above", "paper", "parts", "young", "story", "point", "times", "heard", "whole", "white", "given", "means", "music", "miles", "thing", "today", "later", "using", "money", "lines", "order", "group", "among", "learn", "known", "space", "table", "early", "trees", "short", "hands", "state", "black", "shown", "stood", "front", "voice", "kinds", "makes", "comes", "close", "power", "lived", "vowel", "taken", "built", "heart", "ready", "quite", "class", "bring", "round", "horse", "shows", "piece", "green", "stand", "birds", "start", "river", "tried", "least", "field", "whose", "girls", "leave", "added", "color", "third", "hours", "moved", "plant", "doing", "names", "forms", "heavy", "ideas", "cried", "check", "floor", "begin", "woman", "alone", "plane", "spell", "watch", "carry", "wrote", "clear", "named", "books", "child", "glass", "human", "takes", "party", "build", "seems", "blood", "sides", "seven", "mouth", "solve", "north", "value", "death", "maybe", "happy", "tells", "gives", "looks", "shape", "lives", "steps", "areas", "sense", "speak", "force", "ocean", "speed", "women", "metal", "south", "grass", "scale", "cells", "lower", "sleep", "wrong", "pages", "ships", "needs", "rocks", "eight", "major", "level", "total", "ahead", "reach", "stars", "store", "sight", "terms", "catch", "works", "board", "cover", "songs", "equal", "stone", "waves", "guess", "dance", "spoke", "break", "cause", "radio", "weeks", "lands", "basic", "liked", "trade", "fresh", "final", "fight", "meant", "drive", "spent", "local", "waxes", "knows", "train", "bread", "homes", "teeth", "coast", "thick", "brown", "clean", "quiet", "sugar", "facts", "steel", "forth", "rules", "notes", "units" };
std::string random()
{
srand(time(NULL));
int randomNum = rand() % wordList.size() + 1;
return wordList[randomNum];
}
int tries = 0;
std::string guess[5]={ "","","","","" };
std::string answer = random();
bool isCorrect = false;
std::map<char, int> mp;
void setup()
{
	
	tries = 0;
	for (int i = 0; i < 5; i++)
	{
		guess[i] = "";
	}
	answer = random();
	mp.clear();
	for (int i = 0; i < answer.size(); i++)
	{
		if (mp.find(answer.at(i)) != mp.end())
		{
			mp.find(answer.at(i))->second++;
		}
		else
			mp[answer.at(i)] = 1;
	}
	isCorrect = false;
}
void success()
{
	system("cls");
	std::cout << R"(   
   _____                             _ 
  / ____|                           | |
 | (___  _   _  ___ ___ ___  ___ ___| |
  \___ \| | | |/ __/ __/ _ \/ __/ __| |
  ____) | |_| | (_| (_|  __/\__ \__ \_|
 |_____/ \__,_|\___\___\___||___/___(_)
  you've guessed the word correctly!                                     
                                       )" << std::endl;
}
void fail()
{
	system("cls");
	std::cout << R"(
  ______    _ _             
 |  ____|  (_) |            
 | |__ __ _ _| |            
 |  __/ _` | | |            
 | | | (_| | | |  _   _   _ 
 |_|  \__,_|_|_| (_) (_) (_)
                            
                            
)" << std::endl;
std::cout << "The answer was: " << answer << std::endl;
}
void draw()
{
	system("cls");
	for (int i = 0; i <= 6; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			if (guess[i] != "")
			{
				if (j == 0)
					std::cout << "#";
				else if (j == 6)
					std::cout << "#";
				else
					std::cout << guess[i].at(j - 1);
			}
			else
			{
				if (j == 0)
					std::cout << "#";
				else if (j == 6)
					std::cout << "#";
				else
					std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
	for (int i = 0; i <= 6; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
}
void input()
{
a:
	std::string input;
	std::cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		input.at(i) = tolower(input.at(i));
	}
	if (input.size() != 5)
	{
		system("cls");
		std::cout << "Length of the input should be exactly 5, try again!" << std::endl;
		goto a;
	}
	else
	{
		guess[tries] = input;
	}
}

void giveAnswer()
{
	std::cout << answer << std::endl;
}

void logic()
{
	if (answer == guess[tries])
		isCorrect = true;
	
	for (int i = 0; i < answer.size(); i++)
	{
		
		if (mp.find(guess[tries].at(i)) != mp.end())
		{
			if (answer.at(i) != guess[tries].at(i))
			{
				guess[tries].at(i) = toupper(guess[tries].at(i));
			}
		}
		if (answer.at(i) != guess[tries].at(i) && islower(guess[tries].at(i)))
		{
			guess[tries].at(i) = '*';
		}
    }
}