#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void saveToFile(const string& filename, const vector<string>& data) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const std::string& word : data) {
            file << word << " ";
        }
        file.close();
    }
    else {
        cout << "error" << endl;
    }
}

void loadFromFile(const string& filename, std::vector<string>& outData) {
    ifstream file(filename);
    if (file.is_open()) {
        std::string word;
        while (file >> word) {
            outData.push_back(word);
        }
        file.close();
    }
    else {
        cout << "error" << endl;
    }
}

int main() {
    vector<string> data1;
    vector<string> data;
    data1.push_back("I");
    data1.push_back("love");
    data1.push_back("programming");
    data1.push_back("jokes");
    string filename = "mytextfile.txt";
    saveToFile(filename, data1);
    loadFromFile(filename, data);
    cout << data[1] << endl;

    return 0;
}