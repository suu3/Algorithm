/*백준 2667 단지번호 붙이기
 * 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
 */
import java.util.*;

public class Baekjoon2667 {
	static Scanner sc = new Scanner(System.in);
	static int N = sc.nextInt(); // 지도의 크기
	static int count = 0;
	static int totalHome = 0; // 총 단지 수
	static int[] total = new int[625]; // 단지 수 넣을 거임
	static Queue<int[]> queue = new LinkedList<int[]>();
	private static void bfs(int[][] arr, int N, int[] start) { //N은 지도의 크기
		
		queue.add(start);
		arr[start[0]][start[1]] = 0;
		count++;
		while(!queue.isEmpty())
		{
			int[] current = queue.poll(); //하나 꺼냄
			int row = current[0];
			int col = current[1];
			//상
			
			if(arr[row-1][col]!=0) {
				int[] up = {row-1, col};
				count++;
				arr[row-1][col] = 0;
				queue.add(up);
			}
			
			//하
			if(arr[row+1][col]!=0) {
				int[] down = {row+1, col};
				count++;
				arr[row+1][col] = 0;
				queue.add(down);				
			}
			
			//좌
			if(arr[row][col-1]!=0) {
				int[] left = {row, col-1};
				count++;
				arr[row][col-1] = 0;
				queue.add(left);				
			}

			//우
			if(arr[row][col+1]!=0) {
				int[] right = {row, col+1};
				count++;
				arr[row][col+1] = 0;
				queue.add(right);				
			}
		}
		
		//printArray(arr, N);
		//System.out.println();
		//큐가 비었으면 count 저장
		for(int i = 0 ; i < 625 ; i++)
		{
			if(total[i]==0) {
				total[i] = count;
				totalHome++;
				count = 0;
				break;
			}
		}
	}
	
	
	
	public static void printArray(int[][] arr, int N)
	{
		for(int i = 0 ; i < N+2 ; i ++) {
			for(int j = 0 ; j < N+2 ; j++)
				System.out.print(arr[i][j]);
			System.out.println();			
		}
	}
	
	public static void main(String[] args){
		int[][] arr = new int[N+2][N+2];
		for(int i = 0 ; i < N+2 ; i++)
		{
			arr[i][0] = 0;
			arr[i][N+1] = 0;
		}
		for(int i = 0 ; i < N+2 ; i++)
		{
			arr[0][i] = 0;
			arr[N+1][i] = 0;
		}
		for(int i = 0 ; i < N ; i++)
		{
			String line = sc.next();
			char li[] = line.toCharArray();
			for(int j = 0 ; j < N ; j++)
			{
				if(li[j]=='1')
					arr[i+1][j+1]=1;
				else if(li[j]=='0')
					arr[i+1][j+1]=0;
			}
		}
		
		for(int i = 0 ; i < N+2 ; i ++) {
			for(int j = 0 ; j < N+2 ; j++)
				if(arr[i][j]==1) {
					int[] start = {i, j};
					bfs(arr, N, start);
				}					
		}
		
		Arrays.sort(total); // 오름차순 정렬
		System.out.println(totalHome);
		for(int i = 0 ; i < 625 ; i++)
		{
			if(total[i]!=0) {
				System.out.println(total[i]);
			}
		}
	}

}   
