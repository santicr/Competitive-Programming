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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* h = NULL;
        int i = 0, n = 0;
        vector <int> vec, vec2, vecRes;
        
        while(head != NULL){
            if (i % 2 == 0)
                vec.push_back(head -> val);
            else
                vec2.push_back(head -> val);
            i++;
            head = head -> next;
        }
        
        for(int i = 0; i < vec.size(); i++)
            vecRes.push_back(vec[i]);
        for(int i = 0; i < vec2.size(); i++)
            vecRes.push_back(vec2[i]);
       
        n = vecRes.size() - 1;
        
        while(n >= 0){
            ListNode *t = new ListNode(vecRes[n]);
            t -> next = h;
            h = t;
            n--;
        }
        
        return h;
        
    }
};