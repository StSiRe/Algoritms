#include <iostream>
#include <cmath>
#include <ctime>
///Функция рекурсивно вычисляет значение n-ного члена подпоследовательности
///Функция по которой расчитывается значение: F(n) = F(n-1) + F(n-2)
int task1(int n)
{
    if(n <= 0) return 0;
    if(n == 1) return 1;
    return task1(n-1) + task1(n-2);
}
int counter = 0;
int task2_req(int n, int m)
{
    counter++;
    if(m == 0 || n == m) return 1;
    return task2_req(n-1,m-1) + task2_req(n-1,m);
}
int task2_dyn(int n, int m)
{
    int M[n+1][n+1];
    for (int i = 0; i <= n; ++i) {
        M[i][0] = 1;
        M[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            counter++;
            M[i][j] = M[i-1][j-1] + M[i-1][j];
        }
    }
    return M[n][m];
}
int task2()
{
    counter =0;
    srand(time(0));
    std::cout << "Task 2: Combinations" << std::endl << "Recursion C(n,m) = " << task2_req(10,4) << std:: endl;
    std::cout << "Steps: " << counter << " Time:" << clock()/1000.0 << std::endl;
    counter =0;
    srand(time(0));
    std::cout << "Dynamic C(n,m) = " << task2_dyn(10,4) << std::endl;
    std::cout << "Steps: " << counter << " Time:" << clock()/1000.0 << std::endl;
    std::cout << std::endl;
}

int task3_req(int n, int m)
{
    counter++;
    if(n == m) return n;
    int a = std::min(std::max(n,m) - std::min(n,m),m);
    int b = std::min(n,m);
    return task3_req(a,b);
}
int task3_dyn(int n, int m)
{
    while(n!=0 && m!=0)
    {
        counter++;
        if(n>m)
        {
            n%=m;
        }
        else
            m%=n;
    }
    return m+n;
}
int task3()
{
    counter =0;
    srand(time(0));
    std::cout << "Task 3: NOD" << std::endl << "Recursion NOD = " << task3_req(500,400) << std:: endl;
    std::cout << "Steps: " << counter << " Time:" << clock()/1000.0 << std::endl;
    counter =0;
    srand(time(0));
    std::cout << "Dynamic NOD = " << task3_dyn(500,400) << std::endl;
    std::cout << "Steps: " << counter << " Time:" << clock()/1000.0 << std::endl;
    std::cout << std::endl;
}


int task4(int n)
{
    int res = 0;
int tmp=n;
    while(n>0)
    {
        res+= std::pow(n%10,3);
        n/=10;
    }
    std::cout  << "=>" << res;
    if(res == 153){
        std::cout << " ";
        return 1;
    }

    else return task4(res)+1;
}
int task5(int n)
{
    if(n%2)
    {
        n/=2;
    }
    else
    {
        n--;
    }
    if(n == 0) return 0;
    else return task5(n) + 1;
}
int main() {
    std::cout << "Task 1: Mystery subsequence" << std::endl << "Let`s count F(6):" << task1(6) << std::endl<< "Done!" << std::endl<< std::endl;
    task2();
    task3();
    std::cout << "Task 4: Find ^3:" << std::endl << "Check path length from number 21: " << task4(21) << std::endl<< "Done!" << std::endl<< std::endl;
    std::cout << "Task 5: Find min length:" << std::endl << "Check path length to number 100: " << task5(100) << std::endl<< "Done!" << std::endl<< std::endl;

    return 0;
}
