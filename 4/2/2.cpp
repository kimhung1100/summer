#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void check(int n) {
    vector <int> ar(n+1);
    stack <int> st;
    int cnt = 1;
    for(int i = 1; i < n+1; i++)
        cin >> ar[i];
    for(int i = 1; i < n+1; i++) {
        while (!st.empty() && st.top() == cnt) {
            st.pop();
            cnt++;
        }
        if (ar[i] == cnt) {
            cnt ++;
        }
        else 
            st.push(ar[i]);
    }
    while (!st.empty() && st.top() == cnt) {
            st.pop();
            cnt++;
    }


    if(!st.empty()) cout << "no";
    else
        cout << "yes";
    cout << endl;
    return ;
}

int main(){
    int n;
    while(1) {
        cin >> n;
        if( n == 0)
            break;
        else
            check (n);
    }
}