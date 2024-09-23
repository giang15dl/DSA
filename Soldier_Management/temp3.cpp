#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MIN_ID = 1;
const int MAX_ID = 100000;
const int MIN_TEAM = 1;
const int MAX_TEAM = 5;
const int MIN_SCORE = 1;
const int MAX_SCORE = 5;

class Solution {
private:
    struct Node {
        int id;
        int team;
        Node *prev, *next;
        Node(int id = 0) : id(id), prev(NULL), next(NULL){};
    } soldiers[MAX_ID + 1];

    class list {
    public:
        Node head, tail;
        static void link(Node *front, Node *back) {
            front->next = back;
            back->prev = front;
        }

        static void erase(Node *node) {
            link(node->prev, node->next);
        }

        void init() {
            link(&head, &tail);
        }

        void insert(Node *node) {
            link(tail.prev, node);
            link(node, &tail);
        }

        bool isEmpty() {
            return (head.next == &tail);
        }

        void splice(list *list) {
            if (list->isEmpty())
                return;
            link(tail.prev, list->head.next);
            link(list->tail.prev, &tail);
            list->init();
        }
    } soldierGroup[MAX_TEAM + 1][MAX_SCORE + 1];

public:
    Solution() {
        for (int i = MIN_TEAM; i <= MAX_TEAM; i++)
            for (int j = MIN_SCORE; j <= MAX_SCORE; j++)
                soldierGroup[i][j].init();
    }

    ~Solution() {}

    void hire(int id, int team, int score) {
        soldiers[id].id = id;
        soldiers[id].team = team;
        soldierGroup[team][score].insert(soldiers + id);
    }

    void fire(int id) {
        list::erase(soldiers + id);
    }

    void updateSoldier(int id, int score) {
        list::erase(soldiers + id);
        soldierGroup[soldiers[id].team][score].insert(soldiers + id);
    }

    void updateTeam(int team, int changeScore) {
        if (changeScore > 0) {
            for (int i = MAX_SCORE - 1; i >= MIN_SCORE; i--) {
                int newScore = i + changeScore;
                if (newScore > MAX_SCORE)
                    newScore = MAX_SCORE;
                soldierGroup[team][newScore].splice(&soldierGroup[team][i]);
            }
        } else if (changeScore < 0) {
            for (int i = MIN_SCORE + 1; i <= MAX_SCORE; i++) {
                int newScore = i + changeScore;
                if (newScore < MIN_SCORE)
                    newScore = MIN_SCORE;
                soldierGroup[team][newScore].splice(&soldierGroup[team][i]);
            }
        }
    }

    int bestSoldier(int team) {
        list *maxScoreGroup;
        for (int i = MAX_SCORE; i >= MIN_SCORE; i--) {
            if (!soldierGroup[team][i].isEmpty()) {
                maxScoreGroup = &soldierGroup[team][i];
                break;
            }
        }

        int maxId = MIN_ID - 1;
        Node *maxScoreSoldier = maxScoreGroup->head.next;
        while (maxScoreSoldier != &(maxScoreGroup->tail)) {
            if (maxId < maxScoreSoldier->id)
                maxId = maxScoreSoldier->id;
            maxScoreSoldier = maxScoreSoldier->next;
        }
        return maxId;
    }
} * solution;

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
