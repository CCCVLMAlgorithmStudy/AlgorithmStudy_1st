function solution(n){
  var primes = []; //
  for(var i=2;i<=n;i++){
      var isPrime = true;
      var st = Math.sqrt(i); // 0부터 i의 제곱근까지 지금까지 찾은 소수로 나눠서 0이 나오면 소수가 아님
      for(var j=0;primes[j]<=st;j++){
          if(i%primes[j] == 0){
              isPrime = false;
              break;
          }
      }
      if(isPrime) primes.push(i);
  }
  return primes.length; 
}
/* //아래와 같이 재귀로 풀 수 있으나 컴파일 에러로 검증은 불가
function solution(n, start = 2, primes=[], count=0) {
  if(start > n) return count;
  var isPrime = primes.every(v => start % v);
  if(isPrime) primes.push(start);
  return solution(n,start+1,primes,count + (isPrime?1:0));
}
*/