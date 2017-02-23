import java.util.Scanner;

public class Ascending {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
	    int dp[][] = new int[N][10];//N자리수, 0~9 마지막 수
	    int total = 0;
		
		for (int i = 0; i <=9; i++)
	        dp[0][i] = 1;
	 
	    for (int i = 1; i < N; i++)
	        for (int j = 0; j < 10; j++)
	            for (int k = j; k < 10; k++)
	                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
	 
	    for (int i = 0; i < 10; i++)
	        total = (total + dp[N-1][i]) % 10007;
	    
	    System.out.println(total);

	}

}
