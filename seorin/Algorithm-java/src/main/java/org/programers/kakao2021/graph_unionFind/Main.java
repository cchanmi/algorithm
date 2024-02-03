package org.programers.kakao2021.graph_unionFind;

public class Main {

	public static void main(String[] args) {
		int n = 8;
		int k = 2;
		String[] cmd = {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"};
		String solution = new Solution().solution(n, k, cmd);
		System.out.println("solution = " + solution);
	}
}
