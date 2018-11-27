#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int S=0;
    int N;
    std::vector<int> A,B;
    
    std::cin>>N;
    for(int i =0;i<N;i++){
        int temp;
        std::cin>>temp;
        A.push_back(temp);
    }
    std::sort(A.begin(),A.end());
    
    for(int i=0;i<N;i++){
        int temp;
        std::cin>> temp;
        B.push_back(temp);
    }
    
    std::sort(B.begin(),B.end(),std::greater<int>());
    
    for(int i=0;i<N;i++){
        S += A[i]*B[i];
    }
    std::cout<<S<<"\n";
}
