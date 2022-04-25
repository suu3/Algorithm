function isChangable(word1, word2){
    let count = 0;
    for(let i = 0 ; i < word1.length ; i++){
        if(word1[i]===word2[i])
            count++;
    }
    
    return count === (word1.length-1) ? true : false;
}

function bfs(begin, target, words){
    let queue = [[begin, 0]];
    let visited = Array(words.length).fill(false);

    while(queue.length!==0){ // not empty
        const current = queue[0][0];
        const count = queue[0][1];
        queue.shift(); // 앞에서 하나 뺌
        
        if(current === target){
            return count;
        }
        
        //둘이 다름. 바꿔줘야함
        for(let i = 0 ; i < words.length ; i++){
            if(!visited[i] && isChangable(current, words[i])){ // 바꿀 수 있다
                visited[i] = true;
                queue.push([words[i], count+1]);
            }
        }
        
    }
    return 0;
}
function solution(begin, target, words) {
    var answer = 0;
    
    answer = bfs(begin, target, words);
    return answer;
}