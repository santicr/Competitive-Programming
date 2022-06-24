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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector <int> vec1, vec2, ans;
        int n, m;
        
        while(l1 != NULL or l2 != NULL){
            if(l1 != NULL){
                vec1.push_back(l1 -> val);
                l1 = l1 -> next;
            }
            if(l2 != NULL){
                vec2.push_back(l2 -> val);
                l2 = l2 -> next;
            }
        }
        
        n = vec1.size();
        m = vec2.size();
        int c = 0, val, i = 0;
        
        i = 0;
        
        while(i < n || i < m){
            if(i < n && i < m){
                val = (vec1[i] + vec2[i] + c);
                ans.push_back(val % 10);
                if(val >= 10)
                    c = 1;
                else
                    c = 0;   
            }
            else if(i < n && i >= m){
                val = (vec1[i] + c);
                ans.push_back(val % 10);
                if(val >= 10)
                    c = 1;
                else
                    c = 0; 
            }
            else if(i >= n && i < m){
                val = (vec2[i] + c);
                ans.push_back(val % 10);
                if(val >= 10)
                    c = 1;
                else
                    c = 0; 
            }
            i++;
        }
        if(c)
            ans.push_back(c);
        
        ListNode *head = new ListNode;
        head -> val = ans[ans.size() - 1];
        
        for(int i = ans.size() - 2; i >= 0; i--){
            ListNode* t = new ListNode;
            t -> val = ans[i];
            t -> next = head;
            head = t;
        }
        
        return head;
    }
};