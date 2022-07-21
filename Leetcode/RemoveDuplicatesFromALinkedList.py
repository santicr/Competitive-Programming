# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        times = {}
        ans = None
        res = None
        
        while head != None:
            val = head.val
            head = head.next
            if val not in times:
                times[val] = 0
            times[val] += 1
        print(times)
        for k in times:
            v = times[k]
            if v == 1 and ans == None:
                ans = ListNode(k)
            elif v == 1 and ans != None:
                new = ListNode(k)
                new.next = ans
                ans = new
        
        while ans != None:
            if res == None:
                res = ListNode(ans.val)
            else:
                new = ListNode(ans.val)
                new.next = res
                res = new
            ans = ans.next
        
        return res