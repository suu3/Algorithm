function calDistance(location, target) {
  let gap = Math.abs(location - target);
  if (gap === 0) return 0;
  if (gap === 1 || gap === 3) return 1;
  if (gap === 2 || gap === 4 || gap === 6) return 2;
  if (gap === 5 || gap === 7 || gap === 9) return 3;
  if (gap === 8 || gap === 10) return 4;
  return 5;
}

function solution(numbers, hand) {
  var answer = "";
  let curLeft = 10;
  let curRight = 12;
  for (let i = 0; i < numbers.length; i++) {
    let number = numbers[i];
    if (number === 0) number = 11;

    if (number === 1 || number === 4 || number === 7) {
      answer += "L";
      curLeft = number;
      continue;
    }
    if (number === 3 || number === 6 || number === 9) {
      answer += "R";
      curRight = number;
      continue;
    }

    let leftDistance = calDistance(curLeft, number);
    let rightDistance = calDistance(curRight, number);

    if (leftDistance < rightDistance) {
      answer += "L";
      curLeft = number;
    } else if (leftDistance > rightDistance) {
      answer += "R";
      curRight = number;
    } else {
      if (hand === "right") {
        answer += "R";
        curRight = number;
      } else {
        answer += "L";
        curLeft = number;
      }
    }
  }

  return answer;
}
