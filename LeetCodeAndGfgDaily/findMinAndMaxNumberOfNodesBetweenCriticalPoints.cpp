#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        int currIdx = 0;
        vector<int> criticalIdx;

        while(curr){
            if(prev == NULL || curr->next == NULL){
                prev = curr;
                curr = curr->next;
                continue;
            }

            if(curr->val > prev->val && curr->val > curr->next->val || curr->val < prev->val && curr->val < curr->next->val){
                criticalIdx.push_back(currIdx);
            }
            prev = curr;
            curr = curr->next;
            currIdx++;
        }
        int n = criticalIdx.size(), maxDist = -1, minDist = INT_MAX;

        if(n >= 2) maxDist = criticalIdx.back() - criticalIdx[0];

        for(int i = 1; i < criticalIdx.size(); i++){
            minDist = min(minDist, criticalIdx[i]-criticalIdx[i-1]);
        }

        if(minDist == INT_MAX) minDist = -1;

        return {minDist, maxDist};
    }
};