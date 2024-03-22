package org.nl.pro2;

public class Main {

	public static void main(String[] args) {
		Solution solution = new Solution();
		/**
		 * input
		 *
		 */

		int N = 1;
		int[] coffee_times = {100,1,50,1,1};
		int[] solution1 = solution.solution(N, coffee_times);
		for (int num : solution1) {
			System.out.println("num = " + num);
		}
	}

}
