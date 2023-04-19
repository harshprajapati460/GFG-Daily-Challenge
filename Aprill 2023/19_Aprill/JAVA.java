class hello{
    public static boolean wifiRange(int N, String S, int X) 
    { 
        int cnt = 0;
        for(int i = 0 ; i < N ; i++){
            if(S.charAt(i) == '0') cnt++;
            else {
                if(cnt > X) return false;
                cnt = -X;
            }
        }
        if(cnt > 0) return false;
        return true;
        // code here
    }
    public static void main(String[] args) {
        String s = "0011000101";
        System.out.println(wifiRange(10,s,0));
    }
}