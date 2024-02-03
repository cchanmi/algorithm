package org.programers.kakao2022.mountain;

import java.util.*;

class Solution {

	int[] gates;
	int[] summits;

	public int[] solution(
			int n,
			int[][] paths,
			int[] gates,
			int[] summits) {
		int[] answer = {Integer.MAX_VALUE, Integer.MAX_VALUE};
		this.gates = gates;
		this.summits = summits;
		ArrayList<Road>[] roadsList = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			roadsList[i] = new ArrayList<>();
		}
		int[] node = new int[n + 1];
		for (int[] path : paths) {
			roadsList[path[0]].add(new Road(path[1], path[2]));
			roadsList[path[1]].add(new Road(path[0], path[2]));
		}
		Arrays.fill(node, Integer.MAX_VALUE);
		Queue<People> peopleQueue = new LinkedList<>();
		for (int gate : gates) {
			peopleQueue.offer(new People(gate, 0));
		}
		while (!peopleQueue.isEmpty()) {
			People people = peopleQueue.poll();
			for (Road road : roadsList[people.location]) {
				if (node[road.dest] > Math.max(people.intensity, road.cost)) {
					node[road.dest] = Math.max(people.intensity, road.cost);
					if (isGate(road.dest)) {
						continue;
					}
					if (isSummit(road.dest)) {
						if (answer[1] > node[road.dest]) {
							answer[0] = road.dest;
							answer[1] = node[road.dest];
						} else if (answer[1] == node[road.dest]) {
							answer[0] = Math.min(answer[0], road.dest);
						}
						continue;
					}
					peopleQueue.add(new People(road.dest, node[road.dest]));
				}
			}
		}

		return answer;
	}

	boolean isGate(int node) {
		return Arrays.stream(gates).anyMatch(gate -> gate == node);
	}

	boolean isSummit(int node) {
		return Arrays.stream(summits).anyMatch(summit -> summit == node);
	}

	class People {

		int location;
		int intensity;

		public People(int location, int intensity) {
			this.location = location;
			this.intensity = intensity;
		}
	}

	class Road {

		int dest;
		int cost;

		public Road(int dest, int cost) {
			this.dest = dest;
			this.cost = cost;
		}
	}
}