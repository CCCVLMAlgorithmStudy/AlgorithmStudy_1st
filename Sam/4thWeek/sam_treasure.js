var fs = require('fs');
var all_input = fs.readFileSync('/dev/stdin').toString().split('\n');
// 입력을 위한 소스
var n = all_input[0];
var A = all_input[1].split(' ');
var B = all_input[2].split(' ');
var sum = 0;
A.sort(function(a, b){return a-b;});
B.sort(function(a, b){return a-b;});
B.reverse(); // 오름차순 정렬 후, 배열 하나는 내림차순으로 reverse
for(var i = 0; i < n; i++){
    sum += A[i] * B[i];
}
console.log(sum);