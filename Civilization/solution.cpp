const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {1, 0, -1, 0};

class Solution {
    static const int MAX_N = 1000;
private:
    int N;
    int map[MAX_N][MAX_N];
public:

    // N: Length of a region (5 <= N <= 1,000)
    Solution(int N = 0) : N(N) {
        //for (int i = 0; i < N; i++)
        //    for (int j = 0; j < N; j++)
        //        map[i][j] = 0;
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
    int newCivilization(int r, int c, int mID) {
        //for (int d = 0; d < 4; d++) {

        //}
        return -1;
    }

    // Removes the Civilization mID.
    // Civilization mID may be a civilization that does not exist yet or that disappeared already when the function is called.
    //
    // mID: ID of the Civilization to remove (1 <= mID <= 1,000,000,000)
    // return: The number of areas Civilization mID owned before disappearing.
    // Return 0 if Civilization mID is a civilization that does not exist or already disappeared.
    int removeCivilization(int mID) {
        return -1;
    }

    // Get ID of the Civilization that occupyting Area(r, c)
    //
    // r: row of the Civilization location (1 <= r <= N)
    // c: column of the Civilization location (1 <= c <= N)
    // return: the ID of the civilization occupying Area (r, c).
    // If there is no civilization in the location, return 0.
    int getCivilization(int r, int c) {
        return -1;
    }

    // Get the number of areas Civilization mID is occupying
    //
    // mID: the ID of the Civilization (1 <= mID <= 1,000,000,000)
    // return: the number of areas Civilization mID is occupying.
    // If the civilization does not exist, return 0.
    int getCivilizationArea(int mID) {
        return -1;
    }

    // Merges Civilization mID2 into Civilization mID1
    //
    // mID1: The ID of civilization which is left after the merger (1 <= mID1 <= 1,000,000,000)0
    // mID2: The ID of civilization which disappeared after the merger (1 <= mID2 <= 1,000,000,000, mID1 \neq mID2)
    // return: The number of areas Civilization mID1 is occupying after the merger.
    int mergeCivilization(int mID1, int mID2) {
        return -1;
    }
} solution;

////////////////////////////////////////////////////////////////////////////////
void init(int N) {
    solution = Solution(N);
}

int newCivilization(int r, int c, int mID) {
    return solution.newCivilization(r, c, mID);
}

int removeCivilization(int mID) {
    return solution.removeCivilization(mID);
}

int getCivilization(int r, int c) {
    return solution.getCivilization(r, c);
}

int getCivilizationArea(int mID) {
    return solution.getCivilizationArea(mID);
}

int mergeCivilization(int mID1, int mID2) {
    return solution.mergeCivilization(mID1, mID2);
}