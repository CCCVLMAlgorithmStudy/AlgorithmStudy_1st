//#짝지어 제거하기 : JavaScript
function solution(s)
{
    var answer = 0;
    var i = 0;
    for(; i < s.length; i++){
        if(s[i + 1] == s[i]){
            s = s.replace(s[i+1] + s[i],'');
            i = -1;
        }
    }
    if(s == '')
        answer = 1;
    return answer;
}
