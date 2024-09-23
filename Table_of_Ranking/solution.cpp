#include <algorithm>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

const int MAX_N = 50000;

struct Result {
    int current_rank;
    int best_rank;
    int worst_rank;
    Result() : current_rank(-1), best_rank(-1), worst_rank(-1) {}
};

using namespace std;
class Solution {
private:
    struct Problem {
    public:
        static int count;
        static unordered_map<string, size_t> hash;
        static int totalPossibleScore;

    public:
        int score;
        list<int> passedPlayer;
        list<int> failedPlayer;

        Problem() {}
        Problem(char name[], int score = 0) : score(score) {
            hash[name] = count++;
            totalPossibleScore += score;
            passedPlayer.clear();
            failedPlayer.clear();
        }
        static int get(char name[]) {
            return hash[name];
        }
        void update(int score) {
            this->score = score;
        }
    };
    vector<Problem> problems;

    struct Player {
    public:
        static int count;
        static unordered_map<string, size_t> hash;
        static int passedCount;
        static int passedTable[MAX_N];
        static int failedCount;
        static int failedTable[MAX_N];

    public:
        int passedScore;
        int failedScore;
        int passedIndex;
        int failedIndex;

        Player() {}
        Player(char name[]) : passedScore(0), failedScore(0) {
            passedTable[passedCount] = count;
            failedTable[failedCount] = count;
            hash[name] = count++;

            passedIndex = passedCount++;
            failedIndex = failedCount++;
        }

        static int get(char name[]) {
            return hash[name];
        }
    };
    vector<Player> players;

    void Reposition(int playerID) {
        Player &player = players[playerID];
        int index;

        index = player.passedIndex;
        for (int i = index + 1; i < Player::passedCount; ++i) {
            Player &player1 = players[Player::passedTable[i - 1]];
            Player &player2 = players[Player::passedTable[i]];
            if (player1.passedScore >= player2.passedScore)
                break;
            swap(Player::passedTable[i - 1], Player::passedTable[i]);
            swap(player1.passedIndex, player2.passedIndex);
        }
        index = player.passedIndex;
        for (int i = index; i > 0; --i) {
            Player &player1 = players[Player::passedTable[i - 1]];
            Player &player2 = players[Player::passedTable[i]];
            if (player1.passedScore >= player2.passedScore)
                break;
            swap(Player::passedTable[i - 1], Player::passedTable[i]);
            swap(player1.passedIndex, player2.passedIndex);
        }

        index = player.failedIndex;
        for (int i = index + 1; i < Player::failedCount; ++i) {
            Player &player1 = players[Player::failedTable[i - 1]];
            Player &player2 = players[Player::failedTable[i]];
            if (player1.failedScore >= player2.failedScore)
                break;
            swap(Player::failedTable[i - 1], Player::failedTable[i]);
            swap(player1.failedIndex, player2.failedIndex);
        }

        index = player.failedIndex;
        for (int i = index; i > 0; --i) {
            Player &player1 = players[Player::failedTable[i - 1]];
            Player &player2 = players[Player::failedTable[i]];
            if (player1.failedScore >= player2.failedScore)
                break;
            swap(Player::failedTable[i - 1], Player::failedTable[i]);
            swap(player1.failedIndex, player2.failedIndex);
        }
    }

    int BinarySearch1(int score, int s, int e) {
        int ret = -1;
        while (s <= e) {
            int mid = (s + e) >> 1;
            if (players[Player::passedTable[mid]].passedScore > score)
                ret = mid, s = mid + 1;
            else
                e = mid - 1;
        }
        return ret + 1;
    }

    int GetCurrentRank(int score) {
        int pos = BinarySearch1(score, 0, Player::passedCount - 1);
        int order = pos + 1;
        return order;
    }

    int GetBestRank(int score) {
        int pos = BinarySearch1(score, 0, Player::passedCount - 1);
        int order = pos + 1;
        return order;
    }

    int BinarySearch2(int value, int s, int e) {
        int ret = -1;
        while (s <= e) {
            int mid = (s + e) >> 1;
            if (Problem::totalPossibleScore - players[Player::failedTable[mid]].failedScore <= value)
                ret = mid, s = mid + 1;
            else
                e = mid - 1;
        }
        return ret;
    }

    int GetWorstRank(int id, int score) {
        int pos = BinarySearch2(score, 0, Player::failedCount - 1);
        int order = Player::failedCount - pos;
        if (Problem::totalPossibleScore - players[id].failedScore > score)
            order--;
        return order;
    }

public:
    Solution() {
        Player::count = 0;
        Player::passedCount = 0;
        Player::failedCount = 0;

        Problem::count = 0;
        Problem::totalPossibleScore = 0;

        for (int i = 0; i < MAX_N; i++) {
            Player::passedTable[i] = 0;
            Player::failedTable[i] = 0;
        }
    }

    ~Solution() {
        Player::hash.clear();
        Problem::hash.clear();
    }

    void newPlayer(char name[]) {
        players.push_back(Player(name));
    }

    void newProblem(char name[], int score) {
        problems.push_back(Problem(name, score));
    }

    void changeProblemScore(char mProblemName[], int mNewScore) {
        int id = Problem::get(mProblemName);
        Problem &problem = problems[id];

        int diff = mNewScore - problem.score;
        Problem::totalPossibleScore += diff;
        problem.score = mNewScore;

        if (diff == 0)
            return;

        for (auto it = problem.passedPlayer.begin(); it != problem.passedPlayer.end(); it++) {
            players[*it].passedScore += diff;
            Reposition(*it);
        }

        for (auto it = problem.failedPlayer.begin(); it != problem.failedPlayer.end(); it++) {
            players[*it].failedScore += diff;
            Reposition(*it);
        }
    }

    void attemptProblem(char mPlayerName[], char mProblemName[], int mAttemptResult) {
        int playerID = Player::get(mPlayerName);
        int problemID = Problem::get(mProblemName);

        Player &player = players[playerID];
        Problem &problem = problems[problemID];

        if (mAttemptResult == 1) {
            player.passedScore += problem.score;
            problem.passedPlayer.push_back(playerID);
        } else {
            player.failedScore += problem.score;
            problem.failedPlayer.push_back(playerID);
        }
        Reposition(playerID);
    }

    Result getRank(char mPlayerName[]) {
        Result res;
        int playerID = Player::get(mPlayerName);
        Player &player = players[playerID];

        int playerGoodScore = Problem::totalPossibleScore - player.failedScore;

        res.current_rank = GetCurrentRank(player.passedScore);
        res.best_rank = GetBestRank(playerGoodScore);
        res.worst_rank = GetWorstRank(playerID, player.passedScore);

        return res;
    }

} * solution;

int Solution::Player::count;
int Solution::Player::passedCount;
int Solution::Player::failedCount;
unordered_map<string, size_t> Solution::Player::hash;

int Solution::Player::passedTable[MAX_N];
int Solution::Player::failedTable[MAX_N];

int Solution::Problem::count;
int Solution::Problem::totalPossibleScore;
unordered_map<string, size_t> Solution::Problem::hash;

///////////////////////////////////////////////////////////////////////////////
void init() { solution = new Solution(); }
void destroy() { delete solution; }
void newPlayer(char mPlayerName[]) { solution->newPlayer(mPlayerName); }
void newProblem(char mProblemName[], int mScore) { solution->newProblem(mProblemName, mScore); }
void changeProblemScore(char mProblemName[], int mNewScore) { solution->changeProblemScore(mProblemName, mNewScore); }
void attemptProblem(char mPlayerName[], char mProblemName[], int mAttemptResult) { solution->attemptProblem(mPlayerName, mProblemName, mAttemptResult); }
Result getRank(char mPlayerName[]) { return solution->getRank(mPlayerName); }
