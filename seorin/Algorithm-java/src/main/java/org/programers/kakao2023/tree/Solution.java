package org.programers.kakao2023.tree;

import java.util.*;

class Solution {

	public int[] solution(long[] numbers) {
		List<Integer> answer = new ArrayList<>();
		for (Long number : numbers) {
			Stack<Boolean> tree = getTree(number);
			answer.add(checkTree(tree) ? 1 : 0);
		}
		return answer.stream().mapToInt(i -> i).toArray();
	}

	private boolean checkTree(Stack<Boolean> tree) {
		while (tree.size() > 1) {
			if(tree.pop()) {
				if (!tree.pop()) {
					return false;
				}
			} else {
				tree.pop();
			}
		}
		return true;
	}

	public Stack<Boolean> getTree(long number) {
		Stack<Boolean> tree = new Stack<>();
		while (number != 0) {
			tree.push(number%2==1);
			number /= 2;
		}
		int fullTreeSize = 0;
		int i=0;
		while (fullTreeSize < tree.size()) {
			fullTreeSize += Math.pow(2, i);
			i++;
		}
		while (fullTreeSize > tree.size()) {
			tree.push(false);
		}
		return tree;
	}

}
