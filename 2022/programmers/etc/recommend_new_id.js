function solution(new_id) {
  let answer = "";
  answer = new_id.toLowerCase();
  const check = "abcdefghijklmnopqrstuvwxyz1234567890-_.";

  let temp_answer = answer;
  for (let i = 0; i < answer.length; i++) {
    const cur = answer[i];
    if (check.includes(cur)) continue;
    temp_answer = temp_answer.replace(cur, "");
  }
  answer = temp_answer;

  //3단계
  while (answer.includes("..")) answer = answer.replace("..", ".");

  //4단계
  if (answer[0] === ".") {
    answer = answer.slice(1, answer.length);
  }
  if (answer[answer.length - 1] == ".") {
    answer = answer.slice(0, answer.length - 1);
  }

  //5단계
  if (answer === "") answer += "a";

  //6단계
  if (answer.length >= 16) {
    answer = answer.slice(0, 15);
    if (answer[answer.length - 1] === ".") {
      answer = answer.slice(0, answer.length - 1);
    }
  }

  //7단계
  if (answer.length <= 2) {
    while (answer.length <= 2) {
      answer += answer[answer.length - 1];
    }
  }
  return answer;
}
