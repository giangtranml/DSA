//
// Created by Tran Giang on 2/3/23.
//
#include <vector>
#include <string>
using namespace std;

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

template<typename T>
void print_1d_vector(vector<T> vec){
    for (auto v : vec){
        cout << v << " ";
    }
    cout << endl;
}

template<typename T>
void print_2d_vector(vector<vector<T>> vec){
    for(auto ve : vec){
        for(auto v: ve){
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void recursive_comb(vector<T> elements, int size, int left, int right, int index, vector<T> &temp, vector<vector<T>> &res){
    if(index == size){
        res.push_back(temp);
        return;
    }

    for(int i = left; i < right && right - i >= size - index; i++){
        temp[index] = elements[i];
        recursive_comb(elements, size, i+1, right, index+1, temp, res);
    }
}

template<typename T>
vector<vector<T>> combinations(vector<T> elements, int size){
    int n = elements.size();
    vector<vector<T>> res;
    vector<T> temp(size);
    recursive_comb(elements, size, 0, n, 0, temp, res);
    return res;
}