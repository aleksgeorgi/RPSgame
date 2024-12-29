#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;


int getUserChoice() {
    int choice;
    cout << "Choose: (1) Rock, (2) Paper, (3) Scissors: ";
    cin >> choice;
    while (choice < 1 || choice > 3) { // Validate choice is within range
        cout << "Invalid choice. Please choose (1) Rock, (2) Paper, or (3) Scissors: ";
        cin >> choice;
    }
    return choice;
}

int getComputerChoice() {
    return rand() % 3 + 1; // Random choice between 1 and 3
}

// Returns 1 if the user wins, -1 if the computer wins, and 0 for a tie
int determineWinner(int userChoice, int computerChoice) {
    if (userChoice == computerChoice) {
        return 0; // Tie
    } else if ((userChoice == 1 && computerChoice == 3) || // Rock beats Scissors
               (userChoice == 2 && computerChoice == 1) || // Paper beats Rock
               (userChoice == 3 && computerChoice == 2)) { // Scissors beats Paper
        return 1; // User wins
    } else {
        return -1; // Computer wins
    }
}

void displayChoice(int choice, string player) {
    cout << player << " chose ";
    if (choice == 1) {
        cout << "Rock" << endl;
    } else if (choice == 2) {
        cout << "Paper" << endl;
    } else if (choice == 3) {
        cout << "Scissors" << endl;
    }
}

int main() {
    srand(time(0)); 
    int userScore = 0, computerScore = 0;
    char playAgain = 'y';

    cout << "Welcome to Rock, Paper, Scissors!" << endl;

    // Loop for each round until user decides not to play again
    while (playAgain == 'y' || playAgain == 'Y') {
        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();

        displayChoice(userChoice, "You");
        displayChoice(computerChoice, "Computer");

        int result = determineWinner(userChoice, computerChoice);
        if (result == 1) {
            cout << "You win this round!" << endl;
            userScore++;
        } else if (result == -1) {
            cout << "Computer wins this round!" << endl;
            computerScore++;
        } else {
            cout << "It's a tie!" << endl;
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Final Score: You: " << userScore << " | Computer: " << computerScore << endl;
    if (userScore > computerScore) {
        cout << "Congratulations, you won the game!" << endl;
    } else if (computerScore > userScore) {
        cout << "The computer wins the game. Better luck next time!" << endl;
    } else {
        cout << "The game is a tie!" << endl;
    }

    return 0;
}
