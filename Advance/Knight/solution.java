package quanma;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class quanma {
	static int T, n, m, arr[][], sx, sy, visited[][], min, count, check[], dist[][], quanx[], quany[];
	static int dx[] = {-2,-1,1,2,2,1,-1,-2};
	static int dy[] = {1,2,2,1,-1,-2,-2,-1};
	static int qx[] = new int[10000], qy[] = new int[10000], frontx, rearx, fronty, reary;
	static void init(){
		frontx = rearx = fronty = reary = -1;
	}
	static boolean isEmptyx(){
		if(frontx == rearx)return true;
		return false;
	}
	static boolean isEmptyy(){
		if(fronty == reary)return true;
		return false;
	}
	static void enQueuex(int e){
		rearx ++;
		qx[rearx] = e;
	}
	static void enQueuey(int e){
		reary ++;
		qy[reary] = e;
	}
	static int deQueuex(){
		if(!isEmptyx()){
			frontx ++;
			return qx[frontx]++;
		}
		return -1;
	}
	static int deQueuey(){
		if(!isEmptyy()){
			fronty ++;
			return qy[fronty];
		}
		return -1;
	}
	static void bfs(int i, int j, int curPoint){
		
		visited[i][j] = 1;
		enQueuex(i);
		enQueuey(j);
		while(!isEmptyx() && !isEmptyy()){
			int a = deQueuex();
			int b = deQueuey();
			for(int k=0; k<8; k++){
				int tx = a + dx[k];
				int ty = b + dy[k];
				if(tx>=0 && tx<n && ty>=0 && ty<m && visited[tx][ty] == 0){
					if(arr[tx][ty] >= 0){
						visited[tx][ty] = visited[a][b] + 1;
						enQueuex(tx);
						enQueuey(ty);
					}
				}
			}
		}
		for(int z = curPoint + 1; z < count; z++){
			if(visited[quanx[z]][quany[z]] != 0 ){
				dist[curPoint][z] = visited[quanx[z]][quany[z]] - 1;
				dist[z][curPoint] = dist[curPoint][z];
			}
			else{
				dist[curPoint][z] = dist[z][curPoint] = -1;
			}
		}
	}
	static void backtrack(int cur, int num, int dem){
		if(dem > min) return;
		if(num == count-1){
			if(dem < min){
				min = dem;
			}
			return;
		}
		for(int i=1; i<count; i++){
			if(check[i] == 0 && dist[cur][i] > 0){
				check[i] = 1;
				backtrack(i, num + 1, dem + dist[cur][i]);
				check[i] = 0;
			}
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for(int t=1; t<=T; t++){
			n = sc.nextInt();
			m = sc.nextInt();
			arr = new int[n][m];
			
			count = 1;
			quanx = new int[n*m];
			quany = new int[n*m];
			dist = new int[n*m][n*m];
			
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					arr[i][j] = sc.nextInt();
					if(arr[i][j] == 3){
						sx = i;
						sy = j;
					}
					if(arr[i][j] == 1){
						quanx[count] = i;
						quany[count] = j;
						count ++;
					}
				}
			}
			check = new int[count];
			min = Integer.MAX_VALUE;
			visited = new int[n][m];
			//khoang cach tu quan ma den cac quan khac
			init();
			bfs(sx, sy, 0);
			
			//khoang cach tu cac quan khac den nhau
			for(int i=1; i<=count-2; i++){
				visited = new int[n][m];
				init();
				bfs(quanx[i], quany[i], i);
			}
			backtrack(0, 0, 0);
			System.out.println("Case #"+t+"\n"+min);
		}
	}

}
