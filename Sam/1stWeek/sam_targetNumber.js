function solution(numbers,target) {
    function func(numbers, r){
        if(numbers.length > 0){
            var tmp = numbers.pop() + r;
            return func(numbers.slice(), tmp) + func(numbers.slice(), -tmp);
        }
        else { return r==target ? 1:0;}
    }
    return func(numbers,0);
}