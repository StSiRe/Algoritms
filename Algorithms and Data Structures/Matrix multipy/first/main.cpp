#include <iostream>
#include <fstream>
#include <vector>
void printMatrix(std::vector<std::vector<int>> first){
    std::cout<< std::endl <<"Result matrix array"<< std::endl;
    for (int i = 0; i < first.size(); ++i) {
        for (int j = 0; j < first[i].size(); ++j) {
            std::cout << first[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void printMatrix2(std::vector<std::vector<int>> first,std::vector<std::vector<int>> second){
    std::cout<< std::endl <<"First array"<< std::endl;
    for (int i = 0; i < first.size(); ++i) {
        for (int j = 0; j < first[i].size(); ++j) {
            std::cout << first[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout<<"Second array"<< std::endl;
    for (int i = 0; i < second.size(); ++i) {
        for (int j = 0; j < second[i].size(); ++j) {
            std::cout << second[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
//Метод решение со сложностью O(n^3) - "в лоб"
std::vector<std::vector<int>> Multipy(std::vector<std::vector<int>> first,std::vector<std::vector<int>> second){
    std::vector<std::vector<int>> result;
    for (int i = 0; i < first.size(); ++i) {
        result.push_back(std::vector<int>());
        for (int j = 0; j < first.size(); ++j) {
            //новый элемент есть сумма умножения столбца А на строку Б
            int tmp =0;
            for (int k = 0; k < second.size(); ++k) {
                tmp += first[i][k]*second[k][j];
            }
            result[i].push_back(tmp);
        }
    }
    return result;
}
int main() {

    std::ifstream firstMatrix;
    std::ifstream secondMatrix;
    firstMatrix.open("a.txt");
    secondMatrix.open("b.txt");
    if(!firstMatrix || !secondMatrix)
    {
        std::cout << "Files is closed!" << std::endl;
        return -1;
    }
    //Objects for data
    std::vector<std::vector<int>> first;
    std::vector<std::vector<int>> second;
    //Парсинг данных из файлов
    //Возможно сделано не эффективно
    // Но работает, так что пусть будет оставаться так
    //Reading matrix from files
    int currentLine = 0;
    while(!firstMatrix.eof()) {

        std::string a;
        getline(firstMatrix,a);
        std::string tmpS;
        first.push_back(std::vector<int>());
        for (int i = 0; i < a.length(); ++i) {
            if(a[i] != 32) {
                tmpS+=a[i];
            }
            else{
                first[currentLine].push_back(atoi(tmpS.c_str()));
                tmpS="";
            }
        }
        first[currentLine].push_back(atoi(tmpS.c_str()));
        currentLine++;
    }
    currentLine = 0;
    while(!secondMatrix.eof()) {

        std::string a;
        getline(secondMatrix,a);
        std::string tmpS;
        second.push_back(std::vector<int>());
        for (int i = 0; i < a.length(); ++i) {
            if(a[i] != 32) {
                tmpS+=a[i];
            }
            else{
                second[currentLine].push_back(atoi(tmpS.c_str()));
                tmpS="";
            }
        }
        second[currentLine].push_back(atoi(tmpS.c_str()));
        currentLine++;
    }
    printMatrix2(first,second); //Выводим данные, полученные в файлах

    printMatrix(Multipy(first,second));


    firstMatrix.close();
    secondMatrix.close();

    return 0;
}
