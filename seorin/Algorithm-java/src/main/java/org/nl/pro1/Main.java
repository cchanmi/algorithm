package org.nl.pro1;

public class Main {

	public static void main(String[] args) {
		Solution solution = new Solution();
		/**
		 * input
		 *
		 */

//		int[] price = {4, 1, 4, 7, 6};
		int[] price = {13, 7, 3, 7, 5, 16, 12};

		int[] solution1 = solution.solution(price);
		for (int i : solution1) {
			System.out.println("i = " + i);
		}
	}

}
