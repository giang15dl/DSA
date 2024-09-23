#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
    struct Soldier {
        static unordered_map<int, int> hashID;
        static unordered_map<int, vector<int>> hashTeam;
        static int count;

    public:
        int id, team;
        short score;
        bool fired;
        Soldier(int id = 0, int team = 0, int score = 0) : id(id), team(team), score(score), fired(false) {
            hashID[id] = count;
            hashTeam[team].push_back(count);
            count++;
        }
        void changeScore(int change) {
            score += change;
            if (score < 1) {
                score = 1;
                return;
            }
            if (score >= 5) {
                score = 5;
                return;
            }
        }
    };
    vector<Soldier> soldiers;

public:
    Solution() {
        Soldier::count = 0;
    }

    ~Solution() {
        Soldier::hashID.clear();
        Soldier::hashTeam.clear();
    }

    void hire(int id, int team, int score) {
        soldiers.push_back(Soldier(id, team, score));
    }

    void fire(int id) {
        int hash = Soldier::hashID[id];
        auto &soldier = soldiers[hash];
        soldier.fired = true;
    }

    void updateSoldier(int id, int score) {
        int hash = Soldier::hashID[id];
        auto &soldier = soldiers[hash];
        soldier.score = score;
    }

    void updateTeam(int team, int changeScore) {
        auto hashes = Soldier::hashTeam[team];
        for (auto hash : hashes)
            soldiers[hash].changeScore(changeScore);
    }

    int bestSoldier(int team) {
        int max = 0;
        int maxID = -1;
        auto hashes = Soldier::hashTeam[team];
        for (auto hash : hashes) {
            auto &soldier = soldiers[hash];

            if (soldier.fired)
                continue;

            if (soldier.score == max && soldier.id > maxID) {
                maxID = soldier.id;
                continue;
            }

            if (soldier.score > max) {
                max = soldier.score, maxID = soldier.id;
                continue;
            }
        }
        return maxID;
    }
} * solution;

unordered_map<int, int> Solution::Soldier::hashID;
unordered_map<int, vector<int>> Solution::Soldier::hashTeam;
int Solution::Soldier::count;

///////////////////////////////////////////////////////////////////////////////
void init() {
    if (solution)
        delete solution;
    solution = new Solution();
}

void hire(int id, int team, int score) {
    solution->hire(id, team, score);
}

void fire(int id) {
    solution->fire(id);
}

void updateSoldier(int id, int score) {
    solution->updateSoldier(id, score);
}

void updateTeam(int team, int changeScore) {
    solution->updateTeam(team, changeScore);
}

int bestSoldier(int team) {
    return solution->bestSoldier(team);
}
