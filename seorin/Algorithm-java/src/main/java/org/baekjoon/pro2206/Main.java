package org.baekjoon.pro2206;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m, result = Integer.MAX_VALUE;
    static int[][] area = new int[1000][1000];
    static boolean visited[][] = new boolean[1000][1000];
    static boolean visitedB[][] = new boolean[1000][1000];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) area[i][j] = s.charAt(j) - '0';
        }
        for (int i = 0; i < n; i++) {
            Arrays.fill(visited[i], false);
            Arrays.fill(visitedB[i], false);
        }
        bfs();
        System.out.println(result <= n*m ? result : -1);
    }

    static void bfs() {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(0, 0, true, 1));
        visited[0][0] = true;
        while (!q.isEmpty()) {
            Node now = q.poll();
            if (now.x == n-1 && now.y == m-1) result = Math.min(result, now.cost);
            for (int i = 0; i < 4; i++) {
                int newX = now.x + dx[i];
                int newY = now.y + dy[i];
                if (newX <0 || newX >= n || newY <0 || newY >= m) continue;
                if (!visited[newX][newY]) {
                    if (visitedB[newX][newY] && !now.br) continue;
                    if (area[newX][newY] == 1) {
                        if (!now.br) continue;
                        visitedB[newX][newY] = true;
                        q.offer(new Node(newX, newY, false, now.cost + 1));
                    } else {
                        if (now.br) {
                            visited[newX][newY] = true;
                            q.offer(new Node(newX, newY, true, now.cost + 1));
                        } else {
                            visitedB[newX][newY] = true;
                            q.offer(new Node(newX, newY, false, now.cost + 1));
                        }
                    }
                }
            }
        }
    }

    static class Node {
        int x, y, cost;
        boolean br;
        Node (int x, int y, boolean br, int cost) {
            this.x = x; this.y = y; this.br = br; this.cost = cost;
        }
    }
}
