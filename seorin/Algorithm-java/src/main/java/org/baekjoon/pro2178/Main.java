package org.baekjoon.pro2178;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

  static int[][] move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  static int[][] area = new int[100][100];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());
    for (int i = 0; i < n; i++) {
      String s = br.readLine();
      for (int j = 0; j < m; j++) {
        area[i] = Arrays.stream(s.split("")).mapToInt(Integer::parseInt).toArray();
      }
    }
    Queue<Result> q = new LinkedList<>();
    q.offer(new Result(new Pair(0, 0), 1));

    while (!q.isEmpty()) {
      Result now = q.poll();
      if (now.pair.x == n - 1 && now.pair.y == m - 1) {
        System.out.println(now.cost);
        return;
      }

      for (int[] moving : move) {
        int nowX = now.pair.x + moving[0];
        int nowY = now.pair.y + moving[1];
        if (nowX < 0 || nowY < 0 || nowX >= n || nowY >= m) continue;
        if (area[nowX][nowY] == 1) {
          area[nowX][nowY] = 0;
          q.offer(new Result(new Pair(nowX, nowY), now.cost + 1));
        }
      }
    }
    System.out.println("??");
  }

  static class Pair {
    int x;
    int y;

    public Pair(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  static class Result {
    Pair pair;
    int cost;

    public Result(Pair pair, int cost) {
      this.pair = pair;
      this.cost = cost;
    }
  }
}
