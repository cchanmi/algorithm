package org.test.a1;


import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {

	Map<String, Freind> freindMap = new HashMap<>();
	Map<Integer, String> nameMap = new HashMap<>();
	int[][] history = new int[50][50];

	public int solution(
			String[] friends,
			String[] gifts) {
		int answer = 0;
		for (int i = 0; i < friends.length; i++) {
			freindMap.put(friends[i], new Freind(friends[i], 0, i));
			nameMap.put(i, friends[i]);
		}
		for (int i = 0; i < 50; i++) {
			Arrays.fill(history[i], 0);
		}

		for (String gift : gifts) {
			String[] s = gift.split(" ");
			String giverName = s[0];
			String receiverName = s[1];
			Freind giver = freindMap.get(giverName);
			Freind receiver = freindMap.get(receiverName);
			giver.giftScore++;
			receiver.giftScore--;
			history[giver.num][receiver.num]++;
		}
		for (int i = 0; i < friends.length; i++) {
			int giftSum = 0;
			for (int j = 0; j < friends.length; j++) {
				if (i==j) continue;
				else {
					if (history[i][j] > history[j][i]) {
						giftSum++;
					} else if (history[i][j] == history[j][i]) {
						String giverName = nameMap.get(i);
						String receiverName = nameMap.get(j);
						Freind giver = freindMap.get(giverName);
						Freind receiver = freindMap.get(receiverName);
						if (giver.giftScore > receiver.giftScore) {
							giftSum++;
						}
					}
				}
			}
			answer = Math.max(answer, giftSum);
		}
		return answer;
	}

	class Freind {

		String name;
		int giftScore;
		int num;

		public Freind(String name, int giftScore, int num) {
			this.name = name;
			this.giftScore = giftScore;
			this.num = num;
		}
	}
}