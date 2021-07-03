#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void prc (int p, int c) {
    queue <int> que; 
    stack <int> queEm;
    vector <int> ar(min(1000,p));
    fill_n(ar.begin(),min(1000,p),0);
    for(int i = 1; i <= min(p,1000); i++)
        que.push(i);
    string s;
    for(int i = 1; i <= c; i++) {
        cin >> s;
        if(s == "N") {
            if(queEm.empty()) {
                for ( ; ; ) {
                    if (ar[que.front()] == 0) break; 
                    ar[que.front()] --;
                    que.pop();
                }
                cout << que.front() << endl;
                que.push(que.front());
                que.pop(); 
            }
            else {
                cout << queEm.top() << endl;
                que.push(queEm.top());
                ar[queEm.top()] ++;
                queEm.pop();
            }
        }
        else {
            int a;
            cin >> a;
            if(!queEm.empty() && queEm.top() == a) {
                continue;
            }
            else 
                queEm.push(a);
        }
    }
}
int main(){
    int p, c;
    int cnt = 1;
    for( ; ; ) {
        cin >> p >> c;
        if (p == 0 && c == 0)
            break;
        else {
            cout << "Case " << cnt << ":" << endl;
            prc(p, c);
            cnt ++;
        }
    }
}