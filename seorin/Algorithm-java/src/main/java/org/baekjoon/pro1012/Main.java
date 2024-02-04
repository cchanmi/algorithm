package org.baekjoon.pro1012;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  static int[][] map = new int[50][50];
  static int m;
  static int n;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader((System.in)));
    StringTokenizer st;
    int t = Integer.parseInt(br.readLine());
    for (int i = 0; i < t; i++) {
      int answer = 0;
      for (int[] line : map) Arrays.fill(line, 0);
      st = new StringTokenizer(br.readLine());
      m = Integer.parseInt(st.nextToken()); // 가로
      n = Integer.parseInt(st.nextToken()); // 세로
      int k = Integer.parseInt(st.nextToken());
      for (int j = 0; j < k; j++) {
        st = new StringTokenizer(br.readLine());
        map[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = 1;
      }
      for (int j = 0; j < m; j++) {
        for (int l = 0; l < n; l++) {
          if (map[j][l] == 1) {
            answer++;
            bfs(j, l);
          }
        }
      }
      System.out.println(answer);
    }
  }

  private static void bfs(int x, int y) {
    Queue<Node> q = new LinkedList<>();
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    q.offer(new Node(x, y));
    map[x][y] = 0;
    while (!q.isEmpty()) {
      Node now = q.poll();
      for (int i = 0; i < 4; i++) {
        int nowX = now.x + dx[i];
        int nowY = now.y + dy[i];
        if (nowX < 0 || nowX >= m || nowY < 0 || nowY >= n) continue;
        if (map[nowX][nowY] == 1){
          q.offer(new Node(nowX, nowY));}
        map[nowX][nowY] = 0;
      }
    }
  }

  static class Node {
    int x, y;
    Node(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }
}