import java.util.Scanner;

public class Move {
	static int arr[][];
	static int count=0;
	static int n,m;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		
		arr = new int[n+1][m+1];
		int dp[][] = new int[n+1][m+1];
		for(int i = 1;i<=n;i++){
			for(int j = 1; j<=m;j++){
				arr[i][j] = sc.nextInt();
			}
		}
		sc.close();
		
		for(int i = 1;i<=n;i++){
			for(int j = 1; j<=m; j++){
				dp[i][j] = arr[i][j]+MAX(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
				
			}
		}
		
		System.out.println(dp[n][m]);
	}
	
	public static int MAX(int a, int b, int c){
		int max = a;
		max = a>b? a:b;
		max = max>c? max:c;
		return max;
	}
	/*
1 2 3 4
0 0 0 5
9 8 7 6

1 3 6 10
1 3 6 15
10 18 25 31
	 */
	

}
