#include <iostream>

using namespace std;

int max1(int ar[], int L, int R){
    int max = ar[L];
    for(int i = L; i <= R; i++)
        if(max < ar[i]) max = ar[i];
    return max;
}
int min(int ar[], int L, int R){
    int min = ar[L];
    for(int i = L; i <= R; i++)
        if(min > ar[i]) min = ar[i];
    return min;
}
int main(){
    int n;
    cin >> n;
    int ar[n];
    int max = 1;
    int L = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
        for( ;L < i; ){
            if(max1(ar,L,i) - min(ar,L,i) <= 1){
                count = i - L + 1;
                break;
            }
            else
                L = i -1;
        }
        
        if(max < count) max = count;
    }
    
    cout << max;
}