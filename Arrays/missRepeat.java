import java.util.*;

public class missRepeat {
    public static void main(String[] args) {
        int[] arr = new int[]{2,2,4,5,1};
        System.out.println(findMissingRepeatXor(arr));
        System.out.println(findMissingRepeatMath(arr));
        // if( (4 & 1 << 2) != 0) System.out.println("bravo");
        // System.out.println();
    }

    private static ArrayList<Integer> findMissingRepeatMath(int[] arr){
        long n = arr.length;
        long sum = (n*(n+1))/2;
        long sum_sq = (n*(n+1)*(2*n+1))/6;
        long act_sum = 0;
        long act_sum_sq = 0;
        for(int val: arr){
            act_sum += val;
            act_sum_sq += (long)val * (long)val;
        }
        //  2*3*5 = 30/6 = 5
        // 
        // repeat - missing = val1
        // repeat^2   -   missing^2  = val2 
        // repeat + missing = val2/val1
        long val1 = act_sum - sum;
        long val2 = act_sum_sq - sum_sq;
        int repeat = (int)((val1+ val2/val1)/2);
        int missing = (int)(repeat - (act_sum - sum));
        // System.out.println(sum+" "+sum_sq+" "+val2/val1+" "+repeat+" "+missing);
        return new ArrayList<Integer>(List.of(repeat, missing));
    }
    
    private static ArrayList<Integer> findMissingRepeatXor(int[] arr){
        int xr = 0;
        for(int i=0; i<arr.length; i++){
            xr ^= arr[i];
            xr ^= (i+1);
        }
        int tmp_xr = xr;
        int bitNo = 0;
        while(tmp_xr != 1){
            bitNo++;
            tmp_xr = tmp_xr >> 1;
        }

        int zero = 0;
        int one = 0;
        for (int i = 0; i < arr.length; i++) {
            if((arr[i] & (1 << bitNo)) != 0){
                one = one^arr[i];
                System.out.println(arr[i]+ " "+(1 << bitNo));
            }
            else{
                zero = zero^arr[i];
                System.out.println(arr[i]+ " "+(1 << bitNo));
            }   
        }

        for (int i = 1; i <= arr.length; i++) {
            if((i & (1 << bitNo)) != 0) one ^= i;
            else zero ^= i;
        }
        
        int repeat = 0, missing = 0;
        for (int i = 0; i < arr.length; i++) {
            if(zero == arr[i]){
                repeat = zero;
                break;
            }
            else if(one == arr[i]){
                repeat = one;
                break;
            } 
        }
        missing = (repeat == zero)?one:zero;
        return new ArrayList<Integer>(List.of(repeat, missing));
    }
}
