#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int A[3000];
    int B[3000];
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < m; i++)
        cin >> B[i];
    int sz = B[m-1]>A[n-1] ? B[m-1] : A[n-1];
    int cnt[sz+1];
    fill_n(cnt,sz,0);
    for(int i = 0; i < m; i++)
        cnt[B[i]] ++;
    for(int i = 0; i < n; i++)
        cnt[A[i]] --;
    for(int i = 1;i < B[m-1]; i++){
        int j = i + 1;
        while(cnt[i] < 0){
            if(cnt[j] == B[m-1]) break;
            if(cnt[j] > 0) {
                cnt[i] ++;
                cnt[j] --;
            }
            else
                j++;
        }
    }
    int sum = 0;
    for(int i = 1; i < sz+1; i++){
        if(cnt[i] < 0) sum += -1*cnt[i];
    }
    cout << sum;
    
        
    return 0;
}