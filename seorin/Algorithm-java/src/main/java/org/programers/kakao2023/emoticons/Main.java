package org.programers.kakao2023.emoticons;

public class Main {
	public static void main(String[] args) {
		int[][] users = {{40, 10000}, {25, 10000}};
		int[] emoticons = {7000, 9000};
		int[] result = solution(users, emoticons);
		System.out.println(result[0] + "   :   " + result[1]);
	}
	public static int[] solution(int[][] users, int[] emoticons) {
		int[] sales = new int[emoticons.length];
		int plusMemberNum = 0;
		int emoBenefit = 0;
		for (int i = 0; i < sales.length; i++) sales[i] = 40;
		int[] result = dsf(0, users, emoticons, sales, plusMemberNum, emoBenefit);
		return result;
	}

	public static int[] dsf(int depth, int[][] users, int[] emoticons, int[] sales,
			int plusMemberNum, int emoBenefit) {
		if (depth == emoticons.length) {
			int[] result = solve(users, emoticons, sales);
			if(plusMemberNum < result[0]) {
				plusMemberNum = result[0];
				emoBenefit = result[1];
			} else if (plusMemberNum == result[0]) {
				emoBenefit = Math.max(emoBenefit, result[1]);
			}
			return new int[]{plusMemberNum, emoBenefit};
		}
		while (sales[depth] > 0) {
			int[] result = dsf(depth + 1, users, emoticons, sales, plusMemberNum, emoBenefit);
			plusMemberNum = result[0];
			emoBenefit = result[1];
			sales[depth] -= 10;
		}
		sales[depth] = 40;
		return new int[]{plusMemberNum, emoBenefit};
	}

	private static int[] solve(int[][] users, int[] emoticons, int[] sales) {
		int plusMemberNum = 0;
		int emoBenefit = 0;
		for (int[] user : users) {
			int  userPay = 0;
			for (int i = 0; i < emoticons.length; i++) {
				if (user[0] <= sales[i]) {
					userPay += emoticons[i] * (100-sales[i])/100;
				}
			}
			System.out.println("userPay = " + userPay);
			if (user[1] <= userPay) {
				plusMemberNum++;
			} else {
				emoBenefit += userPay;
			}
		}
		return new int[]{plusMemberNum, emoBenefit};
	}
}
