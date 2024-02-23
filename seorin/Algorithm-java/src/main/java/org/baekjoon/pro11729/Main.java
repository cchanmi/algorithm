package org.baekjoon.pro11729;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  static int n;
  static int result = 1;
  public static StringBuilder sb = new StringBuilder();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    n = Integer.parseInt(br.readLine());
    for (int i = 2; i <= n; i++) result = 2 * result + 1;
//    System.out.println(result);
    sb.append(result).append("\n");
    dfs(n, 1, 3, 2);
    System.out.println(sb);
  }

  private static void dfs(int top, int start, int end, int etc) {
    if (top == 1) {
//      System.out.println(start + " " + end);
      sb.append(start + " " + end).append("\n");
    } else {
      dfs(top - 1, start, etc, end);
//      System.out.println(start + " " + end);
      sb.append(start + " " + end).append("\n");
      dfs(top - 1, etc, end, start);
    }
  }
}