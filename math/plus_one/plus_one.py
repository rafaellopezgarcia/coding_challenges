from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        ix = len(digits) -1
        increment = 1
        while ix >= 0 and increment > 0:
            if digits[ix] < 9:
                digits[ix] += 1
                increment = 0

            else:
                digits[ix] = 0
            ix -= 1

        if increment == 1:
            digits.insert(0, 1)
        return digits
