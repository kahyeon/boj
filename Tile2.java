import java.util.Scanner;

public class Tile2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();

		int Dp[] = new int[31];
		int result[] = new int[31];

		Dp[0] = 1;
		result[0] = 1;
		Dp[2] = 3;
		for (int i = 4; i <= 30; i += 2)
			Dp[i] = 2;

		for (int i = 2; i <= K; i += 2) {
			for (int j = 2; j <= i; j += 2) {
				result[i] += Dp[j] * result[i - j];

			}
		}
		System.out.println(result[K]);

	}

}
