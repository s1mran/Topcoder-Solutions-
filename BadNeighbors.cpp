#include <bits/stdc++.h>
using namespace std;

class BadNeighbors{
	public:
	int maxDonations(vector <int> v){
		int i,k,n=v.size();
		if(n==2){
			return max(v[0],v[1]);
		}
		if(n==3){
			return max(v[1],(v[0]+v[2]));
		}
		vector<int>a(n,0);
		a[1]=v[1];
		a[2]=max(v[1],v[2]);
		for(i=3;i<n;i++){
			a[i]=max(v[i]+a[i-2],a[i-1]);
		}
		k=a[n-1];
		a[2]=v[2],a[3]=max(v[2],v[3]);
		for(i=4;i<n-1;i++){
			a[i]=max(v[i]+a[i-2],a[i-1]);
		}
		return max(k,a[n-2]+v[0]);
	}
};
