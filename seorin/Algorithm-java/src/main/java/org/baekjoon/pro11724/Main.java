package org.baekjoon.pro11724;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  static int[] parent = new int[1001];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
    boolean[] visited = new boolean[1001];
    Arrays.setAll(parent, i -> i);
    for (int i = 0; i < m; i++) {
      st = new StringTokenizer(br.readLine());
      int u = Integer.parseInt(st.nextToken()), v = Integer.parseInt(st.nextToken());
      unionParent(u, v);
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
      if (!visited[getParent(i)]) {
        visited[getParent(i)] = true;
        answer++;
      }
    }
    System.out.println(answer);
  }

  private static void unionParent(int u, int v) {
    if (getParent(u) > getParent(v)) {
      parent[getParent(u)] = getParent(v);
    } else {
      parent[getParent(v)] = getParent(u);
    }
  }

  private static int getParent(int num) {
    if (num == parent[num]) return num;
    return parent[num] = getParent(parent[num]);
  }
}
