package org.test.c3;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {

	Map<String, Integer> resultMap = new HashMap<>();
	int diceHistory[];
	int selectNum[];
	boolean diceSeleced[];
	int[][] dices;

	public int[] solution(
			int[][] dice) {
		dices = dice;
		int n = dices.length;
		diceHistory = new int[n];
		selectNum = new int[n];
		diceSeleced = new boolean[n];
		Arrays.fill(diceHistory, -1);
		Arrays.fill(selectNum, 0);
		Arrays.fill(diceSeleced, false);
		int[] answer = {};
		ArrayList<Integer> answerList = new ArrayList();
		int result = 0;
		dfs(0, n);
		for (String key : resultMap.keySet()) {
			if (result < resultMap.get(key)) {
				result = resultMap.get(key);
				answerList.clear();
				String[] split = key.split("#");
				for (int i = 1; i < split.length; i++) {
					answerList.add(Integer.parseInt(split[i]));
				}
				answer = answerList.stream().mapToInt(i->i+1).toArray();
			}
		}
		return Arrays.stream(answer).sorted().toArray();
	}

	void dfs(int diceNum, int n) {
		if (diceNum == n) {
			int mySum = 0;
			int otherSum = 0;
			for (int i = 0; i < n; i++) {
				if (isMySelect(i, n)) {
					mySum += diceHistory[i];
				} else {
					otherSum += diceHistory[i];
				}
			}
			if (mySum > otherSum) {
				saveResult(n);
			}
		} else {
			for (int i = 0; i < n; i++) {
				if (!diceSeleced[i]) {
					diceSeleced[i] = true;
					selectNum[diceNum] = i;
					for (int j = 0; j < 6; j++) {
						diceHistory[diceNum] = dices[i][j];
						dfs(diceNum + 1, n);
					}
					diceSeleced[i] = false;
				}
			}
		}
	}

	private void saveResult(int n) {
		String key = "";
		for (int i = 0; i < n; i++) {
			if (isMySelect(i, n)) {
				key += "#" + selectNum[i];
			}
		}
		Integer sum = resultMap.get(key);
		if (sum == null) {
			sum = 0;
		}
		sum = sum+1;
		resultMap.put(key, sum);
	}

	private boolean isMySelect(int i, int n) {
		for (int j = 0; j < n; j++) {
			if (selectNum[j] == i ) {
				if (j < n / 2) {
					return true;
				} else {
					return false;
				}
			}
		}
		return true;
	}
}