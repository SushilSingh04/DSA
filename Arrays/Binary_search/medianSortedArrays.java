package Binary_search;

public class medianSortedArrays {
    public static void main(String[] args) {
        int[] nums1 = new int[]{1,3,4,6,7};
        int[] nums2 = new int[]{2,5,8,9,10};

        System.out.println(bruteMedianSortedArrays(nums1, nums2));
    }

    public static double bruteMedianSortedArrays(int[] nums1, int[] nums2){
        int[] arr = mergeArrays(nums1, nums2);
        int n = arr.length;
        if(arr.length % 2 == 0){
            return (double)(arr[n/2-1] + arr[n/2])/2;
        }
        else{
            return (double)arr[n/2];
        }
    }

    public static int[] mergeArrays(int[] nums1, int[] nums2){
        int n = nums1.length, m = nums2.length;
        int[] arr = new int[n+m];
        int i = 0, j=0, k=0;
        while(i < n && j < m){
            if(nums1[i] > nums2[j]){
                arr[k++] = nums2[j++];
            }
            else{
                arr[k++] = nums1[i++];
            }
        }

        while(i < n){
            arr[k++] = nums1[i++];
        }
        while(j < m){
            arr[k++] = nums2[j++];

        }

        return arr;
    }
}
