#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main() {
	int N, min=0;
	priority_queue<int> sortA;
	priority_queue<int,vector<int>, greater<int> > sortB;
	
	cin>>N;
	
	int A[N],B[N];
	
	for(int i=0; i<N; i++) {
		cin>>A[i];
		sortA.push(A[i]);
	}
	
	for(int i=0; i<N; i++) {
		cin>>B[i];
		sortB.push(B[i]);
	}
	
	for(int i=0; i<N; i++) {
		min+=sortA.top()*sortB.top();
		sortA.pop();
		sortB.pop();
	}
	
	cout<<min<<endl;
	
	return 0;
}
