/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)return{-1,-1};
        ListNode* temp=head;
        ListNode* prev=head;
        vector<int>mn;
        int len=0;
        while(temp!=NULL&&temp->next!=NULL){
            len++;
            if(temp->val>prev->val&&temp->val>temp->next->val){
                mn.push_back(len);
            }
            if(temp->val<prev->val&&temp->val<temp->next->val){
                mn.push_back(len);
            }
            prev=temp;
            temp=temp->next;

        }
        sort(mn.begin(),mn.end());
        int n=mn.size();
        if(n < 2)return{-1,-1};
        int mx1=mn[n-1]-mn[0];
        int mn1=INT_MAX;
        for(int i=1;i<n;i++){
            if(mn[i]-mn[i-1]<mn1)mn1=mn[i]-mn[i-1];
        }
        return {mn1,mx1};

    }
};