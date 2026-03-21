package Binary_search;
public class num_of_bouqets {
    public static void main(String[] args){
        int[] arr = new int[]{7,7,7,7,12,7,7};
        // System.out.println(bloomDayN(arr, 12, 2, 3));
        System.out.println(bruteForce(arr, 2, 3));
    }

    static int bruteForce(int[] arr, int m, int k){
        if(m * k > arr.length){
            return -1;
        }
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE; 
        for(int i = 0; i<arr.length; i++){
            if(arr[i] > max) max = arr[i];
            if(arr[i] < min) min = arr[i];
        }

        // System.out.println(max +" "+min);
        for(int i=min; i<=max; i++){
            if(bloomDayN(arr, i, m, k)) return i;
        }

        return -1;
    }

    static boolean bloomDayN(int[] arr, int day, int m, int k){
        int cnt = 0;
        int b = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i] <= day){
                cnt++;
                // System.out.println(cnt);
            }
            else{
                // System.out.println(cnt);
                b += cnt/k;
                cnt = 0;
            }
        }
        b += cnt / k;
        // System.out.println(b);
        if(b >= m) return true;
        return false;
    }
}
