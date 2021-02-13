import java.util.Scanner;

//백준 15652
/*자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.*/

public class Baekjoon15652 {
	static int[] arr;
	static int[] visit;
	static String str="";
	private static void dfs(int n, int m, int d) {

		if(d == m) {
			for(int i = 0 ; i <arr.length ; i++)
				str = str + arr[i] + " ";
			str += "\n";
			return;
		}
		
		for(int i = 1; i <= n; i++) {
			if(visit[i]==0) {
				for(int j = 1 ; j < i ; j++) {
					visit[j] = 1;
				}
				arr[d] = i;
				dfs(n, m, d+1);
				for(int j = 1 ; j < i ; j++) {
					visit[j] = 0;
				}
			}
		}
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		arr = new int[M];
		visit = new int[N+1];
				
		dfs(N, M, 0);

		System.out.print(str);
	}
}