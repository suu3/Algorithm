let answer_global = [];
function dfs(routes, map, depth, final_depth, visited){
    if(depth==final_depth){//티켓 다 씀
        if(answer_global.length!==0) return;
        for(const elem of routes){
            answer_global.push(elem);
        }
        
        return;
    }


    const current = routes[routes.length-1];
    try{
        for(let i = 0; i < map[current].length ; i++){

            if(visited[current][i])
                continue;
            visited[current][i] = true;
            const new_routes = [...routes];
            new_routes.push(map[current][i]);

            dfs(new_routes, map, depth+1, final_depth, visited);
            visited[current][i] = false;

        }
    }catch(e){
        console.log("fail");
    }
}

function solution(tickets) {
    var answer = [];
    let map = {};
    let visited = {};
    for(let i = 0 ; i < tickets.length ; i++){
        const key = tickets[i][0];
        if(!map[key]){
            map[key] = [tickets[i][1]];
            visited[key] = [false];
        }
        else{
            map[key].push(tickets[i][1]);            
            visited[key].push(false);
        }
    }
    
    for(const key in map){
        map[key].sort();
    }
    
    dfs(["ICN"], map, 0, tickets.length, visited);
    answer = answer_global;
    return answer;
}