package dp_java;

import java.util.Scanner;

public class Downhill_1520 {
	// static
	static int[][] arr;
	static int count = 0;
	static int m, n;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		m = sc.nextInt();// 세로
		n = sc.nextInt();// 가로

		arr = new int[m][n];

		for (int i = 0; i < m; i++) {
			// sc.nextLine();
			for (int j = 0; j < n; j++) {
				arr[i][j] = Integer.parseInt(sc.next());
			}
		}
		sc.close();
		dp(0,0);
		System.out.println(count);

	}

	public static void dp(int preX, int preY) {// 현재 위치

		int[][] pos = { { 0, -1 }, { -1, 0 }, { 1, 0 }, { 0, 1 } };
		for (int i = 0; i < 4; i++) {

			int x = preX + pos[i][0];
			int y = preY + pos[i][1];
			if (x >= 0 && y >= 0 && x <= m-1 && y <= n-1 && arr[preX][preY] > arr[x][y]) {
				if (x == m-1 && y == n-1) {
					count++;
				} else {
					dp(x, y);
				}
			}

		}

	}

}
