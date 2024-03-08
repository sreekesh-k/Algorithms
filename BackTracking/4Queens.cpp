#include <iostream>
#include <vector>

using namespace std;
const int N = 4;

void printBoard(vector<vector<int>> &board)
{
}

bool isSafe(vector<vector<int>> &board, int row, int col)
{

    return true;
}

bool placeQueen(vector<vector<int>> &board, int col)
{
    if (col == N) // if all the queens are placed
    {
        printBoard(board);
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
}

int main()
{
    vector<vector<int>> board(N, vector<int>(N, 0));
    if (!placeQueen(board, 0)) // start by placing queen in [0,0]
        cout << "Solution does not exist" << endl;

    return 0;
}