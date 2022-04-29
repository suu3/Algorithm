function solution(n, lost, reserve) {
  let tempLost = new Set([...lost]);
  let tempReserve = new Set([...reserve]);
  for (let i = 0; i < reserve.length; i++) {
    const cur = reserve[i];
    if (tempLost.has(cur)) {
      tempLost.delete(cur);
      tempReserve.delete(cur);
    }
  }
  reserve = [...tempReserve].sort();
  for (let i = 0; i < reserve.length; i++) {
    const cur = reserve[i];
    //앞 번호
    if (tempLost.has(cur - 1)) {
      tempLost.delete(cur - 1);
      tempReserve.delete(cur);
      continue;
    }
    //뒷 번호
    if (tempLost.has(cur + 1)) {
      tempLost.delete(cur + 1);
      tempReserve.delete(cur);
      continue;
    }
  }
  return n - tempLost.size;
}
