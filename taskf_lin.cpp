#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int Q[100000];
int A[100000];
int main(void)
{
	int t,n,k,i,r,head,tail;
	ifstream cin("ladder.in");
	for (cin>>t;t>0;--t) {
		cin>>n>>k;
		for (i=0;i<n;i++)
			cin>>A[i];
		head=0,tail=-1;
		for (i=0;i<k;i++) {
			for (;tail>=head && Q[tail]>A[i];tail--);
			Q[++tail]=A[i];
		}
		r=k;
		for (;i<n && tail>=head;i++) {
			if (A[i]>Q[head]) {
				r=i+1;
				for (;tail>=head && Q[tail]>A[i];tail--);
				Q[++tail]=A[i];
			}
			if (Q[head]==A[i-k])
				head++;
		}
		cout<<r<<endl;
	}
	return 0;
}

