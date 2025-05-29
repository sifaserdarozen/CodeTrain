// Compute Complexity O(N)
// Space Complexity O(N)

class Solution {
private:
    bool isConsecutive(char a, char b) {
        auto diff = abs(int(a) - int(b));
        return (diff == 1 || diff == ('z' - 'a'));
    }
public:
    string resultingString(string s) {
        stack<char> chars;

        for (const auto& ch: s) {
            if (!chars.empty() && isConsecutive(chars.top(), ch)) {
                chars.pop();
            } else {
                chars.push(ch);
            }
        }

        // form an empty string with size of stack
        auto res = string(chars.size(), ' ');

        auto it = res.rbegin();
        while (!chars.empty()) {
            *it = chars.top();
            chars.pop();
            it++;
        }

        return res;
    }
};