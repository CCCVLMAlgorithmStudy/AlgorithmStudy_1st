function check(val,index, arr){
    return val;
}
function solution(n) {
    const arr = Array(n+1);
    arr.fill(true);
    arr[0] = false;
    arr[1] = false;
    for(var i=2; i<n+1; i++){
        if(!arr[i]) continue;
        for(var j=i+i; j<n+1; j=j+i){
            arr[j] = false;
        }    
    }

    return arr.filter(check).length;
}