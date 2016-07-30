// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
char box[] = {'0','1','2','3','4','5','6','7','8','9'};
int play = 1;
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
	char opt;
	if (play == 2)
	{
		opt = 'x';
	}
	else if(play==1)
	{
		opt = 'o';
	}

	cout << "here";
	cout << "\n CHECK\n";
	cout << box[poss] << opt;
	if (box[poss] == opt)
	{
		cout << "loop1";
		if (box[poss + 1] == opt)
		{
			cout << "loop2";
			if (box[poss - 1] == opt )
			{
				cout << "loop3";
				if (poss % 2 == 0)
				{
					cout << "loop4";
					cout << "WINNER";
					exit(0);
				}
			}
			else if (box[poss + 2] == opt)
			{
				cout << "loop5";
				if ((poss + 1) % 2 == 0)
				{
					cout << "loop6";
					cout << "WINNER";
					exit(0);
				}
			}
		}
		else if (box[poss - 1] == opt)
		{
			if (box[poss + 1] == opt  )
			{
				if (poss % 2 == 0)
				{
					cout << "WINNER";
					exit(0);
				}
			}
			else if (box[poss - 2] == opt)
			{
				if ((poss - 1) % 2 == 0)
				{
					cout << "WINNER";
					exit(0);
				}
			}
		}
	}
		poss++;
		cout << "POOOOOOOOOOO\t" << poss << "   " << box[poss];
		if(box[poss + 3] == opt&&box[poss + 6] == opt)
		{
		
			cout << "winner";
			exit(0);
		
		}
		if (box[poss - 3] == opt&&box[poss - 6] == opt)
		{

			cout << "winner";
			exit(0);

		}
		if (box[poss + 3] == opt&&box[poss -3] == opt)
		{

			cout << "winner";
			exit(0);

		}
	
	if (box[poss++])
	{
		cout << "or this";
		if(box[poss++]==opt)
		cout << box[poss];
	}
}
void enterval()
{
	int pos;
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
				check(pos);
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

