package org.nl.pro2;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class Solution {

	public int[] solution(
			int N,
			int[] coffee_times) {
		List<Integer> answer = new ArrayList<>();
		PriorityQueue<Coffee> pq = new PriorityQueue<>();
		int idx = N;
		for (int i = 0; i < N; i++) {
			pq.offer(new Coffee(i + 1, coffee_times[i]));
		}
		while (!pq.isEmpty()) {
			Coffee now = pq.poll();
			answer.add(now.idx);
			if (idx < coffee_times.length) {
				pq.offer(new Coffee(idx + 1, coffee_times[idx] + now.time));
			}
			idx++;
		}
		return answer.stream().mapToInt(i -> i).toArray();
	}

	static class Coffee implements Comparable<Coffee> {
		int idx, time;
		Coffee(int idx, int time) {
			this.idx = idx;
			this.time = time;
		}
		@Override
		public int compareTo(Coffee o) {
			if (this.time == o.time) return this.idx - o.idx;
			else return this.time - o.time;
		}
	}
}