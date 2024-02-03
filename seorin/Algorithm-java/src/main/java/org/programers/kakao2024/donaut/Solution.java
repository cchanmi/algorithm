package org.programers.kakao2024.donaut;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {

  int value[][];

  int tset[];

  void solution(int[][] land) {
    value = land;
    int a=  value.length;
    // 가로
    int b =  value[0].length;

    tset = new int[b];
    System.out.println("a = " + a);
    System.out.println("b = " + b);
  }
}