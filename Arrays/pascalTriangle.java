import java.util.*;

public class pascalTriangle {
    public static void main(String[] args) {
        // long res = elementAtIndex(37, 19);
        // System.out.println(res);
        List<List<Long>> lst = generateTriangle(10);
        for(int i=0; i<lst.size(); i++){
            for(int j=0; j<i+1; j++){
                System.out.print(lst.get(i).get(j)+" "); 
            }
            System.out.println();
        }
        // List<Long> row = generateRow(0);
        // for(int i=0; i<row.size(); i++){
        //     System.out.print(row.get(i)+" ");
        // }
    }

    static long elementAtIndex(int row, int col){
        // 10C3 = 10 * 9 * 8
        //        1  * 2 * 3
        long res = 1;    // 7 
        if(row < 0 || col <0 || col>row){
            return -1;
        }
        // 37C19 => 37C18  20 > 17
        else if(col > row-col){
            col = row-col; // 17
        }
        for(int i=0; i<col; i++){ // 10 9 8 
            res *= (row-i); // (10-0)*(10-1)*(10-2)
            res /= (i+1);
        }
        return res;
    }

    static List<List <Long>> storeTriangle2(int n){ // T.C = O(n * r)
        List<List <Long>> lst = new ArrayList<>();
        for(int i=0; i<n+1; i++){
            List<Long> tempList = new ArrayList<>();
            for(int j=0; j<i+1;j++){
                tempList.add(elementAtIndex(i, j));
            }
            lst.add(tempList);
        }
        return lst;
    }


    static List<Long> generateRow(int n){
        List<Long> lst = new ArrayList<>();
        long res = 1;
        lst.add(res);
        int num = n;
        for(int j=1; j<n+1;j++){
            res *= num; // Do this in two steps
            res /= j;
            lst.add((long)res);
            num--;
        }
        return lst;
    }

    static List<List <Long>> generateTriangle(int n){ // T.C = 
        List<List <Long>> lst = new ArrayList<>();
        for(int i=0; i<n+1; i++){
            List<Long> temp = generateRow(i);
            lst.add(temp);
        }
        return lst;
    }

}
