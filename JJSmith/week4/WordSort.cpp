#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int cmp(const string& a, const string& b) {
	if(a.length()==b.length()) return a<b;
	return a.length()<b.length();
}

int main() {
	int N;
	string str;
	
	cin>>N;
	
	set<string> uni;
	vector<string> res;
	
	for(int i=0; i<N; i++) {
		cin>>str;
		uni.insert(str);
	}
	
	set<string>::iterator it;
	
	for(it=uni.begin(); it!=uni.end(); it++) {
		res.push_back(*it);
	}
	
	sort(res.begin(), res.end(), cmp);
	
	for(int i=0; i<res.size(); i++) {
		cout<<res[i]<<endl;
	}
	
	return 0;
}
