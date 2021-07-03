#include <iostream>

using namespace std;

void sortMin(long long int arA[],int na,int k){
    for(int i = 0; i < k; i++){
        for(int j = i; j < na; j++){
            if(arA[j] < arA[i]){
                int temp = arA[i];
                arA[i] = arA[j];
                arA[j] = temp;
            }
        }
    }
}
void sortMax(long long int arA[],int na,int m){
    for(int i = 0; i < m; i++){
        for(int j = i; j < na; j++){
            if(arA[j] > arA[i]){
                int temp = arA[i];
                arA[i] = arA[j];
                arA[j] = temp;
            }
        }
    }
}
string print(long long int arrK[], int k,long long int  arrB[], int m){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < m; j++){
            if (arrK[i] >= arrB[j]){
                return "NO";
            }
        }
    }
    return "YES";
}
int main(){
    int na, nb, k,m;
    cin >> na >> nb >> k >> m;
    long long int  *arA = new long long int [na];
    long long int  *arB = new long long int [nb];
    for(int i = 0; i < na; i++){
        cin >> arA[i];
    }
    for(int i = 0; i < nb; i++){
        cin >> arB[i];
    }
    //////////////
    sortMin(arA,na,k);
    sortMax(arB,nb,m);
    /////////
    long long int  *arrK = new long long int [k];
    long long int  *arrB = new long long int [m];
    for(int i = 0; i < k ; i++){
        arrK[i] = arA[i];
    }
    for(int i = 0; i < m ; i++){
        arrB[i] = arB[i];
    }
    cout << print(arrK,k,arrB,m);
}