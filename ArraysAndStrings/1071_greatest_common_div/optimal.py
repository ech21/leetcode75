class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        max_length = gcd(len(str1), len(str2))
        return str1[:max_length]
    
    #Realize that if BOTH strings are divisible by the same string, 
    #then concaetanating them in any order should yield the same result.
    #If this holds true, then the GCD string must be the length of the GCD of the lengths of both strings.
    #The GCD string cannot be shorter than the GCD of the lengths
    #because if it were, GCD string would also be divisible. Since we want the GREATEST
    #common divisor string, this shorter one cannot be the answer.
    # Time complexity O(m + n) to concat both strings.
    #Space complexity O(m + n) to store the concatenated strings.