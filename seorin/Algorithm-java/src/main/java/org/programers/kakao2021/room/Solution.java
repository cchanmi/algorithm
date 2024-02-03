package org.programers.kakao2021.room;

import java.util.*;

class Solution {

	int[][] around = {
			{-1, 0},
			{1, 0},
			{0, -1},
			{0, 1}
	};

	public int[] solution(String[][] places) {
		ArrayList<Integer> answer = new ArrayList<>();
		for (String[] place : places) {
			Queue<Node> queue = new LinkedList<>();
			putPerson(queue, place);
			answer.add(getAnswer(queue, place));
		}
		return answer.stream().mapToInt(i -> i).toArray();
	}

	private int getAnswer(Queue<Node> queue, String[] place) {
		while (!queue.isEmpty()) {
			Node nowNode = queue.poll();
			if (nowNode.dist >= 2) continue;
			for (int[] coordinate : around) {
				int newX = nowNode.x + coordinate[0];
				int newY = nowNode.y + coordinate[1];
				if (newX < 0 ||  newX >= 5
						|| newY < 0 || newY >= 5) continue;
				char newChar = place[newX].charAt(newY);
				if (newChar == 'P' && newX != nowNode.beforeX && newY != nowNode.beforeY) {
					return 0;
				}
				if (newChar == 'X') continue;
				if (newChar == 'O') {
					queue.offer(new Node(
							newX,
							newY,
							nowNode.dist+1,
							nowNode.x,
							nowNode.y));
				}
			}
		}
		return 1;
	}

	private void putPerson(Queue<Node> queue, String[] place) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (place[i].charAt(j) == 'P') {
					queue.offer(new Node(i, j, 0, -1, -1));
				}
			}
		}
	}

	class Node {
		int x;
		int y;
		int dist;
		int beforeX;
		int beforeY;
		public Node(int x, int y, int dist, int beforeX, int beforeY) {
			this.x = x;
			this.y = y;
			this.dist = dist;
			this.beforeX = beforeX;
			this.beforeY = beforeY;
		}
	}
}