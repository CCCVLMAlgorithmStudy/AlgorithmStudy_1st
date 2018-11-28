var fs = require('fs');
var all_input = fs.readFileSync('/dev/stdin').toString().split('\n');

for(var i=0; i< all_input.length-2; i++){
    var input = all_input[i].split(' ');
    var a = parseInt(input[0]);
    var b = parseInt(input[1]);
    
    var map = [];
    for(var j=0; j<b; j++){
        i++;
        map.push(all_input[i].split(' '));
    }
    //console.log(map);
    
    get_answer(map);
}
function get_answer(map){
    var stack = [];
    var answer = 0;
    for(var i in map){
        for(var j in map[i]){
            if(map[i][j] == 1){
                stack.push([i,j]);
                while(stack.length>0){
                    var tmp = stack.pop();
                    map[tmp[0]][tmp[1]] = 0;
                    check(map,stack,tmp[0],tmp[1]);
                }
                answer++;
            }
        }
    }
    console.log(answer);
}
function check(map,stack,a,b){
    a = parseInt(a)
    b = parseInt(b)
    //console.log(map,a,b);
    if(map[a-1] != undefined){
        if(map[a-1][b-1]==1) stack.push([a-1,b-1])
        if(map[a-1][b]==1)   stack.push([a-1,b])
        if(map[a-1][b+1]==1) stack.push([a-1,b+1])
    }
    if(map[a][b-1]==1)   stack.push([a,b-1])
    if(map[a][b+1]==1)   stack.push([a,b+1])
    if(map[a+1] != undefined){
        if(map[a+1][b-1]==1) stack.push([a+1,b-1])
        if(map[a+1][b]==1)   stack.push([a+1,b])
        if(map[a+1][b+1]==1) stack.push([a+1,b+1])
    }
    //console.log(stack)
}