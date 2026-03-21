import java.util.*;

public class fourSum {
    public static void main(String[] args){
        // int[] nums = new int[]{2,3,1,5,-4,2};
        // int[] nums1 = new int[]{0,0,0,0,0,0};
        // int target = 0;
        // System.out.println(findFourSum(nums1, target));
    }

    static List<List <Integer>> findFourSum(int[] arr, int target){
       Set<List<Integer>> set = new HashSet<>();
       
       for(int i=0; i<arr.length; i++){
           for(int j=i+1; j<arr.length; j++){
               Set<Integer> temp = new HashSet<>();
               for(int k=j+1; k<arr.length; k++){
                int sum = arr[i]+arr[j]+arr[k];
                if(temp.contains(target-sum)){
                    List<Integer> templ = new ArrayList<>(List.of(arr[i], arr[j], arr[k], target-sum));
                    Collections.sort(templ);
                    set.add(templ);
                }
                temp.add(arr[k]);
                }
            }
       }
       List<List<Integer>> lst = new ArrayList<>(set);
       return lst;
    }
}
