package org.naver_labs.pro1;
import java.util.Stack;

class Solution {

	public int[] solution(int[] price) {
		int max = 0;
		Stack<Node> st = new Stack<>();
		int[] answer = new int[price.length];
		for (int i = price.length - 1; i >= 0; i--) {
			if (price[i] >= max) {
				answer[i] = -1;
				max = price[i];
				st.clear();
				st.push(new Node(i, price[i]));
			} else {
				while (st.peek().price <= price[i]) st.pop();
				answer[i] = st.peek().idx - i;
				st.push(new Node(i, price[i]));
			}
		}
		return answer;
	}

	static class Node {
		int idx, price;
		Node(int idx, int price) {
			this.idx = idx;
			this.price = price;
		}
	}
}