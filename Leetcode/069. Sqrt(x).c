int mySqrt(int x)
{
    int n = 1;
    while(n < x / n)
        n++;
    if(n > x / n) n--; 
    return n;
}