function K(arr,K){
    arr.sort(function(a, b){
        return a - b;
    });
    return arr[K];
}
function solution(array, commands) {
    var answer = [];
    for(var i = 0; i < commands.length;i++){
        answer.push(K(array.slice(commands[i][0]-1,commands[i][1]), commands[i][2]-1));
    }
    return answer;
}