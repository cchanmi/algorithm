package org.baekjoon.pro1007;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  static boolean[] isStart = new boolean[20];
  static int[] numX = new int[20];
  static int[] numY = new int[20];
  static double result;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    int t = Integer.parseInt(br.readLine());
    for (int a = 0; a < t; a++) {
      result = Double.MAX_VALUE;
      int n = Integer.parseInt(br.readLine());
      for (int i = 0; i < n; i++) {
        st = new StringTokenizer(br.readLine());
        numX[i] = Integer.parseInt(st.nextToken());
        numY[i] = Integer.parseInt(st.nextToken());
      }
      dfs(0, 0, n);
      System.out.println(result);
      String c;
    }
  }

  private static void dfs(int start, int d, int n) {
    if (d == n / 2) {
      long sumX = 0, sumY = 0;
      for (int i = 0; i < n; i++) {
        sumX += isStart[i] ? -numX[i] : numX[i];
        sumY += isStart[i] ? -numY[i] : numY[i];
      }
      result = Math.min(result, Math.sqrt(Math.pow(sumX, 2) + Math.pow(sumY, 2)));
    } else {
      for (int i = start; i < n / 2 + d; i++) {
        if (!isStart[i]) {
          isStart[i] = true;
          dfs(i + 1, d + 1, n);
          isStart[i] = false;
        }
      }
    }

  }
}
