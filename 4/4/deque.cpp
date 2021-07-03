#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

void prc(int p, int c){ 
    deque<int> q;
    for(int i=1;i<=min(p,1000);i++) q.push_back(i);
    string s;
    int k;
    for(int i=0;i<c;i++){
        cin >> s;
        if(s == "N") {
            cout << q.front() << endl;
            q.push_back(q.front());
            q.pop_front();
        } else {
            cin >> k;

            q.erase(remove(q.begin(),q.end(),k),q.end());
            q.push_front(k);
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
    system("pause");
}