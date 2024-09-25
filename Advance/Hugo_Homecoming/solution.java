package hugovenha;

import java.util.Scanner;

public class hugovenha {
	static int T, n, arr[][], min;
	static void backtrack(int i, int cost, int s0, int s1, int s2){
		if(cost >= min) return;
		if(i==n){
			if(cost < min) min = cost;
			return;
		}
		backtrack(i+1, cost + arr[1][i], s0, s1, s2);
		backtrack(i+1, cost + 2 * arr[1][i], s0 + arr[0][i], s1, s2);
		
		int total = s0 + s1 + s2;
		if(total >= arr[0][i]){
			if(s2 >= arr[0][i]){
				backtrack(i+1, cost, 0, s0, s1);
			}
			else if(s1 + s2 >= arr[0][i]){
				backtrack(i+1, cost, 0, s0, s1 + s2 - arr[0][i]);
			}
			else{
				backtrack(i+1, cost, 0, total - arr[0][i], 0);
			}
			
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for(int t=1; t<=T; t++){
			n = sc.nextInt();
			arr = new int[n][n];
			for(int i=0; i<n; i++){
				arr[0][i] = sc.nextInt();
				arr[1][i] = sc.nextInt();
			}
			min = Integer.MAX_VALUE;
			backtrack(0, 0, 0, 0, 0);
			System.out.println("#"+t+" "+min);
		}
	}

}
