var fs = require('fs');
var all_input = fs.readFileSync('/dev/stdin').toString().split('\n');

var a = all_input[1].split(' ');
var b = all_input[2].split(' ');

a.sort(function(a, b){return a - b});
b.sort(function(a, b){return a - b}).reverse();

//console.log(a);
//console.log(b);

var sum = 0;
for(var i=0; i< all_input[0]; i++){
    sum += a[i]*b[i];
}
console.log(sum);