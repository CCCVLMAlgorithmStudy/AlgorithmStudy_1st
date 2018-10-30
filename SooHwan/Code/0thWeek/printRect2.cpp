#include <iostream>

using namespace std;

std::string makeLoopString(const char * str,int count);

int main(void) {
    int m,n;
    cin >> m >> n;
    std::cout<<makeLoopString(makeLoopString("*", m).c_str(), n);
    return 0;
}

std::string makeLoopString(const char * src,int count){
    std::string s = "";

    for(int i = 0;i<count;i++){
        s.append(src);
    }
    s.append("\n");

    return s;
}