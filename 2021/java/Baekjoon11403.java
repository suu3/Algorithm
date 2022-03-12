/* 백준 11403번 : 경로 찾기
 * 그래프 이론, 플로이드–와샬
 */
import java.util.*;

public class Baekjoon11403 {
	static Scanner sc = new Scanner(System.in);
	static int N = sc.nextInt(); //정점의 개수
	static int[][] adj = new int[N][N];
	static int[][] ans = new int[N][N];	
	static int[][] visited = new int [N][N];
	
	public static void floyd() {
		Stack<int[]> queue = new Stack<int[]>();
		
		for(int i = 0 ; i < N ; i++)
			for(int j = 0 ; j < N ; j++) {
				if(adj[i][j]==1) {
					ans[i][j]=1;
					int[] node = {i, j};
					queue.add(node);
				}
			}

		while(!queue.isEmpty()) {
			int[] node = queue.pop();
			int temp = node[1];
			if(visited[node[0]][node[1]]==1)
				continue;
			
			visited[node[0]][node[1]]=1;
			for(int i = 0 ; i < N ; i++) 
				if(adj[temp][i]==1) {
					ans[node[0]][i]=1;
					int[] newNode = {node[0], i};
					queue.add(newNode);
				}
		}
	}
	
	public static void printArray(int[][] arr) {
		for(int i = 0 ; i < N ; i++) {
			for(int j = 0 ; j < N ; j++) {
				if(j==N-1)
					System.out.print(arr[i][j]);
				else
					System.out.print(arr[i][j] + " ");
				
			}
			System.out.println();
			
		}
	}
	public static void main(String[] args){
		//초기화
		for(int i = 0 ; i < N ; i++)
			for(int j = 0 ; j < N ; j++)
				adj[i][j]=sc.nextInt();
	
		
		floyd();
		printArray(ans);
		
	}
}   
