#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int count = n;
    int ar[n];
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    int l = ar[n-1];
    int pos = n - 1 - ar[n - 1];
    if(l > (n-1)) {
        l = n - 1;
        pos = 0;
    }
    for(int i = n-1; i >= 0; i--){
        int it = i - ar[i];
        if(it < 0) it = 0;
        if(it < pos) {
            if(i < pos)
                l += i - it;
            else
                l += pos - it;
            pos = it;
        }
    }
    cout << n - l;
        
}

