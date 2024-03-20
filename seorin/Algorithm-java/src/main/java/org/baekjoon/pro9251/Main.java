package org.baekjoon.pro9251;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s1 = br.readLine();
    String s2 = br.readLine();
    int result = 0;
    int[][] value = new int[s1.length() + 1][s2.length() + 1];
    for (int i = 0; i < value.length; i++) Arrays.fill(value[i], 0);
    for (int i = 1; i <= s1.length(); i++)
      for (int j = 1; j <= s2.length(); j++) {
        value[i][j] = Math.max(value[i - 1][j - 1] + (s1.charAt(i - 1) == s2.charAt(j - 1) ? 1 : 0), Math.max(value[i - 1][j], value[i][j - 1]));
        result = Math.max(result, value[i][j]);
      }
    System.out.println(result);
  }
}
