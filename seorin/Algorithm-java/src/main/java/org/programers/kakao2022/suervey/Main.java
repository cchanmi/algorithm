package org.programers.kakao2022.suervey;

public class Main {

	public static void main(String[] args) {
		String[] survey = {"AN", "CF", "MJ", "RT", "NA"};
		int[] choices = {5, 3, 2, 7, 5};
		String solution = new Solution().solution(survey, choices);
		System.out.println("solution = " + solution);
	}

}
