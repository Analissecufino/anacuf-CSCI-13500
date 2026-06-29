#include <iostream>

// Reminder: Information about functions is on the specification PDF

void Print2DArray(const int matrix_local[][3], const int matrix_local_rows_total, const int matrix_local_col_total){

    // Function start message to terminal

    std::cout << "\n--------------------\nFunction called: \n\nPrint2DArray \n--------------------\n\n";

    // Body of the function. Do your magic!

    // for loop to traverse through every row x col element 

    for (int i = 0; i < matrix_local_rows_total; i++){
        
        // bracket format will execute before loop is complete and one more time after to create the [ x ] format 
       
        std::cout << "[";
        for (int j = 0; j < matrix_local_col_total; j++){
            std::cout << matrix_local[i][j];                    // prints one element in the array at a time
            if (j < (matrix_local_col_total - 1)){
                std::cout << "|";                               // after printing an element, if it is an element not in the last column it will print a | after it 
            }
        } 
        std::cout << "]\n";
    }
    
    std::cout << "\n";

    // Function end message to terminal

    std::cout << "\n--------------------\nEnd of function: \n\nPrint2DArray \n--------------------\n\n";

}

// print function without the start and end messages for readability when run through other functions

void PrintMatrix(const int matrix_local[][3], const int matrix_local_rows_total, const int matrix_local_col_total){

    // for loop to traverse through every row x col element 

    for (int i = 0; i < matrix_local_rows_total; i++){
        
        // bracket format will execute before loop is complete and one more time after to create the [ x ] format 
       
        std::cout << "[";
        for (int j = 0; j < matrix_local_col_total; j++){
            std::cout << matrix_local[i][j];                    // prints one element in the array at a time
            if (j < (matrix_local_col_total - 1)){
                std::cout << "|";                               // after printing an element, if it is in col 0 or 1 it will print a | after it 
            }
        } 
        std::cout << "]\n";
    }
    
    std::cout << "\n";

}

void MatrixAddition(const int matrix_one[][3], const int matrix_one_rows_total,
                    const int matrix_two[][3], const int matrix_two_rows_total){
        
        //Function start message to terminal 

        std::cout << "--------------------\nFunction called: \n\nMatrixAddition \n--------------------\n\n"; 

        //body of function 

        //declaring result of addition operation on both matrices holds sum. index interchangable since both equal 3 and same dimensions required to perform operation 

        int result[matrix_one_rows_total][3];

        //for loop to go through the total rows of both arrays 

        for(int i = 0; i < matrix_one_rows_total; i++){
            for( int j = 0; j < 3; j++){
                result[i][j] = matrix_one[i][j] + matrix_two[i][j];                     //result will hold the sum of every matrix element. an element being added to an element in another array will have the same position so can be added directly
            }
        }

        //call print function to print matrices being added and the final result 

        std::cout << "Matrix one: \n\n";

        PrintMatrix(matrix_one, 3,3);

        std::cout << " +\n\nMatrix two: \n\n";

        PrintMatrix(matrix_two, 3, 3);

        std::cout << " = \n\n";

        PrintMatrix(result, matrix_one_rows_total, 3);


        //function end message to terminal 

        std::cout << "\n--------------------\nEnd of function:  \n\nMatrixAddition \n--------------------\n\n";

    }

void TransposeMatrix(const int matrix_local[][3], const int matrix_local_rows_total){
   
    // Function start message to terminal

    std::cout << "--------------------\nFunction called: \n\nTransposeMatrix\n--------------------\n\n";

    // body of the function 

    //transposed matrix declared 

    int matrix_local_transpose[3][3];

    // if the dimension of the resulting matrix doesn't match the print function, you could do it manually here
    // or modify the parameter of the print function so it doesn't cause errors

    for(int i = 0; i < matrix_local_rows_total; i++){                       // the time complexity here is simple since the i loop goes to n and the j loop is a constant. this would result in O(n).
        for(int j = 0; j < 3; j++){
            matrix_local_transpose[i][j] = matrix_local[j][i];              // simple swap of row i element and col j element will make a transposed matrix 
        }
    }

     // display resulting matrix

     std::cout << "Origin matrix: \n\n";

     PrintMatrix(matrix_local, 3, 3);                                      // printmatrix function is also a simple O(n) since the outer loop increases with the rows but the inner loops is a constant. 
                                                                         
     std::cout << "Transposed matrix: \n\n";

     PrintMatrix(matrix_local_transpose, 3,3);
    
    // Function end message to terminal 

    std::cout << "\n--------------------\nEnd of function: \n\nTransposeMatrix \n--------------------\n\n";
}

void Determinant(const int matrix_local[][3], const int size){
    
    // Function start message to terminal

    std::cout << "--------------------\nFunction called: \n\nDeterminant\n--------------------\n\n";
    
    // initialize answer to get determinant later 

    int answer = 0; 

    // check for valid dimensions (2x2 or 3x3) 
    // dimensions require different formulas 
    if(size == 2){

        answer = (matrix_local[0][0] * matrix_local[1][1]) - (matrix_local[0][1] * matrix_local[1][0]); // determinant formula for 2x2 = ad - bc
        
    }
    else if(size == 3){
                                                                                                                                  // formula for 3x3 det from geeksforgeeks
        answer = (matrix_local[0][0] * ((matrix_local[1][1] * matrix_local[2][2]) - (matrix_local[1][2] * matrix_local[2][1]))) - // a(ei - fh) - 
                 (matrix_local[0][1] * ((matrix_local[1][0] * matrix_local[2][2]) - (matrix_local[2][0] * matrix_local[1][2]))) + // b(di - gf) +
                 (matrix_local[0][2] * ((matrix_local[1][0] * matrix_local[2][1]) - (matrix_local[1][1] * matrix_local[2][0])));  // c(dh -eg)
        
    }

    // exits function early if nothing found 

    else{

        std::cout << "Invalid dimensions. Must be a 2x2 or a 3x3 matrix\n\n";
        return;
    }

    // print the determinant value on the terminal

    std::cout << "Origin matrix: \n\n";

    PrintMatrix(matrix_local, size, size);

    std:: cout << "The det is: " << answer <<"\n";


    // Function end message to terminal

    std::cout << "\n--------------------\nEnd of function: \n\nDeterminant \n--------------------\n\n";
}

void SearchValue(const int matrix_local[][3], const int rows, const int target){
   
    // Function start message to terminal 

    std::cout << "--------------------\nFunction called: \n\nSearchValue \n--------------------\n\n";

    // body of the function
        // found  or not 

        // tracks if value found or not 
    bool found = false;
    
    // will check every element in matrix

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < 3; j++){
            if(matrix_local[i][j] == target){
                found = true;
                std::cout << "The target " << target << " was found in row [" << i << "] and column [" << j << "]\n";
            }
        }
    }

    if(found == false){
    std::cout << "Target was not found in the matrix.\n\n";
    }
    
    // Function end message to terminal

    std::cout << "\n--------------------\nEnd of function: \n\nSearchValue \n--------------------\n\n";
}

void MatrixMultiplication(const int matrix_a[][3], const int matrix_b[][3], 
                    const int rows_a, const int cols_a, 
                    const int rows_b, const int cols_b){
    
    // Function start message to terminal

    std::cout << "--------------------\nFunction called: \n\nMatrixMultplication \n--------------------\n\n";
    
    int result[3][3];
    int sum = 0;

    // check for valid arrays

    if(cols_a == rows_b){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
            sum = 0;                                                // sum needs to be reset before collecting new result of dot product
            for(int k = 0; k < cols_a; k++){                        // iterates through shared dimension (cols_a) to collect dot product ex) a11 * b11
                sum += matrix_a[i][k] * matrix_b[k][j];
            }

            result[i][j] = sum;                                     // new dot product stored in current position
            }
        }

         // Print resulting matrix
         std::cout << "Matrix one: \n\n";

        PrintMatrix(matrix_a, 3, 3);

        std::cout << " * \n\nMatrix two: \n\n";

        PrintMatrix(matrix_b, 3, 3);

        std::cout << " = \n\n";

        PrintMatrix(result, rows_a, cols_b);
    }

    else{
        std::cout << "Invalid dimensions.\n";

    }

    // Function end message to terminal

    std::cout << "\n--------------------\nEnd of function: \n\nMatrixMultiplication \n--------------------\n\n";
}

int main(){
    // Use these two matrices for basic testing.

    int testing_matrix_one[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    int testing_matrix_two[3][3] = {
        {12,65,82},
        {83,2,8},
        {10,96,67}
    };
  
    // getting active row count of matrix one 

    int matrix_one_row_count =
        sizeof(testing_matrix_one)/sizeof(testing_matrix_one[0]);

    // getting active row count of matrix two 

    int matrix_two_row_count =
        sizeof(testing_matrix_two)/sizeof(testing_matrix_two[0]);

// calling Print2DArray function to test 

Print2DArray(testing_matrix_two, 3,3);

// calling MatrixAddition function to test

MatrixAddition(testing_matrix_one, matrix_one_row_count,
testing_matrix_two, matrix_two_row_count);

// calling transposematrix function to test

TransposeMatrix(testing_matrix_one, matrix_one_row_count);

// calling determinant function to test

Determinant(testing_matrix_one, 3);

// calling searchvalue function to test

SearchValue(testing_matrix_one, matrix_one_row_count, 3);

// calling matrixmultiplication function to test

MatrixMultiplication(testing_matrix_one, testing_matrix_two, matrix_one_row_count, 3, matrix_two_row_count, 3);

}

