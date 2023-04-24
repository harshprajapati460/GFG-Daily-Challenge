#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int gcd(int a,int b){
        if(b == 0) return a;
        else return gcd(b,a%b);
    }
    int minimumNumber(int n,vector<int> &arr){
        // Code here
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            ans = gcd(ans,arr[i]);
        }
        return ans;
    }
};
int main(){
     Solution obj;
     int n = 5;
     vector<int>arr = {2,4,6,5,4};
     cout<<obj.minimumNumber(n,arr)<<endl;

return 0;
}