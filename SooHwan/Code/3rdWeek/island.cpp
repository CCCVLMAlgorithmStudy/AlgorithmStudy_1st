#include <iostream>
#include <vector>

void discover(std::vector<std::vector<int> >& map, int currentX, int currentY);


int main() {

	int w, h;
	int answer = 0;
	std::vector<std::vector<int> > map;
	do {
		std::cin >> w >> h;

		for (int i = 0; i<h; i++) {
			std::vector<int> temp;
			map.push_back(temp);
			for (int j = 0; j<w; j++) {
				int n;
				std::cin >> n;
				map[i].push_back(n);
			}
		}

		for (int i = 0; i<h; i++) {
			for (int j = 0; j<w; j++) {
				if (map[i][j] == 1) {
					discover(map, j, i);
					answer++;
				}

			}
		}

		if(w*h>0) //종료 시에는 출력을 하지 말아야 한다.
			std::cout << answer << "\n";

		map.clear();
		answer = 0;
	} while (w != 0 && h != 0);

	return 0;
}

void discover(std::vector<std::vector<int> >& map, int currentX, int currentY) {
	int h = map.size();
	int w = map[0].size();

	if (currentX<0 || currentX >= w || currentY<0 || currentY >= h)
		return;
	if (map[currentY][currentX] == 0)
		return;

	map[currentY][currentX]--;

	discover(map, currentX - 1, currentY - 1);
	discover(map, currentX - 1, currentY);
	discover(map, currentX - 1, currentY + 1);
	discover(map, currentX, currentY - 1);
	discover(map, currentX, currentY + 1);
	discover(map, currentX + 1, currentY - 1);
	discover(map, currentX + 1, currentY);
	discover(map, currentX + 1, currentY + 1);
}
