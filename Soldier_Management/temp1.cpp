#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    struct Soldier {
        int id, team, score;
        bool fired;
        Soldier() : id(0), team(0), score(0), fired(false) {}
        Soldier(int id, int team, int score) : id(id), team(team), score(score), fired(false) {}
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
    unordered_map<int, int> hashID;

public:
    Solution() {}

    void hire(int id, int team, int score) {
        soldiers.push_back(Soldier(id, team, score));
    }

    void fire(int id) {
        for (auto &soldier : soldiers){
            if (soldier.id == id) {
                soldier.fired = true;
                break;
            }
        }
    }

    void updateSoldier(int id, int score) {
        for (auto &soldier : soldiers){
            if (soldier.id == id) {
                soldier.score = score;
                break;
            }
        }
    }

    void updateTeam(int team, int changeScore) {
        for (auto &soldier : soldiers){
            if (soldier.team == team) {
                soldier.changeScore(changeScore);
            }
        }
    }

    int bestSoldier(int team) {
        int max = 0;
        int maxID = -1;
        for (auto &soldier : soldiers){
            if (soldier.fired || soldier.team != team)
                continue;

            if (soldier.score == max && soldier.id > maxID) {
                maxID = soldier.id;
            }

            if (soldier.score > max) {
                max = soldier.score, maxID = soldier.id;
            }
        }
        return maxID;
    }
}solution;

///////////////////////////////////////////////////////////////////////////////
void init() {
    solution = Solution();
}

void hire(int id, int team, int score) {
    solution.hire(id, team, score);
}

void fire(int id) {
    solution.fire(id);
}

void updateSoldier(int id, int score) {
    solution.updateSoldier(id, score);
}

void updateTeam(int team, int changeScore) {
    solution.updateTeam(team, changeScore);
}

int bestSoldier(int team) {
    return solution.bestSoldier(team);
}