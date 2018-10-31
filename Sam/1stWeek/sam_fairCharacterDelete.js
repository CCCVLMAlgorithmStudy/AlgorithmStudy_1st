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
/*
JavaScript의 문자 치환을 사용하여 문제 풀이
문자열의 총길이까지 첫문자열부터 현재 자리와 다음 자리를 비교하여 같은 문자면 문자열에서 공백으로 치환하여 문자열에서 제거한다. 제거한 이후 문자열의 첫문자부터 다시 비교하여 반복한다.
반복을 마친 후에는 문자열이 비어있는지 확인 후 비어있으면 1을 아니면 기본값인 0을 반환한다.
*/
