import java.util.Arrays;
import java.util.Scanner;

//1238번 파티
/*
 * N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다. 
 * 어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다. 이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.
 * 각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.
 * 이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.
 *
 */

public class Baekjoon1238 {
	static Scanner sc = new Scanner(System.in);
	static int N = sc.nextInt();
	static int M = sc.nextInt();
	static int X = sc.nextInt();
	static int[][] weight = new int[N+1][N+1]; //가중치 저장
	
	static int distanceToS[] = new int[N+1]; //X->start까지 최단거리 
	static int distanceToX[] = new int[N+1]; //start->X까지 최단거리
	
   public static void dijkstraToX(int start){
        
        boolean[] visited = new boolean[N+1]; //방문체크
        for(int i = 0 ; i <= N ; i++){
            distanceToX[i] = 100*N;
        }
        
        //시작노드값 초기화
        distanceToX[start] = 0;
        visited[start] = true;
         
        for(int i = 1 ; i <= N ; i++){ //X -> start까지의 거리 초기화 
            if(!visited[i] && weight[start][i] !=0){
                distanceToX[i] = weight[start][i];
            }
        }
         
         
        for(int i = 0 ; i < N-1 ; i++){
            int localMin = 100*N;
            int min_index= -1;
             
            // 최소값 찾기
            for(int j = 1 ; j <= N ; j++){
            	if(!visited[j] && distanceToX[j] != 100*N){
                    if( distanceToX[j] < localMin ){
                        localMin = distanceToX[j];
                        min_index = j;
                    }
                }
            }
            visited[min_index] = true;
            if(min_index==X) {
            	distanceToS[start] += distanceToX[min_index];
            	return;            	
            }
            
            for(int j = 1 ; j <= N ; j++){
                if(!visited[j] && weight[min_index][j]!=0){
                    if(distanceToX[j] > distanceToX[min_index] + weight[min_index][j]){
                        distanceToX[j] = distanceToX[min_index] + weight[min_index][j];
                    }
                }
            }
 
        }
    }
		
    //X부터 Start까지
    public static void dijkstraToS(){
        
        boolean[] visited = new boolean[N+1]; //방문체크

        //distanceToS값 초기화.
        for(int i = 0 ; i <= N ; i++){
            distanceToS[i] = 100*N;
        }
        //시작노드값 초기화
        distanceToS[X] = 0;
        visited[X] = true;
         
        for(int i = 1 ; i <= N ; i++){ //X -> start까지의 거리 초기화 
            if(!visited[i] && weight[X][i] !=0){
                distanceToS[i] = weight[X][i];
            }
        }
         
         
        for(int i = 0 ; i < N-1 ; i++){
            int localMin = 100*N;
            int min_index= -1;
             
            // 최소값 찾기
            for(int j = 1 ; j <= N ; j++){
            	if(!visited[j] && distanceToS[j] != 100*N){
                    if( distanceToS[j] < localMin ){
                        localMin = distanceToS[j];
                        min_index = j;
                    }
                }
            }
            visited[min_index] = true;
            for(int j = 1 ; j <= N ; j++){
                if(!visited[j] && weight[min_index][j]!=0){
                    if(distanceToS[j] > distanceToS[min_index] + weight[min_index][j]){
                        distanceToS[j] = distanceToS[min_index] + weight[min_index][j];
                    }
                }
            }
 
        }
    }
	
	
	public static void main(String[] args){
		//가중치 입력 받음
		for(int i = 0 ; i < M ; i++)
		{
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			weight[a][b] = c;
		}


		dijkstraToS();
         
		for(int i = 1 ; i <= N ; i++) {
			if(i == X)
				continue;
			dijkstraToX(i);
		}
			
		Arrays.sort(distanceToS);
		System.out.println(distanceToS[N-1]);
		
	}
}   