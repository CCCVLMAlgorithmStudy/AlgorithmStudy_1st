var fs = require('fs');
var all_input = fs.readFileSync('/dev/stdin').toString().split('\n');
var re = /^[0-9]+$/; //숫자만 검출
var me = new Set();

function quick(arr){
    if(arr.length == 0)
        return [];
    var pivot = arr[0];
    var left = [];
    var right = [];
    
    for(var i = 1; i < arr.length; i++){
        if(pivot.length > arr[i].length){
            left.push(arr[i]);
        }
        else{
            right.push(arr[i]);
        }
    }
    return quick(left).concat(pivot, quick(right));
}

all_input.sort();
for(var i in all_input){
    if(re.exec(all_input[i])){
       all_input.splice(i,1);
    }
    me.add(all_input[i]);
}
var arr = [];
var i = 0;
me.forEach(function(item){
           arr[i] = item.toString(i);
    i++;
});

console.log(quick(arr));