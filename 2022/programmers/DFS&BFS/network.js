let root_nodes;

function dfs(node, n, computers, visited_local){
    if(visited_local[node]){
        return;
    }
    visited_local[node] = true;

    for(let i = 0 ; i < computers[node].length ; i++){
        if(node===i)
            continue;
        
        if(computers[node][i]===1){ //node랑 i가 연결되어있으면
            root_nodes[i] = Math.max(root_nodes[node], root_nodes[i]); //부모 통일
            dfs(i, n, computers, visited_local);
        }
    }
    
}

function solution(n, computers) {
    var answer = 0;
    root_nodes = Array(n).fill(-1);
    
    for(let i = 0 ; i < n ; i++){
        if(root_nodes[i]!==-1)
            continue;
        
        root_nodes[i] = i;
        let visited_local = Array(n).fill(false);
        dfs(i, n, computers, visited_local);
    }
    
    const set = new Set();
    for(let i = 0 ; i < n ; i++){
        set.add(root_nodes[i]);
    }
    
    return set.size;
}