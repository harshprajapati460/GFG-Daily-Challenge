#include<bits/stdc++.h>
using namespace std;
bool wifiRange(int N, string S, int X){
        // code here
        int cnt = 0;
        for(int i = 0 ; i < N ; i++){
            if(S[i] == '0') cnt++;
            else {
                if(cnt > X) return false;
                cnt = -X;
            }
        }
        if(cnt > 0) return false;
        return true;
    }
int main(){
string s = "101011100";
int N = s.length();
int X = 3;
cout<<wifiRange(N,s,X);
return 0;
}