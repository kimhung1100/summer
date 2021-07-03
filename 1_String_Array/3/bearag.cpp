#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int *array = new int[n+2];
    for(int i = 1; i < n+1; i++){
        cin >> array[i];
    }
    array[0] = 0;
    array[n+1] = 90;
    for(int i = 0; i < n+1; i++){
        if(array[i] + 15 < array[i+1]){
            cout << array[i] +15;
            break;
        }
        if(i == n)
            cout << array[i+1];
    }

}