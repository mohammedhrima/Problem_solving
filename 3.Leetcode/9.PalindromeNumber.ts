function isPalindrome(x: number): boolean {
  let y: number = x;
  let z: number = 0;
  while (y > 0) {
    z = z * 10 + (y % 10);
    y = Math.floor(y / 10);
  }
  return z === x;
}
