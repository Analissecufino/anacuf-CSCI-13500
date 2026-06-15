#include <iostream>
#include <string>
#include <iomanip>
int main() {

// Instructions for user on steps of GPA calculator
std::cout << "This is a GPA calculator." << std::endl; 
std::cout << std::endl;
std::cout << "This program will calculate your semester GPA based on the number of credits and letter grade you received for each class." << std::endl;
std::cout << std::endl;
std::cout << "You will be prompted to enter the number of credits for a class and the letter grade you received for that class." << std::endl;
std::cout << std::endl;
std::cout << "After you have entered the information for a class, you will be asked if you would like to enter another class." << std::endl;
std::cout << std::endl;
std::cout << "Once you have entered all of your classes, the program will output the number of classes you took and your semester GPA." << std::endl;
std::cout << std::endl;

//initialize and assign data types for variables to be used in loop and GPA calculation

double totalGradePoints = 0;
int totalCredits = 0;
int classCount = 0;
char decision;

//loop that runs at least once to commit to at least one entry before asking user to continue
do {
    //ask user for number of credits for a class to add to total credits later for GPA calculation 
    
    int credits;
    std::cout << "Enter number of credits for class:" << std::endl;
    std::cin >> credits;

    //validate range of credits before proceeding with rest of loop
    //does not handle non numerical input 

    while (credits <= 0 || credits >= 10){
        std::cout << std::endl;
        std::cout << "Invalid input. Please enter a valid number of credits (1-9): " << std::endl;
        std::cin >> credits;
    }
    
    //ask user for letter grade achieved in class before being able to convert to numerical value for GPA calculation

    std::string letterGrade;
    std::cout << std::endl;
    std::cout << "Enter letter grade for class (A+, A, A-, B+, B, B-, C+, C, D, F, WU, FIN, FAB): " << std::endl;
    std::cin >> letterGrade;
    
    //validate grade input (case insensitive) before converting letter grade to grade point value
    while (letterGrade != "A+" && letterGrade != "a+" && letterGrade != "A" && letterGrade != "a" && letterGrade != "A-" && letterGrade != "a-" && letterGrade != "B+" && letterGrade != "b+" && letterGrade != "B" && letterGrade != "b" && letterGrade != "B-" && letterGrade != "b-" && letterGrade != "C+" && letterGrade != "c+" && letterGrade != "C" && letterGrade != "c" && letterGrade != "D" && letterGrade != "d" && letterGrade != "F" && letterGrade != "f" && letterGrade != "WU" && letterGrade != "wu" && letterGrade != "FIN" && letterGrade != "fin" && letterGrade != "FAB" && letterGrade != "fab"){
        std::cout << std::endl;
        std::cout << "Invalid input. Please enter a valid letter grade (not case sensitive): " << std::endl;
        std::cin >> letterGrade;
    }

    //introduce variable to hold letter grade value after conversion 

    double letterGradeValue;

    //convert letter grade to Hunter's GPA scale 
    if (letterGrade == "A+" || letterGrade == "a+" || letterGrade == "A" || letterGrade == "a"){
        letterGradeValue = 4.0;
    }

    else if (letterGrade == "A-" || letterGrade == "a-"){
        letterGradeValue = 3.7;
    }

    else if (letterGrade == "B+" || letterGrade == "b+"){
        letterGradeValue = 3.3;
    }

    else if (letterGrade == "B" || letterGrade == "b"){
        letterGradeValue = 3.0;
    }

    else if (letterGrade == "B-" || letterGrade == "b-"){
        letterGradeValue = 2.7;
    }

    else if (letterGrade == "C+" || letterGrade == "c+"){
        letterGradeValue = 2.3;
    }

    else if (letterGrade == "C" || letterGrade == "c"){
        letterGradeValue = 2.0;
    }

    else if (letterGrade == "D" || letterGrade == "d"){
        letterGradeValue = 1.0;
    }

    else if (letterGrade == "F" || letterGrade == "f" || letterGrade == "WU" || letterGrade == "wu" || letterGrade == "FIN" || letterGrade == "fin" || letterGrade == "FAB" || letterGrade == "fab"){
        letterGradeValue = 0.0;
    }

    //multiply credit for a class by letter grade value and add to total grade points
   
    totalGradePoints += credits * letterGradeValue;
   
    // update total credits by adding credits for class to total credits
   
    totalCredits += credits;

    //update valid class entry  
    classCount++;

    //ask user if they would like to continue
    std::cout << std::endl;
    std::cout << "Would you like to enter another class? Enter Y for yes or N for no: " << std::endl;
    std::cin >> decision;

    //validate user input for decision to proceed or end loop

    while (decision != 'Y' && decision != 'y' && decision != 'N' && decision != 'n'){
        std::cout << "Invalid input. Please enter Y or y for yes or N or n for no: " << std::endl;
        std::cin >> decision;
    }

    //check condition here: while user enters y continue if n quit loop

    }while (decision == 'Y' || decision == 'y');
    
    //after loop ends, calculate GPA by dividing total grade points by total credits
    
    double GPA = totalGradePoints / totalCredits;


    //output classes taken based on how many increments of classCount

    std::cout << "Classes taken: " << classCount << std::endl;

    std::cout << std::endl;

    // output semester GPA with the precision set to 2 decimal places to round to the hundredths. 
    std::cout << "Semester GPA: " << std::fixed << std::setprecision(2) << GPA << std::endl;

    return 0;
}


