#include <cstdlib>
const int MAX_N = 10000;
const int MAX_M = 10;

using namespace std;
class Solution {
private:
    int N, M;
    char (*images)[MAX_M][MAX_M];
    char temp[MAX_M*MAX_M];
    struct Node {
        Node *child[2]; // Since the image has 2 pixels value;
        int minID;
        Node() : minID(-1) {
            for (int i = 0; i < 2; i++)
                child[i] = NULL;
        }
    }*root, pool[1000000];

    int nodes;
    int diffPixels;

    void search(Node* node, int &res, int countMismatch = 0, int idx = 0) {
        if(countMismatch > 2 || node == NULL)
            return;
        if(idx == M*M){
            if(res == -1 && diffPixels == -1){
                res = node->minID;
                diffPixels = countMismatch;
            }
            else if(diffPixels > countMismatch || (diffPixels == countMismatch && res > node->minID)){
                res = node->minID;
                diffPixels = countMismatch;
            }
            return;
        }
        if(temp[idx] == 0){
            search(node->child[0], res, countMismatch, idx+1);
            search(node->child[1], res, countMismatch+1, idx+1);
        }
        if(temp[idx] == 1){
            search(node->child[0], res, countMismatch+1, idx+1);
            search(node->child[1], res, countMismatch, idx+1);
        }
    }

    void convert(char mImage[MAX_M][MAX_M]) {
        for(int i = 0; i < M; i++)
            for(int j = 0; j < M; j++)
                temp[i * M + j] = mImage[i][j];
    }

public:
    Solution() {}

    Solution(int N, int M, char mImageList[MAX_N][MAX_M][MAX_M]) : N(N), M(M), images(mImageList) {
        nodes = 0;
        Node* newNode = &pool[nodes++];
        root = newNode;

        for (int id = 0; id < N; id++) {
            Node *temp = root;
            char (*image)[MAX_M] = mImageList[id];
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    if (!temp->child[image[i][j]]) {
                        Node* newNode = &pool[nodes++];
                        temp->child[image[i][j]] = newNode;
                    }
                    temp = temp->child[image[i][j]];
                }
            }
            if(temp->minID == -1)
                temp->minID = id + 1;
        }
    }

    int findImage(char mImage[MAX_M][MAX_M]) {
        int res = -1;
        diffPixels = -1;
        convert(mImage);
        search(root, res);
        return res;
    }
}*solution;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void init(int N, int M, char mImageList[MAX_N][MAX_M][MAX_M]) { if (solution) delete solution; solution = new Solution(N, M, mImageList); }
int findImage(char mImage[MAX_M][MAX_M]) { return solution->findImage(mImage); }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

