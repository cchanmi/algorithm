package org.test.d4;


class Solution {
	public int solution(int coin, int[] cards) {
		int answer = 0;
		int location[] = new int[cards.length + 1];
		location[0] = 0;
		for (int i = 0; i < cards.length; i++) {
			location[cards[i]] = i;
		}
		for (int i = cards.length/3+1; i < cards.length; i+=2) {
			boolean isOk = false;
			for (int j = 0; j <= i; j++) {
//				System.out.println("i = " + i);
//				System.out.println("(cards.length+1-cards[j]) = " + (cards.length + 1 - cards[j]));
//				System.out.println("(location[cards.length+1-cards[j]]) = " + (location[cards.length+1-cards[j]]));
				if (location[cards.length+1-cards[j]] <= i) {
					if (location[cards.length+1-cards[j]] > cards.length/3) {
						coin--;
//						System.out.println("coin1 = " + coin);
					}
					if (j > cards.length/3-1) {
						coin--;
//						System.out.println("coin2 = " + coin);
					}
					if (coin < 0)  {
						break;
					}
					location[cards[j]] = 2000;
					location[cards.length+1-cards[j]] = 2000;
					isOk = true;
					break;
				}
			}
//			System.out.println("roud : " + answer);
//			for (int j = 1; j < cards.length+1; j++) {
//				System.out.print(location[j] + " " );
//			}
//			System.out.println();
//			System.out.println();
			answer++;
			if (!isOk) break;
		}
		return answer;
	}
}