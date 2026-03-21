public class setMatrixZeroes {
    public static void main(String[] args){
        int[][] arr = {{0,1,6,1},{4,5,6,0},{7,9,6,0},{2,3,7,1}};
        setMatrix(arr);
        // 0 1 6 1
        // 4 5 6 0
        // 7 9 6 0
        // 2 3 7 1
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr[0].length; j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void setMatrix(int[][] arr){
        int col0 = 1;

        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr[0].length; j++){
                if(arr[i][j] == 0){
                    // mark the 0th column
                    arr[i][0] = 0;
                    // If 0th column mark col0=0
                    if(j == 0) col0 = 0;
                    // else mark the 1st row
                    else arr[0][j] = 0;
                }
            }
        }
        for(int i=1; i<arr.length; i++){
            for(int j=1; j<arr[0].length; j++){
                if(arr[0][j] == 0 || arr[i][0] == 0) arr[i][j] = 0;
            }
        }

        for(int j=1; j<arr[0].length; j++){
            if(arr[0][0] == 0) arr[0][j] = 0;
        }

        for(int i=0; i<arr.length; i++){
            if(col0 == 0) arr[i][0] = 0;
        }

    }
    
    public static void setMatrix2(int[][] arr){ // Maintaining two arrays for row indices and column indices resp.
        // T.C: O(2*n*m)
        // S.C: O(n)+O(m)
        int[] nums1  = new int[arr.length];
        int[] nums2 = new int[arr[0].length];
        // 1 0 1
        // 1 1 1
        // 0 1 1
        
        // nums1 = [1, 0, 1]
        // nums2 = [0, 1, 0]
        
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr[0].length; j++){
                if(arr[i][j] == 0){
                    nums1[i] = 1;
                    nums2[j] = 1;
                }
            }
        }
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr[0].length; j++){
                if(nums1[i] == 1 || nums2[j] == 1){
                    arr[i][j] = 0;
                }
            }
        }
    }

}
