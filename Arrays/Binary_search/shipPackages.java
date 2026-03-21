package Binary_search;

public class shipPackages {
    public static void main(String[] args){
        int[] weights = {4, 3, 6, 2, 2, 8};
        System.out.println(shipWithinDays(weights, 4));
    }

    public static int shipWithinDays(int[] weights, int days){
        int min = Integer.MAX_VALUE, sum = 0;
        for(int i=0; i<weights.length; i++){
            sum += weights[i];
            if(weights[i] < min) min = weights[i];
        }
        int low = min, high = sum;
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(calcDays(weights, mid) <= days){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }

    public static int calcDays(int[] weights, int capacity){
        int days = 1;
        int load = weights[0];
        for(int i=1; i<weights.length; i++){
            if(load + weights[i] >capacity){
                days++;
                load = weights[i];
            }
            else load += weights[i];
        }
        return days;
    }
}
