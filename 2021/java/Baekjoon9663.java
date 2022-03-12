//백준 9663번 백트래킹
//N-queen 문제
import java.util.*;

public class Baekjoon9663 {
	static int count = 0;
	static Scanner sc = new Scanner(System.in);
	static int N = sc.nextInt();
	
	public static boolean isPromising (int[][] pan, int row, int col) { //유효성검사 
		
		//같은 행 검사
		for(int i = 0 ; i < N && i!=row ; i ++)
			if(pan[i][col]==1)
				return true;

		//대각선 검사
		
		int r = row + 1, c = col + 1;
		while(0 <= r && r <N && 0<=c && c<N) {
			if(pan[r][c]==1)
				return true;
			r++;
			c++;

		}
		
		r = row - 1;
		c = col + 1;
		while(0 <= r && r <N && 0<=c && c<N) {
			if(pan[r][c]==1)
				return true;
			r--;
			c++;
		}

		r = row - 1;
		c = col - 1;
		while(0 <= r && r <N && 0<=c && c<N) {
			if(pan[r][c]==1)
				return true;
			r--;
			c--;
		}

		r = row + 1;
		c = col - 1;
		while(0 <= r && r <N && 0<=c && c<N) {
			if(pan[r][c]==1)
				return true;
			r++;
			c--;
		}

		return false;
	}

	public static void queen(int[][] pan, int row) {
		for(int i = 0 ; i < N ; i++) {
			dfs(pan, row, i);
		}
	}
	
	public static void dfs (int[][] pan, int row, int col) {
		
		//후처리가 중요하다,, 배열 다시 깨끗하게
		for(int i = row ; i < N ; i++)
			for(int j = 0; j < N ; j++)
				pan[i][j]=0;
		
		pan[row][col]=1;
		

		if(isPromising(pan, row, col)) {
			pan[row][col]=0;
			return;
		}
			
		
		if(row == N-1) { // 종료조건
			count++;
			return;
			
		}
		
		queen(pan, row+1);
	
	}
	
	public static void initial (int[][] pan) {
		//체스판 0으로 초기화 함수
		for(int i = 0 ; i < N ; i++) {
			for(int j = 0 ; j < N ; j++)
				pan[i][j]=0;
		}	
	}
	
	public static void printArray(int[][] pan) {
		for(int i = 0 ; i < N ; i++) {
			for(int j = 0 ; j < N ; j++)
				System.out.print(pan[i][j]);
			System.out.println();
		}
	}
	public static void main(String[] args){
		int[][] pan = new int[N][N];
		
		initial(pan);
		queen(pan, 0);
		
		
		System.out.println(count);
	

	}
}   
