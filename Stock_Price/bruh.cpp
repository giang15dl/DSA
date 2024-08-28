#include <vector>
#include <unordered_map>
#include <set>
#include <string>
 
using namespace std;
 
class Stock {
public:
    Stock() {};
    Stock(int stockCode, int bizcode, string type, int price) {
        this->stockCode = stockCode;
        this->bizcode = bizcode;
        this->type = type;
        this->price = price;
    };
    ~Stock() {};
 
    const bool operator< (const Stock& other) const {
        return this->price == other.price ? this->stockCode < other.stockCode : this->price < other.price;
    }
 
    string GetFeature() {
        return to_string(bizcode) + " " + type;
    }
 
    int stockCode;
    int bizcode;
    string type;
    int price;
};
 
 
unordered_map<int, Stock> stocks;
unordered_map<string, set<Stock>> features;
 
void init() {
    stocks.clear();
    features.clear();
}
 
int add(char mStockInfo[]) {
    string str = string(mStockInfo);
 
    string itemName;
    string val;
 
    unordered_map<string, string> props;
 
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] == '[') {
            itemName.clear();
            int j = i + 1;
            while (j < len && str[j] != ']') {
                itemName.push_back(str[j++]);
            }
            i = j;
        }
        if (str[i] == '{') {
            val.clear();
            int j = i + 1;
            while (j < len && str[j] != '}') {
                val.push_back(str[j++]);
            }
            props[itemName] = val;
            i = j;
        }
    }
 
    int stockCode = atoi(props["STOCKCODE"].c_str());
    auto stock = Stock(stockCode, atoi(props["BIZCODE"].c_str()), props["TYPE"], atoi(props["PRICE"].c_str()));
    stocks[stockCode] = stock;
    features[stock.GetFeature()].insert(stock);
    // int a = features[stock.GetFeature()].begin()->stockCode;
    return features[stock.GetFeature()].rbegin()->stockCode;
}
 
int remove(int mStockCode) {
    auto stock = stocks[mStockCode];
    features[stock.GetFeature()].erase(stock);
    stocks.erase(mStockCode);
    return features[stock.GetFeature()].empty() ? -1 : features[stock.GetFeature()].begin()->stockCode;
}
 
int search(char mCondition[]) {
    string str = string(mCondition);
 
    string itemName;
 
    unordered_map<string, vector<string>> props;
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] == '[') {
            itemName.clear();
            int j = i + 1;
            while (j < len && str[j] != ']') {
                itemName.push_back(str[j++]);
            }
            i = j;
        }
        if (str[i] == '{') {
            int j = i + 1;
            string val;
            while (j < len && str[j] != '}') {
                if (str[j] == ',') {
                    props[itemName].emplace_back(val);
                    val.clear();
                    j++;
                    continue;
                }
                val.push_back(str[j++]);
            }
            if (!val.empty()) {
                props[itemName].emplace_back(val);
            }
            i = j;
        }
    }
 
    int res = -1;
    int resPrice = 1000000007;
 
    for (auto& bizcode : props["BIZCODE"]) {
        for (auto& type : props["TYPE"]) {
            for (auto& price : props["PRICE"]) {
                Stock tmp = Stock(-1, atoi(bizcode.c_str()), type, atoi(price.c_str()));
                auto query = features[tmp.GetFeature()].lower_bound(tmp);
                if (query == features[tmp.GetFeature()].end()) {
                    continue;
                }
                if (query->price == resPrice && query->stockCode < res) {
                    res = query->stockCode;
                }
                else if (query->price < resPrice) {
                    res = query->stockCode;
                    resPrice = query->price;
                }
            }
        }
    }
    return res;
}