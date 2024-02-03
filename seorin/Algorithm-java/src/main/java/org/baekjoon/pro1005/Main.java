package org.baekjoon.pro1005;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

  static int T;
  static int[] cost = new int[1001];
  static int[] indegree = new int[1001];
  static int[] nodeCost = new int[1001];
  static List<Integer>[] roads = new ArrayList[1001];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    T = Integer.parseInt(br.readLine());
    for (int t = 0; t < T; t++) {
      Arrays.fill(nodeCost, 0);
      Arrays.fill(indegree, 0);
      st = new StringTokenizer(br.readLine());
      int n = Integer.parseInt(st.nextToken());
      int k = Integer.parseInt(st.nextToken());
      st = new StringTokenizer(br.readLine());
      for (int i = 1; i <= n; i++) {
        cost[i] = Integer.parseInt(st.nextToken());
        nodeCost[i] = cost[i];
        roads[i] = new ArrayList<>();
      }
      for (int i = 1; i <= k; i++) {
        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        roads[x].add(y);
        indegree[y]++;
      }
      int start = Integer.parseInt(br.readLine());
      /**
       * solve
       */
      Queue<Node> q = new LinkedList<>();
      for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0){
          q.offer(new Node(i, cost[i]));
        }
      }
      while (!q.isEmpty()) {
        Node now = q.poll();
        for (Integer end : roads[now.val]) {
          nodeCost[end] = Math.max(nodeCost[end], cost[end] + now.cost);
          indegree[end]--;
          if (indegree[end] == 0) {
            q.offer(new Node(end, nodeCost[end]));
          }
        }
      }
      System.out.println(nodeCost[start]);
    }
  }

  public static final class Node {
    private final int val;
    private final int cost;

    public Node(int val, int cost) {
      this.val = val;
      this.cost = cost;
    }
  }
}