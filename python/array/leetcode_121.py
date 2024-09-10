# LeetCode
# 121. Best Time to Buy and Sell Stock
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

import sys

def maxProfit(prices) -> int:

    # 시간 초과 문제 O(n)^2
    result = 0

    # # 이미 지난 날짜는 볼 수 없고...
    for i in range(len(prices)):
        minTemp = prices[i]
        for j in range(i+1, len(prices)):
            if minTemp <= prices[j]:
                result = max(prices[j]-minTemp, result)

    # 상승곡선이 아래로 넘어가면 넘어가고, 상승곡선이 위로 올라가면 가장 큰값을 갱신
    # 시간복잡도 개선하고 O(n)으로 해결한 풀이
    max_value = -sys.maxsize-1
    min_value = sys.maxsize

    for price in prices:
        # 최소값을 계속 갱신해 주고
        min_value = min(min_value, price)
        # 최소값을 토대로 큰값을 뺀값 중 가장 큰값을 갱신해 줌
        max_value = max(price-min_value, max_value)

    return max_value