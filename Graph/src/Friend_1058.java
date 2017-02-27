import java.util.Scanner;

public class Friend_1058 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int[][] friend = new int[num][num];
		int[] count = new int[num];
		
		//y=1 n=0
		for(int i = 0; i<num; i++){
			for(int j = 0; j<num; j++){
				if(friend[i][j] ==1){
					count[i]++;
				}else if(i!=j){
					for(int k = 0; k<num;k++){
						if(friend[i][k] ==1 && friend[j][k]==1){
							count[i]++;
							break;
						}
					}
				}
			}
		}
		
		int max = count[0];
		for(int i=1; i<num;i++){
			max = max>count[i]? max:count[i];
		}
		
		System.out.println(max);
	}

}
