package org.baekjoon.pro1920;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static List<Integer> setNumber = new ArrayList<>();
    static List<Integer> resultNumber = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int number = Integer.parseInt(st.nextToken());
            setNumber.add(number);
        }
        Collections.sort(setNumber);
        int m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            resultNumber.add(Integer.parseInt(st.nextToken()));
        }
        for (Integer num : resultNumber) {
            System.out.println(solve(n, m, num));
        }
    }

    static int solve(int n, int m, int number) {
        int left = 0;
        int right = n - 1;
        int mid = (left + right) / 2;
        while (left <= right) {
            if (setNumber.get(mid) == number) {
                return 1;
            } else if (setNumber.get(mid) > number) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        return 0;
    }
}