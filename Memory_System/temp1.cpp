#include <vector>
#include <queue>
#include <map>
#include <functional>

using namespace std;

int n;

map<int, int> fms, fml, a;

map<int, priority_queue<int, vector<int>, greater<int>>> f;

void init(int N) {
    fms.clear();
    fml.clear();
    a.clear();
    f.clear();
    n=N;
    f[n].push(0);
    fms[0]=n;
    fml[n-1]=n;
    return;
}

int allocate(int mSize) {
    auto i=f.lower_bound(mSize);
    if(i==f.end())
        return -1;
    int size=i->first;
    int index=(i->second).top();
    (i->second).pop();
    if((i->second).empty()) //if heap becomes empty delete it from map f
        f.erase(i->first);
    fms.erase(index);
    fml.erase(size+index-1);
    if(mSize<size){ // if empty space is more than mSize, move extra remaining size to map
        int e_size= size-mSize;
        int e_index= mSize+index;
        f[e_size].push(e_index);
        fms[e_index]=e_size;
        fml[e_index+e_size-1]=e_size;
    }
    a[index]=mSize;
    return index;
}


int release(int mAddr) { // replace it with mAddr
    int mIndex=mAddr,mStart=mAddr,mEnd;
    if(a.find(mIndex)==a.end()|| fms.find(mIndex)!=fms.end())
        return -1;
    int mSize=a[mIndex], released=a[mIndex];
    mEnd=mStart+mSize-1;
    a.erase(mIndex);
    int before_start=mIndex-1, after_end=mIndex+mSize;

    if(fml.find(before_start)!=fml.end()){ // if index just before mIndex is free
        int size= fml[before_start], end=before_start;
        int start=end-size+1;
        vector<int>t;
        while(f[size].top()!=start){
            t.push_back(f[size].top());
            f[size].pop();
        }
        f[size].pop();
        for(auto &x: t)
            f[size].push(x);
        if(f[size].empty())
            f.erase(size);
        mSize+=size;
        fml.erase(end);
        fms.erase(start);
        mStart=start;
    }

    if(fms.find(after_end)!=fms.end()){ // if index just after end of main is free 
        int size= fms[after_end];
        int start=after_end;
        int end=start+size-1;
        vector<int>t;
        while(f[size].top()!=start){
            t.push_back(f[size].top());
            f[size].pop();
        }
        f[size].pop();
        for(auto &x: t)
            f[size].push(x);
        if(f[size].empty())
            f.erase(size);
        mSize+=size;
        fml.erase(end);
        fms.erase(start);
        mEnd=end;
    }
    fms[mStart]=mSize;
    fml[mEnd]=mSize;
    f[mSize].push(mStart);
    return released;
}
