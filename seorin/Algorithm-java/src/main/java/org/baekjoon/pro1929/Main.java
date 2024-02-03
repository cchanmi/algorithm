package org.baekjoon.pro1929;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      int m = Integer.parseInt(st.nextToken());
      int n = Integer.parseInt(st.nextToken());
      boolean[] prime = new boolean[1000001];
      Arrays.fill(prime, true);
      for (int num = 2; num <= Math.sqrt(n) ; num++) {
        if (!prime[num]) continue;
        if (num >= m) System.out.println(num);
        for (int i = 1; i <= n; i++) {
          if (num * i > n) break;
          prime[num * i] = false;
        }
      }
    }
}
