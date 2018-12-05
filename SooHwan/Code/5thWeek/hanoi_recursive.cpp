#include<iostream>
#include<stack>
#include <vector>
#include <algorithm>

class BigNum{
public:
    BigNum operator*(int a){
        unsigned long long carry = 0;
        if(a==0||(this->container.size()==1&&this->container.front() == 0)){
            return BigNum(0);
        }
        BigNum result(*this);
        
        for(auto i = result.container.begin();i!= result.container.end();i++){
            *i *= a;
            *i += carry;
            
            carry = *i/result.unit;
            *i %= result.unit;
        }
        while(carry > 0){
            result.container.push_back(carry%result.unit);
            carry /= result.unit;
        }
        return result;
    }
    
    BigNum operator+(int a){
        if(this->container.size() == 1&& container.front() == 0){
            return BigNum(a);
        }
        
        BigNum result(*this);
        
        result.container[0] += a;
        unsigned long long carry =0;
        for(auto i = result.container.begin();i!= result.container.end();i++){
            *i += carry;
            
            carry = *i/result.unit;
            *i %= result.unit;
        }
        while(carry > 0){
            result.container.push_back(carry%result.unit);
            carry /= result.unit;
        }
        
        return result;
    }
    
    BigNum(const BigNum& a):unit(a.unit){//복사 생성자
        this->container.resize(a.container.size());
        std::copy(a.container.begin(),a.container.end(),this->container.begin());
    }
    
    BigNum(const unsigned long long num):unit(10000){
        unsigned long long n = num;
        if(n==0){
            this->container.push_back(0);
            return;
        }
        
        while(n>0){
            container.push_back(num%this->unit);
            n /= this->unit;
        }
    }
    friend std::ostream& operator<<(std::ostream& o, const BigNum& a);
private:
    std::vector<unsigned long long> container;
    const unsigned long long unit;
};

std::ostream& operator<<(std::ostream& o, const BigNum& a){
    
    for(auto i = a.container.rbegin();i!= a.container.rend();i++){
        if(i == a.container.rbegin()){
            o <<*i;
        }
        else{
        unsigned long long unit = 1000;
        unsigned long long temp = *i;
        while(unit>0){
            o<<temp/unit;
            temp %= unit;
            unit /= 10;
            }
        }
    }
        return o;
}

BigNum hanoi_count(unsigned long long N) {
    if (N == 1) {
        return BigNum(1ULL);
    }
    else {
        return hanoi_count(N - 1ULL) * 2 + 1;
    }
}
void hanoi_path(int N, int from, int by, int to);


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    unsigned long long N;
    
    std::cin >> N;
    
    std::cout << hanoi_count(N) << "\n";
    
    if (N <= 20)
        hanoi_path(N, 1, 2, 3);
    return 0;
}

void hanoi_path(int N, int from,int by, int to){
    if(N==1)
        std::cout<<from<<" "<<to<<"\n";
    else{
        hanoi_path(N-1,from,to,by);
        std::cout<<from<<" "<<to<<"\n";
        hanoi_path(N-1,by,from,to);
    }
}