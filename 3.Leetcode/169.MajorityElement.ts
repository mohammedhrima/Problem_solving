function majorityElement(nums: number[]): number {
  nums.sort();
  return nums[Math.floor(nums.length / 2)];
}
