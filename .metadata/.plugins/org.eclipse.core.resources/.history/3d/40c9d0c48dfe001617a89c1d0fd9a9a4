import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Island_4963 {
	public static int island[][];
	public static int w,h;

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
		String str[];
		int count = 0;
		while(true){
			int num = 0;
			str = read.readLine().split(" ");
			w = Integer.parseInt(str[0]);
			h = Integer.parseInt(str[1]);
			island = new int[h][w];
			if(w==0 && h==0) break;
			for(int i = 0;i<h;i++){
				str = read.readLine().split(" ");
				for(int j = 0;j<w;j++){
					island[i][j] = Integer.parseInt(str[j]);
				}
			}
			
			for(int i = 0;i<h;i++){
				for(int j = 0;j<w;j++){
					if(island[i][j]>0){
						count++;
						connect(i,j);
					}
				}
			}

			System.out.println(count);
		}
		read.close();
	}
	
	public static void connect(int x, int y){

		int pos[][] = {{0,1}, {1,1}, {1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
		island[x][y] = 0;//Å½»ö ÈÄ 0
		for(int i = 0;i<8;i++){
			int movX = x+ pos[i][0];
			int movY = y+ pos[i][1];
			
			if((0<=movX && movX<h)&& (0<=movY && movY<w) && island[movX][movY]>0) connect(movX,movY);
		}
	}
}
