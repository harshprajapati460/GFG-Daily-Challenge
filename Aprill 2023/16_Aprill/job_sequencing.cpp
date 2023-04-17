
// TIME AND SPACE COMPLEXITY S(N) O(N*LOG(N)) ->PRIORITY QUEUE SORTING
// 
#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
    
};
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int>ans(2,0);
        priority_queue<pair<int,int>>pq;
        int maxdead = -1;
        
        for(int i = 0 ; i < n ; i++){
            pq.push({arr[i].profit,arr[i].dead});
            maxdead = max(maxdead,arr[i].dead);
        }
        vector<int>maxd(maxdead+1,-1);
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            for(int i = p.second; i >= 1; i--){
                if(maxd[i] == -1){
                    ans[1] += p.first;
                    ans[0]++;
                    maxd[i] = 1;
                    break;
                }
            }
        }
        return ans;
        // your code here
    } 
};

int main(){
 
 int n = 5;
 Job arr[n];
 for(int i = 0 ; i < n ; i++){
   int x,y,z;
   cin >> x >> y >> z;
   arr[i].id = x;
   arr[i].dead = y;
   arr[i].profit = z;  
 }
 Solution obj;
 vector<int>ans = obj.JobScheduling(arr,n);
 for(auto it:ans){
    cout<<it<<" ";
 }


return 0;
}