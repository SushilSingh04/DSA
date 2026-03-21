import java.util.*;

public class twoSum {
    public static void main(String[] args) {
        int target = 10;
        int[] arr = {2,4,9,1,8,2};
        int [] sol = findTwoSum(arr, target);
        for(int val: sol){
            System.out.print(val+" ");
        }
    }

    public static int[] findTwoSum(int[] nums, int target) {
        // HashMap is used to spped up the search.
        HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i=0; i<nums.length;i++){
            if(hm.containsKey(target-nums[i])){
                return new int[]{hm.get(target-nums[i]),i};
            }
            hm.put(nums[i],i);
        }
        return new int[]{};
    }
}
