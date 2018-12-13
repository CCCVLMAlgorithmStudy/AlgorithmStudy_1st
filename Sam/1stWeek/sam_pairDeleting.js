function solution(s)
{
    let answer = 0;
    let arr = [];
    for(let i = 0; i<s.length;i++){
        let temp = arr.pop();
        if(temp != s[i]){
            if(temp != undefined)
                arr.push(temp);
            arr.push(s[i]);
        }
    }
    console.log(arr);
    if(!arr.pop()){
        answer++;
    }
    return answer;
}