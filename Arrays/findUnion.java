import java.util.ArrayList;

public class findUnion{
public static ArrayList<Integer> union(int a[], int b[]) {
    ArrayList<Integer> lst = new ArrayList<Integer>();
    int i=0,j=0,k=0;
    if(a[0] > b[0]){
        lst.add(b[0]);
        j=1;
    }
    else if(a[0] == b[0]){
        lst.add(a[0]);
        j=1;i=1;
    }
    else{
        lst.add(a[0]);
        i=1;
    }
    k=0;
    while(i<a.length && j<b.length){
        if(a[i] > b[j]){
            if(lst.get(k) != b[j]){
                lst.add(b[j]);
                k++;
            }
            j++;
        }
        else if(a[i] < b[j]){
            if(lst.get(k) != a[i]){
                lst.add(a[i]);
                k++;
            }
            i++;
        }
        else{
            if(lst.get(k) != a[i]){
                lst.add(a[i]);
                k++;
            }
            i++;j++;
        }
    }
    if(j<b.length){
        while(j<b.length){
            if(lst.get(k) != b[j]){
                lst.add(b[j]);
                k++;
            }
            j++;
        }
    }
    else{
        while(i<a.length){
            if(lst.get(k) != a[i]){
                lst.add(a[i]);
                k++;
            }
            i++;
        }
    }
    
    return lst;
}
}