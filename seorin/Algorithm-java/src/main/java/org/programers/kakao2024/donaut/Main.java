package org.programers.kakao2024.donaut;

public class Main {

  public static void main(String[] args) {
    Solution solution = new Solution();
    int[][] edges = {{2, 1}, {4, 3}, {2, 3}, {1, 1}};
    /*
    int[][] edges = {
        {4, 11},
        {1, 12},
        {8, 3},
        {12, 7},
        {4, 2},
        {7, 11},
        {4, 8},
        {9, 6},
        {10, 11},
        {6, 10},
        {3, 5},
        {11, 1},
        {5, 3},
        {11, 9},
        {3,8}
    };

     */
//    int[] answer = solution.solution(edges);
//    for (int i = 0; i < answer.length; i++) {
//      System.out.println("answer[" + i + "] = " + answer[i]);
//    }
    solution.solution(edges);
  }
}
