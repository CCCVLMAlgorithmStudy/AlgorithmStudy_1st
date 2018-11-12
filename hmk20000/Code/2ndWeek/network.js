function solution(n, computers) {
    const array = Array(n);
    var stack = [];
    var answer = 0;
    
    array.fill(false);
    
    //전체 탐색
    for(var i in array){
        //방문 안한 노드만
        if(array[i]!=true){
            //노드를 스택에 추가
            stack.push(i);
            //스택이 비워질때까지 반복.            
            while(stack.length){
                var tmp = stack.pop();                
                //- 해당노드에서 방문가능한 모든 노드를 스택에 추가.
                for(var j in computers[tmp]){
                    // 자기 자신 제외
                    // 이미 방문한 노드일 경우 제외
                    if((computers[tmp][j])&&(!array[j])){
                        // console.log("tmp:"+tmp+", j:"+j+", "+computers[tmp])
                         stack.push(j);
                         array[j] = true;
                    }
                }
            }
            answer++;
        }
    }
    return answer;
}