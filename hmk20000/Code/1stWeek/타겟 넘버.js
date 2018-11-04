function solution(num, target) {
    function ccc(num,r){
        if(num.length>0){
            // console.log(n);
            var tmp = num.pop()+r;
            return ccc(num.slice(),tmp)+ccc(num.slice(),-tmp);
        }else{
            return r==target?1:0
        }
    }
    return ccc(num,0);
}
