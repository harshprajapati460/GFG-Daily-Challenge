#include<bits/stdc++.h>
using namespace std;

int totalTime(int n, vector<int> &arr, vector<int> &time) {
        // code here
        int t = -1;

        unordered_set<int>s;
        for(int i = 0 ; i < arr.size(); i++){
            
             t++;
            if(s.find(arr[i]) == s.end()){
                s.insert(arr[i]);
            }
            else {
                t += time[arr[i]-1]-1;
            }
            
        }
        return t;
    }

int main(){
 vector<int>arr = {1, 2, 3, 4};
 vector<int>time = {1, 2, 3, 4};
 cout<<totalTime(5,arr,time)<<endl;


return 0;
}