function solution(nums) 
{
    if(nums.length == 1)
        return 0;
    
    let maxCnt = nums.length / 2;
    var s = new Set();
    for(let i = 0; i < nums.length; i++)
        s.add(nums[i]);
    
    if(s.size >= maxCnt)
        return maxCnt;
    
    return s.size;
}