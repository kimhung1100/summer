#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ar[n];
    int sum = 0, count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        sum += ar[i];
    }
    int L = 0, R = n - 1;
    while(sum != 0) {
        if(ar[L] <= ar[R]) {
            sum -= ar[L];
            ar[R] -= ar[L];
            ar[L] = 0;
            count1 ++;
            L ++;
            if(L == R) {
                count2 ++;
                break;
            }
            continue;
        }
        else {
            sum -= ar[R];
            ar[L] -= ar[R];
            ar[R] = 0;
            count2 ++;
            R --;
            if(L == R) {
                count1 ++;
                break;
            }
            continue;
        }
    }
    cout << count1 << " " << count2;
}