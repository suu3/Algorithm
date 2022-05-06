function solution(board, moves) {
  var answer = 0;
  let stack = [];
  
  for(let i = 0 ; i < moves.length ; i++){
      let cur = moves[i] - 1;
      for(let j = 0 ; j < board.length ; j++){
          console.log(board[j][cur]);
          if(board[j][cur]!=0){
              const val = board[j][cur];
              board[j][cur] = 0;
              let last = stack.length===0 ? 0 : stack[stack.length-1];
              if(last===val){
                  answer+=2;
                  stack.pop();
                  break;
              }
              stack.push(val);
              break;
          }            
      }
      
  }
  
  return answer;
}