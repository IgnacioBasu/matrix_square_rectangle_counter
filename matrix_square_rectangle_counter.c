#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COLUMN 5

/*
Function name: if_null
Description: Given a matrix, it defines if exists a null data.
Parameters:
    - matrix: A 2D array representing the matrix.
Return:
    - Returns 1 if there's at least one null data, otherwise returns 0.
*/
int if_null(int matrix[ROW][COLUMN]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            if(matrix[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

/*
Function name: search_first_non_null_data
Description: Given a matrix, it searches for the first data that is not null.
Parameters:
    - matrix: A 2D array representing the matrix.
Return:
    - Returns the first non-null data found in the matrix, or 0 if no non-null data is found.
*/
int search_first_non_null_data(int matrix[ROW][COLUMN]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            if(matrix[i][j] != 0){
                return matrix[i][j];
            }
        }
    }
    return 0; // If no non-null value is found.
}

/*
Function name: row_non_zero
Description: Finds the first row containing a non-zero value in the matrix.
Parameters:
    - matrix: A 2D array representing the matrix.
Return:
    - Returns the index of the first row containing a non-zero value, or 0 if no such row is found.
*/
int row_non_zero(int matrix[ROW][COLUMN]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            if(matrix[i][j] != 0){
                return i;
            }
        }
    }
    return 0; // If no non-zero value is found.
}

/*
Function name: column_non_zero
Description: Finds the first column containing a non-zero value in the matrix.
Parameters:
    - matrix: A 2D array representing the matrix.
Return:
    - Returns the index of the first column containing a non-zero value, or 0 if no such column is found.
*/
int column_non_zero(int matrix[ROW][COLUMN]){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            if(matrix[i][j] != 0){
                return j;
            }
        }
    }
    return 0; // If no non-zero value is found.
}

/*
Function name: right
Description: Counts the number of consecutive non-null values to the right of a given position in the matrix.
Parameters:
    - matrix: A 2D array representing the matrix.
    - row: The row index.
    - column: The column index.
    - current_value: The current value at the specified position.
Return:
    - Returns the number of consecutive non-null values to the right.
*/
int right(int matrix[ROW][COLUMN], int row, int column, int current_value){
    int count = 0;
    for(int i = column; i < COLUMN; i++){
        if(matrix[row][i] != current_value){
            return count - 1;
        }
        count++;
    }
    if(count > 0) return count - 1;
    return 0;
}

/*
Function name: down
Description: Counts the number of consecutive non-null values downwards from a given position in the matrix.
Parameters:
    - matrix: A 2D array representing the matrix.
    - row: The row index.
    - column: The column index.
    - current_value: The current value at the specified position.
Return:
    - Returns the number of consecutive non-null values downwards.
*/
int down(int matrix[ROW][COLUMN], int row, int column, int current_value){
    int count = 0;
    for(int i = row; i < ROW; i++){
        if(matrix[i][column] != current_value){
            return count - 1;
        }
        count++;
    }
    if(count > 0) return count - 1;
    return 0;
}

/*
Function name: build
Description: Checks if it's possible to build a square using the consecutive non-null values.
Parameters:
    - matrix: A 2D array representing the matrix.
    - current_row: The starting row index.
    - current_column: The starting column index.
    - end_row: The ending row index.
    - end_column: The ending column index.
    - current_value: The current value to be checked.
Return:
    - Returns 1 if it's possible to build a square, otherwise returns 0.
*/
int build(int matrix[ROW][COLUMN], int current_row, int current_column, int end_row, int end_column, int current_value){
    for(int i = current_row; i <= end_row; i++){
        for(int j = current_column; j <= end_column; j++){
            if(matrix[i][j] != current_value){
                return 0;
            }
        }
    }
    return 1;
}

/*
Function name: construct_figure
Description: Builds a square using the consecutive non-null values.
Parameters:
    - matrix: A 2D array representing the matrix.
    - current_row: The starting row index.
    - current_column: The starting column index.
    - end_row: The ending row index.
    - end_column: The ending column index.
*/
void construct_figure(int matrix[ROW][COLUMN], int current_row, int current_column, int end_row, int end_column){
    for(int i = current_row; i <= end_row; i++){
        for(int j = current_column; j <= end_column; j++){
            matrix[i][j] = 0;
        }
    }
}

/*
Function name: count_numbers
Description: Counts the number of occurrences of a value within a specified region in the matrix.
Parameters:
    - matrix: A 2D array representing the matrix.
    - current_row: The starting row index.
    - current_column: The starting column index.
    - end_row: The ending row index.
    - end_column: The ending column index.
    - value: The value to count.
Return:
    - Returns the count of occurrences of the value.
*/
int count_numbers(int matrix[ROW][COLUMN], int current_row, int current_column, int end_row, int end_column, int value){
    int count = 0;
    if(current_row == end_row && current_column == end_column) return 0;
    for(int i = current_row; i <= end_row; i++){
        for(int j = current_column; j <= end_column; j++){
            if(matrix[i][j] == value){
                count++;
            }
        }
    } 
    return count;    
}

/*
Function name: count_squares
Description: Counts the number of squares that can be formed from the given matrix.
Parameters:
    - matrix: A 2D array representing the matrix.
Return:
    - Returns the count of squares that can be formed.
*/
int count_squares_and_rectangles(int matrix[ROW][COLUMN]){
    int squares = 0;
    while(!if_null(matrix)){
        int current_value = search_first_non_null_data(matrix);
        //printf("The current value of the matrix is %d \n", current_value);
        int current_row = row_non_zero(matrix);
        int current_column = column_non_zero(matrix);
        //printf("The position in the matrix is (%d,%d)\n", current_row, current_column);

        int right_count = right(matrix, current_row, current_column, current_value);
        int down_right_count = down(matrix, current_row, current_column + right_count, current_value);
        int down_count = down(matrix, current_row, current_column, current_value);
        int right_count_2 = right(matrix, current_row + down_count, current_column, current_value);

        if(build(matrix, current_row, current_column, current_row + down_right_count, current_column + right_count, current_value) &&
           build(matrix, current_row, current_column, current_row + down_count, current_column + right_count_2, current_value)){

            if(count_numbers(matrix, current_row, current_column, current_row + down_right_count, current_column + right_count, current_value) >=
               count_numbers(matrix, current_row, current_column, current_row + down_count, current_column + right_count_2, current_value)){
                construct_figure(matrix, current_row, current_column, current_row + down_right_count, current_column + right_count);
                squares++;
            } else {
                construct_figure(matrix, current_row, current_column, current_row + down_count, current_column + right_count_2);
                squares++;
            }
        }

        if(build(matrix, current_row, current_column, current_row + down_right_count, current_column + right_count, current_value)){
            construct_figure(matrix, current_row, current_column, current_row + down_right_count, current_column + right_count);
            squares++;            
        }
        if(build(matrix, current_row, current_column, current_row + down_count, current_column + right_count_2, current_value)){
            construct_figure(matrix, current_row, current_column, current_row + down_count, current_column + right_count_2);
            squares++;            
        }
    }
    return squares;
}

int main(){
    int matrix[3][5] = {{1, 1, 2, 2, 2},
                        {1, 3, 2, 2, 2},
                        {3, 3, 1, 3, 3}};
    int count = count_squares_and_rectangles(matrix);
    printf("\n THE MINIMUM AMOUNT OF SQUARES IS: %d\n", count);
    return 0;
}
