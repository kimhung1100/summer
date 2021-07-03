#include <iostream>

using namespace std;

int sub_Min(int ar[], int n){
    int min = ar[0];
    for(int i = 0; i < n; i++){
        if(min > ar[i] ) min = ar[i];
    }
    for(int i = 0; i < n; i++){
        if(min == ar[i]) {
            ar[i] = 727379969;
            return min;
        }
    }
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    int ar[n];
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        sum += ar[i];
    }
    //find min
    int L = 0, R = n-1;
    while(m < sum){
        if(ar[L] >= ar[R]) {
            sum -= ar[L];
            L ++;
        }
        else {
            sum -= ar[R];
            R --;
        }
    }
    while(L != 0 && R != n - 1 && (sum + ar[L-1] <= m || sum + ar[R+1] <= m )){
        if(ar[L-1] <= ar[R+1] ){
            sum += ar[L-1]; L --;
        }
        else {
            sum += ar[R+1];
            R ++;
        }
    }
    cout << R - L + 1 ;
}