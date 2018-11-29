function K(arr,K){
    arr.sort(function(a, b){ // 그냥 sort()하게 되면 ASCII 코드 값으로 정렬되므로. 숫자의 크기대로 정렬하기 위해 function을 통해 정렬해준다
        return a - b; // a가 b보다 크면(a>b), return 이 양수 -> 오름차순 / 반대로 a<b, return 이 음수 -> 내림차순
    });
    return arr[K];
}
function solution(array, commands) {
    var answer = [];
    for(var i = 0; i < commands.length;i++){
        answer.push(K(array.slice(commands[i][0]-1,commands[i][1]), commands[i][2]-1));
        //아래는 민구st 소스. 
        //var c = commands[i];
        //answer.push(array.slice(c[0]-1,c[1]).sort(function(a, b){return a-b;}),c[2]-1);
    }
    return answer;
}