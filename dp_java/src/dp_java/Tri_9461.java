package dp_java;

import java.util.Scanner;

public class Tri_9461 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int N;
		long dp[] = new long[100];
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 2;
		dp[4] = 2;
		for (int i = 0; i < T; i++) {
			N = sc.nextInt();
			for (int j = 5; j <= N - 1; j++) {
				dp[j] = dp[j - 1] + dp[j - 5];
			}
			System.out.println(dp[N - 1]);
		}

		sc.close();

	}

}
