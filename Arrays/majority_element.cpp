#include<bits/stdc++.h>
using namespace std;

vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        vector<int> vec;
        int ele1=-1,ele2=-1,cnt1=0,cnt2=0;
        for(int val: arr){
            if(ele1 != val && ele2 != val ){
                if(cnt1 == 0){
                    cnt1++; 
                    ele1=val;
                }
                else if(cnt2==0){
                    cnt2++;
                    ele2=val;
                }
                else{
                    cnt1--;
                    cnt2--;
                }
            }
            else if(ele1 == val){
                cnt1++;
            }
            else if(ele2== val){
                cnt2++;
            }
        }
        int count1=0, count2=0;
        for(int val: arr){
            if(val == ele1) count1++;
            if(val == ele2) count2++;
        }

        if(count1 > n/3 && count2 > n/3){
            if(ele1<ele2){
                vec.push_back(ele1);
                vec.push_back(ele2);
            }
            else{
                vec.push_back(ele2);
                vec.push_back(ele1);
            }
        }
        else if(count2 > n/3) vec.push_back(ele2);
        else if(count1 > n/3) vec.push_back(ele1);
        return vec;
    }