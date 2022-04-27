// 2020 KAKAO BLIND RECRUITMENT : 괄호 변환
function isCorrect(p) {
  let stack = [];

  for (let i = 0; i < p.length; i++) {
    const str = p[i];
    if (p[i] === "(") {
      stack.push("(");
    } else {
      if (stack.length !== 0) {
        stack.pop();
      } else {
        return false;
      }
    }
  }

  return true;
}

function splitStr(p) {
  let count = 0;

  if (p[0] === "(") count++;
  else count--;
  let index = 1;
  for (let i = 1; i < p.length; i++) {
    if (p[i] === "(") count++;
    else count--;

    if (count == 0) {
      index = i + 1;
      break;
    }
  }
  let u = p.slice(0, index);
  let v = p.slice(index, p.length);

  return { u, v };
}
function solutionAnswer(p) {
  if (p === "") return "";
  const { u, v } = splitStr(p);

  if (isCorrect(u)) {
    return u + solutionAnswer(v);
  } else {
    let temp = "(";
    temp += solutionAnswer(v);
    temp += ")";
    for (let i = 1; i < u.length - 1; i++) {
      if (u[i] === "(") temp += ")";
      else temp += "(";
    }
    return temp;
  }
}

function solution(p) {
  return solutionAnswer(p);
}
