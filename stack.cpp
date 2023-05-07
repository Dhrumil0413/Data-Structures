#include <iostream>
using namespace std;

#define n 100

class stack {
    int *PtrArray;
    int top;

    public:
        stack() {
            PtrArray = new int[n];
            top = -1;
        }

        void push(int x) {
            if (top == n-1) {
                cout << "Stack Overflow" << endl;
                return;
            }
            top++;
            PtrArray[top] = x;

        }

        void pop() {
            if (top == -1){
                cout << "Stack is Empty" << endl;
                return;
            }
            
            top--;
        }

        int Top(){
            if (top == -1) {
                cout << "Stack is Empty" << endl;
                return -1;
            }
            return PtrArray[top];

        }
        bool empty() {
            if (top == -1) {
                return true;
            } 
            return false;
        }
};

int main(void)  {
    stack firstStack;
    
    for (int i = 0; i < 10; i++) {
        firstStack.push(i+1);
    }

    for (int i = 0; i < 10; i++) {
        cout << firstStack.Top() << endl;
        firstStack.pop();
    }

    std::cout << boolalpha;
    cout << firstStack.empty() << endl;
}