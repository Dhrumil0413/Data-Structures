#include <iostream>
#include <stack>
using namespace std;

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

void printStack(stack<int> st, int size) {
    for (int i = 0; i < size; i++) {
        cout << st.top() << ", ";
        st.pop();
    }
    cout << endl;
}

int main(void) {
    int size = 10;
    stack<int> st;

    for (int i = 0; i < size; i++) {
        st.push(i+1);
    }

    printStack(st, size);

    ReverseStack(st);

    printStack(st, size);
}