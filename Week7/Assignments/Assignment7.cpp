#include <iostream>
#include <fstream>
#include <string>
#include <sstream> // necessary for istringstream (formatting details below)

// create new file containing how many times a user chosen word appears and replace that word from the input file with another word the user chooses 
int main() {

    // declare string variables for input file name, search word and replacement word 
    std::string input_filename;
    std::string output_filename;
    std::string search_word;
    std::string replacement_word;

    // ask user for input file, search word, and replacement word 

    // ask for input file name 
    std::cout << "Enter input file name: ";
    std::cin >> input_filename;

    // ask for output file name 
    std::cout << "Enter output file name: ";
    std::cin >> output_filename;

    // ask for search word 
    std::cout << "Enter the word to search for: ";
    std::cin >> search_word;

    // ask for word that will replace the search word 
    std::cout << "Enter a word to replace the word you chose to search: ";
    std::cin >> replacement_word;

    // declare ifstrean and open with input filename
    std::ifstream input_file(input_filename);

    // check if open was successful and display error message if invalid
    if (!input_file.is_open()){
        std::cout << "Input file was not opened successfully.\n";
        return 1; // false nonzero convention 
    }

    // open output file 
    std::ofstream output_file(output_filename);

    // validate open output file and display error message if invalid 
    if (!output_file.is_open()){
        std::cout << "Output file was not opened successfully.\n";
        return 1;
    }

    // initialize word counter to 0 outside loop
    int match_count = 0;

    // declare variable for current line being read 
    std::string current_line;

    // when open input file successful read file one line at a time
    while (std::getline(input_file, current_line)){
        std::istringstream line_reader(current_line);                   // so line can be read word for word to preserve line breaks 
        std::string current_word;

        // every new line then gets read and compared  
        while (line_reader >> current_word){

            // compare current word to search word in input file
            // if match then count matches (increment counter) and replacement word takes over search word 
            if (current_word == search_word){
                match_count++;
                output_file << replacement_word << " ";
            }

            // otherwise, write unmodified current word 
            else{
                output_file << current_word << " ";
            }
        }
        
        // may have extra space before newline. write new line to output file 
        output_file << "\n"; 
    }

    // print match count message in accordance to assignment 7 posted format 
    std::cout << "The word \"" << search_word << "\" was found " << match_count << " times.\n";

    // print confirmation message 
    std::cout << "The modified text has been saved to " << output_filename << "\n";

    // close ifstream and ofstream 
    input_file.close();
    output_file.close(); 

    return 0;
}


