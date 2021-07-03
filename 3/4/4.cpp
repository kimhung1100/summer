#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> ar(n);
    vector <int> ar1(n);
    vector <int> result(n);
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        ar1[i] = ar[i];
    }

    sort(ar.begin(),ar.begin() + n);
    result[n-1] = 1;
    int count = 1;
    int ret1[2000];
    ret1[ar[n-1] ] = 1;

    for(int i = n -2; i > -1; i--) {
        if(ar[i] != ar[i+1]) {
            result[i] = result[i+1] + count;
            ret1[ar[i] ] = result[i];
            count = 1;
        }
        else {
            result[i] = result[i + 1];
            count ++;
        }
            
    }
    for(int i = 0; i < n; i++)
        cout << ret1[ar1[i]] << " ";
}