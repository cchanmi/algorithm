package org.baekjoon.pro1260;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

  static int n;
  static int m;
  static int v;
  static boolean[] visited;
  static List<Integer>[] road;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    v = Integer.parseInt(st.nextToken());
    visited = new boolean[n + 1];
    road = new ArrayList[n + 1];
    for (int i = 0; i < n + 1; i++) {
      road[i] = new ArrayList<>();
    }
    for (int i = 0; i < m; i++) {
      st = new StringTokenizer(br.readLine());
      int node1 = Integer.parseInt(st.nextToken());
      int node2 = Integer.parseInt(st.nextToken());
      road[node1].add(node2);
      road[node2].add(node1);
    }
    for (int i = 1; i <= n; i++) {
      Collections.sort(road[i]);
    }
    Arrays.fill(visited, false);
    dfs(v);
    System.out.println();
    Arrays.fill(visited, false);
    bfs(v);
  }

  private static void bfs(int v) {
    Queue<Integer> bfsQ = new LinkedList();
    bfsQ.offer(v);
    visited[v] = true;
    while (!bfsQ.isEmpty()) {
      int node = bfsQ.poll();
      System.out.print(node + " ");
      for (Integer minNode : road[node]) {
        if (!visited[minNode]) {
          visited[minNode] = true;
          bfsQ.offer(minNode);
        }
      }
    }
  }

  private static void dfs(int v) {
    System.out.print(v + " ");
    visited[v] = true;
    for (Integer node : road[v]) {
      if (!visited[node]) {
        dfs(node);
      }
    }
  }
}
