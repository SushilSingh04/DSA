// User function Template for Java
import java.util.*;

public class alternatePosNeg {
    public static void main(String[] args){
        ArrayList<Integer> arr = new ArrayList<>(List.of(9, 4, -2, -1, 5, 0 ,-5, -3, 2));
        System.out.println(rearrange(arr));
    }
    static ArrayList<Integer> rearrange(ArrayList<Integer> arr) {
        // code here
        ArrayList<Integer> posLst = new ArrayList<>();
        ArrayList<Integer> negLst = new ArrayList<>();
        for(int i=0; i<arr.size(); i++){
            if(arr.get(i) >= 0){ // positive element
                posLst.add(arr.get(i));
            }
            else{ // negative element
                negLst.add(arr.get(i)); 
            }
        }

        int posPointer = 0, negPointer = 0;
        int arrPointer = -1;
        boolean check = true;

        while(posPointer < posLst.size() || negPointer < negLst.size()){
            arrPointer++;
            if(posPointer >= posLst.size()) check = false;
            if(negPointer >= negLst.size()) check = true;
            if(posPointer < posLst.size() && check){ // positive element
                arr.set(arrPointer,posLst.get(posPointer));
                posPointer++;
                check=false;
            }
            else if(negPointer < negLst.size() && !check){ // negative element
                arr.set(arrPointer, negLst.get(negPointer));
                negPointer++;
                check=true;
            }
        }
        return arr;
    }
}