#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// FUNCTION 1: handle a player turn
// Handles one player's turn by rolling the dice,
// moving the player forward, displaying the result,
// and assigning a finishing place if they reach the finish line.
void playTurn(int &position, bool &done, int &place, int &playerPlace, int finishLine, int maxFinishers, int playerNum) {
     // only allow the player to move if they have not finished
    if (!done) {
                // generate a random dice roll from 1 to 6
        int roll = rand() % 6 + 1;
        position += roll;
        cout << "Player " << playerNum << " rolls " << roll << " -> " << position << endl;

        if (position >= finishLine && place <= maxFinishers) {
            done = true;
            playerPlace = place++;
        }
    }
}

// FUNCTION 2: print results
// Displays the final placement of a player.
// If the player did not finish, it prints a blank line.
void printResults(int place, int playerNum) {
    
    if (place > 0)
        cout << "Player " << playerNum << " finished in place " << place << endl;
    else
        cout << "\n";
}

// FUNCTION 3: check if game is over
// Checks if all finishing spots have been filled.
// Returns true if the game should end.
bool isGameOver(int place, int maxFinishers) {
    return (place > maxFinishers);
}

int main() {

    srand(time(0));

    // seed random number generator
    int numPlayers;
    // distance needed to win
    int finishLine = 50;
    // player positions
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
        // tracks whether each player finished
    bool p1Done = false, p2Done = false, p3Done = false, p4Done = false;
        // stores finishing places
    int p1Place = 0, p2Place = 0, p3Place = 0, p4Place = 0;
      // keeps track of current place
    int place = 1;
// get valid number of players from user
    do {
        cout << "Enter number of players (2-4): ";
        cin >> numPlayers;
    } while (numPlayers < 2 || numPlayers > 4);
    // last player does not finish
   int maxFinishers = numPlayers - 1;

    bool gameOver = false;
    // controls game loop
    int round = 1;
// continue game until all finishing spots are filled
    while (!gameOver) {
        // display current round

        cout << "\n===== ROUND " << round << " =====\n";

        playTurn(p1, p1Done, place, p1Place, finishLine, maxFinishers, 1);
        playTurn(p2, p2Done, place, p2Place, finishLine, maxFinishers, 2);

        if (numPlayers >= 3)
            playTurn(p3, p3Done, place, p3Place, finishLine, maxFinishers, 3);

        if (numPlayers == 4)
            playTurn(p4, p4Done, place, p4Place, finishLine, maxFinishers, 4);
                 // check if game should end
        gameOver = isGameOver(place, maxFinishers);
        // move to next round
        round++;
    }
    // display final results section

    cout << "\n===== FINAL RESULTS =====\n";

    printResults(p1Place, 1);
    printResults(p2Place, 2);

    if (numPlayers >= 3)
        printResults(p3Place, 3);

    if (numPlayers == 4)
        printResults(p4Place, 4);

    cout << "\nGame Over!\n";

    return 0;
}
