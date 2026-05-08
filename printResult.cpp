#include <iostream>
using namespace std;
// FUNCTION 2:
// Displays the final placement of a player.
// If the player did not finish, it prints a blank line.// FUNCTION 2:
// Displays the final placement of a player.
// If the player did not finish, it prints a blank line.
void printResults(int place, int playerNum) {
    if (place > 0)
        cout << "Player " << playerNum << " finished in place " << place << endl;
    else
        cout << "\n";
}
