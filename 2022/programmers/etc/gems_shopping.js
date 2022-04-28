function solution(gems) {
    var answer = [1, gems.length];
    let map = new Map();
    let set = new Set();
    gems.forEach((elem) => {
        set.add(elem);
    });
    const setSize = set.size;
    let left = 0;
    let right = 0;
    map.set(gems[right], 1);
    let result = gems.length;
    while(left <= right && right < gems.length){
        if(right >= gems.length) break;
        //구간 내 개수 셈
        if(setSize > map.size){
            right++;
            if(!map.get(gems[right])){
                map.set(gems[right], 1);                
            }else
                map.set(gems[right], map.get(gems[right])+1);

        }else if(setSize < map.size){
            if(map.get(gems[left])==1){
                map.delete(gems[left]);
            }else
                map.set(gems[left], map.get(gems[left])-1);
            left++;
        }else{
            if(map.get(gems[left])==1){
                map.delete(gems[left]);
            }else
                map.set(gems[left], map.get(gems[left])-1);
            left++;
            if(answer[1] - answer[0] > right + 1 - left){
                answer[1] = right + 1;
                answer[0] = left;
            }
        }
    }
    return answer;
}