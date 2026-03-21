public class spiralFashion {
    public static void main(String[] args){
        // 1  2  3
        // 6  7  8
        // 11 12 13
        int[][] matrix = new int[][] { {1,2,3}, {6,7,8}, {11,12,13} };
        printSpiral(matrix);
    }

    static void printSpiral(int[][] matrix){
        int top = 0, left = 0, right = matrix[0].length-1, bottom = matrix.length-1;
        while(left <= right && top <= bottom){
            for(int i=left; i<=right; i++){
                System.out.print(matrix[top][i]+" ");
            }
            for(int i=top+1; i<=bottom; i++){
                System.out.print(matrix[i][right]+" ");
            }
            if(top != bottom){
                for(int i=right-1; i>=left; i--){
                    System.out.print(matrix[bottom][i]+" ");
                }
            }
            if(left != right){
                for(int i=bottom-1; i>=top+1; i--){
                    System.out.print(matrix[i][left]+" ");
                }
        }
            top++; bottom--;
            left++; right--;
        }
    }
}
