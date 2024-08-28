#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

const int MAX_CITY = 50;
const int MAX_ROAD = 50;
const int MAX_RES = 10000;

using namespace std;

struct Res {
    int city;
    int val;
};

struct City {
    vector<char> neighbors;
    vector<int> res;

    void addRes(int idx) {
        res.push_back(idx);
    }

    bool exist(int idx) const {
        for (int r : res)
            if (r == idx)
                return true;

        return false;
    }

};

Res Restaurants[MAX_RES];
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
            if (Restaurants[ptr[i]].val < Restaurants[ptr[j]].val)
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
            if (Restaurants[cityRes[i]].val < Restaurants[cityRes[j]].val)
                max_idx = j;
        }
        swap(cityRes[i], cityRes[max_idx]);
    }
}

int nextRes;
unordered_map<string, int> hashName, hashMap;

void init(int N, int M, int mRoads[][2]) {
    nextRes = 0;
    hashMap.clear();
    hashName.clear();

    for (int i = 0; i < N; i++) {
        Cities[i].neighbors.clear();
        Cities[i].res.clear();
    }

    for (int i = 0; i < M; i++) {
        int u = mRoads[i][0];
        int v = mRoads[i][1];
        u--, v--; // Reset to 0-based index
        Cities[u].neighbors.push_back(v);
        Cities[v].neighbors.push_back(u);
    }
}

void addHash(char mName[], int resIdx) {
    string strName(mName);
    string tmp;

    for (unsigned int len = 1; len <= strName.size(); len++) {
        for (unsigned int i = 0; i + len <= strName.size(); i++) {
            tmp = strName.substr(i, len);
            if (!hashMap[tmp])
                hashMap[tmp] = resIdx;

            else if (Restaurants[hashMap[tmp]].val < Restaurants[resIdx].val)
                hashMap[tmp] = resIdx;
        }
    }
}

void addRestaurant(int mCityID, char mName[]) {
    mCityID--; // Reset to 0-based index
    Restaurants[nextRes].city = mCityID;
    Restaurants[nextRes].val = 0;
    hashName[mName] = nextRes;

    Cities[mCityID].addRes(nextRes);

    if (Cities[mCityID].res.size() > 3)
        Cities[mCityID].res.pop_back();

    addHash(mName, nextRes);
    nextRes++;
}

void addValue(char mName[], int mScore) {
    int res_idx = hashName[mName];
    Restaurants[res_idx].val += mScore;

    int cityID = Restaurants[res_idx].city;

    if (!Cities[cityID].exist(res_idx))
        Cities[cityID].addRes(res_idx);

    sort(Cities[cityID].res);

    if (Cities[cityID].res.size() > 3)
        Cities[cityID].res.pop_back();

    addHash(mName, res_idx);
}

int bestValue(char mStr[]) {
    int idx = hashMap[mStr];
    return Restaurants[idx].val;
}

int regionalValue(int mCityID, int mDist) {
    mCityID--; // Reset to 0-based index
    int visited[MAX_CITY] = {};
    int dist[MAX_CITY] = {};
    int idxTopVal[4] = {};

    queue<int> q;
    q.push(mCityID);
    visited[mCityID] = 1;
    int cSize = 0;

    while (!q.empty()) {
        int fnt = q.front();
        q.pop();

        if (dist[fnt] > mDist)
            break;

        for (unsigned int j = 0; j < Cities[fnt].res.size(); j++) {
            if (cSize >= 3 && Restaurants[Cities[fnt].res[j]].val < Restaurants[idxTopVal[cSize - 1]].val)
                break;

            idxTopVal[cSize++] = Cities[fnt].res[j];
            sort(idxTopVal, cSize);
            cSize = (cSize > 3) ? 3 : cSize;
        }

        for (char city : Cities[fnt].neighbors) {
            if (visited[city])
                continue;

            q.push(city);
            dist[city] = dist[fnt] + 1;
            visited[city] = 1;
        }
    }
    return Restaurants[idxTopVal[0]].val + Restaurants[idxTopVal[1]].val + Restaurants[idxTopVal[2]].val;
}

