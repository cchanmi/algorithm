package org.programers.kakao2024.dice;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

// https://school.programmers.co.kr/learn/courses/30/lessons/258709/solution_groups?language=java
class Solution {

  int[][] diceNum;
  List<Integer> answer = new ArrayList<>();
  Set<Integer> select = new HashSet<>();
  int answerSum = 0;
  int n;

  public int[] solution(int[][] dice) {
    diceNum = dice;
    n = dice.length;
    dfs(0, 0);
    return answer.stream().mapToInt(i -> i).toArray();
  }

  void dfs(int depth, int start) {
    if (depth == n / 2) {
      int winCount = getWinCount();
      System.out.print("num : ");
      for (Integer num : select) {
        System.out.print(num + "   ");
      }
      System.out.println();
      System.out.println("winCount = " + winCount);
      System.out.println();
      if (answerSum < winCount) {
        answerSum = winCount;
        answer.clear();
        answer = select.stream().sorted().collect(Collectors.toList());
      }
    } else {
      for (int i = start; i < n; i++) {
        select.add(i);
        dfs(depth + 1, i + 1);
        select.remove(i);
      }
    }
  }

  private int getWinCount() {
    List<Integer> diceResult = new ArrayList<>();
    List<Integer> otherResult = new ArrayList<>();
    dfsSelectResult(0, 0, 0, diceResult);
    dfsOtherResult(0, 0, 0, otherResult);
    Collections.sort(diceResult);
    Collections.sort(otherResult);
    int winCount = 0;
    for (int num : diceResult) {
      int left = 0, right = otherResult.size() - 1;
      while (left < right) {
        int middle = (left + right) / 2;
        if (otherResult.get(middle) < num) right = middle - 1;
        else left = middle +1;
      }
      winCount += left;
    }
    return winCount;
  }

  private void dfsOtherResult(int depth, int start, int sum, List<Integer> diceResult) {
    if (depth == n / 2) {
      diceResult.add(sum);
    } else {
      for (int i = start; i < n; i++) {
        if (!select.contains(i)) {
          for (int num : diceNum[i]) {
            dfsOtherResult(depth + 1, i + 1, sum + num, diceResult);
          }
          break;
        }
      }
    }
  }

  private void dfsSelectResult(int depth, int start, int sum, List<Integer> diceResult) {
    if (depth == n / 2) {
      diceResult.add(sum);
    } else {
      for (int i = start; i < n; i++) {
        if (select.contains(i)) {
          for (int num : diceNum[i]) {
            dfsSelectResult(depth + 1, i + 1, sum + num, diceResult);
          }
          break;
        }
      }
    }
  }
}