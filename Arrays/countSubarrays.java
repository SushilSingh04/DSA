import java.util.*;

public class countSubarrays {
    public static void main(String[] args) {
        
    }

    static int withXorK(int[] arr, int k){
        int xor = 1;
        // 000
        // 111
        int count = 0;
        HashMap<Integer, Integer> hm  = new HashMap<>();
        hm.put(xor, 1);
        for(int i=0; i<arr.length; i++){
            xor = xor^arr[i];
            count += hm.getOrDefault(xor^k, 0);
            hm.put(xor, hm.getOrDefault(xor,0)+1);
        }
        return count;

    }
}
