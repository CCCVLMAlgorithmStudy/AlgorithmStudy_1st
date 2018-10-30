#include <iostream>

using namespace std;

void printSquare(int width,int height);
int main(void) {
    int m,n;
    cin >> m >> n;
    printSquare(m,n);
    return 0;
}

void printSquare(int width, int height){
    for (int h = 0;h<height;h++){
        for(int w = 0;w < width;w++){
            std::cout<<'*';
        }
        std::cout<<'\n';
    }
}