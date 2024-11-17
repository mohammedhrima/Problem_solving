function maxArea(height: number[]): number {
    let max = 0;
    let l = 0;
    let r = height.length - 1;

    while(l < r)
    {
        max = Math.max(max, (r - l) * Math.min(height[l], height[r]));
        if(height[l] < height[r]) l++;
        else r--;
    }
    return max;
};