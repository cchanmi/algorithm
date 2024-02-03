package org.programers.kakao2023.Month;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

	public static void main(String[] args) {
		String today = "2022.05.19";
		String[] terms = {"A 6", "B 12", "C 3"};
		String[] pricaies = {
				"2021.05.02 A",
				"2021.07.01 B",
				"2022.02.19 C",
				"2022.02.20 C"};
		int[] solution = solution(today, terms, pricaies);
		System.out.println("solution.length = " + solution.length);
		for (int i : solution) {
			System.out.println(i);
		}
	}

	public static int[] solution(String today, String[] terms, String[] privacies) {
		List<Integer> answer = new ArrayList<>();
		int todayYear = Integer.parseInt(today.substring(0, 4));
		int todayMonth = Integer.parseInt(today.substring(5, 7));
		int todayDay = Integer.parseInt(today.substring(8, 10));
		Map<Character, Integer> termMap = new HashMap<>();
		for (String term : terms) {
			termMap.put(term.charAt(0), Integer.parseInt(term.substring(2)));
		}
		for (int i = 0; i < privacies.length; i++) {
			int priYear = Integer.parseInt(privacies[i].substring(0, 4));
			int priMonth = Integer.parseInt(privacies[i].substring(5, 7));
			int priDay = Integer.parseInt(privacies[i].substring(8, 10));
			char priTerm = privacies[i].charAt(11);
			Integer termSub = termMap.get(priTerm) * 28;
			int daySub = (todayYear-priYear) * 28 * 12 + (todayMonth-priMonth) * 28 + (todayDay-priDay);
			if (daySub >= termSub) {
				answer.add(i+1);
			}
		}
		return answer.stream().mapToInt(i -> i).toArray();
	}
}
