#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    int ar[n];
    int ar1[n];
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        ar1[i] = ar[i];
    }
    
    int L = 0, R = 0;
    for(int i = 0; i < n; i++) {
        if(ar[i] > ar[i+1])
            for(int j = i; i < n; j++) {
                if(ar[j] < ar[j+1] || j == n - 1){
                    L = i; R = j;
                    break;
                }
            }
        if(R != 0) break;
    }

    int temp[R - L + 1];
    for(int i = R; i >= L; i--){
        temp[R - i] = ar[i];
    }
    for(int i = 0; i <= R - L ; i++){
        ar[i+ L] = temp[i];
    }
    sort(ar1, ar1 + n);
    for(int i = 0; i < n; i++){
        if(ar1[i] != ar[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << L+1 << " " << R+1;
    return 0;
}