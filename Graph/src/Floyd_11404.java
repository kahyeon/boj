import java.util.Scanner;

public class Floyd_11404 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n  =sc.nextInt();
		int m = sc.nextInt();
		
		
		int[][] cost = new int[n][n];
		for(int i = 0; i<n;i++){
			for(int j = 0; j<n; j++){
				if(i==j) cost[i][j] = 0;
				else cost[i][j] = 100000;
			}
		}
		
		for(int i = 0; i<m;i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			
			cost[a-1][b-1] = MIN(c, cost[a-1][b-1]);
			
		}
		
		//거쳐가는 경우
		for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                cost[i][j] = MIN(cost[i][j], cost[i][k]+cost[k][j]);
	            }
	        }
		}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				System.out.print(cost[i][j]+ " ");
			}
			System.out.print("\n");
		}
	}

	public static int MIN(int a, int b){
		return a<b?a:b;
	}
}
