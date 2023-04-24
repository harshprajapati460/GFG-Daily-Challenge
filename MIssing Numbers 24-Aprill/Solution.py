def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)
def minimumNumber(n,arr):
    ans = 0
    for i in range(len(arr)):
        ans = gcd(ans,arr[i])
    return ans 

list = [3,2,4]
n = 3
print(minimumNumber(n,list))