
// class JAVA{
    
//     int[] JobScheduling(Job arr[], int n){
        
//         //sort array based on profits
//         Arrays.sort(arr, new JobComparator());
        
//         int[] ans = new int[2];
        
//         //for slot booking
//         boolean[] planned = new boolean[n];
        
//         //iterate over arr
//         for(int i=0; i<n; i++){
            
//             int deadline = arr[i].deadline;
            
//             //we have enough days
//             if(deadline>=n){
//                 ans[0]++;
//                 ans[1] += arr[i].profit;
//                 continue;
//             }
            
//             //find available slot
//             while(deadline>0){
//                 if(!planned[deadline-1]){
//                     planned[deadline-1] = true;
//                     ans[0]++;
//                     ans[1] += arr[i].profit;
//                     break;
//                 }
//                 deadline--;
//             }
            
//         }
//         return ans;
//     }
// }

// public class JobComparator implements Comparator<Job> {
//     public int compare(Job j1, Job j2){
//         return j2.profit - j1.profit;
//     }
// }