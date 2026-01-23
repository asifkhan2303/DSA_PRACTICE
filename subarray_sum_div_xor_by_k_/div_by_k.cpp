#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int solve(vector<int> &arr,int n,int k){
    int prefixSum=0;
    unordered_map<int,int> mp;
    mp[0]=1;
    int count=0;
    for(int i=0;i<n;i++){
        prefixSum+=arr[i];
        int req=(prefixSum%k+k)%k;
        if(mp[req]){
            count+=mp[req];
        }
        mp[req]++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cin>>k;
    cout<<solve(arr,n,k);
    return 0;
}