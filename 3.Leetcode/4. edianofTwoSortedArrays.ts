function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  let nums = [...nums1, ...nums2];
  nums.sort((a, b) => a - b);
  // console.log(nums);
  let half = nums.length / 2;
  if (nums.length % 2 == 0) return (nums[half] + nums[half - 1]) / 2;

  return nums[Math.floor(half)];
}
