public class mergeSort{
    public static void main(String[] args) {
        int[] arr = {9,4,2,7,4,6};
        mergesort(arr,0,arr.length-1);
        for(int val: arr){
            System.out.print(val+" ");
        }
    }

    static void mergesort(int[] arr,int left,int right){
        if(left < right){
            int mid = (left+right)/2;
            mergesort(arr, left, mid);
            mergesort(arr, mid+1, right);
            merge(arr,left,mid,right);
        }
    }

    static void merge(int[] arr,int left,int mid,int right){
        int[] temp = new int[right-left+1];
        int i=left, j=mid+1, k=0;
        while(i<=mid && j<=right){
            if(arr[i] < arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }
        for(;i<mid+1;i++){
            temp[k++] = arr[i];
        }
        for(;j<right+1; j++){
            temp[k++] = arr[j];
        }

        for(int m=0; m<temp.length; m++){
            arr[left+m] = temp[m];
        }
    } 
}