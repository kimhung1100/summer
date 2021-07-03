#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class proc {
public:
    long long t;
    long long d;
    proc(){
        t = 0; d = 0;
    }
    proc(int _t, int _d){
        t = _t; d = _d;
    }
};
int main(){
    int n, b;
    cin >> n >> b;
    queue <proc> que;
    int time = 0;
    int ttime = 0;
    long long prc = 0;
    long long prm = 0;
    vector <proc> ar(n);
    for(int i = 0; i < n; i++){
        long long t , d;
        cin >> t >> d;
        ar[i] = proc(t,d);
    }
    for(int i = 0; i < n ;i++ ){
        ttime = ar[i].t;
        if (ttime >= prc && que.size()) {
            prc += que.front().d;
            que.pop();
            if(ttime > prc) {
                prc = 0;
            }
        }
        if(prc == 0 && que.empty()) {
            prc = ttime + ar[i].d;
            prm = prc;
            cout << prc << " ";
        }
        else if(prc != 0 && que.size() < b){
            que.push(ar[i]);
            prm += ar[i].d;
            cout << prm << " ";
            continue;
        }
        else if(prc != 0 && que.size() == b){
            cout << -1 << " ";
        }
    }
}