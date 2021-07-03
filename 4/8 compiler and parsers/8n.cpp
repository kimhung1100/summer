#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int z = 0; z < n; z++) {
        string s;
        cin >> s;
        int prc = 0;
        stack <char> stk;
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt = 0, maxc = 0;
        for(long long i = 0; i < s.size(); i++) {
            if(s[i] == '<') {
                prc = 1;
                stk.push(s[i]);
                cnt1 ++;
            }
            else if (s[i] == '>') {
                if(prc == 0) break;
                stk.push(s[i]);
                cnt2 ++;
                if(cnt2 == cnt1) {
                    cnt = cnt1* 2;
                    maxc = max(cnt,maxc);
                    for(int j = 0; j < cnt; j++)
                        stk.pop();
                    cnt = 0;
                }
            }
        }
        cout << maxc << endl;
    }
}