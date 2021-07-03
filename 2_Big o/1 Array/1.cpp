#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int input[n];
    for(int i = 0; i < n; i++)
        cin >> input[i];
    int count_Ar[100000+1];
    int unique = 0;
    fill_n(count_Ar,100000+1,0);
    
    int L = 0;
    for(int R = 0; R < n; R++){
        count_Ar[input[R]] ++;
        if(count_Ar[input[R]] == 1)
            unique ++;
        while (unique == k) {
            count_Ar[input[L]] -= 1;
            if(count_Ar[input[L]] == 0){
                cout << L+1 << " " << R+1;
                return 0;
            }
            L += 1;
        }
    }
    cout << "-1 -1";
        
    return 0;
}