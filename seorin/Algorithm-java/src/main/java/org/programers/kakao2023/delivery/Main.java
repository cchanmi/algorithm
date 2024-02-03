package org.programers.kakao2023.delivery;

public class Main {

	public static void main(String[] args) {
		long solution = solution(4, 5,
				new int[]{1, 0, 3, 1, 2},
				new int[]{0, 3, 0, 4, 0});
		System.out.println(solution);
	}
	public static long solution(int cap, int n, int[] deliveries, int[] pickups) {
		long answer = 0;
		int delEnd = n-1, pickEnd = n-1;
		while(delEnd >= 0 || pickEnd >= 0) {
			int dist = 0;
			int delCap = cap, pickCap = cap;
			while (delCap > 0) {
				if (delEnd < 0) break;
				if (deliveries[delEnd] > 0) {
					dist = Math.max(dist, delEnd+1);
					deliveries[delEnd]--;
					delCap--;
				} else delEnd--;
			}
			while (pickCap > 0) {
				if (pickEnd < 0) break;
				if (pickups[pickEnd] > 0) {
					dist = Math.max(dist, pickEnd+1);
					pickups[pickEnd]--;
					pickCap--;
				} else pickEnd--;
			}
			answer += dist * 2;
		}
		return answer;
	}
}
