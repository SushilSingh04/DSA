import java.util.Arrays;
import java.util.HashMap;

public class TwoSum {
    static int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        int i=0;
        for(; i<nums.length;i++){
            if(hm.containsKey(target-nums[i])){
                return new int[]{hm.get(target-nums[i]),i};
            }
            hm.put(nums[i],i);
        }
        return new int[]{};
    }
    static String greedyApproach(int[] nums, int target){
        Arrays.sort(nums);
        for(int i=0,j=nums.length-1;i<j;i++,j--){
            
        }
    }

    public static void main(String args[]){
        int arr[] = twoSum(new int[]{2,5,7,11}, 12);
        for(int val:arr){
            System.out.println(val+" ");
        }
    }
}    

