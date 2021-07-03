#include <iostream>
#include <string>
#include <stack>

using namespace std;

int mass(char c) {return c == 'C' ? 12 : c == 'H' ? 1 : 16;}

int main(){
    string s;
    cin >> s;
    stack <int> stk;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z')
            stk.push(mass(s[i]));
        else if ( s[i] == '(')
            stk.push(0);
        else if (s[i] == ')') {
            int tmp = 0;
            while ( 1) {
                if(stk.top() == 0) break;
                
                else {
                    tmp += stk.top();
                    stk.pop();
                }
            }
            stk.pop();
            stk.push(tmp);
        }

        else if (s[i] >= '0' && s[i] <= '9') {
            int temp = stk.top();
            temp *= s[i] - '0';
            stk.pop();
            stk.push(temp);
        }
    }
    int res = 0;
    while (!stk.empty()) {
        res += stk.top();
        stk.pop();
    }
    cout << res;
}