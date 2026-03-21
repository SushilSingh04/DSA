import java.util.HashMap;

// Given an array arr[] containing both positive and negative integers, the task is to find the length of 
// the longest subarray with a sum equals to 0.

public class largestSubarrayWith0Sum{
    public static void main(String[] args) {
        int[] arr =  new int[]{-31, -48, -90, 54, 20, 95, 6, -86, 22};
        // 
        // -31,0 -79,1 -169,2 -115,3 -95,4 0,5 6,6 -80,7 -58,8 
        // int[] arr1  = new int[]{1, 0, -4, 3, 1, 0};
        System.out.println(maxLengthSubarray0Sum(arr));
    }

    static int maxLengthSubarray0Sum(int[] arr){
        HashMap<Long, Integer> hm = new HashMap<>();
        long sum = 0;
        int maxLen = 0;
        int currLen = 0;
        for(int i=0; i<arr.length; i++){
            sum += arr[i];
            hm.putIfAbsent(sum, i);
            if(hm.containsKey(sum)){
                if(sum == 0){
                    currLen = i+1;
                    maxLen = Math.max(maxLen, currLen);
                }
                currLen = i - hm.get(sum);
                maxLen = Math.max(maxLen, currLen);
            }
        }
        return maxLen;
    }
}