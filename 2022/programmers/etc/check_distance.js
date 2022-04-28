let check = true;
function dfs(strArray, coord, depth, visit){
    const [r, c] = coord;
    console.log(depth, strArray[r][c]);
    if(depth===2){
        if(strArray[r][c] === "P")
            check = false;
        return;
    }
    
    if(depth===1 && strArray[r][c]==="X"){
        return;
    }else if(depth===1 && strArray[r][c]==="P"){
        check = false;
        return;
    }
    
    const dr = [0, 0, 1, -1];
    const dc = [1, -1, 0, 0];
    for(let i = 0 ; i < 4 ; i++){
        const nr = dr[i] + r;
        const nc = dc[i] + c;
        if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || visit[nr][nc]) 
            continue;
        
        visit[nr][nc] = true;
        dfs(strArray, [nr, nc], depth + 1, visit);
        visit[nr][nc] = false;
    }
    
}

function checkArray(strArray){
    let queue = [];
    for(let i = 0 ; i < 5 ; i++){
        for(let j = 0 ; j < 5 ; j++){
            if(strArray[i][j]==="P")
                queue.push([i, j]);
        }
    }
    
    check = true;
    for(let i = 0 ; i < queue.length ; i++){
        const coord = queue[i];
        const [r, c] = coord;
        console.log("coord: ", coord);
        let visit = Array(5).fill(this).map(()=>
            new Array(5).fill(false));
        visit[r][c] = true;
        dfs(strArray, coord, 0, visit);
        
        if(!check){
            return 0;
        }
    }
    return 1;
}

function solution(places) {
    var answer = [];
    for(let i = 0 ; i < 5 ; i++){
        const result = checkArray(places[i]);
        answer.push(result);
    }
    return answer;
}