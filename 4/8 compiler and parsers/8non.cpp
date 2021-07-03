#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++) {
		string chrAr;
		cin>>chrAr;
		long top=0,cnt=0,tmpCnt=0;
		for(long long i=0;i<chrAr.size();i++)
		{
			if(chrAr.at(i)=='<')
				top++;
			else
			{
				top--;
				if(top<0)
					break;
				tmpCnt++;
				if(top==0)
				{
					cnt=tmpCnt;
				}	
			}
		}	
		cout << cnt*2 << endl;
	}
	
return 0;
}