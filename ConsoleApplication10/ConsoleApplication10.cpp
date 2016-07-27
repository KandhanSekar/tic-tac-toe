// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
char box[3][3] = {'1','2','3','4','5','6','7','8','9'};
void printbox()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << box[i][j]<<"\t";
		}
		cout << "\n";
	}
}

void enterval()
{

}
int main()
{
	printbox();
	enterval();
    return 0;
}

