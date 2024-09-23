#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class App {
private:
    static const int MAX_PRODUCTS = 30000;
    static const int MAX_TAGS = 30;
    static const int MAX_LEN = 9; // Maximum length of a tag name
    int N;                        // The number of tags available on the app
    int cnt;                      // Count number of products added to the app
    struct Product {
        int price;
        bool bought;
        vector<string> tags;
        Product();
        bool contains(char[]) const;
        bool contains(char[], char[], char[]) const;
    } products[MAX_PRODUCTS];

public:
    App(int N);
    void addProduct(int, int, char[][10]);
    int buyProduct(char[], char[], char[]);
    void adjustPrice(char[], int);
} * app;

/*****************************************************************************/
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

App::Product::Product() : price(0), bought(false) {}

bool App::Product::contains(char tag1[]) const {
    for (string tag : tags)
        if (tag == tag1)
            return true;
    return false;
}

bool App::Product::contains(char tag1[], char tag2[], char tag3[]) const {
    // TODO : Refactor this function, try to use the above function.
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

App::App(int N) : N(N), cnt(0) {}

void App::addProduct(int mPrice, int tagNum, char tagName[][10]) {
    products[cnt].price = mPrice;
    products[cnt].tags.resize(tagNum);
    for (int i = 0; i < tagNum; i++)
        products[cnt].tags[i] = tagName[i];
    cnt++;
}

int App::buyProduct(char tag1[], char tag2[], char tag3[]) {
    int min = INT_MAX;
    int minIdx = 0;
    for (int i = 0; i < cnt; i++) {
        const Product *product = &products[i];
        if (product->bought)
            continue;
        if (product->contains(tag1, tag2, tag3) && product->price < min)
            min = product->price, minIdx = i;
    }
    //return (min < INT_MAX) ? min : -1;
    if (min < INT_MAX) {
        products[minIdx].bought = true;
        return min;
    }
    return -1;
}

void App::adjustPrice(char tag1[], int changePrice) {
    for (int i = 0; i < cnt; i++) {
        Product *product = &products[i];
        if (product->bought)
            continue;
        if (product->contains(tag1))
            product->price += changePrice;
    }
}