// W: max length of words, NW: number of words
// N: length of target
// Compute Complexity = O(N*W)
// Space Complexity = O(max(N, W*NW))

#define ALPSIZE 'z' - 'a' + 1
#define INTMAX numeric_limits<int>::max()

class Solution {
private:
    struct Dict {
        vector<Dict*> next;
        int cost;

        Dict(): next(vector<Dict*>(ALPSIZE, nullptr)), cost(INTMAX) {};
    };

    void addToDict(Dict* root, const string& str, int cost) {
        for (const auto& ch : str) {
            if (nullptr == root->next[ch - 'a']) {
                root->next[ch - 'a'] = new Dict;
            }
            root = root->next[ch - 'a'];
        }

        // in case cost of word is set multiple times
        root->cost = min(root->cost, cost);
    }

public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        
        auto dict = new Dict();
        for (int i = 0; i < words.size(); ++i) {
            addToDict(dict, words[i], costs[i]);
        }
        
        const int N = target.size();
        vector<int> targetCost(N + 1, INTMAX);
        targetCost.back() = 0;

        for (int idx = N-1; idx >= 0; --idx) {
            auto tmp = dict;
            long long int minCost = INTMAX;
            for (int j = idx; j < N && nullptr != tmp; j++)
            {
                tmp = tmp->next[target[j] - 'a'];
                if (nullptr != tmp && INTMAX != tmp->cost) {
                    minCost = min(minCost, (long long int)tmp->cost + targetCost[j + 1]);
                }
            }
            targetCost[idx] = int(minCost);

        }

        return targetCost.front() == INTMAX ? -1 : targetCost.front();
    }
};