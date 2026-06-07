#include <iostream>
using namespace std;

void createSudoku(int mat[9][9])
{
    cout << "\nEnter the Sudoku grid (use 0 for empty cells):\n";

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void printSudoku(int mat[9][9])
{
    cout << "\n+-------+-------+-------+\n";

    for(int i = 0; i < 9; i++)
    {
        cout << "| ";

        for(int j = 0; j < 9; j++)
        {
            cout << mat[i][j] << " ";

            if((j + 1) % 3 == 0)
                cout << "| ";
        }

        cout << endl;

        if((i + 1) % 3 == 0)
            cout << "+-------+-------+-------+\n";
    }
}

bool isSafe(int mat[9][9], int row, int col, int num)
{
    for(int x = 0; x < 9; x++)
    {
        if(mat[row][x] == num)
            return false;
    }

    for(int x = 0; x < 9; x++)
    {
        if(mat[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(mat[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudokuRec(int mat[9][9], int row, int col)
{
    if(row == 8 && col == 9)
        return true;

    if(col == 9)
    {
        row++;
        col = 0;
    }

    if(mat[row][col] != 0)
        return solveSudokuRec(mat, row, col + 1);

    for(int num = 1; num <= 9; num++)
    {
        if(isSafe(mat, row, col, num))
        {
            mat[row][col] = num;

            if(solveSudokuRec(mat, row, col + 1))
                return true;

            mat[row][col] = 0;
        }
    }

    return false;
}

void solveSudoku(int mat[9][9])
{
    if(solveSudokuRec(mat, 0, 0))
    {
        cout << "\nSudoku solved successfully!\n";
        printSudoku(mat);
    }
    else
    {
        cout << "\nNo valid solution exists.\n";
    }
}

int main()
{
    int mat[9][9] = {0};
    int command;

    cout << "=================================\n";
    cout << "         SUDOKU SOLVER\n";
    cout << "=================================\n";

    do
    {
        cout << "\nMenu\n";
        cout << "1. Create Sudoku Puzzle\n";
        cout << "2. Display Sudoku Puzzle\n";
        cout << "3. Solve Sudoku Puzzle\n";
        cout << "4. Exit\n";
        cout << "\nEnter command: ";

        cin >> command;

        switch(command)
        {
            case 1:
                createSudoku(mat);
                break;

            case 2:
                printSudoku(mat);
                break;

            case 3:
                solveSudoku(mat);
                break;

            case 4:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid command. Try again.\n";
        }

    } while(command != 4);

    return 0;
}
