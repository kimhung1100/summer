#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> ar(n);
    int cnt[1001];
    int unq = 0;
    fill_n(cnt,1001,0);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        cnt[ar[i]] ++;
        if(cnt[ar[i]] == 1) unq ++;
    }
    sort(ar.begin(),ar.begin()+n);
    int hmax = unq;
    int cntT = 0;
    int t;
    while(1) {
        for(int i = ar[0]; i <= ar[n-1]; i++) {
            cnt[i] --;
            if(cnt[i] == 0) unq --;
        }
        cntT ++;
        if(unq == 0) break;
        if(unq == 1) {
            for(int i = 0; i < n; i++)
                if(cnt[ar[i]] > 0) {cntT += cnt[ar[i]]; break;}
            break;
        }
    }
    cout << cntT << " " << hmax;
}