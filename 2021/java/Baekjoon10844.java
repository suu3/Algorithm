import java.io.*;

//동적 계획법
//백준 10844번: 쉬운 계단 수
/*
45656이란 수를 보자.

이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.

세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)
*/

public class Baekjoon10844 {
	static final long mod = 1000000000;
    static long[][] memo;
    static void stairs(int n) {
    	if(n<=60) { //오버플로우 문제 때문에 n을 1. 60이하, 2. 60초과 두 가지 경우로 나눈다.
	    	for(int i = 0 ; i <=9 ; i++) {
		        if(n==0) {
		            memo[i][0]=0;
		        }
		        else if(n==1) {
		        	memo[i][1]=1;
		        }
		        else if(memo[i][n]==0) {
	        		stairs(n-1);
		        	if(i==0) {
		        		memo[0][n] = memo[1][n-1];
		        	}
		        	else if(i==9) {
		        		memo[9][n] = memo[8][n-1];
		        	}
	        		else if(1<=i && i<=8) {
		        		memo[i][n] = memo[i-1][n-1] + memo[i+1][n-1];
	        		}
		        }
	    	}
    	}
    	else {
    		for(int i = 0 ; i <=9 ; i++) {
    			if(memo[i][n]==0) {
	        		stairs(n-1);
		        	if(i==0) {
		        		memo[0][n] = memo[1][n-1];
		        	}
		        	else if(i==9) {
		        		memo[9][n] = memo[8][n-1];
		        	}
	        		else if(1<=i && i<=8) {
		        		memo[i][n] = memo[i-1][n-1]%mod + memo[i+1][n-1]%mod;
	        		} // 오버플로우 방지를 위해 덧셈이 일어나는 곳에 mod 연산을 해준다.
		        }
	    	}
    		
    	}
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        memo = new long[10][101];
        int N = Integer.parseInt(br.readLine());
        stairs(N);
        
        long answer=0;
        for(int i = 1 ; i < 10 ; i ++) {
       		answer += memo[i][N];
        }
        
       	bw.write(String.valueOf(answer%mod));
        bw.flush();
        bw.close();
 
    }
 
}