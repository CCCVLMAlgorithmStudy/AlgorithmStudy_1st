function solution(n, computers) {
    let answer = 0;
    let arr = Array(n);
    let stk = [];
    arr.fill(false);
    for(let i in arr){
        // 방문을 안했으면
        if(arr[i] == false){
            stk.push(i);
            while(stk.length){
                let temp = stk.pop();
                for(let j in computers[temp]){
                    if(computers[temp][j] && !arr[j]){
                        stk.push(j);
                        arr[j] = true;
                    }
                }
            }
            answer++;
        }
    }
    return answer;
}