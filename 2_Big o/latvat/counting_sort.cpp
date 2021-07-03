#include <iostream>

using namespace std;

void countingSort(int input[],const int n){
    int *output = new int [n];
    int max = input[0];
    int min = input[0];
    
    for(int i = 0; i < n; i++){
        if(input[i] > max)
            max = input[i];
        else if(input[i] < min)
            min = input[i];
    }

    int k = max - min +1;

    int count_array[k];

    fill_n(count_array,k,0);
    
    for(int i = 0; i < n; i++)
        count_array[input[i] - min]++;
    
    for(int i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];
    
    for(int i = 0; i < n; i++){
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }

    for(int i = 0; i < n; i++)
        input[i] = output[i];
            
}
int main(){
    int n;
    cin >> n;
    int *arr = new int [n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    countingSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;

}