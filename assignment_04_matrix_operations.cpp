// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function Prototypes
void inputMatrix(int matrix[10][10], int rows, int cols);
void displayMatrix(int matrix[10][10], int rows, int cols);
void transposeMatrix(int matrix[10][10], int rows, int cols);
void addMatrices();
void multiplyMatrices();

int main()
{
    int choice;
    int matrix[10][10];
    int rows, cols;

    do
    {
        cout << "\n===============================" << endl;
        cout << "     MATRIX OPERATIONS MENU" << endl;
        cout << "===============================" << endl;
        cout << "1. Transpose Matrix" << endl;
        cout << "2. Add Two Matrices" << endl;
        cout << "3. Multiply Two Matrices" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter number of rows: ";
                cin >> rows;

                cout << "Enter number of columns: ";
                cin >> cols;

                cout << "\nEnter Matrix Elements\n";
                inputMatrix(matrix, rows, cols);

                cout << "\nOriginal Matrix\n";
                displayMatrix(matrix, rows, cols);

                cout << "\nTransposed Matrix\n";
                transposeMatrix(matrix, rows, cols);
                break;

            case 2:
                addMatrices();
                break;

            case 3:
                multiplyMatrices();
                break;

            case 4:
                cout << "\nProgram terminated." << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}

//======================================================
// Function to Input Matrix
//======================================================
void inputMatrix(int matrix[10][10], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

//======================================================
// Function to Display Matrix
//======================================================
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

//======================================================
// PART A - Transpose Matrix
//======================================================
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    displayMatrix(transpose, cols, rows);
}

//======================================================
// PART B - Add Two Matrices
//======================================================
void addMatrices()
{
    int A[10][10], B[10][10], Sum[10][10];
    int rows, cols;

    cout << "\nEnter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter First Matrix\n";
    inputMatrix(A, rows, cols);

    cout << "\nEnter Second Matrix\n";
    inputMatrix(B, rows, cols);

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nFirst Matrix\n";
    displayMatrix(A, rows, cols);

    cout << "\nSecond Matrix\n";
    displayMatrix(B, rows, cols);

    cout << "\nSum Matrix\n";
    displayMatrix(Sum, rows, cols);
}

//======================================================
// PART C - Multiply Two Matrices
//======================================================
void multiplyMatrices()
{
    int A[10][10], B[10][10], Product[10][10];
    int rowsA, colsA, rowsB, colsB;

    cout << "\nEnter rows of Matrix A: ";
    cin >> rowsA;

    cout << "Enter columns of Matrix A: ";
    cin >> colsA;

    cout << "\nEnter rows of Matrix B: ";
    cin >> rowsB;

    cout << "Enter columns of Matrix B: ";
    cin >> colsB;

    if(colsA != rowsB)
    {
        cout << "\nMatrix multiplication is NOT possible." << endl;
        return;
    }

    cout << "\nEnter Matrix A\n";
    inputMatrix(A, rowsA, colsA);

    cout << "\nEnter Matrix B\n";
    inputMatrix(B, rowsB, colsB);

    // Initialize product matrix
    for(int i = 0; i < rowsA; i++)
    {
        for(int j = 0; j < colsB; j++)
        {
            Product[i][j] = 0;
        }
    }

    // Matrix Multiplication
    for(int i = 0; i < rowsA; i++)
    {
        for(int j = 0; j < colsB; j++)
        {
            for(int k = 0; k < colsA; k++)
            {
                Product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMatrix A\n";
    displayMatrix(A, rowsA, colsA);

    cout << "\nMatrix B\n";
    displayMatrix(B, rowsB, colsB);

    cout << "\nProduct Matrix (A x B)\n";
    displayMatrix(Product, rowsA, colsB);
}
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

