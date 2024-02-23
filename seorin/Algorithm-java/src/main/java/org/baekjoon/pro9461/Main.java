package org.baekjoon.pro9461;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(br.readLine());
    long[] length = new long[101];
    length[1] = 1;
    length[2] = 1;
    length[3] = 1;
    for (int i = 0; i < t; i++) {
      int num = Integer.parseInt(br.readLine());
      for (int j = 4; j <= num; j++)
        length[j] = length[j - 3] + length[j - 2];
      System.out.println(length[num]);
    }
  }
}
