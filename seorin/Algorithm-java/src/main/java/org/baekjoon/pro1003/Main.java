package org.baekjoon.pro1003;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  static int a;

  public static void main(String[] args) throws IOException {
    int[] zero = new int[41];
    int[] one = new int[41];
    a = 10;
    System.out.println("a = " + a);
    zero[0] = 1;
    zero[1] = 0;
    one[0] = 0;
    one[1] = 1;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(br.readLine());
    for (int i = 0; i < t; i++) {
      int num = Integer.parseInt(br.readLine());
      for (int j = 2; j <= num; j++) {
        zero[j] = zero[j - 1] + zero[j - 2];
        one[j] = one[j - 1] + one[j - 2];
      }
      for (int j = 0; j <= num; j++) {
        System.out.print(zero[j] + " ");
      }
      System.out.println(zero[num] + " " + one[num]);
    }
  }
}
