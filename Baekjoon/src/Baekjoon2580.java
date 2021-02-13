import java.io.*;
import java.util.StringTokenizer;

// 백준 2580
// 스도쿠가 주어졌을 때 빈칸을 채워서 출력한다.

public class Baekjoon2580 {
	static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static int[][] blankLocation;
	static int zeroCount;
	private static boolean probability (int[] answer, int location, int[][] sudoku) {
		int x = blankLocation[location][0];
		int y = blankLocation[location][1];

		//같은 행 체크
		for(int i = 0 ; i < 9 ; i ++) {
			if(i==y) continue;
			if(sudoku[x][i] == answer[location])
				return false;
		}
		
		//같은 열 체크
		for(int i = 0 ; i < 9 ; i ++) {
			if(i==x) continue;
			if(sudoku[i][y] == answer[location])
				return false;
		}
		
		//3x3정사각형 안 체크
		int newX = (x / 3) * 3;
		int newY = (y / 3) * 3;
 		for (int i = newX; i < newX + 3; i++) {
			for (int j = newY ; j < newY + 3; j++) {
				if (i==x && j==y) continue;
				if (sudoku[i][j] == answer[location]) {
					return false;
				}
			}
		}

		return true;
	}
	
	private static void dfs(int index, int[] answer, int[][] sudoku) throws IOException { // index = 현재 단계
		if(index!=0) {
			if(!probability(answer, index-1, sudoku)) { //가능한 경우의 수인지 검사
				return;
			}
		}

		if(index == zeroCount) { //빈칸을 다 채운다면
			for(int i = 0 ; i < zeroCount ; i++) {
				sudoku[blankLocation[i][0]][blankLocation[i][1]]=answer[i];
			}
			
			//답안 출력
			for(int i = 0 ; i < 9 ; i++) {
				for(int j = 0 ; j < 8 ; j++) {
					bw.write(Integer.toString(sudoku[i][j]) + " ");
				}
				bw.write(sudoku[i][8] + "\n");
			}
			
			bw.flush();
			System.exit(0); //가능한 경우의 수가 나오면 바로 종료
			return;
		}
		
		for(int i = 1; i <= 9; i++) {
			answer[index] = i;
			sudoku[blankLocation[index][0]][blankLocation[index][1]]= i ;
			dfs(index+1, answer, sudoku);
			sudoku[blankLocation[index][0]][blankLocation[index][1]]= 0 ;
		}
	}
	
	public static void main(String[] args) throws IOException{
		int[][] sudoku = new int[9][9];
		
		zeroCount = 0;
		for(int i = 0 ; i < 9 ; i++) {
			String a = bf.readLine();
			StringTokenizer st = new StringTokenizer(a);
			for(int j = 0 ; j < 9 ; j++) {
				sudoku[i][j] = Integer.parseInt(st.nextToken());
				if(sudoku[i][j]==0)
					zeroCount++;
			}
		} //스도쿠 배열을 입력받고, 빈칸의 개수를 센다.
		
		blankLocation = new int[zeroCount][2]; //빈칸의 좌표(행,열)를 저장한다.
		int a = 0;
		for(int i = 0 ; i < 9 ; i++) {
			for(int j = 0 ; j < 9 ; j++) {
				if(sudoku[i][j]==0) {
					blankLocation[a][0] = i;
					blankLocation[a][1] = j;
					a++;
				}
			}
		}
		
		int[] answer = new int[zeroCount]; //답안을 모아놓을 배열.
		dfs(0, answer, sudoku);
		
		bw.close();
		
	}
}