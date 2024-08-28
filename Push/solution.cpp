#include <iostream>
#include <queue>
#include <stack>
#define MAX_N 30

// Up, Right, Down, Left        //   0
const int di[4] = {-1,0,1,0};   // 3 x 1
const int dj[4] = {0,1,0,-1};   //   2

using namespace std;
class Solution {
private:
    int N; // Map Size
    int (*map)[MAX_N];

    struct Point {
        int i, j;
        Point(int i = 0, int j = 0) : i(i), j(j) {}
        bool valid(const int N) const {
            return i >= 0 && j >= 0 && i < N && j < N;
        }
        bool operator==(const Point& rhs) const {
            return i == rhs.i && j == rhs.j;
        }
    };

    struct State {
        Point coor;
        int dir;
        int steps;
        State(Point coor, int dir = 0, int steps = 0) : coor(coor), dir(dir), steps(steps) {}
    };

    bool DFS(const Point& src, const Point &dst, const Point &rock) const {
        bool visited[MAX_N][MAX_N] = {};
        stack<Point> s;
        s.push(src);
        visited[src.i][src.j] = true;
        while (!s.empty()) {
            Point prev = s.top(); s.pop();
            if (prev == dst)
                return true;
            for (int d = 0; d < 4; d++) {
                Point next(prev.i + di[d], prev.j + dj[d]);
                if (map[next.i][next.j] || visited[next.i][next.j] || next == rock)
                    continue;

                visited[next.i][next.j] = true;
                s.push(next);
            }
        }
        return false;
    }
public:
    Solution () {}

    Solution(int N, int mMap[MAX_N][MAX_N]) : N(N), map(mMap) {}

    int push(int mRockR, int mRockC, int dir, int mGoalR, int mGoalC) {
        Point rock = Point(mRockR, mRockC);
        Point goal = Point(mGoalR, mGoalC);
        dir = (dir + 2) % 4;
        bool visited[4][MAX_N][MAX_N] = {};

        queue<State> q;
        q.push(State(rock, dir));
        visited[dir][rock.i][goal.j] = true;

        while (!q.empty()) {
            State curr = q.front(); q.pop();
            if (curr.coor == goal)
                return curr.steps;

            Point currPlayer = Point(curr.coor.i - di[curr.dir], curr.coor.j - dj[curr.dir]);
            for (int d = 0; d < 4; d++) {
                Point next      (curr.coor.i + di[d], curr.coor.j + dj[d]);
                Point nextPlayer(curr.coor.i - di[d], curr.coor.j - dj[d]);

                if (map[next.i][next.j] || map[nextPlayer.i][nextPlayer.j] || visited[d][next.i][next.j])
                    continue;

                if (!DFS(currPlayer, nextPlayer, curr.coor))
                    continue;

                visited[d][next.i][next.j] = true;
                q.push(State(next, d, curr.steps + 1));
            }
        }
        return 0;
    }
} solution;

////////////////////////////////////////////////////////////////////////////////
void init(int N, int mMap[MAX_N][MAX_N]) { solution = Solution(N, mMap); }
int push(int mRockR, int mRockC, int mDir, int mGoalR, int mGoalC) { return solution.push(mRockR, mRockC, mDir, mGoalR, mGoalC);}
////////////////////////////////////////////////////////////////////////////////
