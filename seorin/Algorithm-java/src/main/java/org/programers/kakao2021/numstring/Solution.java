package org.programers.kakao2021.numstring;

import java.util.*;

class Solution {

	Map<String, Integer> stringIntegerMap = new HashMap<String, Integer>() {
		{
			put("zero", 0);
			put("one", 1);
			put("two", 2);
			put("three", 3);
			put("four", 4);
			put("five", 5);
			put("six", 6);
			put("seven", 7);
			put("eight", 8);
			put("nine", 9);
		}
	};

	public int solution(String s) {
		int answer = 0;
		while (s.length() > 0) {
			if (s.substring(0, 1).matches("[0-9]")) {
				answer *= 10;
				answer += Integer.parseInt(s.substring(0, 1));
				s = s.substring(1, s.length());
			} else {
				for (String key : stringIntegerMap.keySet()) {
					if (s.length() >= key.length()) {
						if (s.substring(0, key.length()).equals(key)) {
							answer *= 10;
							answer += stringIntegerMap.get(key);
							s = s.substring(key.length(), s.length());
							break;
						}
					}
				}
			}
		}
		return answer;
	}
}