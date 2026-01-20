class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        len1 = len(str1)
        len2 = len(str2)

        def valid(k): 
            if len1 % k or len2 % k:
                return False
            n1 = len1 // k
            n2 = len2 // k
            base = str1[:k]
            return str1 == n1 * base and str2 == n2 * base
        
        for i in range(min(len1, len2), 0, -1):
            if valid(i):
                return str1[:i]
        return ""
    
    # Algorithm exploration:
    # Start at the length of the shorter string. Check to see if it's a divisible string. 
    # If so, return it. If not, decrement length by 1 and check again.
    # valid(k) func: If either string length is not divisible by k, return False. 
    # Next, do floor division to get the number of repeats. 
    # Using k, find the base string from str1(they both need to match, it doesn't matter str1 or str2)
    # Finally, check if str1 and str2 equal their respective number of repeats of the base string.
    # For every iteration, if valid(k) returns True, we have found the GCD string. Return it.
    # Time complexity: m, n are lengths of str1 and str2. 
    # there are min(m, n) bases to check, and each check takes O(m+n) time. 
    # Therefore, time complexity is O((m+n) * min(m, n))
    # Space complexity: O(min(m, n)) to store the base string in the worst case.

    
