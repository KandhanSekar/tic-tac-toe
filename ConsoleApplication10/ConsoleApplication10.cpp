// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
char box[] = {'0','1','2','3','4','5','6','7','8','9'};
void printbox()
{
	int i = 1;
	while (box[i] != 0)
	{
		cout << box[i]<<"\t";
		i++;
		if (i % 3 == 1)
		{
			cout << "\n";
		}
	}
}
void printtnstr()
{
	cout << "WELCOME TO KANDY'S TIC TAC TOE" << "\n";
	cout << "The Grid shows you the position number of each blank space,\n indicate the position number where you want to place your mark during your turn\n";
}
void check(int poss)
{
	cout << "\n CHECK\n";
	
		if (box[poss--] == 'x')
		{
			cout << "\n poss   " << box[poss];
			cout << "\n poss--   " << box[poss--];
			cout << "\n poss++   " << box[poss++];
			if (box[poss] == 'x'&&box[poss--] == 'x'&&box[poss++] == 'x')
			{
				cout << "\nWINNER";
				exit(0);
			}
			
		}
		poss++;
		cout << "POOOOOOOOOOO\t" << poss << "   " << box[poss];
		if(box[poss + 3] == 'x'&&box[poss + 6] == 'x')
		{
		
			cout << "winner";
			exit(0);
		
		}
		if (box[poss - 3] == 'x'&&box[poss - 6] == 'x')
		{

			cout << "winner";
			exit(0);

		}
		if (box[poss + 3] == 'x'&&box[poss -3] == 'x')
		{

			cout << "winner";
			exit(0);

		}
	
	if (box[poss++])
	{
		cout << "or this";
		if(box[poss++]=='x')
		cout << box[poss];
	}
}
void enterval()
{
	int pos,play=1;
	while (true)
	{
		if (play == 1)
		{
			cout << "Player one!!! Enter your position number";
			cin >> pos;
			if (box[pos] == 'x' || box[pos] == 'o')
			{
				cout << "Invalid !! try again";
				enterval();
			}
			else
			{
				box[pos] = 'x';
				play = 2;
				printbox();
				check(pos);
			}
			
		}
		else
		{
			cout << "Player two!!! Enter your position number";
			cin >> pos;
			if (box[pos] == 'x' || box[pos] == 'o')
			{
				cout << "Invalid !! try again";
				enterval();
			}
			else
			{
				box[pos] = 'o';
				play = 1;
				printbox();
			}

		}
		
	}
}
int main()
{
	printtnstr();
	printbox();
	enterval();
    return 0;
}

