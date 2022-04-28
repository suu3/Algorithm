function bfs(graph, distance, visit){
    let queue = [0];
    
    while(queue.length !== 0){
        const current = queue[0];
        queue.shift();
        
        graph[current].forEach((elem)=>{
            if(!visit[elem]){
                distance[elem] = distance[current] + 1;
                visit[elem] = true;
                queue.push(elem);

            }
        })
        
    }
}

function solution(n, edge) {
    let graph = Array(n).fill().map(()=>{
        return [];
    });
    edge.forEach((relation)=>{
        const [first, second] = relation;
        graph[first-1].push(second-1);
        graph[second-1].push(first-1);
    })
    
    let distance = Array(n).fill(0);
    let visit = Array(n).fill(false);
    visit[0] = true;
    bfs(graph, distance, visit);
    
    distance.sort((a, b) => b - a);
    const maxVal = distance[0];
    let count = 0;
    distance.forEach((elem)=>{
        if(maxVal===elem) count++;
    })
    return count;
}