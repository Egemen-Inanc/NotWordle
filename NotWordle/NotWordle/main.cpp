#include <iostream>
#include<windows.h>
#include <vector>
#include<string>
#include "utilities.hpp"


int main()
{

	std::cout << R"(
 ________   ________  _________  ___       __   ________  ________  ________  ___       _______      
|\   ___  \|\   __  \|\___   ___\\  \     |\  \|\   __  \|\   __  \|\   ___ \|\  \     |\  ___ \     
\ \  \\ \  \ \  \|\  \|___ \  \_\ \  \    \ \  \ \  \|\  \ \  \|\  \ \  \_|\ \ \  \    \ \   __/|    
 \ \  \\ \  \ \  \\\  \   \ \  \ \ \  \  __\ \  \ \  \\\  \ \   _  _\ \  \ \\ \ \  \    \ \  \_|/__  
  \ \  \\ \  \ \  \\\  \   \ \  \ \ \  \|\__\_\  \ \  \\\  \ \  \\  \\ \  \_\\ \ \  \____\ \  \_|\ \ 
   \ \__\\ \__\ \_______\   \ \__\ \ \____________\ \_______\ \__\\ _\\ \_______\ \_______\ \_______\
    \|__| \|__|\|_______|    \|__|  \|____________|\|_______|\|__|\|__|\|_______|\|_______|\|_______|
                                                                                                     
if a letter is crossed out, that letter is not contained in the answer.
if a letter is represented with its capital form, the letter is contained in the answer but with a different position.
if a letter is represented as lower then it means it is present in the answer and is in its right position.  
                                                                          )" << std::endl;
a:
	bool decision = false;
	std::cout << "Would you like to play?\n 1)Yes \n 0)No\n";
	std::cin >> decision;
	if (decision)
	{
		system("cls");
		setup();
		draw();
		while (tries < 5 && isCorrect != true)
		{
			input();
			logic();
			draw();
			tries++;
		}
		if (isCorrect == true)
		{
			success();
			goto a;
		}
		else if(tries >=5 && isCorrect!=true)
		{
			fail();
			goto a;
		}
	}
	else
		std::cout << "Goodbye!" << std::endl;
	
	return 0;
}
