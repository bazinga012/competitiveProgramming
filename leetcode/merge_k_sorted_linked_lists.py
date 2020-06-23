# https://leetcode.com/problems/merge-k-sorted-lists/

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
import heapq

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        h = []
        for i in range(0, len(lists)):
            if lists[i] == None:
                continue
            h.append([lists[i].val,i,lists[i].next])
        response = end = None
        heapq.heapify(h)
        while len(h)>1:
            val , list_idx , next_node = s = h[0]
            nn = ListNode(val)
            if not response:
                response = end = nn
            else:
                end.next = nn
                end = nn
            if next_node == None:
                heapq.heappop(h)
                continue
            s[0] = next_node.val
            s[2] = next_node.next
            heapq.heapreplace(h, s)
            
        if h:
            val , list_idx , next_node = h[0]
            nn = ListNode(val)
            if not response:
                response = end = nn
            else:
                end.next = nn
                end = nn
            curr = next_node
            while curr is not None:
                nn = ListNode(curr.val)
                if not response:
                    response = end = nn
                else:
                    end.next = nn
                    end = nn
                curr = curr.next
        return response
                