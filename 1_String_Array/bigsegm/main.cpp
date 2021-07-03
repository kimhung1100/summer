#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int **arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[2];
        for(int j = 0; j < 2; j++)
            cin >> arr[i][j];
    }
    
    int minL = arr[0][0], maxR = arr[0][1], retR = -1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            if(minL > arr[i][0]) 
                minL = arr[i][0];
            if(maxR < arr[i][1]) 
                maxR = arr[i][1];
        }
    }

    for(int i = 0; i < n; i++)
        if(arr[i][0] == minL && arr[i][1] == maxR) retR = i;
    

    if(retR != -1) cout << retR+1;
    else cout << -1;

    for(int i = 0; i<n; i++)
        delete []arr[i];
    delete []arr;
}