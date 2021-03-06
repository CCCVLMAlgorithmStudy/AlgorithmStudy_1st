* 주차 : 5주차
* 문제명 : 하노이 탑
* 링크 : https://www.acmicpc.net/problem/1914
* 사용언어 : C++ 
* 자체평점(5점 만점) : 3.5/5 (큰 정수가 지원되는 언어로 풀 시 2/5) 
  
  ---

  풀이

  하노이 탑의 개념을 묻고 있다. 이 문제의 답은 엄청나게 큰 숫자가 답으로 나오기 때문에 반드시 '큰 정수형'을 사용해야 한다. 다만 C++에는 이것이 없으므로 직접 구현해야 한다. 풀이 과정을 출력하는 것은 여러 하노이 탑 예제 소스코드를 그대로 가져다 쓰면 되고, 최적화 한다면 비재귀로 고칠 수는 있다. 다만 이 문제는 시간 제한이 굉장히 널널한 관계로, 크게 신경 쓸 만한 부분은 아니다.  
  
  문제는 실행 횟수인데 N개의 원판을 가진 하노이 탑의 전체 이동 횟수는 2^N-1회이다. 1<=N<=100 이므로 N=100일때의 값은 2^100 -1 로 이를 담기 위해서는 총 100비트가 필요하다. 이를 담을 수 있는 자료형은 C++에 존재하지 않는다. 따라서 직접 구현해 줘야 한다.이를 구현하기 위한 아이디어는 n진법의 구현을 배열로 바꾸는 것이다.  
  
  숫자를 담을 컨테이너, n진법에서의 n에 해당하는 단위, 연산들을 덧셈, 곱셈, 출력 연산을 구현해주면 된다. 여기서는 구현의 편의상 단위를 10000(1만)으로 했다.  
  
  큰 숫자 연산의 덧셈,곱셈,출력은 단위 크기에 따라 연산 횟수가 달라지는데, 구체적으로는 unit^x<= N < unit^(x+1)일 때 x+1 회의 연산이 필요하다. 즉 큰 수의 각 연산의 시간복잡도는 O(x)이다.
  
  하노이 탑의 이동횟수를 구하는 함수의 호출 횟수는 총 N번이고, 이 함수안에서는 N=1일 때를 제외하고는 큰 수 연산이 두 번(곱셈 1회, 덧셈 1회) 일어나므로 총 연산의 횟수는 (N-1)(2x) + 1회 이다. 즉 하노이탑 횟수 연산의 최대 시간 복잡도는 O(Nx)이다.  
  
  하노이탑의 과정을 출력하는 연산은 이와 별개로 이루어지는데, 재귀의 경우만 살펴보면 전체 함수 호출 횟수는 2^N -1 회이므로 전체 시간 복잡도는 O(2^N)이다. 그래서 20회 이하의 경우에만 출력을 하게 만든 것이다.