// 2019 KAKAO BLIND RECRUITMENT : 문자열 압축
function solution(s) {
  var answer = s.length;
  for (let i = 1; i <= s.length / 2; i++) {
    let repeatWord = s.slice(0, i);
    let count = 0;
    let repeatCount = 1;
    for (let j = i; j <= s.length - i; j += i) {
      const nextWord = s.slice(j, j + i);
      if (repeatWord === nextWord) {
        repeatCount++;
      } else {
        // 단어 바뀌는 순간
        if (repeatCount !== 1) {
          count += repeatCount.toString().length;
        }
        count += i;
        repeatCount = 1;
        repeatWord = nextWord;
      }
    }
    if (repeatCount !== 1) count += repeatCount.toString().length;
    count += i;
    if (s.length % i != 0) {
      count += s.length % i;
    }
    answer = Math.min(count, answer);
  }
  return answer;
}
