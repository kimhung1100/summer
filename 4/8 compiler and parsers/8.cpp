#include <iostream>
#include <stack>

using namespace std;

void prc(string s) {
    stack <char> st;
    int maxcnt = 0;
    int L = 0;
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == '<') {
            st.push(s[i]);
            L = i;
        }
        else if(s[i] == '>') {
            while (1) {
                if(st.empty())
                    break;
                else if (st.top() == '<') {
                    if (i - st.size() + 1 > maxcnt ) maxcnt = i - st.size() + 1;
                    st.pop();
                    break;
                }
            }
        }
    }
    cout << maxcnt << endl;
}
int main(){
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        prc(s);
    }
}