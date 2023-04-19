def wifiRange(N, S, X):
        cnt = 0
        for i in range(len(S)):
            if S[i] == '0':
                cnt+=1;
            else:
                if cnt > X:
                    return False
                cnt = -X;
        if cnt > 0:
            return False
        return True
s = "01100010"
print(wifiRange(len(s),s,0))