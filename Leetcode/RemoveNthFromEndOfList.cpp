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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector <int> vec;
        ListNode* h = NULL;
        int m = 0, size;
        
        while(head != NULL){
            vec.push_back(head -> val);
            head = head -> next;
            m++;
        }
        size = m;
        m--;
        
       while(m >= 0){
           if(m != (size - n)){
               ListNode* t = new ListNode(vec[m]);
               t -> next = h;
               h = t;
           }
           
           m--;
       }
        
        return h;
    }
};