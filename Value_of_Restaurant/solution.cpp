#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <functional>

const int MAX_CITY = 50;
const int MAX_ROAD = 50;
const int MAX_RES = 10000;

using namespace std;

struct Res {
    int city;
    int value;
};

struct City {
    vector<int> neighbors;
    vector<int> res_indexes;

    void addRes(int index) {
        res_indexes.push_back(index);
    }

    bool exist(int index) const {
        for (int res_index : res_indexes)
            if (res_index == index)
                return true;
        return false;
    }
};

Res restaurants[MAX_RES];
City Cities[MAX_CITY];

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void sort(int *ptr, int len) {
    for (int i = 0; i < len - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < len; j++) {
            if (restaurants[ptr[i]].value < restaurants[ptr[j]].value)
                max_idx = j;
        }
        swap(ptr[i], ptr[max_idx]);
    }
}

void sort(vector<int> &cityRes) {
    int len = cityRes.size();
    for (int i = 0; i < len - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < len; j++) {
            if (restaurants[cityRes[i]].value < restaurants[cityRes[j]].value)
                max_idx = j;
        }
        swap(cityRes[i], cityRes[max_idx]);
    }
}

int R;
unordered_map<string, int> hashName, hashMap;

// void addHash(char name[], int res_index) {
void addHash(const string &str, int res_index) {
    // string str(name);
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


void init(int N, int M, int mRoads[][2]) {
    R = 0;
    hashMap.clear();
    hashName.clear();

    for (int i = 0; i < N; i++) {
        Cities[i].neighbors.clear();
        Cities[i].res_indexes.clear();
    }

    for (int i = 0; i < M; i++) {
        int u = mRoads[i][0];
        int v = mRoads[i][1];
        u--, v--;
        Cities[u].neighbors.push_back(v);
        Cities[v].neighbors.push_back(u);
    }
}

void addRestaurant(int mCityID, char mName[]) {
    mCityID--;
    restaurants[R].city = mCityID;
    restaurants[R].value = 0;
    hashName[mName] = R;

    Cities[mCityID].addRes(R);

    if (Cities[mCityID].res_indexes.size() > 3)
        Cities[mCityID].res_indexes.pop_back();

    addHash(mName, R);
    R++;
}

void addValue(char mName[], int mScore) {
    int res_idx = hashName[mName];
    restaurants[res_idx].value += mScore;

    int cityID = restaurants[res_idx].city;

    if (!Cities[cityID].exist(res_idx))
        Cities[cityID].addRes(res_idx);

    sort(Cities[cityID].res_indexes);

    if (Cities[cityID].res_indexes.size() > 3)
        Cities[cityID].res_indexes.pop_back();

    addHash(mName, res_idx);
}

int bestValue(char mStr[]) {
    int idx = hashMap[mStr];
    return restaurants[idx].value;
}

int regionalValue(int mCityID, int mDist) {
    mCityID--;
    int visited[MAX_CITY] = {};
    vector<int> topVal;
    queue<int> q;
    q.push(mCityID);
    visited[mCityID] = 1;
    int cSize = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (visited[u] - 1 > mDist)
            break;

        for (int res_indexes : Cities[u].res_indexes)
            topVal.push_back(restaurants[res_indexes].value);

        for (char v : Cities[u].neighbors) {
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
