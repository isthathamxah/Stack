#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

string infixToPostfix(string exp) {
    stack<char> s;
    string result = "";

    for (char ch : exp) {
        if (isalnum(ch)) {
            result += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                result += s.top(); s.pop();
            }
            if (!s.empty()) s.pop(); // Pop '('
        }
        else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                result += s.top(); s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        result += s.top(); s.pop();
    }

    return result;
}

string infixToPrefix(string infix) {
    // 1. Reverse infix
    reverse(infix.begin(), infix.end());

    // 2. Swap '(' and ')'
    for (char& ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    // 3. Get postfix of modified expression
    string postfix = infixToPostfix(infix);

    // 4. Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
