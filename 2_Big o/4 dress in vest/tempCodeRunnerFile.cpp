#include <iostream>

using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int soldier[n];
    int sInAr[n];
    int armor[m];
    for(int i = 0; i < n; i++){
        cin >> soldier[i];
        sInAr[i] = 0;
    }
    for(int i = 0; i < m; i++)
        cin >> armor[i];
    int tmp = 0;
    int count = 0;
    for(int S = 0; S < n; S++ ){
        for( ;tmp < m; tmp++  ){
            if(armor[tmp] >= soldier[S] - x 
            && armor[tmp] <= soldier[S] + y && armor[tmp] != 0){
                sInAr[S] = tmp + 1;
                armor[tmp] = 0;
                count ++;
                break;
            }
        }
    }
    cout << count << endl;
    if(count != 0)
        for(int i = 0; i < n; i++){
            if(sInAr[i] != 0) cout << i+1 << " " << sInAr[i]  << endl;
        }
}