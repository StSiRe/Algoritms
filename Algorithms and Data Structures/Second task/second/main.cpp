#include <iostream>
#include <cmath>
float func(float x) {
    return pow(x,3)-x+exp(-x);
}
void PassiveSearch(float left,float right, float e)
{
    int steps = 0;
    float minPoint = 0;
    float minVal = 99999999;
    for (float i = left; i <= right; i+=e) {
        steps++;
        float tmp = func(i);
        if(minVal > tmp) {
            minVal = tmp;
            minPoint = i;
        }
    }
    std::cout << "X:" << minPoint << " Y:" << func(minPoint) << std::endl;
}
void Task1_SearchHalfPart(float a,float b,float e){
    float x1;
    float a1=0,b1 = 999999;
    float a0 = a;
    float b0 = b;

    while(b1-a1 > e) {
        float om = (b0 - a0) / 10;
        float alp0 = (a0 + b0) / 2 - om;
        float bet0 = alp0 + 2 * om;
        float fAlp = func(alp0);
        float fBet = func(bet0);


        if (fAlp <= fBet) {
            x1 = alp0;
            a1 = a0;
            b1 = bet0;
        } else {
            a1 = alp0;
            x1 = bet0;
            b1 = b0;
        }

        a0 = a1;
        b0 = b1;
    }
    float res = (a1 + b1) / 2;
    std::cout << "X:" << res << " Y:" << func(res) << std::endl;
}
void Task1_SearchGoldCut(float a,float b,float e){
    float x1;
    float a1=0,b1 = 999999;
    float a0 = a;
    float b0 = b;

    while(b1-a1 > e) {
        float om = b0 - a0;
        float alp0 =a0+(2*om)/(3+sqrt(5));
        float bet0 = a0+(2*om)/(1+sqrt(5));
        float fAlp = func(alp0);
        float fBet = func(bet0);


        if (fAlp <= fBet) {
            x1 = alp0;
            a1 = a0;
            b1 = bet0;
        } else {
            a1 = alp0;
            x1 = bet0;
            b1 = b0;
        }

        a0 = a1;
        b0 = b1;
    }
    float res = (a1 + b1) / 2;
    std::cout << "X:" << res << " Y:" << func(res) << std::endl;
}
float Fib(int n)
{
    if(n == 0) return 1;
    if(n== 1) return 1;
    return Fib(n-1) + Fib(n-2);
}
void Task1_SearchFib(float a, float b, float e)
{
    int f0 = 1;
    int f1=1;
    float a0 = a;
    float b0 = b;
    float d0 = b0-a0;
    int N = 1;

    while(d0/Fib(N) >= e)
    {
        N++;
    }


    float x1=0;
    float a1=0,b1 = 999999;
    int k =0;
    while(b1-a1 > e) {
        float om = b0 - a0;
        float alp0 = a0 + Fib(N-k-2)/Fib(N-k)*om;
        float bet0 = a0 + Fib(N-k-1)/Fib(N-k)*om;
        float fAlp = func(alp0);
        float fBet = func(bet0);

        if (fAlp <= fBet) {
            x1 = alp0;
            a1 = a0;
            b1 = bet0;
        } else {
            a1 = alp0;
            x1 = bet0;
            b1 = b0;
        }

        a0 = a1;
        b0 = b1;
        k++;
    }
    float res = (a1 + b1) / 2;
    std::cout << "X:" << res << " Y:" << func(res) << std::endl;
}
int main() {
    float left,right,e;
//    std::cout << "Current function y=x^3-x+e^(-x)" << std::endl;
//    std::cout << "Type left limit:";
//    std::cin >> left;
//    std::cout << "Type right limit:";
//    std::cin >> right;
//    std::cout << "Type accuracy:";
//    std::cin >> e;
//    std::cout<<std::endl;
//
//    PassiveSearch(left,right,e);
    e= 0.001;
    std::cout<< "Task 2 Functions(accuracy = 0.001)" << std::endl;
    std::cout << std::endl<<"Part 1: Searching extremum in range[-5,-3]" << std::endl;
    left = -5;
    right = -3;
    std::cout << "Method 1: Classic search: "; PassiveSearch(left,right,e);
    std::cout << "Method 2: Like-binary search: ";Task1_SearchHalfPart(left,right,e);
    std::cout << "Method 3: Gold-cut search: ";Task1_SearchGoldCut(left,right,e);
    std::cout << "Method 4: Fib search: ";Task1_SearchFib(left,right,e);

    std::cout << std::endl<<"Part 2: Search Max-points in range [-3,0]"; std::cout << std::endl;
    left = -3;
    right = 0;
    std::cout << "Method 1: Classic search: "; PassiveSearch(left,right,e);
    std::cout << "Method 2: Like-binary search: ";Task1_SearchHalfPart(left,right,e);
    std::cout << "Method 3: Gold-cut search: ";Task1_SearchGoldCut(left,right,e);
    std::cout << "Method 4: Fib search: ";Task1_SearchFib(left,right,e);

    std::cout <<std::endl << "Part 3: Search Min-points in range [0,3]"; std::cout << std::endl;
    left = 0;
    right = 3;
    std::cout << "Method 1: Classic search: "; PassiveSearch(left,right,e);
    std::cout << "Method 2: Like-binary search: ";Task1_SearchHalfPart(left,right,e);
    std::cout << "Method 3: Gold-cut search: ";Task1_SearchGoldCut(left,right,e);
    std::cout << "Method 4: Fib search: ";Task1_SearchFib(left,right,e);

    std::cout <<std::endl<< "End. Thanks for using our software" << std::endl;
    return 0;
}
