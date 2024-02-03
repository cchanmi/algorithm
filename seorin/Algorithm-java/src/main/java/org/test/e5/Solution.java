package org.test.e5;

import static java.lang.Math.*;
import java.util.*;

class Solution {


	public int solution(int n, int[] tops) {
		int tri[] = new int[n+1];
		int squ[] = new int[n+1];
		tri[0] = 1;
		squ[0] = 0;
		for (int i = 1; i < n+1; i++) {
			if (tops[i-1] == 1){
				tri[i] = (tri[i-1]*3 + squ[i-1]*2)%10007;
				squ[i] = (tri[i-1] + squ[i-1])%10007;
			} else {
				tri[i] = (tri[i-1]*2 + squ[i-1])%10007;
				squ[i] = (tri[i-1] + squ[i-1])%10007;
			}
		}

		int answer = (tri[n] + squ[n])%10007;
		return answer;
	}
}