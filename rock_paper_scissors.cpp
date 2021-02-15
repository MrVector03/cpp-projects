#include <iostream>
#include <random>
using namespace std;

/*
This function decides who won a round 

- rock (1) beats scissors (3)
- paper (2) beats rock (1)
- scissors (3) beats paper (2)

*/
string judge(int user_turn, int bot_turn){
    if (user_turn == bot_turn){
        return "draw";
    } else if (user_turn == 1 && bot_turn == 2){
        return "bot";
    } else if (user_turn == 1 && bot_turn == 3){
        return "user";
    } else if (user_turn == 2 && bot_turn == 1){
        return "user";
    } else if (user_turn == 2 && bot_turn == 3){
        return "bot";
    } else if (user_turn == 3 && bot_turn == 1){
        return "bot";
    } else if (user_turn == 3 && bot_turn == 2){
        return "user";
    }
}


int main(){
    string decision;
    int user_score;
    int bot_score;
    cout << "Menu:" << endl << "1. Start playing => 'play'" << endl << "2. Finish playing => 'end'" << endl;
    cout << "Query: ";
    cin >> decision;
    cout << endl;
    while(decision != "exit" || decision != "2" || decision != "end" || decision != "no" || decision != "n"){
        
        // Taking input from user as one or multiple rounds are played (Game ends when user decides)
        if (decision == "play"){
            user_score = 0;
            bot_score = 0;

            cout << "Enter 'rock' (or '1'), 'paper' (or '2') and  'scissors' (or '3')" << endl; 
            cout << "Enter 'end' in 'Your turn: ' tab when you want to finish the game" << endl;
            string query;
            int user_turn;
            int bot_turn;
            
            // User inputs their choice, bot choice gets generated
            // jugde() function decides who won
            while(query != "end"){
                // The while loop below is created just in case user miswrites the input
                while(true){
                    cout << "Your turn: ";
                    cin >> query;
                    if (query == "rock" || query == "1"){
                        user_turn = 1;
                        break;
                    } else if (query == "paper" || query == "2"){
                        user_turn = 2;
                        break;
                    } else if (query == "scissors" || query == "3"){
                        user_turn = 3;
                        break;
                    } else if (query == "end"){
                        break;
                    } else {
                        cout << "Unrecognised input, try again." << endl << endl;
                    }
                }
                bot_turn = (rand() % 3) + 1;
                if (query == "end"){
                    break;
                }

                // judge() function brings the final decision
                if (judge(user_turn, bot_turn) == "user"){
                    cout << "You won the round" << endl;
                    user_score++;
                } else if (judge(user_turn, bot_turn) == "bot"){
                    cout << "You lost the round" << endl;
                    bot_score++;
                } else if (judge(user_turn, bot_turn) == "draw"){
                    cout << "Draw" << endl;
                }
            }

            // Game results and other info displayed for more interesting user experience
            cout << endl << "Game results:" << endl << endl;
            cout << "User: " << user_score << endl << "Opponent: " << bot_score << endl;
            if (user_score > bot_score){
                cout << endl << "You won. Congratulations!" << endl;
            } else if (user_score < bot_score){
                cout << endl << "You lost. Better luck next time." << endl;
            } else if (user_score == bot_score){
                cout << endl << "Draw!" << endl;
            }
            
            // Query repeats and asks user whether more matches are going to be played or not
            cout << endl << "Menu:" << endl << "1. Start playing => 'play'" << endl << "2. Finish playing => 'end'" << endl;
            cout << "Query: ";
            cin >> decision;
            cout << endl;
        } else {
            cout << "Thank you for playing!" << endl << endl; 
            break;
        }
    }
}
