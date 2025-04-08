#include <stdio.h>

char box[3][3];
char Player = 'X';


void showBoxes()   // to show what the boxes looks like
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {

        for (int z = 0; z < 3; z++)
        {
            printf("%c", box[i][z]);
            if (z < 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2)
        {
            printf("-+-+-\n");
        }
    }
    printf("\n");
}

void assignBoxes() // to give the boxes their numbers when selecting which box to play in
{
    int num = 1;
    int i;
    for (i = 0; i < 3; i++) 
    {
        for (int z = 0; z < 3; z++) 
        {
            box[i][z] = num + '0';
            num++;
        }
    }
}





void takeTurn() 
{
    int pos;
    while (1) 
    {
        printf("Player %c , choose a spot (1-9): ", Player);
        scanf_s("%i", &pos);

        if (pos >= 1 && pos <= 9) // to check that the number is between 1 and 9
        {
            int row = (pos - 1) / 3;  // changes the number to the row value
            int col = (pos - 1) % 3;  // changes the number to the column value

            if (box[row][col] != 'X' && box[row][col] != 'O') 
            {
                box[row][col] = Player;
                break;

            }
            else 
            {
                printf("Cant place there,choose a different spot\n");
            }
        }
        else 
        {
            printf("Cant place there,choose a different spot.\n");
        }
    }
}




void switchPlayer()  // function to switch to the other player
{
    if (Player == 'X')     // if the player is X then
    {
        Player = 'O';    // the next go is O
    }
    else 
    {
        Player = 'X';    // if the player is O then the next go is X
    }
}




// function to check if a player has won
int checkWin() 
{
  
    // Check rows, columns, and diagonals

    for (int i = 0; i < 3; i++) 
    {
        if (box[i][0] == Player && box[i][1] == Player && box[i][2] == Player) 
        {
            return 1;
        }
        if (box[0][i] == Player && box[1][i] == Player && box[2][i] == Player) 
        {
            return 1;
        }
    }
    if (box[0][0] == Player && box[1][1] == Player && box[2][2] == Player) 
    {
        return 1;
    }
    if (box[0][2] == Player && box[1][1] == Player && box[2][0] == Player) 
    {
        return 1;
    }
    return 0;
}


int checkDraw() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int z = 0; z < 3; z++) 
        {
            if (box[i][z] != 'X' && box[i][z] != 'O')  // if there is a value thats not x or o then its not full else its a draw
            {
                return 0;
            }
        }
    }
    return 1; 
}





int main() 
{
    int gameOver = 0;
    assignBoxes(); 

    while (!gameOver) 
    {
        showBoxes();
        takeTurn();

        if (checkWin()) 
        {
            showBoxes();
            printf("%c has won \n", Player);
            gameOver = 1;
        }
        else if (checkDraw()) 
        {
            showBoxes();
            printf("it is a draw \n");
            gameOver = 1;
        }
        else 
        {
            switchPlayer();
        }
    }

    return 0;
}

