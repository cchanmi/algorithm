package org.programers.kakao2023.graph;

import java.util.*;

class Solution {
	Cell[][] graph = new Cell[50][50];

	public String[] solution(String[] commands) {
		List<String> answer = new ArrayList<>();
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				graph[i][j] = new Cell(null);
			}
		}
		for (String command : commands) {
			String[] s = command.split(" ");
			switch (s[0]) {
				case "UPDATE":
					if (s.length == 4) {
						int r = Integer.parseInt(s[1])-1;
						int c = Integer.parseInt(s[2])-1;
						Cell parent = graph[r][c].getParent();
						parent.value = s[3];
					} else {
						updateValue(s[1], s[2]);
					}
					break;
				case "MERGE":
					int r1 = Integer.parseInt(s[1])-1;
					int c1 = Integer.parseInt(s[2])-1;
					int r2 = Integer.parseInt(s[3])-1;
					int c2 = Integer.parseInt(s[4])-1;
					Cell cell1 = graph[r1][c1].getParent();
					Cell cell2 = graph[r2][c2].getParent();
					String value = null;
					if (cell1.value != null && cell2.value != null) {
						value = cell1.value;
					} else if (cell1.value == null) {
						value = cell2.value;
					} else if (cell2.value == null) {
						value = cell1.value;
					}
					cell2.parent = cell1;
					cell1.value = value;
					break;
				case "UNMERGE":
					int r = Integer.parseInt(s[1])-1;
					int c = Integer.parseInt(s[2])-1;
					Cell parent = graph[r][c].getParent();
					String value1 = parent.value;
					parent.parent = null;
					Cell newParent = graph[r][c].getParent();
					System.out.println("newParent = " + parent.equals(newParent));
					newParent.value = value1;
					break;
				case "PRINT":
					int r3 = Integer.parseInt(s[1])-1;
					int c3 = Integer.parseInt(s[2])-1;
					Cell cell = graph[r3][c3].getParent();
					String response = cell.value == null ? "EMPTY" : cell.value;
					answer.add(response);
					break;
			}
			for (int i = 0; i < 50; i++) {
				for (int j = 0; j < 50; j++) {
					System.out.print(graph[i][j].value + " ");
				}
				System.out.println();
			}
		}
		return answer.stream().toArray(String[]::new);
	}

	private void updateValue(String value1, String value2) {
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				Cell cell = graph[i][j].getParent();
				if (value1.equals(graph[i][j].getParent().value)) {
					cell.value = value2;
				}
			}
		}
	}

	class Cell {
		public String value;
		public Cell parent;

		public Cell(String value) {
			this.value = value;
			this.parent = this;
		}

		public Cell getParent() {
			if (parent == null) {
				parent = this;
			}
			if (parent == this) {
				return this;
			}
			return parent.getParent();
		}
	}
}