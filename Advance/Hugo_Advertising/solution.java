   public static class Queue {
       private Node head = null;
       private Node tail = null;

       private class Node {
           Pair data;
           Node next;

           public Node(Pair data) {
               this.data = data;
               this.next = null;
           }
       }

       public boolean isEmpty() {
           return head == null;
       }

       public void add(Pair item) {
           Node newNode = new Node(item);
           if (tail != null) {
               tail.next = newNode;
           }
           tail = newNode;
           if (head == null) {
               head = tail;
           }
       }

       public Pair poll() {
           if (isEmpty()) {
               return null;
           }
           Pair data = head.data;
           head = head.next;
           if (head == null) {
               tail = null;
           }
           return data;
       }
   }

   public static class Pair {
       int x;
       int y;
       int dist;

       public Pair(int x, int y, int dist) {
           this.x = x;
           this.y = y;
           this.dist = dist;
       }
   }


import java.util.Scanner;

public class Solution {
	static int n, ans;
	static int[] L, P, timeDen, timeDi, visitedAds;
	static int[][] score;

	static boolean checkAds(int min, int max) {
		for (int i = min; i < max; i++) {
			if (visitedAds[i] == 1) {
				return false;
			}
		}
		return true;
	}

	static void visitAd(int min, int max, int a) {
		for (int i = min; i < max; i++) {
			visitedAds[i] = a;
		}
	}

	static int sumScore() {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int tmp = 0;
			for (int j = 0; j < 3; j++) {
				if (score[i][j] > tmp) {
					tmp = score[i][j];
				}
			}
			sum += tmp;
		}
		return sum;
	}

	static void back(int k) {
		if (k == 3) {
			int diem = sumScore();
			if (diem > ans) {
				ans = diem;
			}
			return;
		}
		for (int i = 1; i < 51; i++) {
			if (checkAds(i, i + L[k])) {
				visitAd(i, i + L[k], 1);
				for (int j = 0; j < n; j++) {
					if (i >= timeDen[j] && i + L[k] <= timeDi[j]) {
						score[j][k] = P[k];
					}
				}
				back(k + 1);
				visitAd(i, i + L[k], 0);
				for (int j = 0; j < n; j++) {
					if (i >= timeDen[j] && i + L[k] <= timeDi[j]) {
						score[j][k] = 0;
					}
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int t = 1; t <= T; t++) {
			n = sc.nextInt();
			L = new int[3];
			P = new int[3];
			for (int i = 0; i < 3; i++) {
				L[i] = sc.nextInt();
			}
			for (int i = 0; i < 3; i++) {
				P[i] = sc.nextInt();
			}
			timeDen = new int[n];
			timeDi = new int[n];
			visitedAds = new int[101];
			for (int i = 0; i < n; i++) {
				timeDen[i] = sc.nextInt();
				timeDi[i] = sc.nextInt() + timeDen[i];
			}
			score = new int[101][3];
			ans = 0;
			back(0);
			System.out.println("Case #" + t);
			System.out.println(ans);

		}

		sc.close();

	}

}

