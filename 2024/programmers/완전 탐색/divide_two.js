//전력망 둘로 나누기

function solution(n, wires) {
  let answer = 100;
  const graphs = Array(n + 1)
    .fill()
    .map(() => []);
  wires.map((relation) => {
    const [w1, w2] = relation;
    graphs[w1].push(w2);
    graphs[w2].push(w1);
  });

  function dfs(start, end, visited) {
    const stack = [];
    stack.push(start);
    let cnt = 0;

    while (stack.length) {
      let v = stack.pop();

      if (!visited[v]) {
        visited[v] = true;
        cnt++;

        for (let node of graphs[v]) {
          if (!visited[node]) {
            if (node !== end) {
              stack.push(node);
            }
          }
        }
      }
    }
    return cnt;
  }

  wires.map((wire) => {
    const visited = Array(n + 1).fill(false);
    let first = dfs(wire[0], wire[1], visited);
    let second = dfs(wire[1], wire[0], visited);
    answer = Math.min(Math.abs(first - second), answer);
  });

  return answer;
}
