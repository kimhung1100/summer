#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void prc(int p, int c){
    queue <int> qu;
    stack <int> quE;
    int *ar = new int [p+1];
    fill_n(ar,p,0);
    int arE = 0;
    for(int i = 1; i <= p; i++)
        qu.push(i);
    string s;
    for(int i = 1; i <= c; i++) {
        cin >> s;
        if (s == "N") {
            if(!quE.empty()) {
                cout << quE.top() << endl;
                qu.push(quE.top());
                ar[quE.top()] --;
                quE.pop();
                continue;
            }
            while (ar[qu.front()] != 0) {
                ar[qu.front()] --;
                qu.pop();
            }
            cout << qu.front() << endl;
            qu.push(qu.front());
            qu.pop();
        }
        else {
            int a;
            cin >> a;
            if(quE.empty()) 
                quE.push(a);
            else if(quE.top() == a) continue;
            else if(ar[a] == 0 || quE.top() != a) 
                quE.push(a);
            ar[a] ++;
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