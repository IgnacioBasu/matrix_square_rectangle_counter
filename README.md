# Matrix Square and Rectangle Counter

This C program counts the minimum number of squares and rectangles that can be formed from an integer matrix. The matrix can contain any number of rows and columns, and the squares or rectangles can be formed using consecutive non-zero values in the matrix.

## Key Features

- Determines if there are any null data in the matrix.
- Finds the first non-zero value in the matrix.
- Locates the first row and column containing non-zero values.
- Counts consecutive non-zero values to the right and downwards from a given position.
- Checks if it's possible to build a square or rectangle using consecutive non-zero values.
- Constructs a square or rectangle using consecutive non-zero values.
- Calculates the minimum number of squares and rectangles that can be formed.

## Usage

1. Clone or download the repository to your local machine.
2. Compile the program using a compatible C compiler.
3. Execute the program providing an integer matrix as input.
4. The program will return the minimum number of squares and rectangles that can be formed from the matrix.

## Example Input

```c
int matrix[3][5] = {{1, 1, 2, 2, 2},
                    {1, 1, 2, 2, 2},
                    {3, 3, 1, 3, 3}};
```

## Example Output

```
THE MINIMUM AMOUNT OF SQUARES AND RECTANGLES IS: 5
```

This is just a simple example to demonstrate the functionality of the program. You can provide any input matrix, and the program will determine the minimum number of squares and rectangles that can be formed.
