#include <bits/stdc++.h>
using namespace std;

// 判断是否为括号
bool isPra(char c) {
    return (c == '(' || c == ')') ? true : false;
}

// 获得符号的优先性
int getPri(char c)
{
    switch (c) {
        case '+':
        case '-':
            return 0;
            break;
        case '*':
        case '/':
            return 1;
            break;
        case '(':
        case ')':
            return -1;
            break;
        default:
            cout << "输入其他运算符\n" << endl;
    }
}

void check(char c, stack<char>& operator_s, string& suffix) {
    if (operator_s.empty()) {
        operator_s.push(c);
        return;
    }

    if (isPra(c)) {
        if (c == '(') {
            operator_s.push(c);
        }
        else {
            while (operator_s.top() != '(') {
                suffix += operator_s.top();
                operator_s.pop();
            }
            operator_s.pop();
        }
    }
    else {
        if (getPri(c) > getPri(operator_s.top())) {
            operator_s.push(c);
        }
        else {
            suffix += operator_s.top();
            operator_s.pop();
            check(c, operator_s, suffix);
        }
    }
}

string infixToSuffix(string& infix) {
    stack<char> operator_s;
    string suffix;

    for (char i : infix) {
        if (i >= '0' && i <= '9') {
            suffix += i;
        }
        else {
            check(i, operator_s, suffix);
        }
    }

    while (!operator_s.empty()) {
        suffix += operator_s.top();
        operator_s.pop();
    }

    return suffix;
}

template <typename T>
T pop(stack<T> st) {
    T a = st.top();
    st.pop();
    return a;
}

int main() {
    string formula;
    cin >> formula;
    formula = infixToSuffix(formula);
    stack<int> st;
    for (char c : formula) {
        if (isdigit(c)) st.push(c - '0');
        else if (c == '+') {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a+b);
        }
        else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a*b);
        }
    }
    cout << st.top();
    return 0;
}
