#include <iostream>
#include <string>

using namespace std;
string s;
int mass(char c) {return c == 'C' ? 12 : c == 'H' ? 1 : 16; }

int cal(int l, int h) {
    int sum = 0;

    for(int i = l; i <= h ; ) {
        if (s[i] == '(') {
            int cnt = 1, st = i + 1;

            for(++i ; cnt != 0; ++i) {
                if(s[i] == ')') -- cnt;
                else if (s[i] == '(') ++ cnt;
            }
            if (s[i] >= '0' && s[i] <= '9' ) 
                sum += cal(st, i - 2) * (s[i++] - '0');
            else
                sum += cal(st, i - 2);
        }
        else {
            if(s[i+1] >= '0' && s[i+1] <= '9')
                sum += mass(s[i]) * (s[++i]++) - '0';
            else 
                sum += mass(s[i++]);
        }
    }
    return sum;
}
int main(){
    cin >> s;
    cout << cal(0,s.size());
}
