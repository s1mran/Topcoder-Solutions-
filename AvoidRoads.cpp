#include<bits/stdc++.h>
using namespace std;
class AvoidRoads{
	public:
	long long numWays(int width, int height, vector <string> bad){
	map<string ,long long int>mp;
	int n=width,i,j,k,m=height;
        string s,s1;
	k=0;
	while(k<bad.size()){
		mp[bad[k]]=1;
	     k++;
	}
	long long ar[m+1][n+1];
	ar[0][0]=1;
	for(i=0;i<m+1;i++){
	//	cout<<i<<" i ";
		for(j=0;j<n+1;j++){
		if(i*j!=0||i+j!=0){	ar[i][j]=0;}
			if(i-1>=0){
				s=to_string(j)+" "+to_string(i-1)+" "+to_string(j)+" "+to_string(i);
				s1=to_string(j)+" "+to_string(i)+" "+to_string(j)+" "+to_string(i-1);
				if(!mp[s]&!mp[s1]){
					ar[i][j]+=ar[i-1][j];
				}
			}
			if(j-1>=0){
				s=to_string(j)+" "+to_string(i)+" "+to_string(j-1)+" "+to_string(i);
				s1=to_string(j-1)+" "+to_string(i)+" "+to_string(j)+" "+to_string(i);
				if(!mp[s]&!mp[s1]){
					ar[i][j]+=ar[i][j-1];
				}
			}
		//	cout<<ar[i][j]<<" ";
		}//cout<<endl;
	}return ar[m][n];
}
};