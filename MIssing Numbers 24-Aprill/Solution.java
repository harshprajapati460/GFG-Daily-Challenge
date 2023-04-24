class Solution {
    public static int gcd(int a,int b){
        if(b == 0) return a;
        else return gcd(b,a%b);
    }
    public static int minimumNumber(int n, int[] arr) {
        // code here
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = gcd(ans,arr[i]);
        }
        return ans;
    }
    public static void main(String[] args) {
        int[] arr = {2,4,6,5,4};
        int n = 5;
        System.out.println(minimumNumber(n, arr));
    }
    
}