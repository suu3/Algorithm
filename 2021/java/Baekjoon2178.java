import java.util.*;

//백준 2178 미로탐색
/*N×M크기의 배열로 표현되는 미로가 있다.
 *미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다.
 *이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
 *한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
 *칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
 */

public class Baekjoon2178 {
	static Scanner sc = new Scanner(System.in);
	static int N = sc.nextInt();
	static int M = sc.nextInt();
	static int total = N*M;
	static Queue<int[]> queue = new LinkedList<int[]>();
	private static void bfs(int[][] arr, int N, int M) { //N과 M은 arr의 크기고 현재위치는 row col
		
		int[] start = {1, 1, 1};
		arr[1][1] = 0;
		queue.add(start);
		
		while(!queue.isEmpty())
		{
			int[] current = queue.poll(); //하나 꺼냄
			int row = current[0];
			int col = current[1];
			int count = current[2];
			//상
			
			if(arr[row-1][col]!=0) {
				int[] up = {row-1, col, count + 1};
				arr[row-1][col] = 0;
				queue.add(up);
			}
			
			//하
			if(arr[row+1][col]!=0) {
				int[] down = {row+1, col, count + 1};
				arr[row+1][col] = 0;
				queue.add(down);				
			}
			
			//좌
			if(arr[row][col-1]!=0) {
				int[] left = {row, col-1, count + 1};
				arr[row][col-1] = 0;
				queue.add(left);				
			}

			//우
			if(arr[row][col+1]!=0) {
				int[] right = {row, col+1, count + 1};
				arr[row][col+1] = 0;
				queue.add(right);				
			}
			
			
			if(row==N && col ==M)
			{
				if(total>= count)
					total = count;
				
			}
			
		}
			
	}
	
	
	
	public static void printArray(int[][] arr, int N, int M)
	{
		for(int i = 0 ; i < N+2 ; i ++) {
			for(int j = 0 ; j < M+2 ; j++)
				System.out.print(arr[i][j]);
			System.out.println();			
		}
	}
	
	public static void main(String[] args){
		int[][] arr = new int[N+2][M+2];
		for(int i = 0 ; i < N+2 ; i++)
		{
			arr[i][0] = 0;
			arr[i][M+1] = 0;
		}
		for(int i = 0 ; i < M+2 ; i++)
		{
			arr[0][i] = 0;
			arr[N+1][i] = 0;
		}
		for(int i = 0 ; i < N ; i++)
		{
			String line = sc.next();
			char li[] = line.toCharArray();
			for(int j = 0 ; j < M ; j++)
			{
				if(li[j]=='1')
					arr[i+1][j+1]=1;
				else if(li[j]=='0')
					arr[i+1][j+1]=0;
			}
		}
		//미로 입력
		
		bfs(arr, N, M);
		System.out.print(total);
	}

}   
