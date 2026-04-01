#include<iostream>
#include<stack>
using namespace std;

class Stack {
    //properties
    public:
        int *arr;
        int top;
        int size;

    //behaviour
    Stack(int size) {
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    void push(int element) {
        //check is space available?
        if(size - top > 1) {
            top++;
            arr[top] = element;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        //check is element present?
        if(top <= -1) {
            cout << "Stack Underflow" << endl;
        } else {
            top--;
        }
    }

    int peek() {
        //check if stack is empty
        if(top <= -1) {
            cout << "Stack is empty" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    bool empty() {
        if(top == -1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {

    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(22);
    st.push(16);

    cout << "top element is " << st.peek() << endl;     //output-> top element is 16

    st.pop();
    cout << "top element is " << st.peek() << endl;     //output-> top element is 22

    st.pop();
    cout << "top element is " << st.peek() << endl;     //output-> top element is 2

    st.pop();
    cout << "top element is " << st.peek() << endl;     //output-> top element is 1

    st.pop();
    cout << "top element is " << st.peek() << endl;     //output-> Stack is empty top element is -1

    return 0;
}