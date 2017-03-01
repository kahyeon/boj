import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long dp[] = new long[n+1];
		//int dp[] = new int[n+1];
		//2X1  dp[n] = dp[n-1]+1, 1X2 2X2 dp[n] = dp[n-2]
		
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 2;i<=n;i++){
			dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
		}
		
		System.out.println(dp[n]%10007);
		
	}

}
