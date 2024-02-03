package org.test.a1;
public class Main {
	public static void main(String[] args) {
		Solution solution = new Solution();
		/**
		 * input
		 *
		 */
		String[] friends = {
				"a",
				"b",
				"c"
		};
		String[] gifts = {
				"a b",
				"b a",
				"c a",
				"a c",
				"a c",
				"c a",
		};

		int solution1 = solution.solution(friends, gifts);
		System.out.println("solution1 = " + solution1);

	}

}
