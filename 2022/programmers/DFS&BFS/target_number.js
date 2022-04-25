let count = 0;

function dfs(numbers, value, depth, target){
    if(depth===numbers.length){
        if(value === target) count++;
        return ;
    }

    const minus = value - numbers[depth];
    const plus = value + numbers[depth];
    dfs(numbers, minus, depth+1, target);
    dfs(numbers, plus, depth+1, target);
}

function solution(numbers, target) {
    var answer = 0;
    dfs(numbers, 0, 0, target);
    answer = count;
    return answer;
}