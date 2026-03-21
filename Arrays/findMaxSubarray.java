import java.util.*;

public class findMaxSubarray {
    public static void main(String[] args){
        int[] arr = {4,-4,-3,-2,-1,0,0,0,4,3,9};
        ArrayList<Integer> lst = findSubarray(arr);
        System.out.println(lst);
    }

    public static ArrayList<Integer> findSubarray(int[] arr){
        int maxSum = Integer.MIN_VALUE;
        int currSum = 0;
        int maxSumEnd = 0;
        for (int i=0; i<arr.length; i++){
            currSum += arr[i]; 
            if(arr[i] > currSum){
                currSum = arr[i];
            }
            if(currSum > maxSum){
                maxSum = currSum;
                maxSumEnd = i;
            }
        }
        ArrayList<Integer> lst = new ArrayList<>();
        int checkSum = 0; 
        for(int i=maxSumEnd; i>=0; i--){
            checkSum += arr[i];
            lst.addFirst(arr[i]);
            if(checkSum == maxSum){
                while(i > 0 && arr[--i] == 0){
                    lst.addFirst(0);
                }
                break;
            }
        }
        return lst;
    }
}
