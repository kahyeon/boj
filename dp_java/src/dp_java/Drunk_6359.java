package dp_java;

import java.util.Scanner;

public class Drunk_6359 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		boolean[] room; 
		int total=0;
		for(int i = 0; i<T;i++){
			int n = sc.nextInt();
			room = new boolean[n+1];
			
			for(int j = 1;j<=n;j++){
				
				for(int k = 1; j*k<=n; k++){
					if(room[j*k]){
						room[j*k] = false;
					}else{
						room[j*k] = true;
						//total++;
					}
				}
				
			}
			for(int k = 1;k<=n; k++){
				if(room[k]) total++;
			}
			System.out.println(total);
			
			
			

		}
		
		sc.close();
	}
	
	
}



