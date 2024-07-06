class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        occurrences = [0] * 30
        offset = ord('a')
        for ch1, ch2 in zip(s,t):
            occurrences[ord(ch1)-offset] +=1
            occurrences[ord(ch2)-offset] -=1
        return all(x==0 for x in occurrences)
