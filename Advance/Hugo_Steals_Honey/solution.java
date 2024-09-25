package thi;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Solution {
	static int[] dx = { -1, +1, 0, 0 };
	static int[] dy = { 0, 0, 1, -1 };

	static int result;
	static int[][] matrix;
	static boolean[][] isVisited;
	static int[][] valueMatrix;
	static int[] myX;
	static int[] myY;
	static Queue queue;

	static class Vertex {
		int x;
		int y;

		public Vertex(int x, int y) {
			// TODO Auto-generated constructor stub
			this.x = x;
			this.y = y;
		}
	}

	static class Queue {
		class Node {
			Vertex val;
			Node nextNode;

			public Node(Vertex val) {
				// TODO Auto-generated constructor stub
				this.val = val;
			}
		}

		Node front = null, rear = null;

		public boolean isEmpty() {
			return front == null;
		}

		public void enQueue(int x, int y) {
			Node newNode = new Node(new Vertex(x, y));
			if (isEmpty()) {
				rear = newNode;
				front = newNode;
			} else {
				rear.nextNode = newNode;
				rear = newNode;
			}
		}

		public Vertex pop() {
			if (isEmpty())
				return null;
			Vertex vertex = front.val;
			front = front.nextNode;
			if (front == null) {
				rear = null;
			}
			return vertex;
		}
	}

	static void bfs(int x, int y) {
		queue.enQueue(x, y);
		while (!queue.isEmpty()) {
			Vertex vertex = queue.pop();
			for (int i = 0; i < dx.length; i++) {
				int curX = vertex.x + dx[i];
				int curY = vertex.y + dy[i];
				if (curX >= 0 && curY >= 0 && curX < matrix.length
						&& curY < matrix.length) {
					if (matrix[curX][curY] > 0 && valueMatrix[curX][curY] == 0) {
						// System.out.println(curX + " " + curY);
						valueMatrix[curX][curY] = valueMatrix[vertex.x][vertex.y] + 1;
						queue.enQueue(curX, curY);
					}
				}
			}
		}
		boolean check = true;
		int num = 0;
		for (int i = 0; i < myX.length; i++) {
			if (valueMatrix[myX[i]][myY[i]] > num)
				num = valueMatrix[myX[i]][myY[i]];
			if (valueMatrix[myX[i]][myY[i]] == 0) {
				check = false;
			}
		}
		if (check) {
			isVisited[0][0] = true;
			if (num < result)
				result = num;
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("src/thi/Input.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			result = Integer.MAX_VALUE;
			int n = sc.nextInt();
			matrix = new int[n][n];
			isVisited = new boolean[n][n];
			valueMatrix = new int[n][n];
			queue = new Queue();
			int numberOfGold = sc.nextInt();
			myX = new int[numberOfGold];
			myY = new int[numberOfGold];

			for (int i = 0; i < numberOfGold; i++) {
				myX[i] = sc.nextInt() - 1;
				myY[i] = sc.nextInt() - 1;
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = sc.nextInt();
				}
			}

			for (int i = 0; i < numberOfGold; i++) {
				matrix[myX[i]][myY[i]] = 2;
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (matrix[i][j] == 1) {
						valueMatrix = new int[n][n];
						bfs(i, j);
					}
					// System.out.print(matrix[i][j] + " ");
				}
				// System.out.println();
			}

			if (isVisited[0][0])
				System.out.println(result);
			else System.out.println(-1);
		}
	}
}
