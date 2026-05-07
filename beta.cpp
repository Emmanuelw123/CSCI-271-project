#include <iostream>
using namespace std;
#include <cstdlib>
  #include <ctime>


  int main() {

      srand(time(0));

      // =========================
      // ALASSANE - GAME SETUP
      // =========================

      int numPlayers;
      int finishLine = 50;

      int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
      bool p1Done = false, p2Done = false, p3Done = false, p4Done = false;

      int p1Place = 0, p2Place = 0, p3Place = 0, p4Place = 0;
      int place = 1;

      // INPUT VALIDATION
      do {
          cout << "Enter number of players (2-4): ";
          cin >> numPlayers;

          if (numPlayers < 2 || numPlayers > 4) {
              cout << "This game needs 2-4 players.\n";
          }

      } while (numPlayers < 2 || numPlayers > 4);

      cout << "You entered: " << numPlayers << endl;

      // =========================
      // EMMANUEL WHITE - DICE / GAME LOOP
      // =========================

      bool gameOver = false;
      int round = 1;

      while (!gameOver) {

          cout << "\n===== ROUND " << round << " =====\n";

          // PLAYER 1
          if (!p1Done) {
              int roll = rand() % 6 + 1;
              p1 += roll;
              cout << "Player 1 rolls " << roll << " -> " << p1 << endl;

              if (p1 >= finishLine) {
                  p1Done = true;
                  p1Place = place;
                  place++;
              }
          }

          // PLAYER 2
          if (!p2Done) {
              int roll = rand() % 6 + 1;
              p2 += roll;
              cout << "Player 2 rolls " << roll << " -> " << p2 << endl;

              if (p2 >= finishLine) {
                  p2Done = true;
                  p2Place = place;
                  place++;
              }
          }

          // PLAYER 3
          if (numPlayers >= 3 && !p3Done) {
              int roll = rand() % 6 + 1;
              p3 += roll;
              cout << "Player 3 rolls " << roll << " -> " << p3 << endl;

              if (p3 >= finishLine) {
                  p3Done = true;
                  p3Place = place;
                  place++;
              }
          }

          // PLAYER 4
          if (numPlayers == 4 && !p4Done) {
              int roll = rand() % 6 + 1;
              p4 += roll;
              cout << "Player 4 rolls " << roll << " -> " << p4 << endl;

              if (p4 >= finishLine) {
                  p4Done = true;
                  p4Place = place;
                  place++;
              }
          }

          // =========================
          // LEMAR - OUTPUT + LEADER
          // =========================

          cout << "\n--- CURRENT POSITIONS ---\n";

          cout << "P1: " << p1;
          if (p1Done) cout << " (Finished)";
          cout << endl;

          cout << "P2: " << p2;
          if (p2Done) cout << " (Finished)";
          cout << endl;

          if (numPlayers >= 3) {
              cout << "P3: " << p3;
              if (p3Done) cout << " (Finished)";
              cout << endl;
          }

          if (numPlayers == 4) {
              cout << "P4: " << p4;
              if (p4Done) cout << " (Finished)";
              cout << endl;
          }

          // LEADER CHECK
          cout << "\n--- LEADER ---\n";

          int maxPos = p1;
          if (p2 > maxPos) maxPos = p2;
          if (numPlayers >= 3 && p3 > maxPos) maxPos = p3;
          if (numPlayers == 4 && p4 > maxPos) maxPos = p4;

          if (p1 == maxPos) cout << "Player 1 is tied/leading\n";
          if (p2 == maxPos) cout << "Player 2 is tied/leading\n";
          if (numPlayers >= 3 && p3 == maxPos) cout << "Player 3 is tied/leading\n";
          if (numPlayers == 4 && p4 == maxPos) cout << "Player 4 is tied/leading\n";

          // =========================
          // ✅ FIXED GAME END LOGIC
          // =========================

          if ((numPlayers == 2 && place > 1) ||
              (numPlayers == 3 && place > 2) ||
              (numPlayers == 4 && place > 3)) {
              gameOver = true;
          }

          round++;
      }

      // =========================
      // FINAL RESULTS
      // =========================

      cout << "\n===== FINAL RESULTS =====\n";

      if (p1Done) cout << "Player 1 finished in place " << p1Place << endl;
      if (p2Done) cout << "Player 2 finished in place " << p2Place << endl;
      if (numPlayers >= 3 && p3Done) cout << "Player 3 finished in place " << p3Place << endl;
      if (numPlayers == 4 && p4Done) cout << "Player 4 finished in place " << p4Place << endl;

      int best = p1Place;
      if (p2Place < best && p2Place != 0) best = p2Place;
      if (numPlayers >= 3 && p3Place < best && p3Place != 0) best = p3Place;
      if (numPlayers == 4 && p4Place < best && p4Place != 0) best = p4Place;

      cout << "\n--- WINNER(S) ---\n";

      if (p1Place == best) cout << "Player 1\n";
      if (p2Place == best) cout << "Player 2\n";
      if (numPlayers >= 3 && p3Place == best) cout << "Player 3\n";
      if (numPlayers == 4 && p4Place == best) cout << "Player 4\n";

      cout << "\nGame Over!\n";

      return 0;
  }

}
