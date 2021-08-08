import java.util.*;

public class Baekjoon2206 {
	static Scanner sc = new Scanner(System.in);
	static int N = sc.nextInt(); //정점의 개수
	static int M = sc.nextInt(); //정점의 개수
	static int[][] arr = new int[N+2][M+2];
	static int distance = N * M;
	static int[][] visited = new int[N+2][M+2];
	static int[] dy = {-1, 1, 0, 0};
	static int[] dx = {0, 0, -1, 1};

	public static void bfs() {
		Queue<int[]> queue = new LinkedList<>();
		int[] start = {1, 1, 1, 0}; // x좌표, y좌표, 이동거리, 공사횟수
		queue.add(start); 
		
		visited[1][1] = 0; // 처음 공사횟수
		
		while(!queue.isEmpty()) {
			int[] node = queue.poll();
			
			if(node[0]==N && node[1]==M) {
				distance = node[2];
				break;
			}
			// 도착지점 만나면 종료

			for(int i = 0 ; i < 4 ; i++) {
				int ny = node[0] + dy[i];
				int nx = node[1] + dx[i];
				int[] newNode = {ny, nx, node[2] + 1, node[3]};
				if(arr[ny][nx] == -1) {
					continue;
				}
				
				if(visited[ny][nx] <= node[3]) {
					continue;
				}
				
				
				if(arr[ny][nx] == 0) { //벽이 아닐 때
					visited[ny][nx] = node[3];
					queue.add(newNode);
					
				}
				else { //벽일 때
					if(node[3]==0) {
						visited[ny][nx] = node[3] + 1;
						newNode[3]++;
						queue.add(newNode);
					}
				}
				
			}
		}
	}

	public static void printArray(int[][] arr) {
		for(int i = 1 ; i < N+1 ; i++) {
			for(int j = 1 ; j < M+1 ; j++) {
				System.out.print(arr[i][j]);
			}
			System.out.println();
			
		}
	}
	public static void main(String[] args){
		
		//초기화
		for(int i = 0 ; i < N+2 ; i++) {
			arr[i][M+1]=-1;
			arr[i][0]=-1;
			visited[i][M+1]=N*M;
			visited[i][0]=N*M;
		}
		
		
		for(int i = 0 ; i < M+2 ; i++) {
			arr[N+1][i]=-1;
			arr[0][i]=-1;
			visited[N+1][i]=N*M;
			visited[0][i]=N*M;
		}
		
		
		for(int i = 1 ; i <= N ; i++) {
			String line = sc.next();
			char[] lineArray = line.toCharArray();
			for(int j = 1 ; j <= M ; j++) {
				arr[i][j]= lineArray[j-1]-'0';
				visited[i][j] = N*M;
			}
		} 
		bfs();
		
		if(N==1 && M==1)
			System.out.println(1);
		else {
			if(distance == N*M)
				System.out.println(-1);
			else
				System.out.println(distance);
		}
	}

}
