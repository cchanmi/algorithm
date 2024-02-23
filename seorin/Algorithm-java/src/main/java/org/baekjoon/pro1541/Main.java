package org.baekjoon.pro1541;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s = br.readLine();
    String[] sums = s.split("-");
    long answer = 0;
    String[] plusNums = sums[0].split("\\+");
    for (String num : plusNums) answer += Integer.parseInt(num);

    for (int i = 1; i < sums.length; i++) {
      String[] nums = sums[i].split("\\+");
      for (String num : nums) answer -= Integer.parseInt(num);
    }
    System.out.println(answer);
  }
}
