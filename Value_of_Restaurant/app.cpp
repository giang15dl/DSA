#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

class Solution {
private:
    static const int MAX_N = 50;
    static const int MAX_M = 50;
    static const int MAX_R = 10000;

    int N, M, R; // Number of cities, roads and restaurants, respectively
    unordered_map<string, int> hashName, hashMap;

    struct Restaurant {
        string name;
        int value;
        int cityID;
        Restaurant () : name(), value(0), cityID(0) {}
        Restaurant (int cityID, char name[]) : name(name), value(0), cityID(cityID) {}
        bool has(char mStr[]) const {
            string subStr = mStr;
            if (name.find(subStr) != std::string::npos)
                return true;
            return false;
        }
        bool at(int cityID) const {
            return this->cityID == cityID;
        }
    };
    vector<Restaurant> restaurants;

    struct City {
        vector<int> neighbors;
        vector<int> res_indexes;

        void addRes(int index) {
            res_indexes.push_back(index);
        }

        bool has(int index) const {
            for (int res_index : res_indexes)
                if (res_index == index)
                    return true;
            return false;
        }
    };
    vector<City> cities;

    void addHash(char name[], int res_index) {
        string str(name);
        unsigned int len = str.size();

        for (unsigned int i = 1; i <= len; i++) {
            for (unsigned int j = 0; j + i <= len; j++) {
                string substr = str.substr(j, i);
                auto it = hashMap.find(substr);
                if (it == hashMap.end())
                    hashMap[substr] = res_index;
                else if (restaurants[it->second].value < restaurants[res_index].value)
                    hashMap[substr] = res_index;
            }
        }
    }

public:
    Solution() : N(0), M(0), R(0) {}

    Solution(int N, int M, int mRoads[][2]) : N(N), M(M), R(0) {
        cities.resize(N);
        for (int i = 0; i < M; i++) {
            int u = mRoads[i][0];
            int v = mRoads[i][1];
            u--, v--;
            cities[u].neighbors.push_back(v);
            cities[v].neighbors.push_back(u);
        }
    }

    void addRestaurant(int mCityID, char mName[]) {
        mCityID--;
        restaurants.push_back(Restaurant(mCityID, mName));
        hashName[mName] = R;
        cities[mCityID].addRes(R);
        addHash(mName, R);
        R++;
    }

    void addValue(char mName[], int mScore) {
        int r = hashName[mName];
        restaurants[r].value += mScore;
        addHash(mName, r);
    }

    int bestValue(char mStr[]) {
        int r = hashMap[mStr];
        return restaurants[r].value;
    }

    int regionalValue(int mCityID, int mDist) {
        mCityID--;
        int visited[MAX_N] = {};
        vector<int> topVal;
        queue<int> q;
        q.push(mCityID);
        visited[mCityID] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (visited[u] - 1 > mDist)
                break;

            for (const auto &r : restaurants)
                if (r.at(u))
                    topVal.push_back(r.value);

            for (char v : cities[u].neighbors) {
                if (visited[v])
                    continue;
                visited[v] = visited[u] + 1;
                q.push(v);
            }
        }

        if (topVal.size() <= 3) {
            int sum = 0;
            for (unsigned int i = 0; i < topVal.size(); i++)
                sum += topVal[i];
            return sum;
        }

        sort(topVal.begin(), topVal.end(), greater<int>());

        return topVal[0] + topVal[1] + topVal[2];
    }

}solution;

///////////////////////////////////////////////////////////////////////////////
void init(int N, int M, int mRoads[][2]) {
    solution = Solution(N, M, mRoads);
}

void addRestaurant(int mCityID, char mName[]) {
    solution.addRestaurant(mCityID, mName);
}

void addValue(char mName[], int mScore) {
    solution.addValue(mName, mScore);
}

int bestValue(char mStr[]) {
    return solution.bestValue(mStr);
}

int regionalValue(int mCityID, int mDist) {
    return solution.regionalValue(mCityID, mDist);
}