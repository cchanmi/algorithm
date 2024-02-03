package org.programers.kakao2023.tree;

public class Main {

	public static void main(String[] args) {
		long[] numbers = { 7,42, 5};
		int[] solution = new Solution().solution(numbers);
		for (int result : solution) {
			System.out.println("result = " + result);
		}
	}
}
