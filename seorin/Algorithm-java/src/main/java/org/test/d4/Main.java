package org.test.d4;

public class Main {

	public static void main(String[] args) {
		Solution solution = new Solution();
		/**
		 * input
		 *
		 */
		int coin = 3;
		int[] cards = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11, 12};

		int solution1 = solution.solution(coin, cards);
		System.out.println("solution1 = " + solution1);
	}

}
