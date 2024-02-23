package org.baekjoon.pro9663;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  static int n;
  static int result = 0;
  static boolean[] visited = new boolean[15];
  static int[] num = new int[15];


  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    n = Integer.parseInt(br.readLine());
    Arrays.fill(visited, false);
    bfs(0);
    System.out.println(result);
  }

  static void bfs(int depth) {
    if (depth == n){
      result++;
      return;
    }
    for (int i = 0; i < n; i++)
      if (isValid(depth, i)) {
        num[depth] = i;
        bfs(depth+1);
      }
  }

  private static boolean isValid(int x, int y) {
    for (int i = 0; i < x; i++) {
      if (num[i] == y) return false;
      if (x - i == Math.abs(y - num[i])) return false;
    }
    return true;
  }
}
