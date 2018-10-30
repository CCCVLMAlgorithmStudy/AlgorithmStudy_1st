#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int getTotalSum(int n){
    if(n == 0){
        return 1;//exception
    }
    return (static_cast<int>(pow(3,n))-1)/2;
}

int getDigit(int n){
    int result = 1;
    unsigned long long total = 3;
    unsigned long long operand = 2*n+1;
    
    while(operand>=total){
        total *= 3;
        result += 1;
    }
    
    return result-1;
}

string solution(int n){
    string answer = "";
    int digit = getDigit(n);
    int Base = n - getTotalSum(digit);
    
    int * count = new int[digit];
    
    for(int i=0;i<digit;i++){
        count[i] = 1; //Base Value
    }
    
    for(int i = static_cast<int>(pow(3, digit-1)),j = digit-1;Base>0;i/=3,j--){
        while(Base>=i){
            count[j] += 1;
            Base -= i;
        }
    }
    
    for(int i=digit-1;i>=0;i--){
        switch(count[i]){
            case 1 :
                answer.append("1");
                break;
            case 2 :
                answer.append("2");
                break;
            case 3 :
                answer.append("4");
                break;
        }
    }
    
    delete[] count;
    return answer;
}
