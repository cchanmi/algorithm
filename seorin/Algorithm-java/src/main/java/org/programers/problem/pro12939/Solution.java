package org.programers.problem.pro12939;

import java.util.Arrays;

class Solution {
  public String solution(String s) {
    int min = Arrays.stream(s.split(" ")).mapToInt(i -> Integer.parseInt(i)).min().getAsInt();
    int max = Arrays.stream(s.split(" ")).mapToInt(i -> Integer.parseInt(i)).max().getAsInt();
    return min + " " + max;
  }
}