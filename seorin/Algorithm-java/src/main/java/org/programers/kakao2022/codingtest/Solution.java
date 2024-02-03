package org.programers.kakao2022.codingtest;

import java.util.*;

class Solution {

	int maxAlp = 0;
	int maxCop = 0;
	int[][] area = new int[301][301];
	int answer = Integer.MAX_VALUE;

	public int solution(int alp, int cop, int[][] problems) {
		for (int i = 0; i < 151; i++) {
			for (int j = 0; j < 151; j++) {
				area[i][j] = 151;
			}
		}
		for (int[] problem : problems) {
			maxAlp = Math.max(maxAlp, problem[0]);
			maxCop = Math.max(maxCop, problem[1]);
		}
		for (int i = 0; i <= alp; i++) {
			for (int j = 0; j <= cop; j++) {
				area[i][j] = 0;
			}
		}
		apply(new int[]{0, 0, 1, 0, 1});
		apply(new int[]{0, 0, 0, 1, 1});
		for (int[] problem : problems) {
			apply(problem);
		}
//		for (int i = 0; i <= maxAlp; i++) {
//			for (int j = 0; j <= maxCop; j++) {
//				System.out.print(area[i][j] + " " );
//			}
//			System.out.println();
//		}
		return answer;
	}

	private void apply(int[] problem) {
		for (int i = 0; i <= maxAlp*2; i++) {
			for (int j = 0; j <= maxCop*2; j++) {
				if (problem[0] > i || problem[1] > j) continue;
				if (problem[2] == 0 && problem[3] == 0) continue;
				if (i < problem[2] || j < problem[3] ) continue;
				area[i][j] = Math.min(area[i][j],
						area[i - problem[2]][j - problem[3]] + problem[4]);
				if (i >= maxAlp && j >= maxCop) {
					answer = Math.min(answer, area[i][j]);
				}
			}
		}
	}
}