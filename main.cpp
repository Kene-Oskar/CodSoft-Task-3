//OKAFOR KENECHUKWU
//C++ Programming
//CodSoft Task 3


#include <iostream>

using namespace std;

char Move;
bool Draw = false;
char Board[3][3] = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}};

void DisplayBoard();
void PlayerMove();
bool GameOver();
void ResetGame();


int main()
{
    cout << " XO CHALLENGE: LET'S TIC - TAC - TOE! " << endl << endl;

    cout << " Player 1 [X] - Player 2 [O] " << endl << endl;

    do
    {
        Move = 'X';

    while (!GameOver())
        {
            DisplayBoard();
            PlayerMove();
        }

        DisplayBoard();

    if (Move == 'O' && !Draw)
        {
            cout << " Player 1 [X] Wins! " << endl << endl;
            cout << " THANKS FOR PLAYING! " << endl << endl;
        }

    else if (Move == 'X' && !Draw)
        {
            cout << " Player 2 [O] Wins! " << endl << endl;
            cout << " THANKS FOR PLAYING! " << endl << endl;
        }

    else
        {
            cout << " Game Over! It's a Draw! " << endl << endl;
            cout << " THANKS FOR PLAYING! " << endl << endl;
        }


        ResetGame();

        cout << "Do you want to play again? (Y/N): " << endl << endl;

        char playAgain;

        cin >> playAgain;

    if (playAgain != 'y' && playAgain != 'Y')
        {
            break;
        }

   }while (true);

    return 0;
}

void DisplayBoard()
{
    cout << "      |      |      " << endl;
    cout << "  " << Board[0][0] << "   |  "   << Board[0][1] << "   |   " << Board[0][2] << endl;
    cout << "______|______|______" << endl;
    cout << "      |      |      " << endl;
    cout << "  " << Board[1][0] << "   |  "   << Board[1][1] << "   |   " << Board[1][2] << endl;
    cout << "______|______|______" << endl;
    cout << "      |      |      " << endl;
    cout << "  " << Board[2][0] << "   |  "   << Board[2][1] << "   |   " << Board[2][2] << endl;
    cout << "      |      |      " << endl << endl;
}

void PlayerMove()
{
    char Choice;
    int Row = 0, Column = 0;
    bool validChoice = false;

    while (!validChoice)
    {
    if (Move == 'X')
        {
            cout << " Player 1 Move [X]: " << endl << endl;
        }

    else if (Move == 'O')
        {
            cout << " Player 2 Move [O]: " << endl << endl;
        }

        cin >> Choice;


    switch (Choice)

        {
        case 'A':
            Row = 0;
            Column = 0;
            validChoice = true;
            break;
        case 'B':
            Row = 0;
            Column = 1;
            validChoice = true;
            break;
        case 'C':
            Row = 0;
            Column = 2;
            validChoice = true;
            break;
        case 'D':
            Row = 1;
            Column = 0;
            validChoice = true;
            break;
        case 'E':
            Row = 1;
            Column = 1;
            validChoice = true;
            break;
        case 'F':
            Row = 1;
            Column = 2;
            validChoice = true;
            break;
        case 'G':
            Row = 2;
            Column = 0;
            validChoice = true;
            break;
        case 'H':
            Row = 2;
            Column = 1;
            validChoice = true;
            break;
        case 'I':
            Row = 2;
            Column = 2;
            validChoice = true;
            break;
        default:
            cout << " Invalid character! Try again " <<endl << endl;
        }

    }

    if (Board[Row][Column] != 'X' && Board[Row][Column] != 'O')

        {
    if (Move == 'X')
        {
            Board[Row][Column] = 'X';
            Move = 'O';
        }
    else
        {
            Board[Row][Column] = 'O';
            Move = 'X';
        }
    }
    else
        {
        cout << " The cell you chose is taken. Try again! " <<endl << endl;
        PlayerMove();
    }
}

bool GameOver()
{
    // Check for win
    for (int i = 0; i < 3; i++)
    {
        if ((Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2]) ||
            (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i]) ||
            ((i == 0 && Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2]) ||
             (i == 2 && Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0])))
        {

            return true;
        }
    }

    // Check for draw
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] != 'X' && Board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    Draw = true;
    DisplayBoard(); // Display the board before declaring a draw
    cout << " Game Over! It's a Draw! " << endl << endl;
    return true;
}



void ResetGame()
{
    Draw = false;
    Move = 'X';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Board[i][j] = 'A' + i * 3 + j;
        }
    }
}
