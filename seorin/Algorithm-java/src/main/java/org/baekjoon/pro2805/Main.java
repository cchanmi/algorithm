package org.baekjoon.pro2805;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    long n = Long.valueOf(st.nextToken()), m = Long.valueOf(st.nextToken());
    st = new StringTokenizer(br.readLine());
    long[] tree = new long[1000001];
    for (int i = 0; i < n; i++)
      tree[i] = -Long.valueOf(st.nextToken());
    Arrays.sort(tree);
    long answer = -tree[0];
    for (int i = 0; i <= n; i++) {
      if (m >= (answer - (-tree[i])) * i) {
        m -= (answer - (-tree[i])) * i;
        answer = -tree[i];
      } else {
        answer -= m % i == 0 ? m / i : m / i + 1;
        break;
      }
    }
    System.out.println(answer);
  }
}