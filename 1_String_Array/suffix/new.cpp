#include <iostream>
#include <string>

using namespace std;

bool findIn(string s, string t){
    int count = 0;
    for(int i = 0; i < t.size(); i++){
        if(t[0] == s[i]){
            for(int j = 0; j < t.size(); j++){
                if(t[j] == s[i+j])
                    count ++;
            }
            if(count == t.size())
                return true;
            else
                count = 0;
        }
    }
    return false;
}
bool checkAuto(string s, string t){
   for(int i = 0; i < s.size(); i++){
       if(s[i] != t[i]) {s.erase(i,1); i--;}
   }
   if(s == t ) return true;
   else return false;
}
int findTinS(string &s, string t){
    int countCh = 0;
    string s1 = s;
    for(int i = 0; i < t.size(); i++){
        for(int j = 0; j < s1.size(); j++){
            if(t[i] == s1[j]) {
                s1[j] = ' ';
                countCh ++;
              	break;
            }
        }
    }

    if(countCh == t.size()){
        if(s1.size() == t.size()) return 1;
        else {
            if(checkAuto(s,t)) return 2;
        }
        return 3;
        
    } 
    else return 0;
}



int main(){
    string s, t;
    cin >> s >> t;
    
    if(findIn(s,t)) {cout << "automaton"; return 0;}
    int ret = findTinS(s,t);
  	if(ret) {
        if(ret == 1) cout << "array";
          else if (ret == 2) cout << "automaton";
          else if (ret == 3) cout << "both";
    }
    else
        cout << "need tree";
     
}