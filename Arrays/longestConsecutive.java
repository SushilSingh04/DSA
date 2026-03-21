import java.util.*;
public class longestConsecutive {
    public static void main(String[] args){
        int[] arr = {9,1,4,7,3,-1,0,5,8,-1,6};
        // int[] arr1 = {100, 4, 101, 3, 99, 98, 102, 2, 1, 2};
        System.out.println(longestConsecutiveSeq2(arr));
    }

    static int longestConsecutiveSeq(int[] nums) { // Set approach 
        Set<Integer> set = new HashSet<>();
        for(int val: nums){
            set.add(val);
        }
        // System.out.println(set);
        int maxLength = 1;
        int currLength = 1;

        for(Integer val: set){
            int find = val-1;
            if(!set.contains(find)){
                find = val+1;
                while(set.contains(find)){
                    currLength++;
                    find++;
                }
                maxLength = Math.max(maxLength, currLength);
                currLength = 1;
            }
        }
        return maxLength;
    }

    static int longestConsecutiveSeq2(int[] arr){ // Sorting approach
        int maxLength = 1;
        int currLength = 1;
        Arrays.sort(arr);
        //  9, 1, 4, 7, 3,-1, 0, 5, 8,-1, 6
        // -1,-1, 0, 1, 3, 4, 5, 6, 7, 8, 9 

        for(int i=0; i<arr.length-1; i++){
            if(arr[i] == arr[i+1]-1){
                currLength++;
            }
            else if(arr[i] == arr[i+1]){
                
            }
            else{
                currLength = 1;
            }
            maxLength = Math.max(currLength, maxLength);
        }
        return maxLength;
    }
}
