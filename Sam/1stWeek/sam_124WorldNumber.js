//#124 나라의 숫자
function solution(n) {
    var answer = '';
    var check = 0;
    var arr = ['4', '1', '2'];
    while(n>0){
        check = n % 3; // 나머지 확인
        n = parseInt(n / 3); // 정확한 연산을 위한 parseInt(). 정수형으로 타입과 값을 변환(나머지 버림 연산)
        if(check == 0) n = n - 1; // 나머지가 0이면 몫을 1 줄임.
        answer = arr[check] + answer;
    }
    return answer;
}
