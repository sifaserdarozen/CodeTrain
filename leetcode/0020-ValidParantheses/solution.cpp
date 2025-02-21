// Compute complexity O(N)
// Space complexity O(N)

class Solution {
    public:
        bool isValid(string s) {
            stack<char> hist;
            for (const auto& ch : s) {
                switch (ch) {
                    case '}':
                        if (hist.empty() || hist.top() != '{') {
                            return false;
                        }
                        hist.pop();
                        break;
                    case ')':
                        if (hist.empty() || hist.top() != '(') {
                            return false;
                        }
                        hist.pop();
                        break;
                    case ']':
                        if (hist.empty() || hist.top() != '[') {
                            return false;
                        }
                        hist.pop();
                        break;
                    case '(':
                    case '[':
                    case '{':
                        hist.push(ch);
                        break;
                }
            }
            
            return hist.empty();
        }
    };
    