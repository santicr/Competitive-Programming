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
    bool isPalindrome(ListNode* head) {
        int val;
        bool ans = true;
        vector <int> vec;
        
        while(head != NULL){
            val = head -> val;
            vec.push_back(val);
            head = head -> next;   
        }
        
        int idx = 1, n = vec.size(), nI;
        
        for(int i = 0; i < n; i++){
            nI = (n - idx++);
            if (vec[i] != vec[nI])
                ans = false;
            if (i == nI && n % 2 != 0)
                break;
            if (i == nI + 1 && n % 2 == 0)
                break;
        }
        
        return ans;
    }
};