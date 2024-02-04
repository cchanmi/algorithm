package org.baekjoon.pro7576;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int[] dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken()), tomatoCount = 0;
    Queue<Tomato> q = new LinkedList<>();
    int[][] map = new int[n][m];
    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < m; j++) {
        map[i][j] = Integer.parseInt(st.nextToken());
        if (map[i][j] == 1 || map[i][j] == 0) tomatoCount++;
        if (map[i][j] == 1) q.offer(new Tomato(i, j, 0));
      }
    }
    int answer = 0;
    while (!q.isEmpty()) {
      Tomato now = q.poll();
      answer = Math.max(answer, now.count);
      tomatoCount--;
      for (int i = 0; i < 4; i++) {
        int nowX = now.x + dx[i];
        int nowY = now.y + dy[i];
        if (nowX < 0 || nowY < 0 || nowX >= n || nowY >= m) continue;
        if (map[nowX][nowY] == 0) {
          map[nowX][nowY] = 1;
          q.offer(new Tomato(nowX, nowY, now.count + 1));
        }
      }
    }
    System.out.println(tomatoCount == 0 ? answer : -1);
  }

  static class Tomato {
    int x, y, count;
    Tomato(int x, int y, int count) {
      this.x = x;
      this.y = y;
      this.count = count;
    }
  }
}
