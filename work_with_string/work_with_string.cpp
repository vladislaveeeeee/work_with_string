#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype> // ispunct()
using namespace std;

bool is_punctuation(char c) {
    return ispunct(c) || isspace(c); // перевірка на розділові знаки
}

int main()
{
    cout << "Enter string : ";
    string str;
    getline(cin, str);
    cout << "Enter string1 : ";
    string str1;
    getline(cin, str1);

    istringstream stream1(str);
    istringstream stream2(str1);

    vector<string> words1;
    vector<string> words2;

    string res;
    while (stream1 >> res) {
        res.erase(std::remove_if(res.begin(), res.end(), is_punctuation), res.end());
        if (!res.empty()) {
            words1.push_back(res);
        }
    }// ["слово", "слово", "слово", "слово"]

    while (stream2 >> res) {
        res.erase(std::remove_if(res.begin(), res.end(), is_punctuation), res.end());
        if (!res.empty()) {
            words2.push_back(res);
        }
    } // ["слово", "слово", "слово", "слово"]

    for (string word : words2) {
        words1.erase(remove(words1.begin(), words1.end(), word), words1.end());
    }
    cout << "Result: ";
    for (string word : words1) {
        cout << word << " ";
    }
}