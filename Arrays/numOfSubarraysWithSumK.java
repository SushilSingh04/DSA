import java.util.HashMap;

public class numOfSubarraysWithSumK {
    static int subarraySum(int[] nums, int k) {
        long sum = 0;
        int count = 0;
        HashMap<Long, Integer> hm = new HashMap<>();
        hm.put(sum, 1);
        // 1 2 3
        // 0,1 1,1 3,1 6,1
        // count = 2
        for(int i=0; i<nums.length; i++){
            sum += nums[i];
            count += hm.getOrDefault(sum-k,0);
            hm.put(sum, hm.getOrDefault(sum,0)+1);
        }
        return count;

    }

    public static void main(String[] args){
        int arr[] = {1,2,3,3};
        System.out.println(subarraySum(arr, 3));
    }
}
