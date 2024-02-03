package org.baekjoon.pro1689;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    int n = Integer.parseInt(br.readLine());
    PriorityQueue<Point> pq = new PriorityQueue<>();
    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      long start = Long.parseLong(st.nextToken());
      long end = Long.parseLong(st.nextToken());
      pq.offer(new Point(start, 1));
      pq.offer(new Point(end, -1));
    }
    int result = 0;
    int sum = 0;
    while (!pq.isEmpty()) {
      Point now = pq.poll();
      sum += now.cost;
      result = Math.max(result, sum);
    }
    System.out.println(result);
  }

  static class Point implements Comparable<Point> {

    long position;
    int cost;

    public Point(long position, int cost) {
      this.position = position;
      this.cost = cost;
    }

    @Override
    public int compareTo(Point o) {
      if (this.position < o.position) {
        return -1;
      } else if (this.position > o.position) {
        return 1;
      } else {
        if (this.cost < o.cost) {
          return -1;
        } else if (this.cost > o.cost) {
          return 1;
        } else {
          return 0;
        }
      }
    }
  }
}