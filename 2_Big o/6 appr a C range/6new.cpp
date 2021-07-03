#include <iostream>

using namespace std;

int main(){
    int n, ni;
    cin >> n;
    cin >> ni;
    int max = ni, min = ni, count = 1, maxcnt = 1;
    for(int i = 1; i < n; i++) {
        cin >> ni;
        if(max < ni) max = ni;
        if(min > ni) min = ni;
        if(max - min <= 1) {
            count ++;
            continue;
        }
        else if ( ni == max) {
            min ++;
            count --;
        }
    }
    

    
}