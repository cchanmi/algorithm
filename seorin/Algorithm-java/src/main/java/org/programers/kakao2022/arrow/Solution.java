package org.programers.kakao2022.arrow;

import static java.lang.Math.*;
import java.util.*;

class Solution {

	List<Arrow> arrows = new ArrayList<>();

	public int[] solution(
			int n,
			int[] info) {
		for (int i = 0; i <=10; i++) {
			info[i]++;
		}
		int[][] area =new int[12][n+1];
		arrows.add(new Arrow(0, 0, 0));
		for (int i = 0; i <=n; i++) area[0][i] = 0;
		for (int i = 1; i <=11; i++) {
			area[i][0] = 0;
			int score = 11-i;
			int val = 11-i;
			if (info[i] > 1) {
				val *= 2;
			}
			arrows.add(new Arrow(score, info[i - 1], val));
		}
		int[][][] result =new int[12][n+1][11];
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= 10; j++) {
				result[0][i][j] = 0;
			}
		}
		for (int i = 0; i <= 11; i++) {
			for (int j = 0; j <= 10; j++) {
				result[i][0][j] = 0;
			}
		}
		for (int i = 1; i <= 11; i++) {
			for (int j = 0; j <=n; j++) {
				Arrow arrow = arrows.get(i);
				if (arrow.count > j) {
					area[i][j] = area[i-1][j];
					result[i][j] = result[i-1][j];
				} else {
					if (area[i-1][j] > area[i-1][j- arrow.count] + arrow.value) {
						area[i][j] = area[i-1][j];
						result[i][j] = result[i-1][j];
					} else if (area[i-1][j] < area[i-1][j- arrow.count] + arrow.value){
						area[i][j] = area[i - 1][j - arrow.count] + arrow.value;
						result[i][j] = result[i - 1][j - arrow.count].clone();
						result[i][j][10 - arrow.score] = arrow.count;
					} else {
						area[i][j] = area[i - 1][j];
						result[i][j] = result[i - 1][j - arrow.count];
						result[i][j][10 - arrow.score] = arrow.count;
					}
				}
			}
		}
		int[] answer = result[11][n];
		return answer;
	}

	class Arrow {
		int score;
		int count;
		int value;

		public Arrow(int score, int count, int value) {
			this.score = score;
			this.count = count;
			this.value = value;
		}
	}
}