# https://leetcode.com/problems/permutation-in-string/
class Solution:

    def check_equality_of_map(self, curr_map, c_map):
        if len(curr_map.keys()) != len(c_map.keys()):
            return False
        for k in curr_map.keys():
            if k not in c_map or c_map[k] != curr_map[k]:
                return False
        return True

    def checkInclusion(self, s1: str, s2: str) -> bool:
        """
        Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
        In other words, one of the first string's permutations is the substring of the second string.
        """
        l1 = len(s1)
        l2 = len(s2)
        if l1 == 0:
            return True
        c_map = {}
        for ch in s1:
            if ch not in c_map:
                c_map[ch] = 0
            c_map[ch] += 1
        i = 0
        curr_map = {}
        st = -1
        while i < l2:
            if s2[i] not in c_map:
                i += 1
                curr_map = {}
                st = -1
                continue

            if s2[i] not in curr_map:
                curr_map[s2[i]] = 0
            curr_map[s2[i]] += 1
            if st == -1:
                st = i
            if i-st+1 == l1:
                if self.check_equality_of_map(curr_map, c_map):
                    return True
                curr_map[s2[st]] -= 1
                if s2[st] == 0:
                    curr_map.pop(s2[st])
                st += 1
            i += 1
        return False
