import java.util.Scanner;

//백준 14889 스타트와 링크.
/*오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 축구는 평일 오후에 하고 의무 참석도 아니다. 축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.

BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. 능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를 수도 있으며, i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.

N=4이고, S가 아래와 같은 경우를 살펴보자.

i\j	1	2	3	4
1	 	1	2	3
2	4	 	5	6
3	7	1	 	2
4	3	4	5	 
예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 능력치는 아래와 같다.

스타트 팀: S12 + S21 = 1 + 4 = 5
링크 팀: S34 + S43 = 2 + 5 = 7
1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.

스타트 팀: S13 + S31 = 2 + 7 = 9
링크 팀: S24 + S42 = 6 + 4 = 10
축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 위의 예제와 같은 경우에는 1, 4번이 스타트 팀, 2, 3번 팀이 링크 팀에 속하면 스타트 팀의 능력치는 6, 링크 팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 최소이다.
*/


public class Baekjoon14889 {
	static int[][] S;
	
	static int N;
	static int minDiff=100000;
	static boolean[] visit;
	
	private static int score(int[] start) {
		int[] link = new int[N/2];

		int j = 0, k = 0;
		for(int i = 1 ; i <= N ; i++) {
			if(start[j]!=i) {
				link[k] = i;
				k++;
			}
			else {
				j++;
				if(j>=N/2)
					j--;
			}
		} // link팀 만들기
		
		int sscore=0;
		for(int i = 0 ; i < N/2 ; i++) {
			for(int m = 0 ; m < N/2 ; m++) {
				if(m!=i) {
					sscore+=S[start[i]][start[m]];
				}
			}
		}
		int lscore=0;
		for(int i = 0 ; i < N/2 ; i++) {
			for(int m = 0 ; m < N/2 ; m++) {
				if(m!=i) {
					lscore+=S[link[i]][link[m]];
				}
			}
		}
		//스코어 계산
		
		int diff = Math.abs(lscore-sscore);
		
		return diff;
	}
	
	private static void dfs(int index, int[] start) { //index = 현재 단계

		if(index == N/2) { //팀원이 꽉차면
			int diff = score(start);
			if(minDiff>diff)
				minDiff = diff;
			return;
		}
		
		for(int i = 1; i <= N; i++) {
			if(!visit[i]) {
				for(int j = 1 ; j <= i ; j++) {
					visit[j] = true;
				}
				start[index] = i;
				dfs(index+1,start);
				for(int j = 1 ; j <= i ; j++) {
					visit[j] = false;
				}
			}
		}
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		S = new int[N+1][N+1];
		visit = new boolean[N+1];
		
		for(int i = 0 ; i<=N ; i++) {
			visit[i]=false;
		}//방문 초기화
		
		for(int i = 1 ; i <= N ; i++) {
			for(int j = 1 ; j <= N ; j++) {
				S[i][j] = sc.nextInt();
			}
		}
		
		int[] start =  new int[N/2];
				
		dfs(0, start);
		System.out.print(minDiff);
	}
}