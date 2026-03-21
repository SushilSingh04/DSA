import java.util.*;

public class mergeOverlappingSubarrays {
    public static void main(String[] args){
        List<List<Integer>> lst = new ArrayList<>();
        // [[1,4],[2,3],[8,12],[9,11]]
        int[][] arr = new int[][]{{2,3}, {1,4}, {8,12}, {9,11}};
        
    }
        // System.out.println(bruteForce(lst));

    public static int[][] bruteForce(int[][] arr){
        List<int[]> rlst = new ArrayList<>();

        Arrays.sort(arr, Comparator.comparingInt(nums -> nums[0]));
        int startIndex = arr[0][0];
        int endIndex = arr[0][1];
        for(int i=1; i<arr.length; i++){
            if(arr[i][0] < endIndex){
                if(arr[i][1] > endIndex){
                    endIndex = arr[i][1];
                }
            }
            else {
                rlst.add(new int[]{startIndex, endIndex});
                startIndex = arr[i][0];
                endIndex = arr[i][1];
            }
        }
        rlst.add(new int[]{startIndex, endIndex});
        return rlst.toArray(new int[rlst.size()][]);

    }

    public static int[][] optimalApproach(int[][] arr){
        List<int[]> ans = new ArrayList<>();
        for(int i=0; i<arr.length; i++){
            if(ans.isEmpty() || arr[i][1] > ans.getLast()[0]){
                ans.add(arr[i]);
            }
            else{
                ans.getLast()[1] = Math.max(ans.getLast()[1], arr[i][1]);
            }
        }
        return ans.toArray(new int[ans.size()][]);

    }
}
