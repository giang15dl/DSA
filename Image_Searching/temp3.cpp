#include <iostream>
using namespace std;

#define MAX_N (10000)
#define MAX_M (10)

struct TrieNode {
    TrieNode* childNode[2];
    int index_min;
}pool[1000005];

int countNode;
TrieNode* getNode(){
    TrieNode* newNode = &pool[countNode++];
    newNode->index_min = -1;
    for(int i = 0; i < 2; i++)
        newNode->childNode[i] = NULL;
    return newNode;
}
char Temp[MAX_M*MAX_M];
int res, countMis;
TrieNode* root;
int n, m;

void init(int N, int M, char mImageList[MAX_N][MAX_M][MAX_M]) {
    countNode = 0;
    root = getNode();
    n = N, m = M;
    for(int i = 0; i < n; i++) {
        TrieNode* tmp = root;
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                if(tmp->childNode[mImageList[i][j][k]] == NULL){
                    tmp->childNode[mImageList[i][j][k]] = getNode();
                }
                tmp = tmp->childNode[mImageList[i][j][k]];
            }
        }
        if(tmp->index_min == -1)
            tmp->index_min = i+1;
    }
}

void search(TrieNode* node, int countMismatch, int idx) {
    if(countMismatch > 2 || node == NULL)
        return;
    if(idx == m*m){
        if(res == -1 && countMis == -1){
            res = node->index_min;
            countMis = countMismatch;
        }
        else if(countMis > countMismatch || (countMis == countMismatch && res > node->index_min)){
            res = node->index_min;
            countMis = countMismatch;
        }
        return;
    }
    if(Temp[idx] == 0){
        search(node->childNode[0], countMismatch, idx+1);
        search(node->childNode[1], countMismatch+1, idx+1);
    }
    if(Temp[idx] == 1){
        search(node->childNode[0], countMismatch+1, idx+1);
        search(node->childNode[1], countMismatch, idx+1);
    }
}

void convert(char mImage[MAX_M][MAX_M]) {
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            Temp[m*i+j] = mImage[i][j];
}


int findImage(char mImage[MAX_M][MAX_M]) {
    res = -1, countMis = -1;
    convert(mImage);
    search(root, 0, 0);
    return res;
}
