import java.util.*;
import java.io.*;

//백준 2108
/*수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.*/

public class Baekjoon2108{
    public static void main(String[] args) throws IOException  {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String s = br.readLine();

		int N = Integer.parseInt(s);
		int[] arr = new int[N];

		int middle;//중앙값
		int scope; //범위
		

		int count[] = new int[8001]; //빈도수
		
		int sum = 0 ;
		for(int i = 0 ; i < N ; i++) {
			String si = br.readLine();

			arr[i] = Integer.parseInt(si);
			sum += arr[i]; //평균을 위한 sum
			
			count[arr[i]+4000]++; //최빈값을 위한 빈도수
		}
		
		
		//최빈값
		int maxCount = 0; //최대 빈도수
		int modes[] = new int[N]; //같은 갯수를 가진 '최빈값'들의 배열
		
		for(int i = 0 ; i < N ; i ++)
			modes[i] = 4001; // sort를 위한 초기화
				
		//최대 빈도수 구하기
		for(int i = 0; i<count.length; i++) {
			if(maxCount<count[i]) {
				maxCount = count[i];
			}
		}
		
		int index = 0 ;
		//최빈값들 모음
		for(int i = 0; i<count.length; i++) {
			if(count[i]==maxCount) {
				modes[index] = i-4000;
				index++;
			}
		}
		
		int resultMode = 0 ;
		//두번째로 작은 값 찾기
		Arrays.sort(modes);
		if(index == 1) { //최빈값이 한 개라면
			resultMode = modes[0];
		}
		else {
			resultMode = modes[1];
		}
		
		//중앙값
		Arrays.sort(arr);
		middle = arr[N/2];

		//범위
		if(N==1)
			scope = 0;
		else
			scope = arr[N-1] - arr[0];

		
		double average = (double)sum / (double)N;
		bw.write(Long.toString(Math.round(average))+ "\n");
		bw.write(Integer.toString(middle)+ "\n");
		bw.write(Integer.toString(resultMode)+ "\n");
		bw.write(Integer.toString(scope));
		
		bw.flush();
		bw.close();
   }
}