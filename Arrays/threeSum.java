import java.util.*;

public class threeSum {
    public static void main(String[] args) {
        int[] arr = new int[] { 0, 0, 0, 1, -1, 1 };
        // int[] arr1 = new int[] { 1, 2};
        List<List<Integer>> lst = findThreeSum(arr);

        System.out.println(lst);
    }

    static List<List<Integer>> findThreeSum(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> lst = new ArrayList<>();
        int k = arr.length - 1;
        int i = 0, j = 0;
        while (i < arr.length-2) {
            if (i > 0 && arr[i - 1] == arr[i]){
                i++;
                continue;
            }
            j = i + 1;
            k = arr.length - 1;
            while (j < k) { // j< k and not j!=k (both can bypass each other)
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    lst.add(List.of(arr[i], arr[j], arr[k]));
                    j++;
                    k--;
                    // Do this to avoid duplication which will be only be in the case of sum=0 found
                    while (j < k && arr[j] == arr[j - 1]) j++;
                    while (j < k && arr[k] == arr[k + 1]) k--;
                }
            }
            i++;
        }
        return lst;
    }

    static List<List<Integer>> findThreeSum2(int[] nums) {
        List<List<Integer>> lst = new ArrayList<>();
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (i != j) {
                    if (hm.containsKey(-nums[i] - nums[j])) {
                        List<Integer> l = new ArrayList<>(List.of(-nums[i] - nums[j], nums[i], nums[j]));
                        l.sort(null);
                        if (!lst.contains(l)) {
                            List<Integer> ll = new ArrayList<>(List.of(-nums[i] - nums[j], nums[i], nums[j]));
                            ll.sort(null);
                            lst.add(ll);
                        }
                    }
                    hm.put(nums[j], j);
                }
            }
            hm.clear();
        }
        return lst;
    }

}
