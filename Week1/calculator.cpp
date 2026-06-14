#include <iostream>

int main(){
    // setting up variables as int so that input from user is compatible with modulo operator
   
    int First_number;
    int Second_number;

    // assigning char data type to operation variable to be able to accept operator symbols 
   
    char operation; 

    // assigning int data type to answer variable because we are only working with integers in this calc 
    
    int calculator_answer;

    // asking user for the first number to input 

    std::cout<< "Enter first number: " << std::endl;
    std::cin>> First_number;

    //asking user for the second number to input

    std::cout << "Enter second number: " << std::endl;
    std::cin >> Second_number;

    //asking user to choose operation to perform on the two numbers

    std::cout << "Choose operation (+, -, *, %, /): " <<std::endl;
    std::cin >> operation;

    //this while loop will check for invalid input and will keep asking for input until it is valid 

    while( operation != '+' && operation != '-' && operation != '*' &&
    operation != '%' && operation != '/') {
        std::cout << "Please try again by typing one of the following operators: +, -, *, %, /" << std::endl;
        std::cin >> operation;
    }

    // this if statement handles modulo by zero and division by zero cases and outputs an error message and will ask for another number 

    if ((operation == '%' || operation == '/') && Second_number == 0){
        while (Second_number == 0){
            std::cout << "Error: cannot modulo or divide by zero. Please enter another second number: " << std::endl;

            std::cin >> Second_number;
        }
    }

//here is where the actual arithmetic will be performed. each case corresponds with a specific operation to be performed on the two input numbers

 switch (operation){

    case '+':
        calculator_answer = First_number + Second_number;
        break;
    
    case '-':
        calculator_answer = First_number - Second_number;
        break;
    
    case '*':
        calculator_answer = First_number * Second_number;
        break;
    
    case '%':
        calculator_answer = First_number % Second_number;
        break;
    
    case '/':
        calculator_answer = First_number / Second_number;
        break;

 } 

 // this will display the answer after numbers and operations have been input 
 std::cout << "The answer is: " << calculator_answer << std::endl;

 return 0;

}