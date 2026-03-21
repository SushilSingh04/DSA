import java.util.ArrayList;

public class arrayDuplicates {
    public static void main(String[] args) {
        int[] arr = {2, 3, 1, 2, 3};
        System.out.println(findDuplicates(arr));
    }

    public static ArrayList<Integer> findDuplicates(int[] arr){
        ArrayList<Integer> lst = new ArrayList<>();
        for(int i=0; i<arr.length; i++){
            int num = Math.abs(arr[i]);
            if(arr[num-1] > 0) arr[num-1] = -arr[num-1];
            else lst.add(num);
        }
        
        return lst;
    }
}
