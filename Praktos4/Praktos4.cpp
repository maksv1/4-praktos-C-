#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

string reverse(const string& word) {
    string reversed_word = word;
    reverse(reversed_word.begin(), reversed_word.end());
    return reversed_word;
}

string removeVowels(const string& word) {
    string result = "";
    for (char ch : word) {
        if (tolower(ch) != 'a' && tolower(ch) != 'e' && tolower(ch) != 'i' && tolower(ch) != 'o' && tolower(ch) != 'u') {
            result += ch;
        }
    }
    return result;
}

string removeConsonants(const string& word) {
    string result = "";
    for (char ch : word) {
        if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u') {
            result += ch;
        }
    }
    return result;
}

string shuffle(const string& word) {
    string shuffled_word = word;
    shuffle(shuffled_word.begin(), shuffled_word.end(), default_random_engine(time(0)));
    return shuffled_word;
}

int main() {
    setlocale(LC_ALL, "ru");
    string word;
    cout << "Введите слово: ";
    cin >> word;

    int choice;
    while (true) {
        cout << "\nМеню:" << endl;
        cout << "1. Слово выводится задом наперед." << endl;
        cout << "2. Вывести слово без гласных." << endl;
        cout << "3. Вывести слово без согласных." << endl;
        cout << "4. Рандомно раскидывать буквы заданного слова." << endl;
        cout << "0. Выход." << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Результат: " << reverse(word) << endl;
            break;
        case 2:
            cout << "Результат: " << removeVowels(word) << endl;
            break;
        case 3:
            cout << "Результат: " << removeConsonants(word) << endl;
            break;
        case 4:
            cout << "Результат: " << shuffle(word) << endl;
            break;
        case 0:
            cout << "Программа завершена." << endl;
            return 0;
        default:
            cout << "Некорректный выбор. Попробуйте еще раз." << endl;
        }
    }

    return 0;
}