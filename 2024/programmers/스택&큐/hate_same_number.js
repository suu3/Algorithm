function solution(arr) {
  let answer = [];

  let previousMember = null;
  arr.map((item) => {
    const isAppeared = previousMember === item;
    if (!isAppeared) answer.push(item);
    previousMember = item;
  });

  return answer;
}
