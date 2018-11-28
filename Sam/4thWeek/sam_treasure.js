var fs = require('fs');
var all_input = fs.readFileSync('/dev/stdin').toString().split('\n');
var n = all_input[0];
var A = all_input[1].split(' ');
var B = all_input[2].split(' ');
var sum = 0;
A.sort(function(a, b){return a-b;});
B.sort(function(a, b){return a-b;});
B.reverse();
for(var i = 0; i < n; i++){
    sum += A[i] * B[i];
}
console.log(sum);