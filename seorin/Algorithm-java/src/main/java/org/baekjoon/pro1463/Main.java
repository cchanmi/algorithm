package org.baekjoon.pro1463;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.*;

public class Main {

  public static void main(String[] args) throws IOException {
    int result[] = new int[1000001];
    Arrays.fill(result, -1);
    BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in));
    int x = Integer.parseInt(br.readLine());
    NumSet first = new NumSet(x, 0);
    Queue<NumSet> queue = new LinkedList<>();
    queue.offer(first);
    result[x] = 0;
    while (result[1] == -1 && !queue.isEmpty()) {
      NumSet numSet = queue.poll();
      int number = numSet.num;
      int cost = numSet.cost;
      if (number % 3 == 0 && number / 3 >= 1 && result[number/3] == -1) {
        result[number/3] = cost + 1;
        queue.offer(new NumSet(number / 3, cost + 1));
      }
      if (number % 2 == 0 && number/2 >= 1 && result[number/2] == -1) {
        result[number/2] = cost + 1;
        queue.offer(new NumSet(number / 2, cost + 1));
      }
      if (number -1 >= 1 && result[number-1] == -1) {
        result[number - 1] = cost + 1;
        queue.offer(new NumSet(number - 1, cost + 1));
      }
    }
    System.out.println(result[1]);
  }

  static class NumSet {
    int num;
    int cost;

    public NumSet(int num, int cost) {
      this.num = num;
      this.cost = cost;
    }
  }
}
