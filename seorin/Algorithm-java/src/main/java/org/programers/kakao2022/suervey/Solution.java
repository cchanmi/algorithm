package org.programers.kakao2022.suervey;

class Solution {

	Character[] surveyList = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
	Integer[] score = {0, 0, 0, 0, 0, 0, 0, 0};
	Integer[] apply = {3, 2, 1, 0, -1, -2, -3};

	public String solution(String[] survey, int[] choices) {
		for (int i = 0; i < survey.length; i++) {
			applyScore(survey[i], choices[i]);
		}
		for (Integer integer : score) {
			System.out.println("integer = " + integer);
		}
		return getAnswer();
	}

	private String getAnswer() {
		String answer = "";
		answer += score[0] >= score[1] ? "R" : "T";
		answer += score[2] >= score[3] ? "C" : "F";
		answer += score[4] >= score[5] ? "J" : "M";
		answer += score[6] >= score[7] ? "A" : "N";
		return answer;
	}

	private void applyScore(String survey, Integer choice) {
		for (int i = 0; i < 8; i++) {
			if (surveyList[i].equals(survey.charAt(0))) {
				score[i] += apply[choice-1];
				break;
			}
		}
	}
}