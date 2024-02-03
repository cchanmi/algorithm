package org.programers.problem.pro12951;

class Solution {

  public String solution(String s) {
    String[] stringList = s.split("");
    String result = "";
    boolean isFirst = true;
    for (String string : stringList) {
      result += isFirst ? string.toUpperCase() : string.toLowerCase();
      isFirst = string.equals(" ") ? true : false;
    }
    return result;
  }
}