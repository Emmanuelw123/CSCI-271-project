#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// FUNCTION 1: handle a player turn
void playTurn(int &position, bool &done, int &place, int &playerPlace, int finishLine, int maxFinishers, int playerNum) {
    if (!done) {
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
void printResults(int place, int playerNum) {
    if (place > 0)
        cout << "Player " << playerNum << " finished in place " << place << endl;
    else
        cout << "\n";
}

// FUNCTION 3: check if game is over
bool isGameOver(int place, int maxFinishers) {
    return (place > maxFinishers);
}

int main() {

    srand(time(0));

    int numPlayers;
    int finishLine = 50;

    int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
    bool p1Done = false, p2Done = false, p3Done = false, p4Done = false;

    int p1Place = 0, p2Place = 0, p3Place = 0, p4Place = 0;
    int place = 1;

    do {
        cout << "Enter number of players (2-4): ";
        cin >> numPlayers;
    } while (numPlayers < 2 || numPlayers > 4);

    int maxFinishers = numPlayers - 1;

    bool gameOver = false;
    int round = 1;

    while (!gameOver) {

        cout << "\n===== ROUND " << round << " =====\n";

        playTurn(p1, p1Done, place, p1Place, finishLine, maxFinishers, 1);
        playTurn(p2, p2Done, place, p2Place, finishLine, maxFinishers, 2);

        if (numPlayers >= 3)
            playTurn(p3, p3Done, place, p3Place, finishLine, maxFinishers, 3);

        if (numPlayers == 4)
            playTurn(p4, p4Done, place, p4Place, finishLine, maxFinishers, 4);

        gameOver = isGameOver(place, maxFinishers);
        round++;
    }

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
