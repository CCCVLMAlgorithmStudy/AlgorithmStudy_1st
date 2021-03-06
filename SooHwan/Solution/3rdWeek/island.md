* 주차 : 3주차
* 문제명 : 섬의 개수
* 링크 : https://www.acmicpc.net/problem/4963
* 사용언어 : C++ 
* 자체평점(5점 만점) : 2/5
  
  ---

  풀이

  평면을 탐색하는 법을 구현하는 단순 구현 문제이다. 이 문제에서는 입력을 직접 받아서 자료구조를 만들어내는 것까지 구현해야 한다.  
  가로와 세로가 헷갈릴 수 있는데, 일관되게만 사용하면 문제가 없다. 섞이지 않도록 주의하자.

  이차원 배열(여기서는 std::vector< std::vector< int > > 로 구현했다)에 숫자를 입력받아 채워 넣었다면 이제 (0,0)부터 탐색을 시작한다. 육지를 처음 발견했다면 해당 육지에서 더 이상 갈 수 있는 육지가 없을 때까지 탐색을 수행한다. 탐색이 끝나면 섬 하나를 발견한 것이므로 섬의 개수를 1개 늘린다. 이후 계속 탐색을 하여 남은 섬의 개수를 모두 카운팅하여 출력한다.

  주의해야 할 점은 입력의 종료인 w=0,h=0인 상황에서 출력을 하지 않도록 조치를 취해줘야 한다는 것이다.


  모든 섬을 확인하기 위해서 전체 평면을 확인해야 하고 확인 하는 과정은 O(1)의 비교연산과 확인한 육지를 체크하기 위한 O(1)의 대입연산 뿐이므로 전체 시간 복잡도는O(w*h)가 된다.