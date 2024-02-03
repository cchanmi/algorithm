package org.test.c3;


public class Main {

	public static void main(String[] args) {
		Solution solution = new Solution();
		/**
		 * input
		 *
		 */
		int[][] dice = {
				{1, 2, 3, 4, 5, 6}, {2, 2, 4, 4, 6, 6}
		};

		int[] solution1 = solution.solution(dice);
		for (int i : solution1) {
			System.out.println("i = " + i);
		}
	}

}
