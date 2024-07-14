#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    for (int i = 0; i < 9; i++)
    {
        // row check
        if (board[row][i] == val)
        {
            return false;
        }
        // for column check
        if (board[i][col] == val)
        {
            return false;
        }
        // 3*3 check now
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>> &board)
{
    int n = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(i, j, board, val))
                    {
                        board[i][j] = val;
                        // recursive call
                        bool SolustionPossible = solveSudoku(board);
                        if (SolustionPossible)
                        {
                            return true;
                        }
                        else
                        {
                            // backtracking
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> board(9, vector<int>(9));
    int a;

    cout << "Enter the 9*9 sudoku matrix where empty sell is representer by 0 :- ";

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a;
            board[i][j] = a;
        }
    }
    cout << "\n Your entered sudoku is :\n";
    print(board);
    cout << "\n After solving the sudoku is \n ";
    solveSudoku(board);
    print(board);

    return 0;
}