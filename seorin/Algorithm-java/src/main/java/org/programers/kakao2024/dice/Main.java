package org.programers.kakao2024.dice;

public class Main {

  public static void main(String[] args) {
    Solution solution = new Solution();
//    int[][] dice = {
//        {1, 2, 3, 4, 5, 6},
//        {2, 2, 4, 4, 6, 6},
//    }
    int[][] dice = {
        {1, 2, 3, 4, 5, 6},
        {3, 3, 3, 3, 4, 4},
        {1, 3, 3, 4, 4, 4},
        {1, 1, 4, 4, 5, 5},
    };

    int[] answers = solution.solution(dice);
    for (int answer : answers) {
      System.out.println("answer = " + answer);
    }
  }
}
