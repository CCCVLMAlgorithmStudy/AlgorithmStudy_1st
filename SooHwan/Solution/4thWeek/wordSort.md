* 주차 : 4주차
* 문제명 : 단어정렬
* 링크 : https://www.acmicpc.net/problem/1181
* 사용언어 : C++ 
* 자체평점(5점 만점) : 1/5
  
  ---

  풀이

정렬 기준을 잘 정하면 쉽게 풀 수 있는 문제이다. 문자열을 직접 비교하면 사전순으로 정렬되기 때문에 다른 기준으로 정렬하기 위해서 std::pair를 사용한다. pair는 자체적으로 비교 연산자가 구현되어 있고, 첫번째 원소를 비교한 뒤 같으면 두번째 원소를 기준으로 정렬한다. 이 Pair를 담을 컨테이너는 중복을 자동으로 걸러주고 정렬도 자동으로 해주는 Set을 사용한다.
pair의 첫번째 원소는 문자열의 길이, 두번째 원소는 문자열 자체로 설정한 뒤 Set에 집어넣고 순서대로 꺼내서 문자열만 출력해주면 정답을 얻을 수 있다.  
시간 복잡도는 Set의 정렬 구현에 전적으로 의존한다. C++ 의 Set은 삽입과 삭제 연산의 시간복잡도가 O(log n)인 균형이진트리이므로 문제 전체의 시간복잡도 역시 O(log n)이다.

