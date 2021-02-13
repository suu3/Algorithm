import java.io.*;
import java.util.StringTokenizer;

public class Baekjoon2869{
	public static void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String a = bf.readLine();
		StringTokenizer st = new StringTokenizer(a);
		Long A = Long.parseLong(st.nextToken());
		Long B = Long.parseLong(st.nextToken());
		Long V = Long.parseLong(st.nextToken());
		
		if(A >= V)
			System.out.print(1);
		else
			if((V-A)%(A-B)!=0) {
				System.out.print((V-A)/(A-B) +2 );				
			}
			else
				System.out.print((V-A)/(A-B) +1 );		
	}
}