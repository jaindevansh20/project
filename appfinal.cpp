#include <iostream>
#include <cstdlib> // For using rand() and srand() function 
#include <ctime>   // For time()

using namespace std;

int main() {
    int choice;
    cout << "Enter choice " << endl;
    cout << "1. Rock Paper Scissors\n";
    cout << "2. Seven Up Seven Down\n";
    cout << "3. Secret Number (Guess the number)\n";
    cout << "0. Exit\n"; 
    cin >> choice;

    switch (choice) {
        case 1: {
         
            int userChoice, computerChoice;
            char continueGame;

            do {
                cout << "Lets play Rock, Paper, Scissors Game! " << endl;
                cout << "Choose an option: Which game you want to play" << endl;
                cout << "1. Rock" << endl;
                cout << "2. Paper" << endl;
                cout << "3. Scissors" << endl;
                cout << "Enter your choice (1-3): ";
                cin >> userChoice;

                
            
                computerChoice = rand() % 3 + 1;       //computer generates random number using random function

                cout << "You chose: \n ";
                switch (userChoice) 
				{
                    case 1: cout << "Rock" << endl; break;
                    case 2: cout << "Paper" << endl; break;
                    case 3: cout << "Scissors" << endl; break;
                    default: cout << "Invalid choice!" << endl; continue;
                }

                cout << "Computer chose: ";
                switch (computerChoice) 
				{
                    case 1: cout << "Rock" << endl; break;
                    case 2: cout << "Paper" << endl; break;
                    case 3: cout << "Scissors" << endl; break;
                }

               
                if (userChoice == computerChoice) 
				{
                    cout << "It's a tie!" << endl;
                } 
				else if ((userChoice == 1 && computerChoice == 3) ||
                           (userChoice == 2 && computerChoice == 1) ||
                           (userChoice == 3 && computerChoice == 2)) 
						   {
                    cout << "You win! The game " << endl;
                }
				 else {
                    cout << "Computer wins!" << endl;
                }

                                                          // Asking   if the user wants to continue
                                       
                cout << "Do you want to play again? (y/n): ";
                cin >> continueGame;

            } while (continueGame == 'y' || continueGame == 'Y');

            cout << "Thanks for playing!" << endl;
            break;
        }

        case 2: {
                  // generation random number 
            char playAgain;

            do {
                char userBet;
                cout << "Bet on the outcome (Enter 'u' for 7 Up or 'd' for 7 Down): ";
                cin >> userBet;

                int die1 = rand() % 6 + 1;         // Roll the first die
                int die2 = rand() % 6 + 1;        // Roll the second die
                int sum = die1 + die2;           // Calculate the sum

                cout << "You rolled a " << die1 << " and a " << die2 << endl;
                cout << "The sum is: " << sum << endl;

                                                                     // Determine if the user won or lost
                if ((userBet == 'u' || userBet == 'U') && sum == 7) {
                    cout << "Congratulations! You got 7 Up!" << endl;
                } else if ((userBet == 'd' || userBet == 'D') && sum != 7) {
                    cout << "Congratulations! You got 7 Down!" << endl;
                } else {
                    cout << "Sorry, you did not win." << endl;
                }

                                                                  // Ask if the user wants to play again
                cout << "Do you want to play again? (y/n): ";
                cin >> playAgain;

            } while (playAgain == 'y' || playAgain == 'Y');

            cout << "Thanks for playing!" << endl;
            break;
        }

        case 3: {
            cout << "\n     !!!   Welcome to Guess The Number game   !!!  \n\n";
            cout << "   You have to guess a number between 1 and 100. \n";
            cout << "You'll have limited choices based on the level you choose. Good Luck!" << endl;

            while (true) {
                cout << "\nEnter the difficulty level: \n\n";
                cout << "1 for easy!\n";
                cout << "2 for medium!\n";
                cout << "3 for difficult!\n";
                cout << "0 for ending the game!\n" << endl;

                int difficultyChoice;
                cout << "Enter the number: ";
                cin >> difficultyChoice;

                if (difficultyChoice == 0) {
                    cout << "Thanks for playing!" << endl;
                    return 0; // Exit the program
                }

           
                int secretNumber = 1 + (rand() % 100);
                int playerChoice;

                int choicesLeft;
                switch (difficultyChoice) {
                    case 1: choicesLeft = 10; break;
                    case 2: choicesLeft = 7; break;
                    case 3: choicesLeft = 5; break;
                    default:
                        cout << "Wrong choice, Enter valid choice to play the game! (0,1,2,3)" << endl;
                        continue; // Restart the loop for a valid choice
                }

                while (choicesLeft > 0) {
                    cout << "\nEnter your guess: ";
                    cin >> playerChoice;

                    if (playerChoice == secretNumber) {
                        cout << "Well played! You won, " << playerChoice << " is the secret number" << endl;
                        cout << "Thanks for playing.... Play again!\n" << endl;
                        break;
                    } else {
                        cout << "Nope, " << playerChoice << " is not the right number\n";
                        if (playerChoice > secretNumber) {
                            cout << "The secret number is smaller than " << playerChoice << endl;
                        } else {
                            cout << "The secret number is greater than " << playerChoice << endl;
                        }
                        choicesLeft--;
                        cout << choicesLeft << " choices left." << endl;

                        if (choicesLeft == 0) {
                            cout << "You couldn't find the secret number, it was " << secretNumber << ", You lose!!\n\n";
                        }
                    }
                }
            }
            break;
        }

        case 0:
            cout << "Exiting the game. Thanks for playing!" << endl;
            break;

        default:
            cout << "Invalid choice! Please select a valid game." << endl;
            break;
    }

    return 0;
}

