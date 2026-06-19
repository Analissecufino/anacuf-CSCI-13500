#include <iostream>
#include <string>
#include <random>


int main(){
   
    //store user choice to continue here

    char rematch;

    //do while to run at least once and then ask player if they want to play again at the end 

    do{
   
        //tell player the game and give instructions to play
        
        std::cout << "\n\nLet's play Rock Paper Scissors!\n\n";
   
        std::cout << "Best of 3 rounds wins\n\n";
    
        std::cout << "Type in either rock, paper, or scissor when it is your turn\n\n";
  

   
        // start game (declare variables to reset at the beginning of every game)

        int player_score = 0;
        int bot_score = 0;
        std::string player_move = "";
        int bot_move = 0;
        std::string bot_pick = ""; 

        // three rounds in game loop

        for (int rounds = 0; rounds < 3; rounds++){

            // check for early winner. stop game if someone has 2 points 

            if (player_score >= 2 || bot_score >= 2){
                break;
            }

            // display current round number 
        
            std::cout << "-----------------------------------";
            std::cout << "\n\nRound " << rounds+1 << "\n\n";
            std::cout << "-----------------------------------\n\n";

            // ask for user input for their move 

            std::cout << "Choose rock, paper or scissor: ";
            std::cin >> player_move;
       

            //validate input to make sure only player move in lowercase is accepted
            
            while (player_move != "rock" && player_move != "paper" && player_move != "scissor"){
            
                std::cout << "\nInvalid input. Please type either rock, paper, or scissor\n\n";
                std::cin >> player_move;
            }

            // generate random for bot move 
            bot_move = rand() % 3;

            if (bot_move == 0){
                bot_pick = "rock";
            }
            else if (bot_move == 1){
                bot_pick = "paper";
            }
            else{
                bot_pick = "scissor";
            }

            //display user and bot move

            std::cout << "\n\nYou chose: " << player_move << " | Bot chose: " << bot_pick << "\n\n";
       
            // compare moves and update the score. No need to add score when its a tie as nothing changes 

            if (player_move == bot_pick){
                std::cout << "\nIt's a tie! No one gets the point.\n\n";
            
            }
            else if (player_move == "rock" && bot_pick == "scissor"){
                player_score++;
                std::cout << "\nYou won this round!\n\n";
            
            }
            else if (player_move == "paper" && bot_pick == "rock"){
                player_score++;
                std::cout << "\nYou won this round!\n\n";
            }
            else if (player_move == "scissor" && bot_pick == "paper"){
                player_score++;
                std::cout << "\nYou won this round!\n\n";
            }
            else{
                bot_score++;
                std::cout << "\nBot won this round. \n\n";
            }
    
            // display current user and bot score for every round 

            std::cout << "\nYour score is: " << player_score << " | Bot score is: " << bot_score << "\n\n";
        

        }
        // Declare winner or tie and display final score

        if (player_score > bot_score){
            std::cout << "-----------------------------------";
            std::cout << "\n\nPlayer wins! The Player final score is: " << player_score << " | Bot final score is: " << bot_score << "\n\n";
        }
        else if (bot_score > player_score){
            std::cout << "-----------------------------------";
            std::cout << "\n\nBot wins :( The bot final score is: " << bot_score << " | Player final score is: " << player_score << "\n\n";
        }
        else{
            std::cout << "\n\nTie! The Player final score is: " << player_score << " | Bot final score is: " << bot_score << "\n\n";
        }   

        // ask user if they want to play again or quit 

        std::cout << "Would you like a rematch? Type y to continue or q to quit: " << std::endl;
        std::cin >> rematch;

        //validate user input for rematch

        while (rematch != 'y' && rematch != 'q'){
            std::cout << "\n\nInvalid input. Type y to continue or q to quit: ";
            std::cin >> rematch;
        }

        // while condition to continue if user types y 
        
    }while (rematch == 'y');
}