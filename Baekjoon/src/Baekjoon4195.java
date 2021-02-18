import java.io.*;
import java.util.*;

//백준 4195 친구네트워크 union-find
/*민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 친구이다. 
 *
 *우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 친구를 모으는 것이 취미이다.
 *어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.
 *
 *친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다. 
 * */

public class Baekjoon4195 {
	static int[] parent = new int[200001]; //root를 저장할 배열
	private static int find(int x) {
		if(x==parent[x])
			return x;
		else
			return parent[x] = find(parent[x]);
	}
	 
	private static void union(int x, int y) { //x로 부모 통일
		x = find(x);
		y = find(y);
		if(x != y) {
			parent[y] = x;
		}
	}
	
	public static boolean isSameParent(int x, int y) { //같은 부모면 true 반환
		x = find(x);
		y = find(y);
		if(x==y) return true;
		else return false;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(bf.readLine());
    	for(int i = 0 ; i < T ; i++) {
    		int[] count = new int[200001]; // 집합의 개수 저장
    		Map<String, Integer> map = new HashMap<>(); // 입력받은 String을 숫자(=노드 이름)와 짝지음
    		int F = Integer.parseInt(bf.readLine()); //친구 관계 수
    		int k = 1;
    		for(int j = 0 ; j < F ; j++) {
    			String[] s = bf.readLine().split(" ");
    			String one = s[0];
    			String two = s[1];
    			int x;
    			int y;
    			
    			//맵에 없는 이름이라면 부모노드=자기자신, count[자기자신]=1
    			if(map.get(one)==null) {
    				map.put(one,k);
    				x=k;
    				parent[x]=x;
    				count[x]++;
    				k++;
    			}else{
    				x=map.get(one);
    			}
    			
    			if(map.get(two)==null) {
    				map.put(two,k);
    				y=k;
    				parent[y]=y;
    				count[y]++;
    				k++;
    			}else{
    				y=map.get(two);
    			}
    			
    			//같은 부모가 아니라면 합친다. 둘 중 작은 수에 합쳐지도록 통일한다.
    			if(!isSameParent(x, y)) {
    				count[find(Math.min(x, y))]+=count[find(Math.max(x, y))];
    				union(Math.min(x, y), Math.max(x, y));
    			}

    			bw.write(Integer.toString(count[find(Math.min(x, y))]) + "\n");
    			bw.flush();
    			
    		}
    		//Test case가 끝났으므로 parent 초기화
    		for(int j = 1 ; j < k ; j++) {
    			parent[j] = 0;
    		}		
    	}
    	bw.close();
    }
}