package org.baekjoon.pro2606;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    int n = Integer.parseInt(br.readLine());
    int lineCount = Integer.parseInt(br.readLine());
    boolean[] visited = new boolean[100];
    Queue<Integer>[] lines = new LinkedList[100];
    for (int i = 0; i < n; i++) lines[i] = new LinkedList<>();
    for (int i = 0; i < lineCount; i++) {
      st = new StringTokenizer(br.readLine());
      int first = Integer.parseInt(st.nextToken());
      int second = Integer.parseInt(st.nextToken());
      lines[first - 1].offer(second - 1);
      lines[second - 1].offer(first - 1);
    }

    Queue<Integer> birusQueue = new LinkedList<>();
    int answer = 0;
    birusQueue.offer(0);
    visited[0] = true;
    while (!birusQueue.isEmpty()) {
      Integer num = birusQueue.poll();
      answer++;
      while (!lines[num].isEmpty()) {
        Integer node = lines[num].poll();
        if (!visited[node]) {
          visited[node] = true;
          birusQueue.offer(node);
        }
      }
    }

    System.out.println(answer - 1);
  }
}
