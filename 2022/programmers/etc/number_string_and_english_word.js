// 20201 KAKAO BLIND RECRUITMENT : 숫자 문자열과 영단어
function solution(s) {
  var answer = "";
  let str = "";
  let map = new Map();
  map.set("zero", "0");
  map.set("one", "1");
  map.set("two", "2");
  map.set("three", "3");
  map.set("four", "4");
  map.set("five", "5");
  map.set("six", "6");
  map.set("seven", "7");
  map.set("eight", "8");
  map.set("nine", "9");

  for (let i = 0; i < s.length; i++) {
    console.log(s[i]);
    if (s.charCodeAt(i) > 57) {
      str = str.concat(s[i]);
      if (map.get(str)) {
        answer = answer.concat(map.get(str));
        str = "";
      }
    } else {
      if (map.get(str)) {
        answer = answer.concat(map.get(str));
      }
      answer = answer.concat(s[i]);
      str = "";
    }
  }
  if (map.get(str)) {
    answer = answer.concat(map.get(str));
  }
  return parseInt(answer);
}
