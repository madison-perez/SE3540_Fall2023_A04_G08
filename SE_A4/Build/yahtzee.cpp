#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Dice {
private:
    vector<int> diceValues;
public:
    Dice() {
        roll();
    }

    void roll() {
        diceValues.clear();
        for (int i = 0; i < 5; ++i) {
            diceValues.push_back(rand() % 6 + 1);
        }
        sort(diceValues.begin(), diceValues.end());
    }

    const vector<int>& getValues() const {
        return diceValues;
    }
};

class ScoreCard {
private:
    vector<int> scores;
public:
    ScoreCard(int numPlayers) : scores(numPlayers, 0) {}

    void addScore(int playerIndex, int score) {
        scores[playerIndex] += score;
    }

    int getScore(int playerIndex) const {
        return scores[playerIndex];
    }
};

class Game {
private:
    vector<string> playerNames;
    vector<ScoreCard> scoreCards;
    Dice dice;

    int rollDie() {
        return rand() % 6 + 1;
    }

    int getScore(const vector<int>& diceValues) {
        int score = 0;
        for (int die : diceValues) {
            score += die;
        }
        return score;
    }

    void displayDice(const vector<int>& diceValues) {
        cout << "Your dice: ";
        for (int die : diceValues) {
            cout << die << " ";
        }
        cout << endl;
    }

    void printScoreCard() {
        cout << "Score Card:" << endl;
        for (size_t i = 0; i < playerNames.size(); ++i) {
            cout << playerNames[i] << ": " << scoreCards[i].getScore(i) << endl;
        }
    }

public:
    Game(int numPlayers) : scoreCards(numPlayers, ScoreCard(numPlayers)) {
        string playerName;
        for (int i = 0; i < numPlayers; ++i) {
            cout << "Enter name for Player " << i + 1 << ": ";
            cin >> playerName;
            playerNames.push_back(playerName);
        }
    }

    void play() {
        srand(static_cast<unsigned int>(time(nullptr)));
        cout << "Welcome to Yahtzee!" << endl;
        for (int round = 1; round <= 13; ++round) {
            cout << "\nRound " << round << ":" << endl;
            for (size_t i = 0; i < playerNames.size(); ++i) {
                cout << "\n" << playerNames[i] << "'s turn:" << endl;
                dice.roll();
                const vector<int>& diceValues = dice.getValues();
                displayDice(diceValues);
                int score = getScore(diceValues);
                cout << "Your score for this round: " << score << endl;
                scoreCards[i].addScore(i, score);
                printScoreCard();
            }
        }
        cout << "\nGame Over!" << endl;
    }
};

int main() {
    int numPlayers;
    cout << "Enter the number of players: ";
    cin >> numPlayers;
    Game game(numPlayers);
    game.play();
    return 0;
}
