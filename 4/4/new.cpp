#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int check(int a, vector <int> ar){
    for(int i = 0; i < ar.size(); i++) {
        if(a == ar[i])
            return i;
    }
    return -1;
}
void prc (int p, int c) {
    queue <int> que; 
    stack <int> queEm;
    vector <int> ar(0);
    int size = 0;
    vector <int> cnt(0);
    //fill_n(ar.begin(),p+1,0);
    for(int i = 1; i <= min(1000,p); i++) que.push(i);
    string s;
    for(int i = 1; i <= c; i++) {
        cin >> s;
        if(s == "N") {
            if(queEm.empty()) {
                for ( ; ; ) {
                    int chk = check(que.front(),ar);
                    if (chk == -1) break; 
                    cnt[chk] --;
                    if(cnt[chk] == 0) 
                        ar.erase(ar.begin() + chk);
                
                    que.pop();
                }
                cout << que.front() << endl;
                que.push(que.front());
                que.pop(); 
            }
            else {
                cout << queEm.top() << endl;
                que.push(queEm.top());
                int chk = check (queEm.top(),ar);
                cnt[chk] ++;
                queEm.pop();
            }
        }
        else {
            int a;
            cin >> a;
            if(!queEm.empty() && queEm.top() == a) {
                continue;
            }
            else {
                queEm.push(a);
                int chk = check (a,ar);
                if(chk == -1) {
                    ar.push_back(a);
                    cnt.push_back(0);
                }
            }
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