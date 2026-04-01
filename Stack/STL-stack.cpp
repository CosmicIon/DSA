#include <iostream>
#include <stack>
using namespace std;

int main() {
    //creation of stack
    stack<int> s;

    //push operation
    s.push(1);
    s.push(2);

    //pop opr.
    s.pop();    //it will remove "2".

    //top element.
    cout << "top element is: " << s.top() << endl;      //output-> top element is: 1

    //stack size
    cout << "size is: " << s.size() << endl;    //output-> size is: 1

    //check empty stack
    cout << "is empty? " << s.empty() << endl;      //output-> is empty? 0
    return 0;
}
