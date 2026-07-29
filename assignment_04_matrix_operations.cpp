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
const int MAX_SIZE = 10;

// Helper function to read a matrix from the user
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Helper function to display a matrix in a grid using setw()
void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose Matrix
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = input[i][j];
        }
    }
}

// PART B: Add Two Matrices
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Multiply Two Matrices (A is M x N, B is N x P, Result is M x P)
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    // --- PART A: TRANSPOSE ---
    cout << "=== PART A: Transpose ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    readMatrix(A, rowsA, colsA);

    cout << endl << "Original Matrix:" << endl;
    displayMatrix(A, rowsA, colsA);

    transposeMatrix(A, result, rowsA, colsA);

    cout << endl << "Transposed Matrix:" << endl;
    displayMatrix(result, colsA, rowsA);

    // --- PART B: ADDITION ---
    cout << endl << "=== PART B: Matrix Addition ===" << endl;
    cout << "Enter matrix dimensions (rows and columns): ";
    cin >> rowsA >> colsA;

    cout << "Enter elements for Matrix A:" << endl;
    readMatrix(A, rowsA, colsA);

    cout << "Enter elements for Matrix B:" << endl;
    readMatrix(B, rowsA, colsA);

    addMatrices(A, B, result, rowsA, colsA);

    cout << endl << "Sum Matrix:" << endl;
    displayMatrix(result, rowsA, colsA);

    // --- PART C: MULTIPLICATION ---
    cout << endl << "=== PART C: Matrix Multiplication ===" << endl;
    cout << "Enter rows and cols for Matrix A (M x N): ";
    cin >> rowsA >> colsA;
    cout << "Enter rows and cols for Matrix B (N x P): ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB) {
        cout << "Error: Number of columns in A must equal number of rows in B for multiplication." << endl;
        return 0;
    }

    cout << "Enter elements for Matrix A:" << endl;
    readMatrix(A, rowsA, colsA);

    cout << "Enter elements for Matrix B:" << endl;
    readMatrix(B, rowsB, colsB);

    multiplyMatrices(A, B, result, rowsA, colsA, colsB);

    cout << endl << "Product Matrix (A x B):" << endl;
    displayMatrix(result, rowsA, colsB);

    return 0;
}
