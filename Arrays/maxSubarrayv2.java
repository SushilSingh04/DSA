import java.util.*;
import java.util.stream.Collectors;
/*Given an array of integers arr[], find the contiguous subarray with the maximum sum that contains only non-negative numbers. 
If multiple subarrays have the same sum, return the one with the smallest starting index. If the array contains only negative numbers, 
return -1. */
public class maxSubarrayv2 {
    public static void main(String[] args){
        int[] arr = new int[]{64, 0, 45, -5, 28};
        System.out.println(findSubarray(arr));
    }

    public static ArrayList<Integer> findSubarray(int[] arr){
        int maxSum = Integer.MIN_VALUE;
        int currSum = 0;
        boolean  negEncounter = false, pos = false;
        int maxSumEnd = 0, possibleMaxStart = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i] < 0){
                currSum = 0;
                negEncounter = true;
                possibleMaxStart = i+1;
            }
            else{
                currSum += arr[i];
                pos = true;
            }
            if(maxSum <= currSum && arr[i] == 0){
                maxSumEnd = i;
            }
            else if(maxSum < currSum){
                maxSum = currSum;
                maxSumEnd = i;
            }
        }
        if(!pos) return new ArrayList<Integer>(List.of(-1));
        if(!negEncounter){
            return Arrays.stream(arr)
                     .boxed()
                     .collect(Collectors.toCollection(ArrayList::new));
        }
        else if(possibleMaxStart < maxSumEnd) {
            return Arrays.stream(arr, possibleMaxStart, maxSumEnd+1)
                     .boxed()
                     .collect(Collectors.toCollection(ArrayList::new));
        }
        else{
            int farLeastNegIndex = 0;
            for(int i=maxSumEnd; i>=0; i--){
                if(arr[i] < 0){
                    farLeastNegIndex = i+1; 
                    break;
                }
            }
            return Arrays.stream(arr, farLeastNegIndex, maxSumEnd+1)
                     .boxed()
                     .collect(Collectors.toCollection(ArrayList::new));
        }
    }
}
