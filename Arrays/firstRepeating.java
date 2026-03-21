import java.util.HashSet;
import java.util.Set;

public class firstRepeating {
    public static void main(String[] args){
        int[] arr = {1, 5, 4, 3, 4, 3, 5, 6};
        System.out.println(firstRepeated(arr));
    }   

    public static int firstRepeated(int[] arr){
        int n = arr.length;
        Set<Integer> seen = new HashSet<>();
        int firstRepeating = -1;
        for(int i=n-1; i>=0; i--){
            if(seen.contains(arr[i])){
                firstRepeating = i+1;
            }
            else seen.add(arr[i]);
        }
        return firstRepeating;
    }
    
    
}
