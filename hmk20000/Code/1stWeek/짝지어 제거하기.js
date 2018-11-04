function solution(s)
{
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
