package org.baekjoon.pro2579;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int[] stairs = new int[301];
    int n = Integer.parseInt(br.readLine());
    for (int i = 0; i < n; i++) stairs[i] = Integer.parseInt(br.readLine());
    int[] zero = new int[301];
    int[] first = new int[301];
    int[] second = new int[301];
    zero[n-1] = -10001;
    first[n - 1] = stairs[n - 1];
    second[n-1] = -10001;
    for (int i = n - 2; i >= 0; i--) {
      zero[i] = Math.max(first[i + 1], second[i + 1]);
      first[i] = zero[i + 1] + stairs[i];
      second[i] = first[i + 1] + stairs[i];
    }
    System.out.println(Math.max(zero[0], Math.max(first[0], second[0])));
  }
}
