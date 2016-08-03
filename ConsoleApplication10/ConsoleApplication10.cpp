// ConsoleApplication10.cpp : Defines the entry point for the console application.
//All rights to use/comment/suggest given to the viewer !! i want to learn how to become better

#include "stdafx.h"
#include<iostream>
using namespace std;
char box[] = {'0','1','2','3','4','5','6','7','8','9'};// The grid!
int play = 1;

//NEW WINNER FUNCTION
void winner(char opt)
{
	cout << "We have a WINNER!!!!";
	if (opt == 'x')
	{
		cout << "\n The winner is PLAYER 1 \n ";
	}
	else
	{
		cout << "\n The winner is PLAYER 2 \n";
	}
	exit(0);
}

//
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

void crossface(char opt)
{
	if (box[1] == opt&&box[5] == opt&&box[9] == opt)
	{
		winner(opt);
	}
	else if (box[3] == opt&&box[5] && box[7] == opt)
	{
		winner(opt);
	}
}
void check(int poss)		// checks one step before and after!!
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

	//cout << "here";
	//cout << "\n CHECK\n";
	//cout << box[poss] << opt;
	if (box[poss] == opt)
	{
		//cout << "loop1";
		if (box[poss + 1] == opt)
		{
			//cout << "loop2";
			if (box[poss - 1] == opt )
			{
				//cout << "loop3";
				if (poss % 2 == 0)	//checks within same row or not!
				{
					//cout << "loop4";
					winner(opt);
				}
			}
			else if (box[poss + 2] == opt)
			{
				//cout << "loop5";
				if ((poss + 1) % 2 == 0)
				{
					//cout << "loop6";
					winner(opt);
				}
			}
		}
		else if (box[poss - 1] == opt)
		{
			if (box[poss + 1] == opt  )
			{
				if (poss % 2 == 0)
				{
					winner(opt);
				}
			}
			else if (box[poss - 2] == opt)
			{
				if ((poss - 1) % 2 == 0)
				{
					winner(opt);
				}
			}
		}
	}
		//poss++;
		//cout << "POOOOOOOOOOO\t" << poss << "   " << box[poss];
		if(box[poss + 3] == opt&&box[poss + 6] == opt)
		{
		
			winner(opt);
		
		}
		if (box[poss - 3] == opt&&box[poss - 6] == opt)
		{
			winner(opt);
		}
		if (box[poss + 3] == opt&&box[poss -3] == opt)
		{

			winner(opt);
		}
	
	if (box[poss++])
	{
		//cout << "or this";
		if(box[poss++]==opt)
		cout << box[poss];
	}
	crossface(opt);
}
void enterval()
{
	int pos;
	while (true)
	{
		if (play == 1)
		{
			cout << "Player one!!! Your symbol is 'x' Enter your position number";
			cin >> pos;
			if (box[pos] == 'x' || box[pos] == 'o'||pos==0||pos>9)
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
			cout << "Player two!!! Your symbol is 'o' Enter your position number";
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
	printtnstr();				//Welcome message !! explain rules
	printbox();					//print the grid!
	enterval();					// user turns auto exit if player wins
	return 0;

}

