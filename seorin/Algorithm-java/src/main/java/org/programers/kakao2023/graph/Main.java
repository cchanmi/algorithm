package org.programers.kakao2023.graph;

public class Main {

	public static void main(String[] args) {
		Solution solution = new Solution();
		/**
		 * input
		 *
		 */

		String[] commands = {
				"UPDATE 1 1 menu",
				"UPDATE 1 2 category",
				"UPDATE 2 1 bibimbap",
				"UPDATE 2 2 korean",
				"UPDATE 2 3 rice",  // 5
				"UPDATE 3 1 ramyeon",
				"UPDATE 3 2 korean",
				"UPDATE 3 3 noodle",
				"UPDATE 3 4 instant",
				"UPDATE 4 1 pasta", // 10
				"UPDATE 4 2 italian",
				"UPDATE 4 3 noodle",
				"MERGE 1 2 1 3",
				"MERGE 1 3 1 4",
				"UPDATE korean hansik",  //15
				"UPDATE 1 3 group",
				"UNMERGE 1 4",
				"PRINT 1 3",
				"PRINT 1 4" // 14
		};

		String[] solution1 = solution.solution(commands);
		for (String s : solution1) {
			System.out.println("s = " + s);
		}

	}

}
