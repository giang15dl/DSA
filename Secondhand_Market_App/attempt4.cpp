#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class App {
private:
    static const int MAX_PRODUCTS = 30000;
    static const int MAX_TAGS = 30;
    static const int MAX_LEN = 9; // Maximum length of a tag name

    int N; // The number of tags available on the app

    struct Product {
        int price;
        bool bought;
        Product() : price(0), bought(false) {}
    } products[30000];

    struct Node {
        Product *product;
        Node *next;
        Node() : product(NULL), next(NULL) {}
    } nodes[500000], tagHeads[27000];

    int ncnt, tcnt, pcnt;

    unordered_map<string, int> tags;

    int getTagID(char name[]) {
        auto tag = tags.find(name);
        if (tag == tags.end()) {
            int tid = tcnt++;
            tags[name] = tid;
            return tid;
        }
        return tag->second;
    }

    void add_node(int tagID, Product *product) {
        Node *node = &nodes[ncnt++];
        node->product = product;
        node->next = tagHeads[tagID].next;
        tagHeads[tagID].next = node;
    }

    int hashCode(int a, int b, int c) {
        return a + b * N + c * N * N;
    }

    int hashCode(vector<int> id) {
        return hashCode(id[0], id[1], id[2]);
    }

public:
    App(int N = 0) : N(N) {
        ncnt = tcnt = pcnt = 0;
    }

    void addProduct(int mPrice, int tagNum, char tagName[][10]) {
        vector<int> tagID(tagNum);
        for (int i = 0; i < tagNum; i++)
            tagID[i] = getTagID(tagName[i]);

        sort(tagID.begin(), tagID.end());

        Product *product = &products[pcnt++];

        product->price = mPrice;

        for (int i = 0; i < tagNum; i++) {
            add_node(tagID[i], product);
            for (int j = i + 1; j < tagNum; j++)
                for (int k = j + 1; k < tagNum; k++)
                    add_node(hashCode(tagID[i], tagID[j], tagID[k]), product);
        }
    }

    int buyProduct(char tag1[], char tag2[], char tag3[]) {
        vector<int> tid(3);
        tid[0] = getTagID(tag1);
        tid[1] = getTagID(tag2);
        tid[2] = getTagID(tag3);
        sort(tid.begin(), tid.end());

        int minprice = INT_MAX;
        Node *minnode;

        Node *node = tagHeads[hashCode(tid)].next;
        while (node) {
            Product *product = node->product;
            if (!product->bought) {
                if (minprice > product->price) {
                    minprice = product->price;
                    minnode = node;
                }
            }
            node = node->next;
        }

        if (minprice != INT_MAX) {
            minnode->product->bought = true;
            return minprice;
        }
        return -1;
    }

    void adjustPrice(char tag[], int changePrice) {
        int tid = getTagID(tag);

        Node *node = tagHeads[tid].next;
        while (node) {
            node->product->price += changePrice;
            node = node->next;
        }
    }
} * app;

///////////////////////////////////////////////////////////////////////////////
void init(int N) {
    if (app)
        delete app;
    app = new App(N);
}

void addProduct(int mPrice, int tagNum, char tagName[][10]) {
    app->addProduct(mPrice, tagNum, tagName);
}

int buyProduct(char tag1[], char tag2[], char tag3[]) {
    return app->buyProduct(tag1, tag2, tag3);
}

void adjustPrice(char tag1[], int changePrice) {
    app->adjustPrice(tag1, changePrice);
}
