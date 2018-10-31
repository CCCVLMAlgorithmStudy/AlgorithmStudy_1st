#include <iostream>
#include <vector>

using namespace std;

vector<bool> selfNum(10100, true);

int dN(int n) {
	int res = n;
	n*=10;
	do { res+=(n/=10)%10; } while(n>0); 
	
	return res;
}

int main() {
	for(int i=1; i<=10000; i++) {
		selfNum[dN(i)]=false;
	}
	
	for(int i=1; i<=10000; i++) {
		if(selfNum[i]) cout<<i<<endl;
	}
	
	return 0;
}
