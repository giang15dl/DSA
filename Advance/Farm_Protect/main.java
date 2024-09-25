import java.util.Scanner;

public class Solution {

	static int[][] arr;
	static int[][] visited;

	static int[] dx = { -1, -1, 0, 1, 1, 1, 0, -1 };
	static int[] dy = { 0, 1, 1, 1, 0, -1, -1, -1 };

	static int fX, fY, rX, rY, m, n;
	static boolean check = false;

	public static boolean bien(int a, int b) {
		return a >= 0 && b >= 0 && a < m && b < n;
	}

	static void init() {
		fX = fY = rX = rY = -1;
	}

	static int[] qX = new int[10000000];
	static int[] qY = new int[10000000];

	static boolean isEmptyX() {
		if (fX == rX)
			return true;
		return false;
	}

	static boolean isEmptyY() {
		if (fY == rY)
			return true;
		return false;
	}

	static void enQueueX(int a) {
		rX++;
		qX[rX] = a;
	}

	static void enQueueY(int a) {
		rY++;
		qY[rY] = a;
	}

	static int deQueueX() {
		fX++;
		return qX[fX];
	}

	static int deQueueY() {
		fY++;
		return qY[fY];
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);

		int TC = sc.nextInt();
		for (int tc = 1; tc <= TC; tc++) {
			m = sc.nextInt();
			n = sc.nextInt();
			arr = new int[m][n];
			visited = new int[m][n];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					arr[i][j] = sc.nextInt();
					visited[i][j] = 0;
				}
			}
			init();
			int count = 0;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (visited[i][j] == 0) {
						check = true;
						visited[i][j] = 1;
						BFS(i, j);
						if (check) {
							count++;
						}
					}
				}
			}
			System.out.println("#" + tc + " " + count);
		}

		sc.close();
	}

	private static void BFS(int x, int y) {
		enQueueX(x);
		enQueueY(y);
		while (!isEmptyX()) {
			int c = deQueueX();
			int d = deQueueY();
			for (int i = 0; i < 8; i++) {
				int a = c + dx[i];
				int b = d + dy[i];
				if (bien(a, b) && visited[a][b] == 0 && arr[a][b] == arr[c][d]) {
					visited[a][b] = 1;
					enQueueX(a);
					enQueueY(b);
				} else if (bien(a, b) && arr[a][b] > arr[c][d]) {
					check = false;
				}
			}
		}
	}

}