#include <iostream>
#include <vector>

using namespace std;
const int N = 4;

void printBoard(vector<vector<int>> &board)
{ // print board
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j < N - 1)
                cout << "| " << board[i][j] << " ";
            else
                cout << "| " << board[i][j] << " |";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<vector<int>> &board, int row, int col)
{ // can i place the queen here? on this row and this col

    // Check row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
            return false;
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool placeQueen(vector<vector<int>> &board, int col)
{
    if (col == N) // if all the queens are placed
    {
        printBoard(board); // on the final row it prints the soluton and goes back
        return true;
    }
    bool solution = false;

    // Try placing a queen in each row of the current column
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1; // Place the queen
            solution = placeQueen(board, col + 1) || solution;
            board[i][col] = 0; // backtrack and try again
        }
    }
    return solution; // solution exists with the current placement or not
}

int main()
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (!placeQueen(board, 0))
        cout << "Solution does not exist";

    return 0;
}