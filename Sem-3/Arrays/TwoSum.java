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
        int i=0,j=nums.length-1;
        while(i<j){
            if(nums[i]+nums[j] == target){
                return "YES";
            }
            else if(nums[i]+nums[j] > target){
                j--;
            }
            else i++;
        }

        return "NO";
    }

    public static void main(String args[]){
        String s = greedyApproach(new int[]{2,5,7,11}, 7);
        System.out.println(s);
        // for(int val:arr){
            // System.out.println(val+" ");
        // }
    }
}    

