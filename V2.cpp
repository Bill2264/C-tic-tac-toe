//version 1, player vs comupter
#include<iostream>
#include<stdlib.h>
using namespace std;
bool checkwinh(char*);
bool checkwinv(char*);
bool checkwind(char*);
int main()
{
	string play1;
	srand(time(NULL));//sets rand seed based on system time,effectivally random
	int a, b,i,p1wins = 0,Cwins = 0;
	char grid[3][3] = {}, playagain;
	char* p1 = &grid[0][0]; 
	cout << "Please enter name of player one: ";//first player's name
	cin >> play1;
	for( i = 1; i<=9;i++)
	{
		if(i==1)
		{
			for (int y = 0; y <= 2; y++)//makes the grid all spaces
			{
				for (int x = 0; x <= 2; x++)
				{
					grid[x][y] = ' ';
				}
			}
		}
		system("CLS");//clears the screen of elements, makes the game look better
		cout << "---------" << endl;
		for (int y = 0; y <= 2; y++)//draws the grid
		{
			for (int x = 0; x <= 2; x++)
			{
				cout << "|" << grid[x][y] << "|";
			}
			cout << endl << "---------" << endl;
		}
		for(int j = 1;j>0;j++)
		{
			if (i % 2 == 1)//decides whos turn it is, returns 1 on odd numbered turns
			{
				cout << play1 << "'s turn, where will you place your X, enter x cord, then enter y cord (top-left is 1,1); ";
				cin >> a >> b;
				a--;
				b--;
				if (grid[a][b] == ' ')//checks if spot is empty before writing the X
				{
					grid[a][b] = 'X';
					j = -1;
				}
				else
				{
					cout << "invalide location"<<endl;
				}
			}
			else
			{
				
				a = rand()%3;//genrates a random number from 0 to 2
				b = rand()%3;
				if (grid[a][b] == ' ')
				{
					grid[a][b] = 'O';
					j = -1;
				}
			}
		}

		if (checkwinh(&grid[0][0]) || checkwinv(&grid[0][0])||checkwind(&grid[0][0]))//runs fuctions to see who wins
		{
			if (i % 2 == 1)//if turn is odd player 1 wins
			{
				
				cout << play1;
				p1wins++;
			}
			else
			{
				cout <<"Computer";
				Cwins++;
			}
			cout << " wins, wanna play again? y/n (" << play1 << "'s wins = " << p1wins << ", Computer's wins = " << Cwins << ") : ";
			cin >> playagain;

			if (playagain == 'y' || playagain == 'Y')//if i is 0, 0 is valid for loop and then i++ and loop starts again at i = 1
			{
				i = 0;
			}
			else//if i is 10 then loop ends
			{
				i = 10;
			}
		}
		if (i == 9)//if neither player gets 3 in a row i = 9 when it reaches this part and states draw
		{
			cout << "Draw game, wanna play again? y/n (" << play1 << "'s wins = " << p1wins << ", Computer's wins = " << Cwins << ") : ";
			cin >> playagain;

			if (playagain == 'y' || playagain == 'Y')
			{
				i = 0;
			}
			else
			{
				i = 10;
			}
		}
	}
	

	return 0;
}
//horizontal win check
bool checkwinh(char* p1)
{

			if (*(p1) == *(p1 + 3) && *(p1) == *(p1 + 6)&& *(p1) != ' ')
			{
				return true;
			}
			if (*(p1+1) == *(p1 + 4) && *(p1+1) == *(p1 + 7) && *(p1+1) != ' ')
			{
				return true;
			}
			if (*(p1+2) == *(p1 + 5) && *(p1+2) == *(p1 + 8) && *(p1+2) != ' ')
			{
				return true;
			}
	
	return false;
}
//vetical win check
bool checkwinv(char* p1)
{
	if (*(p1) == *(p1 + 1) && *(p1) == *(p1 + 2) && *(p1) != ' ')
	{
		return true;
	}
	if (*(p1 + 3) == *(p1 + 4) && *(p1+3) == *(p1 + 5) && *(p1 + 3) != ' ')
	{
		return true;
	}
	if (*(p1 + 6) == *(p1 + 7) && *(p1 + 6) == *(p1 + 8) && *(p1 + 6) != ' ')
	{
		return true;
	}
	return false;
}
//diagonal win check
bool checkwind(char* p1)
{
	
		if (*(p1) == *(p1 + 4) && *(p1) == *(p1 + 8) && *(p1) != ' ')
		{
			return true;
		}
		if (*(p1+6) == *(p1 + 4) && *(p1+6) == *(p1 + 2) && *(p1+6) != ' ')
		{
			return true;
		}
	return false;
}