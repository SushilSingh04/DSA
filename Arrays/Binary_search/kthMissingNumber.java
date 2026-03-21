package Binary_search;

public class kthMissingNumber {
    public static void main(String[] args){
        int[] arr = {2,3,4,7,11};
        System.out.println(findKthPositive(arr, 5));
    }

    public static int findKthPositive(int[] arr, int k){
        int low = 0, high = arr.length-1;
        while(low <= high){
            int mid = (low + high)/2;
            int missing = arr[mid]-mid-1;
            if(missing < mid){
                low = mid+1;
            }
            else high = mid-1;
        }
        // becuase high will cross low something needs to be added to arr[high] 
        return high + k+1; // arr[high] + (k - (arr[high] - high -1))
                          //   arr[high] + more_to_add
    }
}
