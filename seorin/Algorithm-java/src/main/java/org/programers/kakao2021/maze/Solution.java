package org.programers.kakao2021.maze;

import java.util.*;

class Solution {

	List<List<Road>> trueRoad = new ArrayList<>();
	List<List<Road>> falseRoad = new ArrayList<>();

	Queue<People> peopleQueue = new LinkedList<>();

	public int solution(int n, int start, int end, int[][] roads, int[] traps) {
		int[] trueNode = new int[n+1];
		int[] falseNode = new int[n+1];
		for (int i = 0; i < n + 1; i++) {
			trueRoad.add(new ArrayList<>());
			falseRoad.add(new ArrayList<>());
		}
		Arrays.fill(trueNode, Integer.MAX_VALUE);
		Arrays.fill(falseNode, Integer.MAX_VALUE);
		int answer = Integer.MAX_VALUE;
		for (int[] road : roads) {
			trueRoad.get(road[0]).add(new Road(road[1], road[2]));
			falseRoad.get(road[1]).add(new Road(road[0], road[2]));
		}
		peopleQueue.offer(new People(true, 0, start));
		while (!peopleQueue.isEmpty()) {
			People people = peopleQueue.poll();
			System.out.println("people.state = " + people.state);
			for (int i = 1; i < n+1; i++) {
				System.out.print(trueNode[i] + " " );
			}
			System.out.println();
			for (int i =1; i < n+1; i++) {
				System.out.print(falseNode[i] + " " );
			}
			System.out.println();
			if (people.state) {
				for (Road road : trueRoad.get(people.location)) {
					if (road.dest == end) {
						answer = Math.min(answer, people.cost + road.cost);
						continue;
					}
					boolean peopleState = isTrap(traps, road.dest) ? false : true;
					if (peopleState) {
						if (trueNode[road.dest] <= people.cost + road.cost) continue;
						trueNode[road.dest] = people.cost + road.cost;
						peopleQueue.offer(new People(peopleState, trueNode[road.dest], road.dest));
					} else {
						if (falseNode[road.dest] <= people.cost + road.cost) continue;
						falseNode[road.dest] = people.cost + road.cost;
						peopleQueue.offer(new People(peopleState, falseNode[road.dest], road.dest));
					}
				}
			} else {
				for (Road road : falseRoad.get(people.location)) {
					if (road.dest == end) {
						answer = Math.min(answer, people.cost + road.cost);
						continue;
					}
					boolean peopleState = isTrap(traps, road.dest) ? true : false;
					if (peopleState) {
						if (trueNode[road.dest] <= people.cost + road.cost) continue;
						trueNode[road.dest] = people.cost + road.cost;
						peopleQueue.offer(new People(peopleState, trueNode[road.dest], road.dest));
					} else {
						if (falseNode[road.dest] <= people.cost + road.cost) continue;
						falseNode[road.dest] = people.cost + road.cost;
						peopleQueue.offer(new People(peopleState, falseNode[road.dest], road.dest));
					}
				}
			}
			System.out.println();
			System.out.println();
			System.out.println();
		}
		return answer;
	}

	private boolean isTrap(int[] traps, int dest) {
		for (int trap : traps) {
			if (trap == dest)  {
				return true;
			}
		}
		return false;
	}

	class People {
		boolean state;
		int cost;
		int location;

		public People(boolean state, int cost, int location) {
			this.state = state;
			this.cost = cost;
			this.location = location;
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