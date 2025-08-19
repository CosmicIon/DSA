#include <iostream>
#include <string>
using namespace std;

bool checkPallindrom(string &s, int i, int j)
{
    // base case
    if (i > j)
        return true;
    if (s[i] != s[j])
        return false;

    checkPallindrom(s, i + 1, j - 1); // recursive call
}

// with only one variable
bool checkPallindromWithOneVariable(string &s, int i)
{
    // base case
    if (i > s.length() - 1 - i)
        return true;
    if (s[i] != s[s.length() - 1 - i])
        return false;

    checkPallindromWithOneVariable(s, i + 1); // recursive call
}

int main()
{
    string s = "abbcbba";
    cout << checkPallindrom(s, 0, s.length() - 1) << endl;

    cout << checkPallindromWithOneVariable(s, 0) << endl;

    return 0;
}