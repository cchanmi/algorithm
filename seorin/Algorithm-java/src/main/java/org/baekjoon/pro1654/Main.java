package org.baekjoon.pro1654;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

import java.util.*;

public class Main {

  static List<Integer> nSet = new ArrayList<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int k = Integer.parseInt(st.nextToken());
    int n = Integer.parseInt(st.nextToken());
    for (int i = 0; i < k; i++) {
      nSet.add(Integer.valueOf(br.readLine()));
    }
    Collections.sort(nSet);
    int result = -1;
    long left = 1;
    long right = nSet.get(k - 1);
    long mid  = (left + right) / 2;
    while (left <= right) {
      int count = getLine(mid);
      if (count >= n) {
        result = (int) Math.max(result, mid);
        left = mid + 1;
      } else {
        right = mid - 1;
      }
      mid = (left + right) / 2;
    }
    System.out.println(result);
  }

  private static int getLine(long number) {
    int sum = 0;
    for (Integer setNum : nSet) {
      sum += setNum / number;
    }
    return sum;
  }
}
