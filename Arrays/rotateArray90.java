public class rotateArray90 {
    public static void main(String[] args){
        int[][] arr = new int[][]{
            {1,2,3}, {4,5,6}, {7,8,9}
        };
        rotate90(arr);
        // 1 2 3
        // 4 5 6
        // 7 8 9
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr[0].length; j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }

    static void rotate90(int[][] arr){
        transpose(arr);
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr[0].length/2; j++){
                int temp = arr[i][j];
                arr[i][j] = arr[i][arr.length-1-j];
                arr[i][arr.length-1-j] = temp;
            }
        }
    }

    static void transpose(int[][] arr){
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<i; j++){
                if(i != j){
                    int temp = arr[i][j];
                    arr[i][j] = arr[j][i];
                    arr[j][i] = temp;
                }
            }
        }

        
    }
}
