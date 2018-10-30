#include<iostream>

using namespace std;

int d(int n);
bool isSelfNumber[10001];


int main(){
    
    for (int i=1;i<10001;i++){
        isSelfNumber[i] = true;
    }
    
    for(int i=1;i<10001;i++){
        if(isSelfNumber[i] == false)
            continue;
        else{
            int temp = i;
            
            while(temp<10001){
                temp = d(temp);
                if(temp>=10001)
                    break;
                else
                    isSelfNumber[temp] = false;
            }
        }
    }
    
    for(int i=1;i<10001;i++){
        if(isSelfNumber[i])
            std::cout<<i<<"\n";
    }
}

int d(int n){
    int result = n;
    
    while(n>0){
        result += n%10;
        n/=10;
    }
    
    return result;
}
