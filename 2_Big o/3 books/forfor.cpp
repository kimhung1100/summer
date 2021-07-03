#include <iostream>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    int ar[n];
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    
    int max = 0;
    int L = 0;
    int R = 0;
    int sum = 0;
  
    
    for( ;R < n ;R++ ){
        sum += ar[R];
        if(sum > m) {
            sum -= ar[R];
            R --;
            break;
        }
        if(R == n-1) {
            cout << R - L +1; return 0;
        }
    }
    for( ; L < n; ){
        sum -= ar[L];
        L++;
        for( ; sum <= m && R < n ; ){
            R++;
            sum += ar[R];
        }
        if(R == n -1 && sum <= m){
            if(max < R - L +1) max = R - L +1;
        }
        else {
            sum -= ar[R];
            R --;
        }
        if(max < R - L +1 ) max = R - L +1;
        if(R == n - 1) break;
    }
        
    cout << max;
}