//METHOD - 1 USE TWO STACK OR PAIR STACK TIME COMPLEXITY O(N) && SPACE COMPLEXITY S(2N)

// TWO STACK
class Solution {
    public static int finLength(int N, int[] color, int[] radius) {
        Stack<Integer>col = new Stack<>();
        Stack<Integer>rad = new Stack<>();
        for(int i=0;i<N;i++)
        {
            if(!col.isEmpty() && col.peek()==color[i] && rad.peek()==radius[i])
            {
                col.pop();
                rad.pop();
            }
            else
            {
                col.push(color[i]);
                rad.push(radius[i]);
            }
        }
        return col.size();
        // code here
    }
}


// Method- 2 Space somplexity S(N)
// Only push index i No need to use two stack or pair stack
class Solution {
    public static int finLength(int N, int[] color, int[] radius) {
        Stack<Integer> s = new Stack<>();
        s.push(0);
        for(int i = 1 ; i < N ; i++){
            if(!s.empty() && color[i] == color[s.peek()] && radius[i] == radius[s.peek()] ){
                s.pop();
            }
            else {
                s.push(i);
            }
        }
        return s.size();
        
        
        // code here
    }
}
// METHOD - 3 MOST OPTIMIZED TIME COMPLEXITY 0(N) and SPACE COMPLEXITY S(1)
// USE TWO INDEXES

class Solution {
    public static int finLength(int N, int[] color, int[] radius) {
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
    
        // code here
    }
}