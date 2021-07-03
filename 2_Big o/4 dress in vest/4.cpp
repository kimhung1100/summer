#include <iostream>

using namespace std;

int binarySearch(int a[], int l, int r, int soldier, int x, int y){
    int mid = (l + r) / 2;
    if(r - l < 0) return -1;

    if(a[mid] >= soldier - x 
            && a[mid] <= soldier + y && a[mid] != 0) 
        return mid;
    
    else if (soldier >= a[mid]) 
        return binarySearch(a, mid +1, r, soldier, x , y);
    
    else
        return binarySearch(a, l, mid - 1, soldier, x, y);
    
}
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
    int Ar = 0;
    int count = 0;
    for(int S = 0; S < n; S++ ){
        int des = binarySearch(armor,Ar,m-1,soldier[S],x,y);
        if(des > 0){
            sInAr[S] = des + 1;
            armor[des] = 0;
            Ar = des + 1;
            count ++;
            break;
        }
        
    }
    cout << count << endl;
    if(count != 0)
        for(int i = 0; i < n; i++){
            if(sInAr[i] != 0) cout << i+1 << " " << sInAr[i]  << endl;
        }
}