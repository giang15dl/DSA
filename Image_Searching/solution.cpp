#include <cstdlib>
const int MAX_N = 10000;
const int MAX_M = 10;

using namespace std;
class Solution {
private:
    int N, M;
    char (*images)[MAX_M][MAX_M];
    char pixels[MAX_M*MAX_M];
    struct Node {
        Node *child[2]; // Since the image has 2 pixels value;
        int minID;
        Node() : minID(-1) {
            for (int i = 0; i < 2; i++)
                child[i] = NULL;
        }
        ~Node() {
            for (int i = 0; i < 2; i++) {
                delete child[i];
            }
        }
    }*root;

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
        if(pixels[idx] == 0){
            search(node->child[0], res, countMismatch, idx+1);
            search(node->child[1], res, countMismatch+1, idx+1);
        }
        if(pixels[idx] == 1){
            search(node->child[0], res, countMismatch+1, idx+1);
            search(node->child[1], res, countMismatch, idx+1);
        }
    }

    void convert(char image[MAX_M][MAX_M]) {
        for(int i = 0; i < M; i++)
            for(int j = 0; j < M; j++)
                pixels[i * M + j] = image[i][j];
    }

public:
    Solution() {}

    ~Solution() {delete root;}

    Solution(int N, int M, char mImageList[MAX_N][MAX_M][MAX_M]) : N(N), M(M), images(mImageList) {
        root = new Node();
        for (int id = 0; id < N; id++) {
            Node *node = root;
            char (*image)[MAX_M] = mImageList[id];
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    if (!node->child[image[i][j]])
                        node->child[image[i][j]] = new Node();
                    node = node->child[image[i][j]];
                }
            }
            if(node->minID == -1)
                node->minID = id + 1;
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
