public class leftShiftbyK{
    public static void main(String[] args) {
        int[] arr = {3,2,6,1,7,2,7};
        leftShift(arr, 3);
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i]+" ");
        }
    }

    public static void leftShift(int[] arr, int k){
        k = k%arr.length;
        // k = arr.length-k; // For right rotation this is required
        // 1. reverse first k elements
        reverseArray(arr, 0, k-1);
        // 2. reverse last k elements
        reverseArray(arr, k, arr.length-1);
        // 3. reverse the whole array
        reverseArray(arr, 0, arr.length-1);
    }

    public static void reverseArray(int[] arr, int start, int end){
        for(int i=start,j=end; i<j; i++, j--){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
