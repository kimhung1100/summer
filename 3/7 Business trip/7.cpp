#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int k;
    cin >> k;
    vector <int> ar(12);
    for(int i = 0; i < 12; i++)
        cin >> ar[i];
    sort(ar.begin(),ar.begin()+12);

    if (k == 0) {cout << 0; return 0;}
    int w = 0;
    int ret;
    for(int i = 11; i > -1; i--) {
        w += ar[i];
        if(w >= k) {ret = 12 - i; break;}
        if(i == 0) {
            cout << -1;
            return 0;
        }
    }
    cout << ret;
    return 0;
}