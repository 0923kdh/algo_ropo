function solution(new_id) 
{
    //step1 
    new_id = new_id.toLowerCase();
    
    //step2
    new_id = new_id.replace(/[^a-z0-9-_.]/gi, "");
    
    //step3
    //+ 앞문자가 하나이상 나올 수 있음.
    new_id = new_id.replace(/\.+/gi, ".");
    
    //step4
    //* 앞문자가 없을수도 무한정 많을 수도 있음
    new_id = new_id.replace(/^\.*/gi, "");
    new_id = new_id.replace(/\.*$/gi, ""); 
    
    //step6
    new_id = new_id.substring(0,15);   
    new_id = new_id.replace(/\.*$/gi, "");

    //step5
    if (new_id.length == 0)
        new_id += 'a';
    
    //step7
    while(new_id.length < 3)
         new_id += new_id[new_id.length-1]
    
    return new_id;
}