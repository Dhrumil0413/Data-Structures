#include <iostream>
using namespace std;

#define MaxSize 100

class stack {
    private:
        int* pArray;
        int ptr;

    public:
        stack() {
            pArray = new int[MaxSize];
            ptr = -1;
        }

        int top() {
            if (ptr == -1)
                return -1;
            
            return pArray[ptr];
        }

        void push(int x) {
            if (ptr == MaxSize-1){
                return;
            }
            ptr++;
            pArray[ptr] = x;
        }

        void pop() {
            if (ptr == -1) {
                return;
            }
            ptr--;
        }

        bool empty() {
            if (ptr == -1) {
                return true;
            }
            return false;
        }

};

void insertAtBottom(stack &st, int ele) {
    if (st.empty()) {
        st.push(ele);
        return;
    }
    int topEle = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(topEle);
}

void ReverseStack(stack &st) {
    if (st.empty()) {
        return;
    }

    int topEle = st.top();
    st.pop();
    ReverseStack(st);

    insertAtBottom(st, topEle);
}

void printStack(stack st, int size) {
    for (int i = 0; i < size; i++) {
        cout << st.top() << ", ";
        st.pop();
    }
    cout << endl;
}

int main(void) {
    stack st;
    int size = 10;

    for (int i = 0; i < size; i++) {
        st.push(i+1);
    }   

    printStack(st, size);

    ReverseStack(st);

    printStack(st, size);
}