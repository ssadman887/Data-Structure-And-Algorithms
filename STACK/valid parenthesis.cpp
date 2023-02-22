#include<bits/stdc++.h>

bool isValid(std::string s) {
    std::stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else if (c == ')' && !stk.empty() && stk.top() == '(') {
            stk.pop();
        } else if (c == '}' && !stk.empty() && stk.top() == '{') {
            stk.pop();
        } else if (c == ']' && !stk.empty() && stk.top() == '[') {
            stk.pop();
        } else {
            return false;
        }
    }
    return stk.empty();
}



int main() {
    std::string s = "{[()]}";
    bool valid = isValid(s);
    std::cout << "Is the string \"" << s << "\" valid?\n" << std::boolalpha << valid << std::endl;
    return 0;
}
