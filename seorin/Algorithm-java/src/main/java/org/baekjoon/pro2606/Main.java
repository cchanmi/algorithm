package org.baekjoon.pro2606;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  static int n, m, maxResult = 0;
  static int[][] area = new int[8][8];
  static List<Birus> originBirus = new ArrayList<>();
  static int[] dx = {-1, 1, 0, 0};
  static int[] dy = { 0, 0, -1, 1};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < m; j++) {
        area[i][j] = Integer.parseInt(st.nextToken());
        if (area[i][j] == 2) originBirus.add(new Birus(i, j));
      }
    }
    dfsBlock(0, 0, 0);
    System.out.println(maxResult);
  }


  static void dfsBlock(int x, int y, int depth) {
    if (depth == 3) bfsBirus();
    else {
      for (int j = y; j < m; j++)
        if (area[x][j] == 0) {
          area[x][j] = 1;
          dfsBlock(x, j+1, depth+1);
          area[x][j] = 0;
        }
      for (int i = x+1; i < n; i++)
        for (int j = 0; j < m; j++)
          if (area[i][j] == 0) {
            area[i][j] = 1;
            dfsBlock(x, y, depth+1);
            area[i][j] = 0;
          }
    }
  }

  static private void bfsBirus() {
    Queue<Birus> q = new LinkedList<>();
    boolean[][] visited = new boolean[n][m];
    for (int i = 0; i < n; i++) Arrays.fill(visited[i], false);
    for (Birus birus : originBirus) q.offer(new Birus(birus.x, birus.y));
    while (!q.isEmpty()) {
      Birus now = q.poll();
      for (int i = 0; i < 4; i++) {
        int nowX = now.x + dx[i];
        int nowY = now.y + dy[i];
        if (nowX < 0 || nowX >= n || nowY<0 || nowY >= m) continue;
        if (area[nowX][nowY] == 0 && !visited[nowX][nowY]) {
          visited[nowX][nowY] = true;
          q.offer(new Birus(nowX, nowY));
        }
      }
    }
    int result = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (area[i][j] == 0 && !visited[i][j]) result++;
    maxResult = Math.max(maxResult, result);
  }

  static class Birus {
    int x, y;
    public Birus(int x, int y) {this.x = x;this.y = y;}
  }
}
