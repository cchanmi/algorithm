package org.baekjoon.pro2667;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {

  static int[][] map = new int[25][25];
  static int n;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    List<Integer> answer = new ArrayList<>();
    n = Integer.parseInt(br.readLine());
    for (int i = 0; i < n; i++) {
      String line = br.readLine();
      for (int j = 0; j < n; j++) {
        map[i][j] = Integer.parseInt(String.valueOf(line.charAt(j)));
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (map[i][j] == 1) {
          int size = bfs(i, j);
          answer.add(size);
        }
      }
    }
    Collections.sort(answer);
    System.out.println(answer.size());
    for (Integer num : answer) {
      System.out.println(num);
    }
  }

  private static int bfs(int x, int y) {
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    Queue<Node> q = new LinkedList<>();
    int result = 0;
    q.offer(new Node(x, y));
    map[x][y] = 0;
    while (!q.isEmpty()) {
      Node now = q.poll();
      result++;
      for (int i = 0; i < 4; i++) {
        int nowX = now.x + dx[i];
        int nowY = now.y + dy[i];
        if (nowX < 0 || nowX >= n || nowY < 0 || nowY >= n) {
          continue;
        }
        if (map[nowX][nowY] == 1) {
          q.offer(new Node(nowX, nowY));
          map[nowX][nowY] = 0;
        }
      }
    }
    return result;
  }

  static class Node {

    int x, y;

    Node(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }
}