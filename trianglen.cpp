// #include<bits/stdc++.h>
// using namespace std;

// bool check_triangle(int n){
// 	int sum = 0;
// 	int i = 1;
// 	while (sum<n){
// 		sum+=i;
// 		i++;
// 	}
// 	if(sum == n){
// 		return true;
// 	}
// 	else{
// 		return false;
// 	}
// }
// int main(){

// 	int n ;
// 	cin >>n;
// 	if (check_triangle(n)){
// 		cout<<"True";
// 	}
// 	else{
// 		cout<<"False";
// 	}

// }
#include <iostream>
using namespace std;
 int main(){
     int n;
     cin>>n;
     bool check = false;
     for(int i=0;i<=n;i++){
         if(i*(i+1)==2*n){
             check = true;
             break;
         }
     }
     if(check) cout<<"TRUE"<<endl;
     else cout<<"FALSE"<<endl;
 }