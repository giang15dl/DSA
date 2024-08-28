#include <set>

using namespace std;
class Solution {
    static const int MAX_ID = 100000; 
private:
    struct Soldier {
        int id;
        int team;
        int score;
        Soldier(int id = 0, int team = 0, int score = 0) : id(id), team(team), score(score) {}
        bool operator<(const Soldier& that) const {
            return score == that.score ? id < that.id : score < that.score;
        }
    };

    set<int> data[6][6];
    int soldiers[MAX_ID];
public:
    Solution() {}

    void hire(int id, int team, int score) {
        soldiers[id] = team;
        data[team][score].insert(id);
    }

    void fire(int id) {
        for (int i = 1; i <= 5; i++)
            data[soldiers[id]][i].erase(id);
    }

    void updateSoldier(int id, int score) {
        fire(id);
        data[soldiers[id]][score].insert(id);
    }

    void updateTeam(int team, int changeScore) {
        if (changeScore == 0)
            return;

        int a = 2;
        int b = 6;
        int step = 1;
        if (changeScore > 0)
            a = 4, b = 0, step = -1;

        for (int score = a; score != b; score += step) {
            int newScore = score + changeScore;

            if (newScore < 1)
                newScore = 1;

            if (newScore > 5)
                newScore = 5;

            bool forward = data[team][score].size() <= data[team][newScore].size();

            set<int> &src = forward ? data[team][score] : data[team][newScore];
            set<int> &dst = forward ? data[team][newScore] : data[team][score];

            for (auto it = src.begin(); it != src.end(); it++)
                dst.insert(*it);

            src.clear();
            if (!forward)
                std::swap(src, dst);
        }
    }

    int bestSoldier(int team) {
        for (int i = 5; i > 0; i--) {
            if (data[team][i].empty())
                continue;
            return *data[team][i].rbegin();
        }
        return 0;
    }
}solution;

///////////////////////////////////////////////////////////////////////////////
void init() { solution = Solution(); }
void hire(int id, int team, int score) { solution.hire(id, team, score); }
void fire(int id) { solution.fire(id); }
void updateSoldier(int id, int score) { solution.updateSoldier(id, score); }
void updateTeam(int team, int changeScore) { solution.updateTeam(team, changeScore); }
int bestSoldier(int team) { return solution.bestSoldier(team); }
