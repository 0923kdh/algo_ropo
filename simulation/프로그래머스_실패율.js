function solution(N, stages) 
{
    var arr = [];
    var total = stages.length;
    for(let i = 1; i <= N; i++)
    {
        let count = stages.filter(element => i === element).length;
        arr.push({ number : i,  failRate : (count/total) * 100});
        total = total - count;  
    }
    
    arr.sort(function(a,b){
        if(a.failRate != b.failRate) 
            return b.failRate - a.failRate;
        else
            return a.number - b.number;
    })
 
    return  arr.map(n=>n.number);
}