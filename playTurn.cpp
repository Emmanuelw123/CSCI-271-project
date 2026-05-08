#include <iostream>
using namespace std;
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