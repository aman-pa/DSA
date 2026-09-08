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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct Comparator{
            bool operator()(ListNode* a,ListNode* b){
                return a->val>b->val;
            }
        };
        priority_queue<ListNode*,vector<ListNode*>,Comparator>pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)
            pq.push(lists[i]);
        }
        ListNode* head=NULL;
        ListNode* ans=NULL;
        while(pq.size()!=0){
            ListNode* temp=pq.top();
            if(head==NULL){head=temp;
            ans=temp;
            pq.pop();
            if(temp->next!=NULL)
            pq.push(temp->next);continue;}
            head->next=temp;
            head=head->next;
            pq.pop();
            if(temp->next!=NULL)pq.push(temp->next);

        }
        return ans;

    }
};