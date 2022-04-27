// 2019 KAKAO BLIND RECRUITMENT : 오픈채팅방

function solution(record) {
  let answer = [];
  let map = new Map();
  for (let i = 0; i < record.length; i++) {
    const [action, id, name] = record[i].split(" ");

    if (action === "Enter") {
      map.set(id, name);
      answer.push(id + "님이 " + "들어왔습니다.");
    } else if (action === "Leave") {
      answer.push(id + "님이 " + "나갔습니다.");
    } else {
      map.set(id, name);
      continue;
    }
  }

  answer = answer.map((str) => {
    const tempArray = str.split("님이 ");
    return map.get(tempArray[0]) + "님이 " + tempArray[1];
  });
  return answer;
}
