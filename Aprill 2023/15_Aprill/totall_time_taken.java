import java.util.HashSet;
class totall_time_taken
{   
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4};
        int [] time = {1, 2, 3, 4};
        System.out.println(totalTime(0, arr, time));
    }
    public static long totalTime(int n,int arr[],int time[])
    {
        HashSet<Integer> set = new HashSet<>();
        int total=0;
        set.add(arr[0]);
        for(int i=1;i<arr.length;i++){
            if(!set.contains(arr[i])){
                set.add(arr[i]);
                total+=1;
            }
            else{
                total+=time[arr[i]-1];
            }
        }
        return total;
    }
}
