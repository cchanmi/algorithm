package org.nl.pro4;

import java.util.Arrays;

class Solution {

	int[][] value;
	int[] amount = new int[25];
	String s;
	int n;

	public int solution(
			String s,
			int n) {
		this.s = s;
		this.n = n;
		value = new int[s.length()][s.length()+1];
		for (int i = 0; i < s.length(); i++)value[i][0] = 0;

		for (int l = 1; l <= s.length(); l++) {
			for (int i = 0; i < s.length()-l+1 ; i++) {
				Arrays.fill(amount, 0);
				int max = 0;
				for (int j = i; j < i + l; j++) {
					amount[s.charAt(j)-'a']++;
					max = Math.max(max, amount[s.charAt(j)-'a']);
				}
				value[i][l] = max;
			}
		}
		return dfs(0, 0, Integer.MAX_VALUE);
	}

	int dfs(int depth, int start, int min) {
		if (depth == n) {
			return value[start][s.length()-start];
		} else {
			for (int i = 0; i <= s.length()-start; i++) {
				if (start + i >= s.length()) continue;
				min = Math.min(min, Math.max(value[start][i], dfs(depth + 1, start + i, min)));
			}
			return min;
		}
	}
}