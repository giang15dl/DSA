#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
    static const int MAX_N = 100000;
    static const int MAX_CAR = 10;
    static const int MAX_BATCH = 5; // Maximum number of passengers in each move
    static const int MAX_JOB = 1000;

private:
    int N;
    int M;
    int J;
    int *Point;
    int *JobID;

    struct Passenger {
        int ID;
        int job;
        int point;
        int car;
        Passenger() : ID(0), job(0), car(0), point(0) {}
        Passenger(int ID, int jobID, int carID, int point) : ID(ID), job(jobID), point(point), car(carID) {}
        bool operator<(const Passenger &that) const {
            return point == that.point ? ID < that.ID : point > that.point;
        }
    } passengers[MAX_N];

    struct Comparator {
        bool operator()(const Passenger *a, const Passenger *b) const {
            return a->point == b->point ? a->ID < b->ID : a->point > b->point;
        }
    };

    vector<Passenger *> jobs[MAX_JOB];
    set<Passenger *, Comparator> cars[MAX_CAR]; // A car is a section of a train.
    int carCount;

public:
    Solution() {}
    Solution(int N, int M, int J, int mPoint[], int mJobID[]) : N(N), M(M), J(J), Point(mPoint), JobID(mJobID) {
        carCount = N / M;
        for (int i = 0; i < N; i++) {
            int sectionID = i / M;
            passengers[i] = Passenger(i, JobID[i], sectionID, Point[i]);
            cars[sectionID].insert(&passengers[i]);
            jobs[mJobID[i]].push_back(&passengers[i]);
        }
    }

    ~Solution() {}

    int update(int mID, int mPoint) {
        Passenger *passenger = &passengers[mID];
        auto &car = cars[passenger->car];
        auto search = car.find(passenger);
        passenger->point += mPoint;
        car.erase(search);
        car.insert(passenger);

        return passenger->point;
    }

    int updateByJob(int mJobID, int mPoint) {
        int sum = 0;
        for (Passenger *passenger : jobs[mJobID]) {
            auto &car = cars[passenger->car];
            auto search = car.find(passenger);
            passenger->point += mPoint;
            car.erase(search);
            car.insert(passenger);
            sum += passenger->point;
        }
        return sum;
    }

    int move(int mNum) {
        int sum = 0;
        Passenger *moveDownPassengers[MAX_BATCH][MAX_CAR];
        Passenger *moveUpPassengers[MAX_BATCH][MAX_CAR];
        for (int i = 0; i < carCount - 1; i++) {
            auto &front = cars[i];
            auto &back = cars[i + 1];

            auto frontIt = front.end();
            --frontIt;

            auto backIt = back.begin();

            for (int j = 0; j < mNum; j++) {
                moveDownPassengers[j][i] = *frontIt;
                sum += moveDownPassengers[j][i]->point;
                frontIt = front.erase(frontIt);
                if (!front.empty())
                    --frontIt;

                moveUpPassengers[j][i] = *backIt;
                sum += moveUpPassengers[j][i]->point;
                backIt = back.erase(backIt);
            }
        }
        for (int i = 0; i < carCount - 1; i++) {
            auto &front = cars[i];
            auto &back = cars[i + 1];
            for (int j = 0; j < mNum; j++) {
                front.insert(moveUpPassengers[j][i]);
                moveUpPassengers[j][i]->car = i;
                back.insert(moveDownPassengers[j][i]);
                moveDownPassengers[j][i]->car = i + 1;
            }
        }

        return sum;
    }
} * solution;

///////////////////////////////////////////////////////////////////////////////
void init(int N, int M, int J, int mPoint[], int mJobID[]) { solution = new Solution(N, M, J, mPoint, mJobID); }
void destroy() { delete solution; }
int update(int mID, int mPoint) { return solution->update(mID, mPoint); }
int updateByJob(int mJobID, int mPoint) { return solution->updateByJob(mJobID, mPoint); }
int move(int mNum) { return solution->move(mNum); }
