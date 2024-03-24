function solution(s) {
  let stack = [];
  for (let i = 0; i < s.length; i++) {
    const cur = s[i];

    if (cur === "(") stack.push(cur);
    if (cur === ")") {
      if (!stack.length) return false;
      stack.pop();
    }
  }

  if (stack.length) return false;

  return true;
}
