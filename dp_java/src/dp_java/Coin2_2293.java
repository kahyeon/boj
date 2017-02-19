package dp_java;

import java.util.Scanner;

public class Coin2_2293 {

	public static void main(String[] args) {
		// dp배열에는 해당 금액을 만드는 최소 동전개수 값이 들어감
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		
		int[] dp= new int[k+1];
		int value[] = new int[n];
		
		for(int i = 0;i<n;i++){
			value[i] = sc.nextInt();
		}
		sc.close();
		
		int temp;//비교를 위한 임시값, value[i]를 사용한 동전갯수가 저장됨
		for(int i = 0;i<n;i++){
			for(int j = value[i];j<=k;j++){
				
				if(dp[j] == 0){
					dp[j] = dp[j-value[i]]+1;
				}else{
					temp = dp[j-value[i]]+1; 
					dp[j] = MIN(dp[j], temp);
				}
					
			}
		}
		if(dp[k] == 0) dp[k] =-1;
		System.out.println(dp[k]);
	}
	
	public static int MIN(int a, int b){
		return a<b?a:b;
	}

	/* 1원 때,       5원 때,
	 * dp[1] = 1    
	 * dp[2] = 2
	 * dp[3] = 3
	 * dp[4] = 4
	 * dp[5] = 5	dp[5] = min(1, 5) = 1// dp[0] + 1
	 * dp[6] = 6	dp[6] = min(2, 6) = 2// dp[1] + 1
	 * dp[7] = 7
	 * dp[8] = 8
	 * dp[9] = 9
	 * dp[10]=10	dp[10] = min(dp[5]+1, dp[10])
	 * dp[11]=11
	 * dp[12]=12
	 * dp[13]=13
	 * dp[14]=14
	 * dp[15]=15
	 */
}
