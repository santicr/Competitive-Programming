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
    ListNode* sortList(ListNode* head) {
        vector <int> vec;
        ListNode* h = NULL;
        
        while(head != NULL){
            vec.push_back(head -> val);
            head = head -> next;
        }
        
        sort(vec.begin(), vec.end());
        int n = vec.size() - 1;
        
        while(n >= 0){
            ListNode *t = new ListNode(vec[n]);
            t -> next = h;
            h = t;
            n--;
        }
        
        return h;
    }
};