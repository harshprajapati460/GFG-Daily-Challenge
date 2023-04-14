//METHOD - 1 USE TWO STACK OR PAIR STACK TIME COMPLEXITY O(N) && SPACE COMPLEXITY S(2N)

// TWO STACK
class Solution {
  public:
    int finLength(int N, vector<int> &color, vector<int> &radius) {
        stack<int> c;
        stack<int> r;
        for(int i = 0 ; i < N ; i++){
            if(!c.empty() && color[i] == c.top() && radius[i] == r.top()){
                c.pop();
                r.pop();
            }
            else {
                c.push(color[i]);
                r.push(radius[i]);
            }
        }
        return c.size();
    }
};
//PAIR STACK
// USE PAIR CLASS
class Pair{
    
    int key;
    int value;
    public Pair(int key,int value){
        this.key = key;
        this.value = value;
    }
    
}

class Solution {
    public static int finLength(int N, int[] color, int[] radius) {
        // code here
        Stack<Pair> s = new Stack<>();
        for(int i = 0 ; i < N ; i++){
            
            if(!s.empty() && color[i] == s.peek().key && radius[i] == s.peek().value){
                s.pop();
            }
            else {
                Pair p = new Pair(color[i],radius[i]);
                s.add(p);
            }
        }
        return s.size();
    }
}
  
class Solution {
  public:
    int finLength(int N, vector<int> &color, vector<int> &radius) {
        stack<pair<int,int>>s;
        
        for(int i = 0 ; i < N ; i++){
            if(!s.empty() && color[i] == s.top().first && radius[i] == s.top().second){
                s.pop();
            }
            else {
                s.push({color[i],radius[i]});
            }
        }
        return s.size();
    }
};

// Method- 2 Space somplexity S(N)
// Only push index i No need to use two stack or pair stack

class Solution {
  public:
    int finLength(int N, vector<int> &color, vector<int> &radius) {
        
        stack<int> s;
        for(int i = 0 ; i < N ; i++){
            if(!s.empty() && color[i] == color[s.top()] && radius[i] == radius[s.top()]){
                s.pop();
            }
            else {
                s.push(i);
            }
        }
        return s.size();
    }
};

// METHOD - 3 MOST OPTIMIZED TIME COMPLEXITY O(N) and SPACE COMPLEXITY S(1)
// USE TWO INDEXES
class Solution {
  public:
    int finLength(int N, vector<int> &color, vector<int> &radius) {
        
        int i = 0,j = 1;
        
        while(j<N){
    
            while(i>=0 && j<N && color[i]==color[j] && radius[i]==radius[j]){
                j++;
                i--;
            }
            if(j<N){
                i++;
                color[i]=color[j];
                radius[i]=radius[j];
                j++;
            }
        }
        return i+1;
    }
};
