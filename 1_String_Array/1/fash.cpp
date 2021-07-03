#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int *array = new int[n];
    int count0 = 0;
    for(int i = 0; i < n; i++ ){
        cin >> array[i];
        if(array[i] == 0)
            count0 ++;
    }
    if ( n == 1){
        if (array[0] == 1)
            cout << "YES";
        else
            cout << "NO";
    }
    else if (count0 == 1)
        cout << "YES";
    else
        cout <<"NO";


}