#include<bits/stdc++.h>
using namespace std;

int main(){
	int r;
	cin >>r;
	int ans=4;
	for(int i = 1;i<r;i++){
		int curr = r*r - i*i;
		if (curr>0){
			int root = sqrt(curr);
			if (root*root == curr)ans+=4;
		} 
	}
	cout<<ans;

	return 0;
}