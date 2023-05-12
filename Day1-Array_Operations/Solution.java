// class Solution {
//     public static int arrayOperations(int n, int[] arr) {
//         // code here
//          int zero = 0;
//         for(int i=0; i<n; i++){
//             if(arr[i] == 0) zero++;
//         }
//         if(zero == 0) return -1;
//         int count = 0,ans = 0;
//         for(int i=0; i<n ; i++){
//             if(arr[i] != 0) count++;
//             else {
//                 if(count > 0) ans++;
//                 count = 0;
//             }
//         }
//         if(count > 0) ans++;
//         return ans;
//     }
// }