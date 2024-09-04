#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TicTacToe {
private:
    int rows = 3;
    int cols = 3;

public:
    vector<vector<string>> Field;

    // Constructor
    TicTacToe() : Field(rows, vector<string>(cols)) {
        Field[0][0] = "a1";
        Field[0][1] = "a2";
        Field[0][2] = "a3";

        Field[1][0] = "b1";
        Field[1][1] = "b2";
        Field[1][2] = "b3";

        Field[2][0] = "c1";
        Field[2][1] = "c2";
        Field[2][2] = "c3";
    }

    void PrintField() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << Field[i][j];
                if (j < 2) {
                    cout << " | ";
                }
            }
            cout << endl;
            if (i < 2) {
                cout << "-------------" << endl;
            }
        }
    }

    void addXO(string ch) {
        bool validMove = false;

        while (!validMove) {
            cout << "Choose place:" << endl;
            cin >> posXO;

            bool found = false;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (posXO == Field[i][j]) {
                        found = true;
                        if (Field[i][j] == "x" || Field[i][j] == "o") {
                            cout << "Field already taken." << endl;
                        } else {
                            Field[i][j] = ch;
                            validMove = true;
                        }
                        break;
                    }
                }
                if (found) break;
            }

            if (!found) {
                cout << "Invalid position! Please choose a valid position." << endl;
            }
        }
    }

private:
    string posXO;

public:
    char check() {
        // Rows:
        for (int i = 0; i < 3; i++) {
            if (Field[i][0] == Field[i][1] && Field[i][1] == Field[i][2]) {
                if (Field[i][0] == "x" || Field[i][0] == "o") {
                    return Field[i][0][0];
                }
            }
        }

        // Columns:
        for (int j = 0; j < 3; j++) {
            if (Field[0][j] == Field[1][j] && Field[1][j] == Field[2][j]) {
                if (Field[0][j] == "x" || Field[0][j] == "o") {
                    return Field[0][j][0];
                }
            }
        }

        // Diagonals:
        if (Field[0][0] == Field[1][1] && Field[1][1] == Field[2][2]) {
            if (Field[0][0] == "x" || Field[0][0] == "o") {
                return Field[0][0][0];
            }
        }
        if (Field[0][2] == Field[1][1] && Field[1][1] == Field[2][0]) {
            if (Field[0][2] == "x" || Field[0][2] == "o") {
                return Field[0][2][0];
            }
        }

        // No winner yet
        return ' ';
    }
};

int main() {

    TicTacToe ttt;
    int actualPlayer = 0;
    string inst;

    int scoreX = 0, scoreO = 0;



    while (true) {
        cout << "TicTacToe game" << endl;
        cout << "For playing press p" << endl;
        cout << "For score reset press r" << endl;
        cout << "For quit press q" << endl; 
        cin >> inst;

        if (inst == "p") {
            for (int i = 0; i < 9; i++) {
                actualPlayer = i % 2;

                cout << "Turn " << i + 1 << ":" << endl;
                
                ttt.PrintField();

                if (actualPlayer == 0) {
                    ttt.addXO("x");
                } else {
                    ttt.addXO("o");
                }

                //ttt.PrintField();

                char winner = ttt.check();
                if (winner == 'x') {
                    cout << "Player X wins!" << endl;
                    scoreX++;
                    break; // End the game after a win
                } else if (winner == 'o') {
                    cout << "Player O wins!" << endl;
                    scoreO++;
                    break; // End the game after a win
                }
            }
            cout << "Final Score - X: " << scoreX << " O: " << scoreO << endl;
        }

        else if (inst == "r") {
            scoreX = 0;
            scoreO = 0;
            cout << "Scores reset." << endl;
        }

        else if (inst == "q") {
            break;
        }

        ttt = TicTacToe();  // Reset the board for a new game
    }

    return 0;
}