
public class missingNumber{
    public static void main(String args[]){
        int nums[] = {4,5,0,3,1};
        int xor1=0,xor2=0;
        for(int i=0; i<nums.length; i++){
            xor1 ^= nums[i];
            xor2 ^= i+1;
        }

        System.out.println(xor1^xor2);

        // System.out.println(mNum1+" "+mNum2);
    }

    public int missingNumber1(int[] nums) {
        int size = nums.length;
        int sumN = size*(size+1)/2, sum = 0;
        for(int i=0; i<size; i++){
            sum += nums[i];
        }
        return (sumN-sum);
    }

    // public int missingNumber2(int[] nums){
    //     //Using XOR
    // } 

}