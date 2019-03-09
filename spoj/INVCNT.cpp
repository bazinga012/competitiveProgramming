#include<iostream>
#include<limits.h>
using namespace std;
typedef long long ll;
 
ll count=0;
 
void merge(ll a[],int l,int m,int h)
{
	int s1=m-l+2,s2=h-m+1;
	ll a1[s1],a2[s2];
	for(int i=0;i<s1-1;i++){
		a1[i]=a[l+i];
	}
	a1[s1-1]=LONG_MIN;
	for(int i=0;i<s2-1;i++){
		a2[i]=a[m+1+i];
	}
	a2[s2-1]=LONG_MIN; 
	int p=0,q=0;
	for(int k=l;k<=h;k++){
		if(a1[p]>a2[q]){
			a[k]=a1[p];
			if(p!=s1-1 && q!=s2-1 )
				count=count+h-m-q;
			p++;
		}
		else{
			a[k]=a2[q];
			q++;
		}
	}
}
 
 
 
void mergesort(ll a[],int l,int h)
{
	if(l>=h)return;
	else{
		int mid=(l+h)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,h);
		merge(a,l,mid,h);
	}
     
}
 
ll inversion_count(ll arr[],int sz)
{
	mergesort(arr,0,sz-1);
	return count;
}
 
int main()
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ll a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<inversion_count(a,n)<<endl;
		count=0;
	}
}