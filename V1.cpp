//version 1, player vs player
#include<iostream>
#include<stdlib.h>
using namespace std;
bool checkwinh(char*);
bool checkwinv(char*);
bool checkwind(char*);
int main()
{
	string play1, play2;

	int a, b,i,p1wins = 0,p2wins = 0;
	char grid[3][3] = {}, playagain;

	cout << "Please enter name of player one: ";
	cin >> play1;

	cout << "Please enter name of player two: ";
	cin >> play2;

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
		system("CLS");
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
			if (i % 2 == 1)
			{
				cout << play1 << "'s turn, where will you place your X, enter x cord, then enter y cord (top-left is 1,1); ";
				cin >> a >> b;
				a--;
				b--;
				if (grid[a][b] == ' ')
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
				cout << play2 << "'s turn, where will you place your O, enter x cord, then enter y cord (top-left is 1,1); ";
				cin >> a >> b;
				a--;
				b--;
				if (grid[a][b] == ' ')
				{
					grid[a][b] = 'O';
					j = -1;
				}
				else
				{
					cout << "invalide location"<<endl;
				}
			}
		}

		if (checkwinh(&grid[0][0]) || checkwinv(&grid[0][0])||checkwind(&grid[0][0]))//wins
		{
			if (i % 2 == 1)
			{
				cout << play1;
				p1wins++;
			}
			else
			{
				cout << play2;
				p2wins++;
			}
			cout << " wins, wanna play again? y/n (" << play1 << "'s wins = " << p1wins << "," << play2 << "'s wins = " << p2wins << ") : ";
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
		if (i == 9)//draw game
		{
			cout << "draw game, wanna play again? y/n (" << play1 << "'s wins = " << p1wins << "," << play2 << "'s wins = " << p2wins << ") : ";
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
	for (int i = 0;i < 3;i++)
	{
			if (*(p1 + (3 * i)) == *(p1 + 1 + (3 * i)) && *(p1 + (3 * i)) == *(p1 + 2 + (3 * i))&& *(p1 + (3 * i)) != ' ')
			{
				return true;
			}
	}
	return false;
}
//vetical win check
bool checkwinv(char* p1)
{
	for (int i = 0;i < 3;i++)
	{
		if (*(p1 +i) == *(p1 + 3 * i) && *(p1 +i) == *(p1 + 6 + 1 * i) && *(p1 + i) != ' ')
		{
			return true;
		}
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
		if (*(p1+2) == *(p1 + 4) && *(p1+2) == *(p1 + 6) && *(p1+2) != ' ')
		{
			return true;
		}
	return false;
}