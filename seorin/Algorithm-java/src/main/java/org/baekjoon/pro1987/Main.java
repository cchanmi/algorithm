package org.baekjoon.pro1987;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int r, c, result = 0;
    static char[][] area = new char[20][20];
    static boolean[][] visited = new boolean[20][20];
    static boolean[] visitedAlpha = new boolean[26];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        for (int i = 0; i < r; i++) {
            String s = br.readLine();
            for (int j = 0; j < c; j++) {
                area[i][j] = s.charAt(j);
            }
        }
        visitedAlpha[area[0][0] - 'A'] = true;
        visited[0][0] = true;
        dfs(1, 0, 0);
        System.out.println(result);
    }

    static void dfs(int depth, int x, int y) {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        result = Math.max(result, depth);
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX < 0 || newX >= r || newY < 0 || newY >= c) continue;
            if (!visited[newX][newY] && !visitedAlpha[area[newX][newY] - 'A']) {
                visited[newX][newY] = true;
                visitedAlpha[area[newX][newY] - 'A'] = true;
                dfs(depth + 1, newX, newY);
                visited[newX][newY] = false;
                visitedAlpha[area[newX][newY] - 'A'] = false;
            }
        }
    }

}