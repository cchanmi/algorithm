package org.programers.kakao2022.queuesum;

import java.util.*;

class Solution {

	long sum1 = 0;
	long sum2 = 0;
	Queue<Integer> q1 = new LinkedList<>();
	Queue<Integer> q2 = new LinkedList<>();

	public int solution(int[] queue1, int[] queue2) {
		int answer = 0;
		sum1 = (long) Arrays.stream(queue1).sum();
		sum2 = (long) Arrays.stream(queue2).sum();
		for (int i = 0; i < queue1.length; i++) {
			q1.offer(queue1[i]);
			q2.offer(queue2[i]);
		}
		int length = queue1.length + queue2.length;
		while (sum1 != sum2) {
			answer++;
			if (answer > length*3/2) {
				answer = -1;
				break;
			}
			if (sum1 > sum2) {
				Integer num = q1.poll();
				sum1 -= num;
				sum2 += num;
				q2.offer(num);
			} else {
				Integer num = q2.poll();
				sum2 -= num;
				sum1 += num;
				q1.offer(num);
			}
		}
		return answer;
	}

}