#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    string Name;
    int Year;
    map<string, Score> RecordBook;
};

using Groups = map<string, vector<Student>>;


void saveToFile(const string& filename, const Groups& groups) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& group : groups) {
            file << group.first << endl;
            for (const auto& student : group.second) {
                file << student.Name << " " << student.Year << endl;
                for (const auto& record : student.RecordBook) {
                    file << record.first << " " << record.second << endl;
                }
            }
        }
        file.close();
    }
    else {
        cout << "ERROR 404" << endl;
    }
}
void loadFromFile(const string& filename, Groups& outGroups) {
    ifstream file(filename);
    if (file.is_open()) {
        string groupName;
        while (getline(file,groupName)){
            vector<Student> students;
            string studentName;
            int studentYear;
            while (file >> studentName >> studentYear) {
                Student student;
                student.Name = studentName;
                student.Year = studentYear;

                string subject;
                int score;
                while (file >> subject >> score) {
                    student.RecordBook[subject] = static_cast<Score>(score);
                }

                students.push_back(student);
            }

            outGroups[groupName] = students;
        }
        file.close();
    }
    else {
        cout << "ERROR 404" << std::endl;
    }
}
int main()
{
    Groups group1;
    Groups group2;
    Student studen1;
    studen1.Name = "Orkhen";
    studen1.Year = 1;
    studen1.RecordBook["IZO"] = Excellent;
    studen1.RecordBook["MATHS"] = Unsatisfactorily;
    Student studen2;
    studen2.Name = "Michael";
    studen2.Year = 2;
    studen2.RecordBook["NATHS"] = Good;
    vector <Student> studens1;
    vector <Student> studens2;
    studens1.push_back(studen1);
    studens1.push_back(studen2);
    group1["IU8-14"] = studens1;
    string filename = "students.txt";
    saveToFile(filename, group1);
    loadFromFile(filename, group2);
    for (const auto& group : group2) {
        cout << "Group: " << group.first << endl;
        for (const auto& student : group.second) {
            cout << "Name: " << student.Name << student.Year << endl;
            for (const auto& record : student.RecordBook) {
                cout << "Subject: " << record.first << ", Score: " << record.second << endl;
            }
        }
    }
}