package org.programers.kakao2022.codingtest;

public class Main {

	public static void main(String[] args) {
		int alp = 10;
		int cop = 10;
		int[][] problems = new int[][]{
				{10, 15, 2, 1, 2},
				{20, 20, 3, 3, 4},
//				{0, 0, 2, 1, 2},
//				{4, 5, 3, 1, 2},
//				{4, 11, 4, 0, 2},
//				{10, 4, 0, 4, 2}
		};
		int solution = new Solution().solution(alp, cop, problems);
		System.out.println("solution = " + solution);
		System.out.println(Integer.MAX_VALUE);
	}

}
