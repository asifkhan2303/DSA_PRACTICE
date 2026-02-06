#include<iostream>
#include<vector>
using namespace std;


vector<int> merge(vector<int> &left,vector<int> &right){
    int n=left.size();
    int m=right.size();
    vector<int> temp;
    int i=0,j=0;
    while(i<n && j<m){
        if(left[i]<right[j]){
            temp.push_back(left[i++]);
        }else{
            temp.push_back(right[j++]);
        }
    }
    while(i<n){
        temp.push_back(left[i++]);
    }
    while(j<m){
        temp.push_back(right[j++]);
    }
    return temp;
}

vector<int> mergeSort(vector<int> &arr,int i,int j){
    if (i > j) {
        return {};
    }
    if(i==j){
        return {arr[i]};
    }
    int mid=i+(j-i)/2;
    vector<int> left=mergeSort(arr,i,mid);
    vector<int> right=mergeSort(arr,mid+1,j);
    return merge(left,right);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> result=mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<result[i]<<" ";
    return 0;
}
