#include <iostream>
using namespace std;
void printResults(int place, int playerNum) {
    if (place > 0)
        cout << "Player " << playerNum << " finished in place " << place << endl;
    else
        cout << "\n";
}