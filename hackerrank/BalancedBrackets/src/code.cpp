#include <stack>
#include <iostream>

using namespace std;

/** function checking expression syntax
 *
 *  Function checks weather opened expressions involving symbols '{[(' are
 *  closed with appropriate ones '}])'
 *
 *  Time complexity is O(n), where n is length of input string
 *  Space complexity is O(n/2)
 *
 *  Example: 
 *          {[()]}        : true
 *          {[(])}        : false
 *          {{[[(())]]}}  : true
 *
 *  @param expression input string to check expressions
 *  @return wheather expressions are perfectly matched or not
 */
bool is_balanced(string expression) {
    std::stack<char> expression_stack;
    
    // iterate throuugh input string and try to match expression pairs
    for (unsigned int i = 0; i < expression.size(); ++i)
    {
        char cur_char = expression[i];
        if (']' == cur_char)
        {
            if ((0 != expression_stack.size()) && ('[' == expression_stack.top()))
                expression_stack.pop();
            else
                return false;
        }
        else if (')' == cur_char)
        {
            if ((0 != expression_stack.size()) && ('(' == expression_stack.top()))
                expression_stack.pop();
            else
                return false;
        }
        else if ('}' == cur_char)
        {
            if ((0 != expression_stack.size()) && ('{' == expression_stack.top()))
                expression_stack.pop();
            else
                return false;
        }
        else
            expression_stack.push(cur_char);          
    }
    
    // chack is stack is empty, which means all opened expressions
    // are perfectly closed
    if (0 == expression_stack.size())
        return true;
    else
        return false;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

