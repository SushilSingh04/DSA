//Left Rotate Array
public class rotateArray{    
    public static void main(String[] args){
        int arr[]  = {1,2,3,4,5,6,7};
        int d = 3;
        // d = d%arr.length;
        //d = arr.length-d; // For Right Rotate Array
        reverseArray(arr,0,d-1);
        reverseArray(arr, d, arr.length-1);
        reverseArray(arr, 0, arr.length-1);
        for(int i=0; i<arr.length; i++){
            System.out.print(arr[i]+" ");
        }
        // System.out.println(1%-2);
    }

    public static void reverseArray(int arr[],int start, int end){
        while(start<end){
            int temp = arr[end];
            arr[end] = arr[start];
            arr[start] = temp;
            start++; end--;
        }
    }
}