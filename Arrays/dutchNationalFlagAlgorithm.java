import java.util.*;
public class dutchNationalFlagAlgorithm {
    public static void main(String[] args){
        // int[] nums = {1,0,1,1,0,2,2,0,1};
        // sortArray(nums);
        // for (int val : nums) {
        //     System.out.print(val+" ");
        // }
        String[] originalArray = {"A", "B", "C", "D", "E"};

        // Define the portion you want (from index 1 up to, but not including, index 4)
        int startIndex = 1; // inclusive
        int endIndex = 4;   // exclusive

        // Create the new array slice
        String[] subArray = Arrays.copyOfRange(originalArray, startIndex, endIndex);

        // Convert the slice to a new ArrayList
        ArrayList<String> arrayList = new ArrayList<>(Arrays.asList(subArray));

        System.out.println("Original Array: " + Arrays.toString(originalArray));
        System.out.println("Portion as ArrayList: " + arrayList);
    }

    static void sortArray(int[] nums){
        // 0  0 ... 0  1 1 ... 1  | .....  | 2 ... 2
        //         low        mid  unsorted  high

        int low = 0;
        int mid = 0;
        int high = nums.length; // not nums.length-1
        while(mid < high){
            if(nums[mid] == 0){
                swap(nums, mid, low);
                low++; mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums, mid, high-1);
                high--;
            }
        }
    }

    static void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
