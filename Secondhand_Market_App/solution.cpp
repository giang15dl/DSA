#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
    static const int MAX_PRODUCTS = 30000;
    static const int MAX_TAGS = 30;
    static const int MAX_LEN = 9; // Maximum length of a tag name

    int N; // The number of tags available on the app
    int P; // Count total products

    struct Product {
        int price;
        bool bought;
        Product() : price(0), bought(false) {}
        Product(int price) : price(price), bought(false) {}
    };

    vector<Product> products;

    unordered_map<string, vector<int>> hash1tag;
    unordered_map<string, vector<int>> hash3tag;

    int hashCode(int a, int b, int c) {
        return a + b * N + c * N * N;
    }

    int hashCode(vector<int> id) {
        return hashCode(id[0], id[1], id[2]);
    }

public:
    Solution(int N = 0) : N(N), P(0) {}

    void addProduct(int mPrice, int tagNum, char tagName[][10]) {
        products.push_back(Product(mPrice));
        vector<string> tags(tagNum);
        for (int i = 0; i < tagNum; i++) {
            tags[i] = tagName[i];
            hash1tag[tags[i]].push_back(P);
        }

        sort(tags.begin(), tags.end());

        for (int i = 0; i < tagNum; i++) {
            for (int j = i + 1; j < tagNum; j++) {
                for (int k = j + 1; k < tagNum; k++) {
                    string str = tags[i] + tags[j] + tags[k];
                    hash3tag[str].push_back(P);
                }
            }
        }
        P++;
    }

    int buyProduct(char tag1[], char tag2[], char tag3[]) {
        vector<string> tag(3);
        tag[0] = tag1;
        tag[1] = tag2;
        tag[2] = tag3;

        sort(tag.begin(), tag.end());

        string str = tag[0] + tag[1] + tag[2];

        int min = INT_MAX;
        int minIndex = -1;

        for (auto id : hash3tag[str])
            if (!products[id].bought && products[id].price < min)
                min = products[id].price, minIndex = id;

        if (min != INT_MAX) {
            products[minIndex].bought = true;
            return min;
        }

        return -1;
    }

    void adjustPrice(char tag1[], int changePrice) {
        for (auto id : hash1tag[tag1])
            products[id].price += changePrice;
    }
} solution;

///////////////////////////////////////////////////////////////////////////////
void init(int N) {
    solution = Solution(N);
}

void addProduct(int mPrice, int tagNum, char tagName[][10]) {
    solution.addProduct(mPrice, tagNum, tagName);
}

int buyProduct(char tag1[], char tag2[], char tag3[]) {
    return solution.buyProduct(tag1, tag2, tag3);
}

void adjustPrice(char tag1[], int changePrice) {
    solution.adjustPrice(tag1, changePrice);
}
