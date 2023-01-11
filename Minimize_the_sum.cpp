class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        priority_queue<int>pq;
for(auto it:arr){
    pq.push(-it);
}
        int ans = 0;
        
        for(int i=0;i<N-1;i++){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            x = -x;
            y = -y;
            
            ans += x+y;
            pq.push(-x-y);
            
            
        
        }
        
        return ans;
        // code here
    }
};