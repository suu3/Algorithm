function solution(nums) {
  const numSet = new Set([...nums]);
  const size = numSet.size;
  const max = nums.length / 2;

  if (max > size) return size;
  return max;
}
