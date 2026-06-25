#include <iostream> 

int main(){

    // ------------------

    //      TASK 1 

    // ------------------


    //initializing 3x3 array
    
    int array_first [3][3] = {0};

    // initializing 6x6 array 

    int array_second [6][6] = {0};

    // setting up for loop for diagonal 1 fill in when size is 3x3. size will be manipulated throughout the tasks

    int size = 3;

    for(int i = 0; i < size; i++){                 //outer loop running based on row index of first array 
        for(int j = 0; j < size; j++){             // inner loop running based on col index of first array 
            if(j <=(size-1)-i){                    // every time we move through a row, the max output of 1's(max fill in up to col index 2) is subtracted by the current row index and that value is placed in the current column space
                array_first[i][j]= 1;              // if condition is met fill 1 in the current i x j space 
            }
            else{                                  // if the column index is bigger than 2(max col index) subtracted by the current row index then fill i x j space with a 0. 
                array_first[i][j]= 0;
            }
        }
    }

    // print out Task 1 execution message

    std::cout << "\nExecuting Task 1\n\n";

    //print out array 

    // for loop to run through every space in the array and print every element 
    
    for(int i = 0; i < size; i++){
        std::cout << "[";
        for(int j=0; j < size; j++){
            std::cout << array_first[i][j];
            if( j < size-1){
                std::cout << "|";
            }
        }
        std::cout << "]\n";
    }

    std::cout << "\n";

    // setting up for loop for diagonal 1 fill in when size is 6x6 

    size= 6;

    for(int i = 0; i < size; i++){                 //outer loop running based on row index of first array 
        for(int j = 0; j < size; j++){             // inner loop running based on col index of first array 
            if(j <=(size-1)-i){                    // every time we move through a row, the output of 1's(max fill in up to col index 5) is subtracted by the current row index and placed in the current column space
                array_second[i][j]= 1;             // if condition is met fill 1 in the current ixj space 
            }
            else{                                  // if current column index is bigger than 5(max col index) minus current row index then fill ixj space with a 0. 
                array_second[i][j]= 0;
            }
        }
    }

    //print out array using for loop to run through every element in the array and print every element 
    
    for(int i = 0; i < size; i++){
        std::cout << "[";
        for(int j=0; j < size; j++){
            std::cout << array_second[i][j];
            if(j < size-1){
                std::cout << "|";
            }
        }
    std::cout << "]\n";
    }

    std:: cout << "\n";


    // ---------------------

    //      Task 2 

    // ---------------------


    //resetting 3x3 array values to 0 

    for( int i = 0; i < 3; i ++){
        for(int j =0; j < 3; j++){
            array_first[i][j]= 0;
        }
    }

    // resetting 6x6 array values to 0 

    for( int i = 0; i < 6; i ++){
        for(int j =0; j < 6; j++){
            array_second[i][j]= 0;
        }
    }

    //for loop to create X shape filled in by 1's 

    size = 3;

    for(int i = 0; i < size; i++){                  // outer loop iteration runs according to row size 
        for(int j = 0; j < size; j++){              //inner loop iteration runs according to col size 
            if(i==j || i+j == size -1){             // condiition is fill in i x j spot with 1 where the row index = the column index or if adding both indexes equals the size subtracted by 1 (main diagonal formula and anti-diagonal formula)
                array_first[i][j] = 1;
            }
            else{                                   //otherwise fill in the i x j space with a 0 
                array_first[i][j] = 0;
            }
        }
    }

    // print task 2 execution message 

    std::cout << "Executing Task 2\n\n";

    // print out 3x3 array where 1's form an X shape 

    for(int i = 0; i < size; i++){
        std::cout << "[";
        for(int j = 0; j < size; j++){
            std::cout << array_first[i][j];
            if( j < (size-1)){
                std::cout << "|";
            }
        }
        std::cout << "]\n";
    }
    std::cout << "\n";

    // test with 6x6 matrix

 size = 6;

    // same for loop logic as above 

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == j || i + j == size -1){
                array_second[i][j] = 1;
            }
            else{
                array_second[i][j] = 0;
            }
        }
    }

    // print 6x6 array where 1's form an X

    for(int i = 0; i < size; i++){
        std::cout << "[";
        for(int j = 0; j < size; j++){
            std::cout << array_second[i][j];
            if(j < size-1){
                std::cout << "|";
            }
        }
        std::cout << "]\n";
    }
 
    std::cout << "\n";


    // -------------------
 
    //        TASK 3

    // -------------------

    // declaring a third array that will be 3x3 randomly filled with nonzeros to test 

    int array_third[3][3]={
        {2,4,6}, 
        {1,3,2}, 
        {4,3,3}
    };

    //declare variable to hold final output of row sums and column sums 

    int result_arr[2][3]= {0};

    // compute row sums first

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result_arr[0][i] += array_third[i][j];          //i is the index here because each row contains one sum derived from adding every element in that row . all the row sums will get placed in first row[0]  
        }
    }

    // compute column sums second

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result_arr[1][j] += array_third[i][j];          //starting off in index 1 (row 2) because we already filled the first row space with row sums. each j (col) will have one sum derived from adding the column elements 
        }
    }

    //print task 3 execution message 

    std::cout << "Executing Task 3\n\n";

    //print row sums first using for loop

    std::cout << "[";

    for(int i= 0; i < 3; i++){                              // run through all three columns 
        std::cout << result_arr[0][i];                      // stay in row 1 (index 0) and supplement col values with the row sums 
        if(i < 2){
            std::cout << "|";
        }
    }
    
    std::cout << "]";

    std::cout << "\n";

    //print column sums second 
    
    std::cout << "[";

    for(int i = 0; i < 3; i++){                             
        std::cout << result_arr[1][i];            //stay in second row and supplement elements with column sums 
        if(i < 2){
            std::cout << "|";
        }
    }

    std::cout << "]";

    std::cout << "\n\n";

    // -----------------

    //      TASK 4

    // -----------------

    // test with previous 3x3 array from task 3, initialize size variable, d1(main digonal), d2(anti-diagonal), c(center element), total sum (x_sum)

    size = 3;
    int d1 = 0;
    int d2 = 0;
    int c = array_third[size/2][size/2];          // center element found in the middle. take the total rows and divide in half. take the total columns and divide in half
    int x_sum = 0;

    for(int i = 0; i < size; i++){
        d1 += array_third[i][i];                  // d1 = main diagonal found when i and j have same value. we add all those values together here to create the main diagonal sum
        d2 += array_third[i][(size-1)-i];         // d2 = anti-diagonal formula used to add sums
    }

    // total X sum 

    x_sum = d1 + d2 - c;                          // regular addition here of the main diagonal sum and anti-diagonal sum, but subtract the center element since it has already been taken into account with the other sums
    
    //print Task 4 execution message 

    std::cout << "Executing Task 4\n\n";

    //print total X sum 

    std::cout << d1 << " + " << d2 << " - " << c << " = " << x_sum << "\n\n";

    

}