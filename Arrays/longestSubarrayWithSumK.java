import java.util.HashMap;

public class longestSubarrayWithSumK{
    public static void main(String[] args){
        // int[] arr = {94, -33, -13, 40, -82, 94, -33, -13, 40, -82};
        // int[] arr1 = {1,3,0,0,-2,3,1,1,2};
        int[] arr1 = {3,0,0,0,0};
        int len = longestSubarray(arr1, 3);
        System.out.println(len);
    }

    static int longestSubarray(int[] arr, int k){
        // With HashMap
        HashMap<Long, Integer> mp = new HashMap<>();
        long  s = 0;
        int maxLen = 0;
        for(int i=0; i<arr.length; i++){
                s+=arr[i];
                mp.putIfAbsent(s, i);
                if(s == k) maxLen = i+1;
                else if(mp.containsKey(s-k)){
                    int len = i - mp.get(s-k);
                    if(len > maxLen) maxLen = len;
                    // maxLen = Math.max(len, maxLen);
                }
        }
        return maxLen;
    }
}