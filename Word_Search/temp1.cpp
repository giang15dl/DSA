#include <string>
#include <vector>

using namespace std;
class Solution {
private:
    struct Words {
        string word;
        int count;
        Words() : count(0), word() {}
        Words(const string &word) : count(1), word(word) {}

        // Search with wildcard characters
        bool contains(const string &str) const {
            if (word.length() != str.length())
                return false;
            for (unsigned int i = 0; i < word.length(); i++) {
                if (str[i] == '?')
                    continue;
                if (word[i] != str[i])
                    return false;
            }
            return true;
        }
    };
    vector<Words> system;

public:
    Solution() {}

    int add(char str[]) {
        for (auto &words : system) {
            if (words.word == str) {
                words.count++;
                return words.count;
            }
        }
        system.push_back(Words(str));
        return 1;
    }

    int remove(char str[]) {
        int count = 0;
        for (auto &words : system) {
            if (words.contains(str)) {
                count += words.count;
                words.count = 0;
            }
        }
        return count;
    }

    int search(char str[]) {
        int count = 0;
        for (auto &words : system) {
            if (words.contains(str)) {
                count += words.count;
            }
        }
        return count;
    }

} solution;

////////////////////////////////////////////////////////////////////////////////
void init() { solution = Solution(); }
int add(char str[]) { return solution.add(str); }
int remove(char str[]) { return solution.remove(str); }
int search(char str[]) { return solution.search(str); }
////////////////////////////////////////////////////////////////////////////////
