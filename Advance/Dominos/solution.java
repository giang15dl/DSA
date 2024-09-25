import java.util.Scanner;


public class Solution {
	static int dominos[][];
	static int matrix[][];
	static boolean visit[][];
	static int ans;
	
	static void backTrack(int count){
		if(count == 28){
			ans++;
			return;
		}
		
		boolean check = false;
		for(int i=0; i<7; i++){
			for(int j=0; j<8; j++){
				if(!visit[i][j]){
					if(i < 6 && !visit[i+1][j]){
						if(dominos[matrix[i][j]][matrix[i+1][j]] == 0){
							visit[i][j] = visit[i+1][j] = true;
							dominos[matrix[i][j]][matrix[i+1][j]] = 1;
							dominos[matrix[i+1][j]][matrix[i][j]] = 1;
							backTrack(count+1);
							visit[i][j] = visit[i+1][j] = false;
							dominos[matrix[i][j]][matrix[i+1][j]] = 0;
							dominos[matrix[i+1][j]][matrix[i][j]] = 0;
							
						}
					}
					if(j < 7 && !visit[i][j+1]){
						if(dominos[matrix[i][j]][matrix[i][j+1]] == 0){
							visit[i][j] = visit[i][j+1] = true;
							dominos[matrix[i][j]][matrix[i][j+1]] = 1;
							dominos[matrix[i][j+1]][matrix[i][j]] = 1;
							backTrack(count+1);
							visit[i][j] = visit[i][j+1] = false;
							dominos[matrix[i][j]][matrix[i][j+1]] = 0;
							dominos[matrix[i][j+1]][matrix[i][j]] = 0;
							
						}
					}
					check = true;
					break;
				}
			}
			if(check){
				break;
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		//System.setIn(new FileInputStream("C:/SCS/ADV2/src/test/input.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			matrix = new int[7][8];
			dominos = new int[7][8];
			visit = new boolean[7][8];
			
			for(int i=0; i<7; i++){
				for(int j=0; j<8; j++){
					matrix[i][j] = sc.nextInt();
				}
			}
			
			ans = 0;
			backTrack(0);
			System.out.println("#" + tc + " " + ans);
		}
		sc.close();
	}
}
