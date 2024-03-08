#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<string> &board)
{
    for (const string &row : board)
    {
        cout << row << endl;
    }
    cout << endl;
}

bool isSafe(const vector<string> &board, int row, int col)
{
    int N = board.size();

    // Check column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void placeQueen(vector<string> &board, int row, vector<vector<string>> &solutions)
{
    int N = board.size();

    if (row == N) // If all queens are placed
    {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 'Q'; // Place the queen

            placeQueen(board, row + 1, solutions); // Recur to place queens in the next row

            board[row][col] = '.'; // Backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '.')); // Initialize empty board
    vector<vector<string>> solutions;
    placeQueen(board, 0, solutions);
    return solutions;
}

int main()
{
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Number of distinct solutions: " << solutions.size() << endl;
    for (const auto &solution : solutions)
    {
        printBoard(solution);
    }

    return 0;
}
