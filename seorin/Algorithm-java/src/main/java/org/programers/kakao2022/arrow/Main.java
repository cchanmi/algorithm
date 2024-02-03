package org.programers.kakao2022.arrow;

public class Main {

	public static void main(String[] args) {
		Solution solution = new Solution();
		/**
		 * input
		 *
		 */
		int n = 5;
		int[] info = {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};

		int[] solution1 = solution.solution(n, info);
		for (int i : solution1) {
			System.out.print(i + "  ");
		}
		System.out.println();
	}

}
