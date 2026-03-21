package Binary_search;

import java.util.AbstractMap;
import java.util.PriorityQueue;

public class minimize_dist_gas_stations {
    public static void main(String[] args) {
        int[] stations = new int[]{3, 6, 12, 19, 33};
        bruteMinMaxDist(stations, 3);
    }

    public double priorityQueueMinMaxDist(int[] stations, int k){
        if(stations.length == 1) return 0;
        int[] howMany = new int[stations.length-1];
        PriorityQueue<AbstractMap.SimpleEntry<Integer, Double>> pq = new PriorityQueue<>((a,b) -> Double.compare(b.getValue(),a.getValue()));
        double[] orgDiff = new double[stations.length-1];
        for(int j=0; j<stations.length-1; j++){
            double diff = (double)(stations[j+1] - stations[j]);
            orgDiff[j] = diff;
            pq.add(new AbstractMap.SimpleEntry<>(j, diff));
        }
        
        for(int i=0; i<k; i++){
            AbstractMap.SimpleEntry<Integer, Double> top = pq.poll();
            int key = top.getKey();
            // double value = top.getValue();
            howMany[key]++;
            double newGap = orgDiff[key]/(howMany[key]+1);
            pq.add(new AbstractMap.SimpleEntry<>(key, newGap));
            // System.out.println(howMany[key]+ " " +newGap);
        }
            
        return pq.peek().getValue();
    }

    public double binarySearchMinMaxDist(int[] stations, int k){
        return 0.0;
    }
    public static double bruteMinMaxDist(int[] stations, int k) {
        // code here
        if(stations.length == 1) return 0;
        int[] howMany = new int[stations.length-1];
        for(int i=0; i<k; i++){
            float maxVal = -1; int maxInd = -1;
            for(int j=0; j<stations.length-1; j++){
                int diff = stations[j+1] - stations[j];
                float sectionLength = diff/(float)(howMany[j]+1);
                if(maxVal < sectionLength){
                    maxVal = sectionLength;
                    maxInd = j;
                }
            }
            howMany[maxInd]++;
        }
        float maxDist = -1;
        for(int i=0; i<stations.length-1; i++){
            float dist = (float)(stations[i+1] - stations[i])/(howMany[i]+1);
            if(maxDist < dist){
                maxDist = dist;
            }
        }
        
        return maxDist;
    }
}
