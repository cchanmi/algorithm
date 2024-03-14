package org.naver_labs.pro3;

import java.util.LinkedList;
import java.util.Queue;

class Solution {

  public int solution(
      int a,
      int b,
      int c,
      int d) {
    Queue<Cup> q = new LinkedList<>();
    q.offer(new Cup(0, 0, 0, 0));
    int[][][] map = new int[101][101][101];
    while (!q.isEmpty()) {
      Cup now = q.poll();
    }
    return 0;
  }

  static class Cup {
    int a, b, c;
    int count;

    Cup(int a, int b, int c, int count) {
      this.a = a;
      this.b = b;
      this.c = c;
      this.count = count;
    }
  }
}