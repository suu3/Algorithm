function win_dfs(win, lose, win_graph, visit, lose_graph){
    win_graph[win].forEach((elem)=>{
        if(elem!=win && !visit[elem]){
            visit[elem] = true;
            win_graph[lose].add(elem);
            lose_graph[elem].add(lose);
            win_dfs(elem, lose, win_graph, visit, lose_graph);
        }
    })
}

function lose_dfs(lose, win, lose_graph, visit, win_graph){
    lose_graph[lose].forEach((elem)=>{
        if(elem!=lose && !visit[elem]){
            visit[elem] = true;
            lose_graph[win].add(elem);
            win_graph[elem].add(win);
            lose_dfs(elem, lose, lose_graph, visit, win_graph);
        }
    })
}

function solution(n, results) {
    let answer = 0;
    let win_graph = Array(n+1).fill().map(()=> new Set()); // elem을 이긴 애들을 모아놓는다.
    let lose_graph = Array(n+1).fill().map(()=> new Set()); // elem에게 진 애들을 모아놓는다.
    
    results.forEach((result)=>{
        const [win, lose] = result;
        win_graph[lose].add(win);
        lose_graph[win].add(lose);       
        
    })
    
    results.forEach((result)=>{
        const [win, lose] = result;
        
        let visit = Array(n+1).fill(false);
        visit[win] = true;
        visit[lose] = true;
        win_dfs(win, lose, win_graph, visit, lose_graph);
        
        let visit2 = Array(n+1).fill(false);        
        visit2[lose] = true;
        visit2[win] = true;
        lose_dfs(lose, win, lose_graph, visit2, win_graph);
        
        lose_graph[win].add(lose);
        win_graph[lose].add(win);        
    })
    
    for(let i = 1 ; i <= n ; i++){
        if(win_graph[i].size + lose_graph[i].size == n-1) answer++;
    }
    return answer;
}