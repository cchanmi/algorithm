package org.baekjoon.pro14888;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

  static int n, max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
  static int[] num;
  static int[] operator = new int[4];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    n = Integer.parseInt(br.readLine());
    st = new StringTokenizer(br.readLine());
    num = new int[n];
    for (int i = 0; i < n; i++) num[i] = Integer.parseInt(st.nextToken());
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < 4; i++) operator[i] = Integer.parseInt(st.nextToken());

    dfs(1, num[0]);
    System.out.println(max);
    System.out.println(min);
  }

  static void dfs(int depth, int preValue) {
    if (depth == n) {
      max = Math.max(max, preValue);
      min = Math.min(min, preValue);
    } else {
      for (int i = 0; i < 4; i++) {
        if (operator[i] == 0) continue;
        operator[i]--;
        dfs(depth + 1, getResult(preValue, num[depth], i));
        operator[i]++;
      }
    }
  }

  private static int getResult(int firstNum, int secondNum, int operatorNum) {
    if (operatorNum == 0) {
      return firstNum + secondNum;
    } else if (operatorNum == 1) {
      return firstNum - secondNum;
    } else if (operatorNum == 2) {
      return firstNum * secondNum;
    } else {
      return firstNum / secondNum;
    }
  }
}
