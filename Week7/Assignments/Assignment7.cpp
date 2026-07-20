#include <iostream>
#include <fstream>
#include <string>

// create new file containing how many times a user chosen word appears and replace that word from the input file with another word the user chooses 
int main() {

    //declare string variables for input file name, search word and replacement word 
    std::string input_filename;
    std::string search_word;
    std::string replacement_word;

//ask user for input file, search word, and replacement word 

// ask for input file name 
std::cout << "Enter input file name: ";
std::cin >> input_filename;

// ask for search word 
std::cout << "Enter the word to search for: ";
std::cin >> search_word;

// ask for word that will replace the search word 
std::cout << "Enter a word to replace the word you chose to search: ";
std::cin >> replacement_word;

//open and validate open input file 

//declare ifstrean abd open with input filename
std::ifstream input_file(input_filename);

//check if open was successful 
if input_file.is_open()


// display error message if open not successful 

//when successful read file one word at a time

//initialize word counter to 0 outside loop

// while getline loop 

    // compare search word to word in input file
    //count matches (increment counter)
    // replacement word takes over search word 


}


