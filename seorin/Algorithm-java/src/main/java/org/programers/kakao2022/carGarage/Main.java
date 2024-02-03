package org.programers.kakao2022.carGarage;

public class Main {

	public static void main(String[] args) {
		Solution solution = new Solution();
		/**
		 * input
		 *
		 */
		int[] fees = new int[]{
				180, 5000, 10, 600
		};
		String[] records = {
				// 0-2, 3-5, 6-10, 11-13
				"05:34 5961 IN",
				"06:00 0000 IN",
				"06:34 0000 OUT",
				"07:59 5961 OUT",
				"07:59 0148 IN",
				"18:59 0000 IN",
				"19:09 0148 OUT",
				"22:59 5961 IN",
				"23:00 5961 OUT"
		};

		int[] solution1 = solution.solution(fees, records);
		for (int sol : solution1) {
			System.out.println("sol = " + sol);
		}
	}

}
