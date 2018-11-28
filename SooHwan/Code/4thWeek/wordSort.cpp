#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    
	int N;
	std::cin >> N;
	std::string str;
	std::set<std::pair<int, std::string> > S;

	for (int i = 0; i < N; i++)
	{
		std::cin >> str;
		S.insert( std::pair<int ,std::string>(str.length(),str));
	}

	for (auto iter = S.begin(); iter != S.end(); iter++)
	{
		std::cout << iter->second << "\n";
	}

	return 0;
}