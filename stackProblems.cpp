//Reverse a String using stack
#include <iostream>
#include <stack>
using namespace std;

void reverseString(string s) {

    stack<string> st;
    int len = s.length();
    string str = "";

    for (int i = 0; i < len; i++) {
        if (s[i] == ' ' || s[i] == '?') {
            str = str + s[i];
            st.push(str);
            str.clear();
        }
        str = str + s[i];
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

void insertAtBottom(stack<int> &st, int ele) {
    if (st.empty()) {
        st.push(ele);
        return;
    }

    int topElement = st.top();
    st.pop();

    insertAtBottom(st, ele);

    st.push(topElement);
}

void ReverseStack(stack<int> &st) {
    if (st.empty()) {
        return;
    }
    int topEle = st.top();
    st.pop();

    ReverseStack(st);
    insertAtBottom(st, topEle);
}

int main(void) {
    stack <int> firstStack;
    
    for (int i = 0; i < 10; i++) {
        firstStack.push(i+1);
    }

    for (int i = 0; i < 10; i++) {
        cout << firstStack.top() << endl;
        firstStack.pop();
    }

    ReverseStack(firstStack);

    for (int i = 0; i < 10; i++) {
        cout << firstStack.top() << endl;
        firstStack.pop();
    }

    cout << "this";
}