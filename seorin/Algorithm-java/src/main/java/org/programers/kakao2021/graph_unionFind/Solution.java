package org.programers.kakao2021.graph_unionFind;

import java.util.*;

class Solution {

	public String solution(int n, int k, String[] cmd) {
		String answer = "";
		boolean[] state = new boolean[n];
		Stack<Integer> deleteStack = new Stack<>();
		Arrays.fill(state, true);
		int endIdx = n-1;
		int nowIdx = k;
		for (String cmdOne : cmd) {
			String[] cmdList = cmdOne.split(" ");
			if (cmdList[0].equals("U")) {
				for (int i = 0; i < Integer.parseInt(cmdList[1]); i++) {
					nowIdx--;
					while (!state[nowIdx]) {
						nowIdx--;
					}
				}
			} else if (cmdList[0].equals("D")) {
				for (int i = 0; i < Integer.parseInt(cmdList[1]); i++) {
					nowIdx++;
					while (!state[nowIdx]) {
						nowIdx++;
					}
				}
			} else if (cmdList[0].equals("C")) {
				if (endIdx == nowIdx) {
					state[nowIdx] = false;
					deleteStack.push(nowIdx);
					while (!state[nowIdx]) {
						nowIdx--;
						endIdx--;
						if (nowIdx == 0) {// Todo:
							System.out.println("Solution.solution");
						}
					}
				} else {
					state[nowIdx] = false;
					deleteStack.push(nowIdx);
					while (!state[nowIdx]) {
						nowIdx++;
					}
				}
			} else if (cmdList[0].equals("Z")) {
				Integer deleteIdx = deleteStack.pop();
				state[deleteIdx] = true;
				endIdx = Math.max(endIdx, deleteIdx);
			}
		}
		for (boolean s : state) {
			answer += s ? "O" : "X";
		}
		return answer;
	}
}