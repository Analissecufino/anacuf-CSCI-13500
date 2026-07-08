#include <iostream>
#include <string>
#include <random>


//function to tell player about the game and give instructions on how to play

void DisplayWelcomeMessage(){
        
    std::cout << "\n\nLet's play Rock Paper Scissors!\n\n";
   
    std::cout << "Best of 3 rounds wins\n\n";
    
    std::cout << "Type in either rock, paper, or scissor when it is your turn\n\n";
}

// function to display current round count 

void DisplayRoundCount(int round_number){

    std::cout << "-----------------------------------";

    std::cout << "\n\nRound " << round_number << "\n\n";
    
    std::cout << "-----------------------------------\n\n";
}

// function to get player move

std::string GetPlayerMove(){

    std::string player_move;

    std::cout << "Choose rock, paper, or scissor: ";

    std::cin >> player_move;

    // validate player move input 

    while (player_move != "rock" && player_move != "paper" && player_move != "scissor"){
        std::cout << "\nInvalid input. Please type either rock, paper, or scissor\n\n";
        std::cin >> player_move;
    }

    return player_move;
}

// function to get bot move 

std::string GetBotMove(){

    // generate random number for bot move 
    
    int bot_move = rand() % 3;

    if (bot_move == 0){
        return "rock";
    }

    else if (bot_move == 1){
        return "paper";
    }

    else{
        return "scissor";
    }

}

// function to decide round winner or declare tie 

std::string DecideRoundWinner(std::string player_move, std::string bot_move){

    // when player and bot have the same move it is declared as a tie. declare first to avoid more statements to define when bot wins

    if(player_move == bot_move){
        return "Tie";
    }

    // implementing scoring standard for rock paper scissors 

    else if (player_move == "rock" && bot_move == "scissor"){
        return "You";
    }

    else if (player_move == "paper" && bot_move == "rock"){
        return "You";             
    }

    else if (player_move == "scissor" && bot_move == "paper"){
        return "You";             
    }

    else{
        return "Bot";
    }
}

// function to calculate score after each round. int& reference score variables in main to increment 

void UpdateScore(std::string round_winner, int& player_score, int& bot_score){
    
    // when player wins a round they get a +1 point 

    if(round_winner == "You"){
        player_score++;
    }

    // when bot wins a round it gets a +1 point 

    else if(round_winner == "Bot"){
        bot_score++;
    }
}

// function to display round summary (moves, round winner or tie, score after round)

void DisplayRoundSummary(std::string player_move, std::string bot_move, int player_score, int bot_score, std::string round_winner){

    // display player and bot move choice 

    std::cout << "\n\nYou chose: " << player_move << " | Bot chose: " << bot_move << "\n\n"; 

    // Round result messages displayed, decided through if statements 

    if(round_winner == "Tie"){
        std::cout << "\nIt's a tie! No one gets the point.\n\n";
    }
    

    else if(round_winner == "You"){
        std::cout << "\nYou won this round!\n\n";
    }

    else{
        std::cout << "\nBot won this round. \n\n";
    }

    // display current round score 

    std::cout << "\nYour score is: " << player_score << " | Bot score is: " << bot_score << "\n\n";
        
}

// function to display final winner or tie 

void DisplayFinalScore(int player_score, int bot_score){

    // we are comparing the scores at the end of the for loop to declare a winner or tie 

    if(player_score > bot_score){
        std::cout << "-----------------------------------";
        std::cout << "\n\nPlayer wins! The Player final score is: " << player_score << " | Bot final score is: " << bot_score << "\n\n";
    }

    else if(bot_score > player_score){
        std::cout << "-----------------------------------";
        std::cout << "\n\nBot wins :( The bot final score is: " << bot_score << " | Player final score is: " << player_score << "\n\n";
    }

    else{
        std::cout << "-----------------------------------";
        std::cout << "\n\nTie! The Player final score is: " << player_score << " | Bot final score is: " << bot_score << "\n\n";      
    }
}

// function to ask for rematch

char AskForRematch(){
    char rematch;
    
    // ask user if they want to play again or quit 

    std::cout << "Would you like a rematch? Type y to continue or q to quit: " << std::endl;
    std::cin >> rematch;

    //validate user input for rematch

    while (rematch != 'y' && rematch != 'q'){

        std::cout << "\n\nInvalid input. Type y to continue or q to quit: ";
        std::cin >> rematch;
    }

    return rematch;
}
        

int main(){
   
    //store user choice to play again or not here

    char rematch;

    //do while to run at least once and then ask player if they want to play again at the end 

    do{
        // call DisplayWelcomeMessage to print instructions 

        DisplayWelcomeMessage();

        // start game (declare variables to reset at the beginning of every game)

        int player_score = 0;
        int bot_score = 0;
    
        // three rounds in game loop

        for (int rounds = 0; rounds < 3; rounds++){

            // check for early winner. stop game if someone has 2 points. decided to leave as is instead of in function 

            if (player_score >= 2 || bot_score >= 2){
                break;
            }

            // call DisplayRoundCount to print current round number 

            DisplayRoundCount(rounds + 1);
        
            // call GetPlayerMove to get player move and validate it 

            std::string player_move = GetPlayerMove();

            // call GetBotMove to generate random bot move 

            std::string bot_move = GetBotMove();

            // call DecideRoundWinner to find out who won the round 

            std::string round_winner = DecideRoundWinner(player_move, bot_move);

            // call UpdateScore to calculate current player score and bot score 
            
            UpdateScore(round_winner, player_score, bot_score);

            // call DisplayRoundSummary to print players current move, round status, and score for every round 

            DisplayRoundSummary(player_move, bot_move, player_score, bot_score, round_winner);
        }

        // call DisplayFinalScore to declare winner and final score 

        DisplayFinalScore(player_score, bot_score);  
      
        // call AskForRematch to ask user for rematch

        rematch = AskForRematch();    
    }

    // do while loop to continue if user types y 

    while (rematch == 'y');
}




