function checkNumber(number){
    var sum = number;
    while(number>0){
        sum = parseInt(sum) + (number % 10);
        number = parseInt(number / 10);
    }
    return parseInt(sum);
}
function solution(){
    var selfNumber=[];
    for(var i = 1;i<=100;i++){
        selfNumber[i] = true;
    }
    for(var i = 1; i<=100;i++){
        selfNumber[checkNumber(i)] = false;
    }
    for(var i = 1; i<=100;i++){
        if(selfNumber[i] == false)
            continue;
        console.log(i);
    }
}
solution();