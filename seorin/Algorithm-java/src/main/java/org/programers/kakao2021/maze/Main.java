package org.programers.kakao2021.maze;

public class Main {

	public static void main(String[] args) {
		int n = 4;
		int start = 1;
		int end = 4;
		int[][] roads = {
				{1, 2, 1},
				{3, 2, 1},
				{2, 4, 1},
		};
		int[] traps = {2, 3};
		int solution = new Solution().solution(n, start, end, roads, traps);
		System.out.println("solution = " + solution);
	}
}
