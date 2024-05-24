#include <iostream>
#include <vector>

using namespace std;

class Player {
public:
    string name;
    vector<int> roundScores;

    Player(const string& name) : name(name) {}

    void addRoundScore(int score) {
        roundScores.push_back(score);
    }

    int getTotalScore() const {
        int total = 0;
        for (int score : roundScores) {
            total += score;
        }
        return total;
    }
};

int main() {
    int numPlayers, numRounds, holesPerRound;

    cout << "Enter number of players: ";
    cin >> numPlayers;

    cout << "Enter number of rounds: ";
    cin >> numRounds;

    cout << "Enter number of holes per round: ";
    cin >> holesPerRound;

    vector<Player> players;
    for (int i = 0; i < numPlayers; ++i) {
        string name;
        cout << "Enter player " << i + 1 << " name: ";
        cin >> name;
        players.push_back(Player(name));
    }

    // Simulate gameplay for each round
    for (int round = 1; round <= numRounds; ++round) {
        cout << "\n** Round " << round << " **\n";
        for (Player& player : players) {
            int roundScore; 
            cin>>roundScore;// Simulate player's round score 
            player.addRoundScore(roundScore);
            cout << player.name << " score: " << roundScore << endl;
        }
    }

    // Determine and display winner
    // Option 1: Use a larger data type (e.g., size_t)
    // size_t minTotalScore = 0;

    // Option 2: Initialize with a non-zero value
    int minTotalScore = holesPerRound * 10; // Assuming 10 is the maximum score per hole

    string winnerName;
    for (const Player& player : players) {
        int totalScore = player.getTotalScore();
        if (totalScore < minTotalScore) {
            minTotalScore = totalScore;
            winnerName = player.name;
        }
    }

    cout << "\n** Overall Winner **\n";
    cout << winnerName << " with a total score of " << minTotalScore<< "is lowest" << endl;

    return 0;
}
