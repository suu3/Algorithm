import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

//백준 2447: 별 찍기 (재귀)
/*재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.

크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.

***
* *
***
N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다.
예를 들어 크기 27의 패턴은 예제 출력 1과 같다.
*/

public class Baekjoon2447 {
	static char[][] arr; //별을 찍을 배열. NXN
	private static void star(int x1, int y1, int x2, int y2) { // 시작좌표(x1, y1), 끝좌표(x2,y2)
		int n = y2-y1+1;
		
		//행
		int startX1 = x1;
		int endX1 = x1+n/3-1;
		int startX2 = x1+n/3;
		int endX2 = x1+n/3*2-1;
		int startX3 = x1+n/3*2;
		int endX3 = x1+n-1;
		
		//열
		int startY1 = y1;
		int endY1 = y1+n/3-1;
		int startY2 = y1+n/3;
		int endY2 = y1+n/3*2-1;
		int startY3 = y1+n/3*2;
		int endY3 = y1+n-1;
		
		if(n==1) {
			arr[x1][y1]='*'; //종료조건
			return;	
		}
		
		star(startX1, startY1, endX1, endY1);
		star(startX1, startY2, endX1, endY2);
		star(startX1, startY3, endX1, endY3);

		star(startX2, startY1, endX2, endY1);
		
		star(startX2, startY3, endX2, endY3);
		
		star(startX3, startY1, endX3, endY1);
		star(startX3, startY2, endX3, endY2);
		star(startX3, startY3, endX3, endY3);
	}
	
    public static void main(String[] args) throws IOException  {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String s = br.readLine();
		int N = Integer.parseInt(s);
		
		arr = new char[N+1][N+1];

		for(int i = 0 ; i <= N ; i ++) {
			for(int j = 0 ; j <= N ; j++ ) {
				arr[i][j]=' ';
			}
		} //초기화	
		
		star(1, 1, N, N);

		for(int i = 1 ; i <= N ; i++) {
			for(int j = 1 ; j <= N ; j++ ) {
				bw.write(arr[i][j]);
			}
			bw.write("\n");
		}

		bw.flush();
		bw.close();
	}
}