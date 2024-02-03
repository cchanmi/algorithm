package org.programers.kakao2022.mountain;

public class Main {

	public static void main(String[] args) {
		int n = 6;
		int[][] paths = new int[][]{
				{1, 2, 3},
				{2, 3, 5},
				{2, 4, 2},
				{2, 5, 4},
				{3, 4, 4},
				{4, 5, 3},
				{4, 6, 1},
				{5, 6, 1}
		};
		int[] gates = new int[]{1, 3};
		int[] summits = new int[]{5};
		int[] solution = new Solution().solution(n, paths, gates, summits);
		for (int i : solution) {
			System.out.println("i = " + i);
		}
	}
}
