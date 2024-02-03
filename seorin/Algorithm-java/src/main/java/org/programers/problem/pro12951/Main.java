package org.programers.problem.pro12951;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//    String s = "3 m e";
    String s = br.readLine();
    String result = new Solution().solution(s);
    System.out.println("result = " + result);
  }
  //asd asd d   asdqw 123 1241 31 r 1rqd
}
