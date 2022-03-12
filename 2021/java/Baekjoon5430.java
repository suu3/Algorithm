import java.io.*;
import java.util.*;

public class Baekjoon5430 {
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    	Deque<String> dq = new ArrayDeque<String>();
    	
    	//백준 5430 AC(큐, 덱)
    	/*선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다.
    	 *이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다. 함수 R은 배열에 있는 숫자의 순서를 뒤집는 함수이고, D는 첫 번째 숫자를 버리는 함수이다.
    	 *배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.
    	 *함수는 조합해서 한 번에 사용할 수 있다.
    	 *예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다.
    	 *예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 숫자를 버리는 함수이다.
    	 *배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.
    	 */
    	
    	int T = Integer.parseInt(br.readLine()); //테스트 케이스

    	for(int i = 0 ; i < T ; i++) {
    		
    		String p = br.readLine(); //함수
    		int n = Integer.parseInt(br.readLine()); //배열 원소 개수
    		String[] arr = br.readLine().replace("[","").replace("]","").split(",");
    		
    		for(String a : arr) { //덱을 채운다.
    			dq.add(a);
    		}
    		
    		boolean error = false; //에러 체크용
    		boolean last = false; //순서가 뒤집혔으면 true, 아니면 false

    		for(int j = 0 ; j < p.length(); j++) {
    			char func = p.charAt(j);
    			switch(func) {
    			case 'R':
    				if(last) last = false;
    				else last = true;
    				break;
    			case 'D':
    				if(n==0) { //error case1 : 원소가 없는데 버려야 함
    	    			error=true;
    	    		}
    				if(dq.isEmpty()) { //error case2 : 덱이 비었는데 버려야 함
    					error=true;
    					break;
    				}
    				if(last) dq.pollLast();
    				else dq.pollFirst();
    				break;
    			}
    		}
    		
    		if(error) {
    			bw.write("error\n");
    			bw.flush();
    			continue;
    		}
    		
    		bw.write("[");
    		while(!dq.isEmpty()) {
    			if(last) bw.write(dq.pollLast()); //순서가 뒤집혔으면 끝에서부터 출력
    			else bw.write(dq.pollFirst()); //순서가 제대로면 처음부터 출력
    			
    			if(!dq.isEmpty()) bw.write(",");
    		}
    		bw.write("]\n");
    		bw.flush();
    	}
    	bw.close();
    }
 
}