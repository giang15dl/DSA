package thi;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Solution {
	static int[] chairs;
	static int[] doors;
	static int[] numberOfCustomers;
	static boolean[] isVisited;
	static int result;

	public static void dfs(int currentDoor, int count, int left, int right) {
		int start = doors[currentDoor];
		
//		int right = start;
//		int left = start;
//		System.out.println("number" + numberOfCustomers[currentDoor] + " "
//				+ currentDoor);
		if (count > result) {
			return;
		}
		
//		if (chairs[start] == 0) {
//			chairs[start] = 1;
//			numberOfCustomers[currentDoor]--;
//			if (right + 1 < chairs.length) {
//				right++;
//
//			}
//			if (left - 1 >= 1) {
//				left--;
//			}
//			while (numberOfCustomers[currentDoor] > 1) {
//				
//			}
//		}
		
		if (numberOfCustomers[currentDoor] == 0) {
			isVisited[currentDoor] = true;
			// System.out.println(count);
			boolean check1 = true;

			for (int i = 1; i <= 3; i++) {
				if (!isVisited[i]) {
					check1 = false;
					isVisited[i] = true;
					dfs(i, count, doors[i], doors[i]);
					isVisited[i] = false;
				}
			}
			if (check1) {
				if (count < result) {
					result = count;
				}
			}
			return;
		}
//		System.out.println("right" + right);
		while (chairs[right] != 0) {
			if (right == chairs.length - 1)
				break;
			if (right + 1 < chairs.length) {
				right++;
			}
		}
//		System.out.println("left" + left);

		while (chairs[left] != 0) {
			if (left == 1)
				break;
			if (left - 1 >= 1) {
				left--;
			}
		}
//		System.out.println(left + " " + right);
		if (left == right) {
			chairs[start] = start - left + 1;
			numberOfCustomers[currentDoor]--;
			dfs(currentDoor, count + chairs[start], left, right);
			chairs[start] = 0;
			numberOfCustomers[currentDoor]++;
		} else if (chairs[right] == 0 && chairs[left] == 0) {
			if (right - start > start - left) {
				chairs[left] = start - left + 1;
				numberOfCustomers[currentDoor]--;
				dfs(currentDoor, count + chairs[left], left, right);
				chairs[left] = 0;
				numberOfCustomers[currentDoor]++;
			} else if (start - left > right - start) {
				chairs[right] = right - start + 1;
				numberOfCustomers[currentDoor]--;
				dfs(currentDoor, count + chairs[right], left, right);
				chairs[right] = 0;
				numberOfCustomers[currentDoor]++;
			} else {
				if (numberOfCustomers[currentDoor] >= 2) {
					chairs[left] = start - left + 1;
					numberOfCustomers[currentDoor]--;
					chairs[right] = right - start + 1;
					numberOfCustomers[currentDoor]--;
					dfs(currentDoor, count + chairs[left] + chairs[right], left, right);
					chairs[left] = 0;
					numberOfCustomers[currentDoor]++;
					chairs[right] = 0;
					numberOfCustomers[currentDoor]++;
				} else {
					chairs[left] = start - left + 1;
					numberOfCustomers[currentDoor]--;
					dfs(currentDoor, count + chairs[left], left, right);
					chairs[left] = 0;
					numberOfCustomers[currentDoor]++;
					chairs[right] = right - start + 1;
					numberOfCustomers[currentDoor]--;
					dfs(currentDoor, count + chairs[right], left, right);
					chairs[right] = 0;
					numberOfCustomers[currentDoor]++;
				}
				
			}

		} else if (chairs[right] == 0) {
			chairs[right] = right - start + 1;
			numberOfCustomers[currentDoor]--;
			dfs(currentDoor, count + chairs[right], left, right);
			chairs[right] = 0;
			numberOfCustomers[currentDoor]++;
		} else if (chairs[left] == 0) {
			chairs[left] = start - left + 1;
			numberOfCustomers[currentDoor]--;
			dfs(currentDoor, count + chairs[left], left, right);
			chairs[left] = 0;
			numberOfCustomers[currentDoor]++;
		}

//		for (int i = 0; i < chairs.length; i++) {
//			System.out.print(chairs[i] + " ");
//		}
//		System.out.println();
	}

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("src/thi/Input.txt"));
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test_case = 1; test_case <= T; test_case++) {
			int n = sc.nextInt();

			chairs = new int[n + 1];
			doors = new int[4];
			isVisited = new boolean[4];
			numberOfCustomers = new int[4];
			result = Integer.MAX_VALUE;

			for (int i = 1; i <= 3; i++) {
				doors[i] = sc.nextInt();
				numberOfCustomers[i] = sc.nextInt();
			}
			isVisited[1] = true;
			dfs(1, 0, doors[1], doors[1]);
			isVisited[1] = false;
			
			isVisited[2] = true;
			dfs(2, 0, doors[2], doors[2]);
			isVisited[2] = false;
			
			isVisited[3] = true;
			dfs(3, 0, doors[3], doors[3]);
			isVisited[3] = false;
			System.out.println("Case #" + test_case + "\n" + result);
		}
	}
}
