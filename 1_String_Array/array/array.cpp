#include <iostream>

using namespace std;

void sortMin(int arA[],int na,int k){
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
void sortMax(int arA[],int na, int m){
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
string print(int arrK[], int k, int arrB[], int m){
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
    int *arA = new int[na];
    int *arB = new int[nb];
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
    
    cout << print(arA,k,arB,m);
}