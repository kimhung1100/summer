#include <iostream>
#include <stack>

using namespace std;

int change(char c){
    if (c == 'H')
        return 1;
    else if ( c == 'C')
        return 12;
    else if ( c == 'O')
        return 18;
    else
        return 0;
}
int main(){
    string s;
    cin >> s;
    stack <char> stk;
    int m = 0;
    int tmp = 0;
    int i = 0;
    for( ; i < s.size(); i++) {
        if(change(s[i]) != 0)
            m += change(s[i]);
        else if ( s[i] == '(') {
            int temp = 0;
            for(int i )
        }
        else if (s[i] >= '1' && s[i] <= '9') {
            s[i] - 48 ;
        }
        else if (s[i] == ')') 


    }
}