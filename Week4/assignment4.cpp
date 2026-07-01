#include <iostream>
#include <vector>


void removeCopies(std::vector<int>& data){

    // The vector is sorted in non-decreasing order.
    // Remove all duplicate values in-place so that
    // each value appears exactly once.
    //
    // Do not create another vector.
    // Modify the vector named "data" directly.
    //
    // Maybe two-pointer method? Hmm?
    // Hint: resize() function

    // initialize first pointer to 0 to track position of unique element found

    int i = 0;  
    
    // iterate through every index in data vector with scanning pointer 

    for(int j = 0; j < data.size(); j++){
        if(data[j] != data[i]){                          // if current element at data[j] does not match the last unique element stored in data[i], then increment i and overwrite data[i] with data[j] 
        i++;                                             // move i pointer position forward to avoid overwriting unique element 
        data[i] = data[j];                               // assign new unique element from data[j] to new position in data[i]
        }
    }

    // resize takes in a count not an index, so need to add a 1 to include all the data 

    data.resize(i+1);                                    
}

void isAnagram(std::string officer_name, std::string spy_name){

    // Write code to see if the spy name is an anagram of the officer name 
    // Maybe a vector of size 26? Hmm?

    // initialize a vector with space for 26 elements to zero to store the frequency count of each letter in officer name  

    std::vector<int> officer_letters(26,0); 

    // initialize a vector with space for 26 elements to zero to store the frequency count of each letter in spy name  

    std::vector<int> spy_letters(26, 0);
    
    // iterate through every index in the officer name using size()

    for (int i = 0; i < officer_name.size(); i++){
        officer_letters[officer_name[i] - 'a']++;                           // subtract 'a'(97) from every officer letter's ASCII code to map index to 0-25. result is the index to increment for frequency count 
    }

    // iterate through every index in the spy name using size()

    for(int j = 0; j < spy_name.size(); j++){
        spy_letters[spy_name[j] - 'a']++;                                   // subtract 'a'(97) from every spy letter's ASCII code to map index to 0-25. result is the index to increment for frequency count
    }
    
    // check to see if the frequency count match in both vectors, then anagram 

    if(officer_letters == spy_letters){                                       
        std::cout<< "No imposter detected.\n\n";                            
    }

    // if the frequency count doesnt match, send a warning that it is not an anagram

    else{
        std::cout << "Warning: Imposter!\n\n";
    }

}

int main(){

    /*Use other test cases to make sure you program works*/
    std::vector<int> server = {1,1,2,2,2,3,3,4,5,6,6,6};

    /*Print out the original server vector before function called*/
     for (auto data : server){
        std::cout << data << " "; // 1,1,2,2,2,3,3,4,5,6,6,6
    }

    removeCopies(server);
    
    /*Print out the modification of the server vector after function called*/
    for (auto data : server){
        std::cout << data << " ";
    }

    std::cout << std::endl;

    /****************************TEST ANAGRAM*************************************/

    isAnagram("syeda", "aysed"); // No imposter detected!
    isAnagram("angelo", "annabeth"); // IMPOSTER! IMPOSTER!

    return 0;

}
