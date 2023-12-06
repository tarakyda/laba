#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Book
{
    string Author;
    string Title;
    int Year;
};
void saveToFile(const string& filename, const vector<Book>& data)
{
    ofstream fout(filename);
    if (fout.is_open()) {
        for (int i = 0; i < data.size(); i++) {
            fout << data[i].Author << " " << data[i].Title << " " << data[i].Year << " ";
        }
        fout.close();
    }
    else {
        cout << "error";
    }
}
void loadFromFile(const string& filename, vector<Book>& data1)
{
    ifstream fin(filename);
    if (fin.is_open()) {
        string author, title;
        int year;
        while (fin >> author >> title >> year) {
            Book book;
            book.Author = author;
            book.Title = title;
            book.Year = year;
            data1.push_back(book);
        }
    }
    else {
        cout << "error";
    }
}
int main() {
    vector <Book> data;
    Book b1 = { "Pushkin", "Onegin",1818 };
    data.push_back(b1);
    Book b2 = { "Brodskiy", "Hype", 1970 };
    data.push_back(b2);

    string filename = "mytextfile1.txt";
    vector <Book> data1;
    saveToFile(filename, data);
    loadFromFile(filename, data1);
    cout << data1[0].Author << " " << data1[0].Title << " " << data1[0].Year;
    return 0;
}