#include<iostream>
#include<string>
using namespace std;

void reverse(string &s, int i, int j) {
    //base case
    if(i>j) return;

    else {
        swap(s[i], s[j]); //processing
        reverse(s, i+1, j-1); //recursive call
    }
}

int main(){
    string s = "abcde";
    reverse(s, 0, s.length()-1);
    cout << s << endl;

    string s1 = "Harsh Nivedan";
    reverse(s1, 0, s1.length()-1);
    cout << s1 << endl;

    return 0;
}