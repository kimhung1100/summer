#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector <long long> ar(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar.begin(),ar.begin() + n);
    long long result = ar[0] * x;
    if(x == 1)
        x ++;
    x--;
    for(int i = 1; i < n ; i++) {
        result += x * ar[i];    
        if(x == 1)
            x ++;
        x--;
    }
    cout << result;
}