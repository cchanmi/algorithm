package org.baekjoon.pro10026;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  static char[][] area = new char[100][100];
  static int n;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    boolean color[][] = new boolean[100][100];
    n = Integer.parseInt(br.readLine());
    for (int i = 0; i < n; i++) Arrays.fill(color[i], false);
    for (int i=0; i<n; i++) {
      String str = br.readLine();
      for (int j = 0; j < n; j++) area[i][j] = str.charAt(j);
    }
    System.out.print(bfs(color) + " ");
    for (int i=0; i<n; i++)
      for (int j = 0; j <n; j++)
        if (area[i][j] == 'G') area[i][j] = 'R';
    for (int i = 0; i < n; i++) Arrays.fill(color[i], false);
    System.out.print(bfs(color));
  }

  static int bfs(boolean[][] visited) {
    int result = 0;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    Queue<Node> q = new LinkedList<>();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (visited[i][j]) continue;
        result++;
        visited[i][j] = true;
        q.offer(new Node(i, j));
        while (!q.isEmpty()) {
          Node now = q.poll();
          for (int k = 0; k < 4; k++) {
            int nowX = now.x + dx[k];
            int nowY = now.y + dy[k];
            if (nowX < 0 || nowX >= n || nowY < 0 || nowY >= n) continue;
            if (area[i][j] == area[nowX][nowY] && !visited[nowX][nowY]) {
              visited[nowX][nowY] = true;
              q.offer(new Node(nowX, nowY));
            }
          }
        }
      }
    return result;
  }

  static class Node {
    int x, y;
    Node(int x, int y) {this.x = x;this.y = y;}
  }
}
