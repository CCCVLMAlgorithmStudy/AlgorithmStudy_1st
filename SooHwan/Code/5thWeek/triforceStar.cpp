#include<iostream>
#include<string>

void drawTriforce(int Length,int startPointX, int startPointY);
char** board;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N;

	std::cin >> N;

	board = new char*[N];
	for (int i = 0; i < N; i++)
	{
		board[i] = new char[2 * N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N - 1; j++)
		{
			board[i][j] = ' ';
		}
		board[i][2 * N - 1] = '\0';
	}

	drawTriforce(N, N - 1, 0);

	for (int i = 0; i < N; i++)
	{
		std::cout << board[i] << "\n";
	}

	for (int i = 0; i < N; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}

void drawTriforce(int Length, int startPointX, int startPointY)
{
	if (Length == 3)
	{
		board[startPointY][startPointX] = '*';
		board[startPointY + 1][startPointX - 1] = '*';
		board[startPointY + 1][startPointX + 1] = '*';
		board[startPointY + 2][startPointX - 2] = '*';
		board[startPointY + 2][startPointX - 1] = '*';
		board[startPointY + 2][startPointX] = '*';
		board[startPointY + 2][startPointX + 1] = '*';
		board[startPointY + 2][startPointX + 2] = '*';
	}
	else
	{
		drawTriforce(Length / 2, startPointX, startPointY);
		drawTriforce(Length / 2, startPointX - Length / 2, startPointY + Length / 2);
		drawTriforce(Length / 2, startPointX + Length / 2, startPointY + Length / 2);
	}
}