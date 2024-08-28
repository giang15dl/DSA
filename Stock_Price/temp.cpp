#include <algorithm>
#include <set>
#include <unordered_map>


using namespace std;


#define MAX_N 30000
#define MAX_BITB 8
#define MAX_BITT 4
#define GOTO(s, c) {while(*s != c && *s != 0) s++;}
#define GET_VALUE(s1, s2) {GOTO(s1,'{');s2 = s1 + 1;GOTO(s1,'}');*s1 = 0;}
#define GET_SUB_VALUE(s1, s2) {s2 = s1;GOTO(s1,',');if(*s1){*s1 = 0;s1++;}}


char *get(char *str, int *value, bool isChar = false) {
    char* s;


    GET_VALUE(str, s);
    *value = (isChar ? (*s == 'c' ? 0 : 1) : atoi(s));


    return ++str;
}


char *getAll(char *str, int *num, int values[], bool isChar = false) {
    char *s1, *s2;


    *num = 0;
    GET_VALUE(str, s1);
    while(*s1) {
        GET_SUB_VALUE(s1, s2);
        values[(*num)++] = (isChar ? (*s2 == 'c' ? 0 : 1) : atoi(s2));
    }


    return ++str;
}


struct STOCK_INFO {
    int scode;
    int bcode;
    int type;
    int price;


    void set(int price) {
        this->scode = this->bcode = this->type = 0;
        this->price = price;
    }


    void set(char *str) {
        while(*str) {
            GOTO(str, '[');
            str++;
            if(*str == 'S') str = get(str, &scode);
            if(*str == 'B') str = get(str, &bcode);
            if(*str == 'T') str = get(str, &type, true);
            if(*str == 'P') str = get(str, &price);
        }
    }
};


struct CONDITION_INFO {
    int bcodeNo;
    int bcode[3];
    int typeNo;
    int type[2];
    int price;


    void set(char *str) {
        while(*str) {
            GOTO(str, '[');
            str++;
            if(*str == 'B') str = getAll(str, &bcodeNo, bcode);
            if(*str == 'T') str = getAll(str, &typeNo, type, true);
            if(*str == 'P') str = get(str, &price);
        }
    }
};


struct COMPARE {
    bool operator()(STOCK_INFO* a, STOCK_INFO* b) {
        if (a->price == b->price)
            return a->scode < b->scode;
        return a->price < b->price;
    }
};


int StockCnt;
STOCK_INFO Stocks[MAX_N];
unordered_map<int, STOCK_INFO*> Map;
set<STOCK_INFO*, COMPARE> Price[MAX_BITB][MAX_BITT];


void _init() {
    for(int i = 1 ; i < MAX_BITB ; i++)
        for(int j = 1 ; j < MAX_BITT ; j++)
            Price[i][j].clear();
    Map.clear();
    StockCnt = 0;
}


int _add(char mStockInfo[]) {
    STOCK_INFO* s = &Stocks[StockCnt++];
    int bb, bt;


    s->set(mStockInfo);
    Map[s->scode] = s;
    bb = (1 << (s->bcode - 1));
    bt = (1 << s->type);
    for(int i = 1 ; i < MAX_BITB ; i++)
        for(int j = 1 ; j < MAX_BITT ; j++)
            if(i & bb && j & bt) Price[i][j].insert(s);


    return ((*(Price[bb][bt].rbegin()))->scode);
}


int _remove(int mStockCode) {
    STOCK_INFO* s;
    int bb, bt;
    auto it = Map.find(mStockCode);


    if(it == Map.end()) return -1;


    s = it->second;
    Map.erase(it);
    bb = (1 << (s->bcode - 1));
    bt = (1 << s->type);
    for(int i = 1 ; i < MAX_BITB ; i++)
        for(int j = 1 ; j < MAX_BITT ; j++)
            if(i & bb && j & bt) Price[i][j].erase(s);


    return (Price[bb][bt].size() ? (*(Price[bb][bt].begin()))->scode : -1);
}


int _search(char mCondition[]) {
    STOCK_INFO s;
    CONDITION_INFO c;
    int i, j;

    c.set(mCondition);
    i = j = 0;
    for(int a = 0 ; a < c.bcodeNo ; a++) i |= (1 << (c.bcode[a] - 1));
    for(int a = 0 ; a < c.typeNo ; a++) j |= (1 << c.type[a]);
    s.set(c.price);


    auto it = Price[i][j].lower_bound(&s);


    return (it == Price[i][j].end() ? -1 : (*it)->scode);
}