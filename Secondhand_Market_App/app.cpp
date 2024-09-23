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
    int N;                        // The number of tags available on the app
    int P;                        // The number of products available on the app
    int T;
    struct Product {
        int price;
        vector<string> tags;
        Product() : price(0) {}

        Product(int price, int tagNum, char tagName[][10]) : price(price), tags(tagNum) {
            for (int i = 0; i < tagNum; i++)
                tags[i] = tagName[i];
        }

        bool contains(char tag1[]) const {
            for (auto tag : tags)
                if (tag == tag1)
                    return true;
            return false;
        }

        bool contains(char tag1[], char tag2[], char tag3[]) const {
            bool flag1 = false, flag2 = false, flag3 = false;
            for (auto tag : tags) {
                if (!flag1 && tag == tag1) {
                    flag1 = true;
                    continue;
                }
                if (!flag2 && tag == tag2) {
                    flag2 = true;
                    continue;
                }
                if (!flag3 && tag == tag3) {
                    flag3 = true;
                    continue;
                }
            }
            if (flag1 && flag2 && flag3)
                return true;
            return false;
        }
    };

    std::list<Product> products;

    unordered_map<string, int> tags;

    int getTagID(char name[], int i) {
        auto it = tags.find(name);
        if (it == tags.end()) {
            tags[name] = i;
            return T++;
        }
        return it->second;
    }

public:
    App() : N() {}

    App(int N) : N(N) {}

    void addProduct(int mPrice, int tagNum, char tagName[][10]) {
        vector<int> tagID(tagNum);
        for (int i = 0; i < tagNum; i++)
            tagID[i] = getTagID(tagName[i], i);

        sort(tagID.begin(), tagID.end());

        Product p(mPrice, tagNum, tagName);
        products.push_back(p);
    }

    int buyProduct(char tag1[], char tag2[], char tag3[]) {
        int min = INT_MAX;
        list<Product>::iterator min_it;
        for (auto it = products.begin(); it != products.end(); it++)
            if (it->contains(tag1, tag2, tag3) && it->price < min)
                min = it->price, min_it = it;

        if (min != INT_MAX) {
            products.erase(min_it);
            return min;
        }
        return -1;
    }

    void adjustPrice(char tag1[], int changePrice) {
        for (auto &product : products)
            if (product.contains(tag1))
                product.price += changePrice;
    }
} app;

///////////////////////////////////////////////////////////////////////////////

void init(int N) {
    app = App(N);
}

void addProduct(int mPrice, int tagNum, char tagName[][10]) {
    app.addProduct(mPrice, tagNum, tagName);
}

int buyProduct(char tag1[], char tag2[], char tag3[]) {
    return app.buyProduct(tag1, tag2, tag3);
}

void adjustPrice(char tag1[], int changePrice) {
    app.adjustPrice(tag1, changePrice);
}
