function solution(s)
{
    var answer = 0;

    // 스택으로 풀어보자
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return sc(s).length>0?0:1;
}

function sc(s){
    var rtn = [];
    for(var i=0; i<s.length;i++){
        var tmp = rtn.pop();

        if(tmp!=s[i]){
            if(tmp != undefined)
                rtn.push(tmp);
            rtn.push(s[i]);
        }
        // console.log(rtn);
    }
    return rtn;
}
