function resultsArray(nums: number[], k: number): number[] {
  let res: number[] = [];
  let i = 0;
  while (i <= nums.length - k) {
    let j = i + 1;
    while (j < i + k && nums[j] - nums[j - 1] == 1) j++;
    if (j == i + k) res.push(nums[j - 1]);
    else res.push(-1);
    i++;
  }
  return res;
}
