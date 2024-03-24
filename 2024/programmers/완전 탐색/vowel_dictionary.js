//프로그래머스 모음사전
function solution(word) {
  let answer = 0;

  const arr = ["A", "E", "I", "O", "U"];
  let count = 0;
  const findGoalWord = function (goal, previousLetter, previousWord) {
    count++;
    const curWord = previousWord + previousLetter;
    if (curWord === goal) {
      answer = count;
      return;
    }

    if (curWord.length === 5) return;

    arr.map((item, index) => {
      findGoalWord(goal, item, curWord);
    });
  };

  arr.map((item, index) => {
    findGoalWord(word, item, "");
  });
  return answer;
}
