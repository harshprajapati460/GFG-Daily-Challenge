class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        unordered_set<int>map;
        int count = 0;
        
        for(int i=0;i<N;i++){
            if(map.find(arr[i]) != map.end()){
                while(map.find(arr[i]) != map.end()){
                    arr[i]++;
                    count++;
                    
                }
                map.insert(arr[i]);
                
            }
            else map.insert(arr[i]);
            
            
        }
        return count;
        // Code here
    }
};
