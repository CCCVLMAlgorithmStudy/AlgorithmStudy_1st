function solution(str) {
    let answer = 0;
    let laserOn = false;
    let stk = [];
    for(let i = 0; i <str.length; i++){
        if(str[i] == '('){
            stk.push(str[i]);
            laserOn = true;
        }
        else{
            stk.pop();
            if(laserOn){
                answer = answer + stk.length;
                laserOn = false;
            }
            else{
                answer = answer + 1;
            }
        }
    }
    return answer;
}