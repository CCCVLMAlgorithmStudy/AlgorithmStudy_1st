function solution(num) {
    var rtn = [];
    for(var i=0; num>0; i++){
        //console.log(num);
        rtn.push((num-1)%3+1);
        num = (num - rtn[i])/3;
    }
    return rtn.reverse().join('').replace( /3/gi, '4');
}
