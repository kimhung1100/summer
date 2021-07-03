#include <iostream>

using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int sld[n], sInA[n], arm[m];
    for(int i = 0; i < n; i++){
        cin >> sld[i];
        sInA[i] = 0;
    }
    for(int i = 0; i < m; i++)
        cin >> arm[i];
    
    int L = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        int tmp = L;
        for( ;tmp < m ;tmp ++ ) {
            if(arm[tmp] >= sld[i] - x 
                && arm[tmp] <= sld[i] + y){
                sInA[i] = tmp + 1;
                L = tmp + 1;
                count ++;
                break;
            }
            else if(arm[tmp] > sld[i])
                break;
        }
    }
    cout << count << endl;
    if(count != 0)
        for(int i = 0; i < n; i++){
            if(sInA[i] != 0) cout << i+1 << " " << sInA[i]  << endl;
        }
}   