class ZigZag{
public :
int longestZigZag(vector <int> v){int n,i,j,k;
	k=1;
	n=v.size();
	vector< int>l(n,1);
	vector< int>h(n,1);
	for(i=1;i<n;i++){
		for(j=i-1;j>=0;j--){
			if(v[j]>v[i]){
				if(h[j]+1>l[i]){
					l[i]=h[j]+1;
				}
			}else{
				if((v[j]<v[i])&(l[j]+1>h[i])){
					h[i]=l[j]+1;				}
			}
		}
		k=max(k,max(l[i],h[i]));
	}
	return k;
}
    };

