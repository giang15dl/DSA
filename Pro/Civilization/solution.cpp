#include <climits>
#include <list>
#include <unordered_map>

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};

using namespace std;
class Solution {
    static const int MAX_N = 1000;
    static const int MAX_CALL = 60000;

private:
    int N;
    int map[MAX_N + 1][MAX_N + 1] = {};
    int genID = 1;

    struct Data {
        int mID;
        bool deleted = false;
        Data(int ID = 0) : mID(ID) {}
    };

    int parent[MAX_CALL] = {};
    int counts[MAX_CALL] = {};
    Data datas[MAX_CALL];
    unordered_map<int, int> hash;

    int getRoot(int x) {
        return parent[x] < 0 ? x : (parent[x] = getRoot(parent[x]));
    }

public:
    // N: Length of a region (5 <= N <= 1,000)
    Solution(int N = 0) : N(N) {
        for (int i = 0; i < MAX_CALL; i++)
            parent[i] = -1;
    }

    // Forms a civilization mID in Area (r, c)
    // - Civilization mID might have existed and disappeared before the function call.
    // - It is guaranteed that there is no Civilization mID in any area at the time of the function call.
    // - In other words, Civilization mID does not occupy any area.
    //
    // r: row of the Civilization location (1 <= r <= N)
    // c: column of the Civilization location (1 <= c <= N)
    // mID: ID of the Civilization (1 <= mID <= 1,000,000,000)
    // return: The ID of the civilization that occupies Area (r, c)
    // Called up to 60,000 times
    int newCivilization(int r, int c, int mID) {
        list<int> saved;
        int maxCount = 0;
        int found = INT_MAX;
        for (int d = 0; d < 4; d++) {
            int nr = r + di[d];
            int nc = c + dj[d];
            if (nr >= 1 && nr <= N && nc >= 1 && nc <= N && map[nr][nc]) {
                int current = map[nr][nc];
                int root = getRoot(current);
                Data data = datas[root];
                if (data.deleted)
                    continue;

                int count = counts[root];
                if (count == 0)
                    saved.push_back(root);

                counts[root] = ++count;

                if (count > maxCount || (count == maxCount && data.mID < datas[found].mID))
                    maxCount = count, found = root;
            }
        }

        if (found != INT_MAX) {
            parent[found]--;
        } else {
            found = genID++;
            hash[mID] = found;
            datas[found] = Data(mID);
        }

        for (int x : saved)
            counts[x] = 0;

        map[r][c] = found;
        return datas[found].mID;
    }

    // Removes the Civilization mID.
    // Civilization mID may be a civilization that does not exist yet or that disappeared already when the function is called.
    //
    // mID: ID of the Civilization to remove (1 <= mID <= 1,000,000,000)
    // return: The number of areas Civilization mID owned before disappearing.
    // Return 0 if Civilization mID is a civilization that does not exist or already disappeared.
    // Called up to 3,000 times
    int removeCivilization(int mID) {
        int id = hash[mID];
        hash.erase(mID);

        if (id == 0)
            return 0;

        if (datas[id].deleted)
            return 0;

        datas[id].deleted = true;
        return -parent[id];
    }

    // Get ID of the Civilization that occupyting Area(r, c)
    //
    // r: row of the Civilization location (1 <= r <= N)
    // c: column of the Civilization location (1 <= c <= N)
    // return: the ID of the civilization occupying Area (r, c).
    // If there is no civilization in the location, return 0.
    // Called up to 10,000 times
    int getCivilization(int r, int c) {
        Data data = datas[getRoot(map[r][c])];
        return data.deleted ? 0 : data.mID;
    }

    // Get the number of areas Civilization mID is occupying
    //
    // mID: the ID of the Civilization (1 <= mID <= 1,000,000,000)
    // return: the number of areas Civilization mID is occupying.
    // If the civilization does not exist, return 0.
    int getCivilizationArea(int mID) {
        int id = hash[mID];
        if (id == 0)
            return 0;

        return datas[id].deleted ? 0 : -parent[id];
    }

    // Merges Civilization mID2 into Civilization mID1
    //
    // mID1: The ID of civilization which is left after the merger (1 <= mID1 <= 1,000,000,000)0
    // mID2: The ID of civilization which disappeared after the merger (1 <= mID2 <= 1,000,000,000, mID1 \neq mID2)
    // return: The number of areas Civilization mID1 is occupying after the merger.
    // Called up to 30,000 times
    int mergeCivilization(int mID1, int mID2) {
        int id1 = getRoot(hash[mID1]);
        int id2 = getRoot(hash[mID2]);
        parent[id1] += parent[id2];
        parent[id2] = id1;
        removeCivilization(datas[id2].mID);
        return -parent[id1];
    }
} * solution;

////////////////////////////////////////////////////////////////////////////////
void init(int N) {
    solution = new Solution(N);
}

int newCivilization(int r, int c, int mID) {
    return solution->newCivilization(r, c, mID);
}

int removeCivilization(int mID) {
    return solution->removeCivilization(mID);
}

int getCivilization(int r, int c) {
    return solution->getCivilization(r, c);
}

int getCivilizationArea(int mID) {
    return solution->getCivilizationArea(mID);
}

int mergeCivilization(int mID1, int mID2) {
    return solution->mergeCivilization(mID1, mID2);
}