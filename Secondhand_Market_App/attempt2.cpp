#include <climits>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

class App {
private:
    static const int MAX_PRODUCTS = 30000;
    static const int MAX_TAGS = 30;
    static const int MAX_LEN = 9; // Maximum length of a tag name
    int N;                        // The number of tags available on the app
    struct Product {
        int price;
        vector<string> tags;
        Product();
        Product(int, int, char[][10]);
        bool contains(char[]) const;
        bool contains(char[], char[], char[]) const;
    };

    std::list<Product> products;

public:
    App(int N);
    void addProduct(int, int, char[][10]);
    int buyProduct(char[], char[], char[]);
    void adjustPrice(char[], int);
};

/*****************************************************************************/
App *app;

void init(int N) {
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
/*****************************************************************************/

App::Product::Product() : price(0) {}

App::Product::Product(int price, int tagNum, char tagName[][10]) : price(price) {
    tags.resize(tagNum);
    for (int i = 0; i < tagNum; i++)
        tags[i] = tagName[i];
}

bool App::Product::contains(char tag1[]) const {
    for (string tag : tags)
        if (tag == tag1)
            return true;
    return false;
}

bool App::Product::contains(char tag1[], char tag2[], char tag3[]) const {
    bool flag1 = false, flag2 = false, flag3 = false;
    for (string tag : tags) {
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

App::App(int N) : N(N) {}

void App::addProduct(int mPrice, int tagNum, char tagName[][10]) {
    Product p(mPrice, tagNum, tagName);
    products.push_back(p);
}

int App::buyProduct(char tag1[], char tag2[], char tag3[]) {
    int min = INT_MAX;
    auto min_it = products.begin();
    for (auto it = products.begin(); it != products.end(); it++)
        if (it->contains(tag1, tag2, tag3) && it->price < min)
            min = it->price, min_it = it;

    if (min < INT_MAX) {
        products.erase(min_it);
        return min;
    }
    return -1;
}

void App::adjustPrice(char tag1[], int changePrice) {
    for (Product &product : products)
        if (product.contains(tag1))
            product.price += changePrice;
}