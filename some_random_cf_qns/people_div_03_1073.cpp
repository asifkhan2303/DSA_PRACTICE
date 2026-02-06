#include<iostream>
using namespace std;

int solve(int n){
    if(n<=3){
        return n;
    }
    if(n%2==0){
        return 0;
    }
    return 1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
}