#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<int> q;
    cout << q.front() << endl;

    q.push(1);
    cout << q.front() << endl;

    q.push(2);
    q.push(3);
    cout << q.front() << endl;

    cout << "size is -> " << q.size() << endl;
    
    q.pop();
    cout << "size is -> " << q.size() << endl;

    cout << q.empty() << endl; //false
    q.pop();
    q.pop();
    cout << q.empty() << endl; //true
    cout << q.front() << endl;

    q.pop();
    cout << q.empty() << endl; //false (why?) because pop shows undefined behaviour when queue is empty
    cout << q.front() << endl;
    return 0;
}