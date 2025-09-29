// Compute Complexity O(N)
// Space Complexity O(N)

class Solution {
public:
    int distinctPoints(string s, int k) {
        pair<int, int> prefix = {0, 0};
        pair<int, int> suffix = {0, 0};
        set<pair<int, int>> results;

        for (int i = 0; i < s.size()-k; i++) {
            switch (s[i]) {
            case 'U':
                prefix.first++;
                break;
            case 'D':
                prefix.first--;
                break;
            case 'R':
                prefix.second++;
                break;
            case 'L':
                prefix.second--;
                break;
            }
        }
        results.insert(prefix);

        for (int i = s.size()-k- 1; i >= 0; i--) {
            switch (s[i]) {
            case 'U':
                prefix.first--;
                break;
            case 'D':
                prefix.first++;
                break;
            case 'R':
                prefix.second--;
                break;
            case 'L':
                prefix.second++;
                break;
            }

            switch (s[i+k]) {
            case 'U':
                suffix.first++;
                break;
            case 'D':
                suffix.first--;
                break;
            case 'R':
                suffix.second++;
                break;
            case 'L':
                suffix.second--;
                break;
            }

            results.insert({prefix.first + suffix.first, prefix.second + suffix.second});
        }

        return results.empty()? 1 : results.size();
    }
};