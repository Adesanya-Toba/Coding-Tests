"""
You are given an array prices where prices[i] is the price
of a given stock on the ith day.

You want to maximize your profit by choosing a single day to
buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.
"""

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        i = 0
        j = i + 1

        #  0  1   2  3  4  5
        # [7, 50, 6, 4, 3, 1], max profit = 43
        # i = 3, j = 4

        # When do I profit?
        # calculate val (j -i) on every loop, but update only if new value is
        # greater. j++
        # profit = 43

        # when do I update my i?
        # if the j price is lower than I. Set I to the lowest val.
        # J always increments

        # else if profit is negative, set it to 0

        # current profit , max_profit

        while j < len(prices):
            current_profit = prices[j] - prices[i]
            if current_profit > max_profit:
                max_profit = current_profit

            if prices[j] < prices[i]:
                i = j
            j += 1

        return max_profit if max_profit > 0 else 0


if __name__ == "__main__":
    sol = Solution()
    print(sol.maxProfit([7, 1, 5, 3, 6, 4]))  # Output 5
    print(sol.maxProfit([7, 6, 4, 3, 1]))  # Output 0
