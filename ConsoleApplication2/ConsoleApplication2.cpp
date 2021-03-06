// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "windows.h"
#include "string"
#include "cmath"
#include "regex"
#include "algorithm"

bool isNumber(std::string input)
{
	std::regex onlyNumbers("[0-9]{1,}");
	return std::regex_match(input, onlyNumbers);
}
void menu()
{
	std::cout << "dezToBin - Decimal to Binary Converter\nroot - get Root of a Number\ndezToHex - Decimal to Hexadecimal Converter\nquit - Exit programm\n";
}

void dezToBin()
{
	std::string input;
	int x;
	while (true)
	{
		std::cout << "DECICMAL TO BINARY CONVERTER - 'back' to go to Main Menu\nEnter decimal number!\n";
		std::getline(std::cin, input);
		if (input == "back")
		{
			system("CLS");
			break;
		}
		std::cin.sync();
		if (isNumber(input))
		{
			x = stoi(input, 0);
			std::string binary;
			for (int i = 0; x != 0; i++)
			{
				binary.append(std::to_string(x % 2));
				x = x / 2;
			}
			std::reverse(binary.begin(), binary.end());
			std::cout << binary << std::endl;
			for (int i = 0; i < 10; i++)
			{
				std::cout << ".";
				Sleep(500);
			}
			system("CLS");
		}
		else
		{
			std::cout << "Enter valid Number!\n";
			for (int i = 0; i < 10; i++)
			{
				std::cout << ".";
				Sleep(500);
			}
			system("CLS");
		}
	}
}

void dezToHex()
{
	std::string input;
	int x;
	while (true)
	{
		std::cout << "DECICMAL TO HEXADECIMAL CONVERTER - 'back' to go to Main Menu\nEnter decimal number!\n";
		std::getline(std::cin, input);
		if (input == "back")
		{
			system("CLS");
			break;
		}
		std::cin.sync();
		if (isNumber(input))
		{
			x = stoi(input, 0);
			std::string hexadecimal;
			for (int i = 0; x != 0; i++)
			{
				std::string newEntry;
				switch (x % 16)
				{
				case 10: newEntry = "A";
					break;
				case 11: newEntry = "B";
					break;
				case 12: newEntry = "C";
					break;
				case 13: newEntry = "D";
					break;
				case 14: newEntry = "E";
					break;
				case 15: newEntry = "F";
					break;
				default: newEntry = std::to_string(x % 16);
				}
				hexadecimal.append(newEntry);
				x = x / 16;
			}
			std::reverse(hexadecimal.begin(), hexadecimal.end());
			std::cout << hexadecimal << std::endl;
			for (int i = 0; i < 10; i++)
			{
				std::cout << ".";
				Sleep(500);
			}
			system("CLS");
		}
		else
		{
			std::cout << "Enter valid Number!\n";
			for (int i = 0; i < 10; i++)
			{
				std::cout << ".";
				Sleep(500);
			}
			system("CLS");
		}
	}
}

void root()
{
	bool bInput;
	std::string xInput;
	float in;
	while (true)
	{
		bInput = false;
		std::cout << "ROOT-CALCULATOR\nEnter number - 'back' to exit to Selection Menu\n";
		std::getline(std::cin, xInput);
		std::cin.sync();
		if (xInput == "back")
		{
			system("CLS");
			break;
		}
		if (isNumber(xInput))
		{
			in = std::stold(xInput, 0);
			long double n = 1;
			for (int i = 0; n * n != in && i <= 50; i++)
			{
				n = (n + in / n) / 2;
				if (i == 50)
				{
					bInput = true;
					std::roundl(n);
				}
			}
			std::cout << n << std::endl;
			if (bInput == true)
			{
				std::cout << "(rounded)";
			}
			for (int i = 0; i < 10; i++)
			{
				std::cout << ".";
				Sleep(500);
			}
		}
		else
		{
			std::cout << "Enter a Number!\n";
			for (int i = 0; i < 3; i++)
			{
				std::cout << ".";
				Sleep(500);
			}
		}
		system("CLS");
	}
}

int main()
{
	std::string input;
	bool validInput;
	bool redrawMenu = false;
	while (true)
	{
		validInput = false;
		std::cout << "MAIN MENU - 'help' for Commands\n";
		if (redrawMenu)
		{
			menu();
			redrawMenu = false;
		}
		std::getline(std::cin, input);
		std::cin.sync();
		if (input == "quit")
		{
			return 0;
		}
		if (input == "root")
		{
			system("CLS");
			root();
			validInput = true;
		}
		if (input == "dezToBin")
		{
			system("CLS");
			dezToBin();
			validInput = true;
		}
		if (input == "dezToHex")
		{
			system("CLS");
			dezToHex();
			validInput = true;
		}
		if (input == "help")
		{
			system("CLS");
			redrawMenu = true;
			validInput = true;
		}
		if (!validInput)
		{
			std::cout << "Enter valid input!\n";
			for (int i = 0; i < 10; i++)
			{
				std::cout << ".";
				Sleep(500);
			}
			system("CLS");
		}
	}
}

