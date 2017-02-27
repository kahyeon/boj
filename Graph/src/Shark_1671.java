import java.util.Scanner;

public class Shark_1671 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		
		int[][] time = new int[num][num];
		int[][] arr = new int[num][num];
		for(int i = 0;i<num;i++){
			for(int j = 0; j<num;j++){
				time[i][j] = sc.nextInt();
				arr[i][j] = time[i][j];
			}
		}
		int result = 0;
		for(int k = 0; k<num;k++){
			for(int i = 0; i<num; i++){
				for(int j = 0; j<num; j++){
					if(i==k || j==k) continue;
					
					if(time[i][j]> time[i][k] + time[k][j]){
						result = -1;
						break;
					}else if(time[i][j] == time[i][k] + time[k][j]){
						arr[i][j] = 0;//k 거치는게 있으면 거쳐간다
					}			
					
				}
			}
		}
		
		
		for(int i = 0;i<num; i++){
			for(int j = i+1;j<num;j++){
				result+= arr[i][j];
			}
		}
		System.out.println(result);
		
	}

}
