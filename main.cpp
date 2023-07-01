#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

// Сортировка чисел по возрастанию
void sortline(std::string &line) { //объявление функции sortline, которая принимает ссылку на строку
    std::stringstream ss(line); //создание объекта со строкой
    std::vector<int> numbers; //объявление вектора, который будет хранить числа
    int number;
    while (ss >> number) {
        numbers.push_back(number); //извлечение числа из строки и добавление в вектор numbers (в цикле)
    }
    std::sort(numbers.begin(), numbers.end()); //сортировка чисел в порядке возрастания
    std::stringstream sortedLine; //создание объекта для отсортированных чисел
    for (size_t i = 0; i < numbers.size(); i++) {
        sortedLine << numbers[i];
        if (i != numbers.size() - 1) {
            sortedLine << " ";
        }
    } // цикл, который формирует отсортированную строку
    line = sortedLine.str(); //присваивание переменной отсортированной строки
}

// Основная часть
int main() {
    std::ifstream inputFile("input.txt"); //открытие исходного файла

    if (!inputFile) {
        std::cout << "ERROR! File can't be opened";
        return 1;
    } //проверка, открылся ли файл

    std::ofstream outputFile("output.txt"); // создание нового файла

    if (!outputFile) {
        std::cout << "ERROR! File can't be created";
        return 1;
    } //проверка, создан ли файл

    std::string line;
    while (std::getline(inputFile, line)) {
        sortline(line);
        std::cout << line << "\n";
        outputFile << line << "\n";
    } // цикл, который читает строки из исходного файла, сортирует их и записывает в файл + выводит в консоль

    inputFile.close(); // закрытие файла
    outputFile.close(); // закрытие файла

    std::cout << "Success. File is created";

    return 0; // успешное завершение программы
}