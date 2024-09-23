#include <climits>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
private:
    struct Stock {
    private:
        int makeFeature(int bizcode, char type) {
            return bizcode * 26 + (type - 'a');
        }

    public:
        int code;
        int bizcode;
        char type;
        int price;
        int feature;

        bool operator<(const Stock &that) const {
            return price == that.price ? code < that.code : price < that.price;
        }

        Stock(int bizcode = 0, char type = 0, int price = 0, int code = 0) : code(code), bizcode(bizcode), type(type), price(price) {
            feature = makeFeature(bizcode, type);
        }

        Stock(char str[]) {
            int start = 0;
            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i + 1] == ',' || str[i + 1] == '\0') {
                    string substr = string(str, start, i - start + 1);
                    start = i + 2;
                    int len = substr.length();
                    string item, value;
                    for (int j = 0; j < len; j++) {
                        if (substr[j] == '=') {
                            item = substr.substr(1, j - 2);
                            value = substr.substr(j + 2, len - j - 3);
                            break;
                        }
                    }
                    switch (item[0]) {
                    case 'P':
                        price = stoi(value);
                        break;
                    case 'T':
                        type = value[0];
                        break;
                    case 'S':
                        code = stoi(value);
                        break;
                    case 'B':
                        bizcode = stoi(value);
                        break;
                    default:
                        break;
                    }
                }
            }
            feature = makeFeature(bizcode, type);
        }
    };

    struct Condition {
        int bizcode[3];
        char type[2];
        int price;
        int t, b;

    public:
        Condition() {}
        Condition(char str[]) : t(0), b(0) {
            int start = 0;
            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i + 1] == ';' || str[i + 1] == '\0') {
                    string substr = string(str, start, i - start + 1);
                    start = i + 2;
                    int len = substr.length();
                    string item, value;
                    for (int j = 0; j < len; j++) {
                        if (substr[j] == '=') {
                            item = substr.substr(1, j - 2);
                            value = substr.substr(j + 2, len - j - 3);
                            break;
                        }
                    }
                    switch (item[0]) {
                    case 'P':
                        price = stoi(value);
                        break;
                    case 'T':
                        if (value.length() == 6)
                            type[0] = 'c', t = 1;
                        else if (value.length() == 9)
                            type[0] = 'p', t = 1;
                        else
                            type[0] = 'c', type[1] = 'p', t = 2;
                        break;
                    case 'B':
                        for (unsigned int k = 0; k < value.length(); k += 2) {
                            bizcode[b] = value[k] - '0';
                            b++;
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    };
    unordered_map<int, Stock> stocks;
    unordered_map<int, set<Stock>> features;

public:
    Solution() {}

    int add(char mStockInfo[]) {
        Stock stock(mStockInfo);
        stocks[stock.code] = stock;
        features[stock.feature].insert(stock);
        set<Stock>::reverse_iterator rit = features[stock.feature].rbegin();
        return rit->code;
    }

    int remove(int mStockCode) {
        Stock stock = stocks[mStockCode];
        features[stock.feature].erase(stock);
        stocks.erase(mStockCode);
        set<Stock>::iterator it = features[stock.feature].begin();
        if (it == features[stock.feature].end())
            return -1;
        return it->code;
    }

    int search(char mCondition[]) {
        Condition c(mCondition);

        int min = INT_MAX, mincode = -1;

        for (int i = 0; i < c.b; i++) {
            for (int j = 0; j < c.t; j++) {
                Stock stock(c.bizcode[i], c.type[j], c.price);
                set<Stock>::iterator it = features[stock.feature].lower_bound(stock);
                if (it == features[stock.feature].end())
                    continue;

                if (it->price == min && it->code < mincode)
                    mincode = it->code;

                else if (it->price < min)
                    mincode = it->code, min = it->price;
            }
        }

        return mincode;
    }

} solution;

///////////////////////////////////////////////////////////////////////////////
void init() { solution = Solution(); }
int add(char mStockInfo[]) { return solution.add(mStockInfo); }
int remove(int mStockCode) { return solution.remove(mStockCode); }
int search(char mCondition[]) { return solution.search(mCondition); }
