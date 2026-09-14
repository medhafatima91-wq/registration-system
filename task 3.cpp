#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Course {
    string name;
    double gradePoints;
    int creditHours;
};

int main() {
    int numCourses;
    
    cout << "=====================================" << endl;
    cout << "      STUDENT CGPA CALCULATOR        " << endl;
    cout << "=====================================" << endl;
    
    cout << "Enter the number of courses taken: ";
    while (!(cin >> numCourses) || numCourses <= 0) {
        cout << "Invalid input! Please enter a valid number of courses: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    
    vector<Course> courses(numCourses);
    double totalGradePoints = 0.0;
    int totalCreditHours = 0;
    
    for (int i = 0; i < numCourses; ++i) {
        cout << "\n--- Course " << (i + 1) << " ---" << endl;
        cin.ignore(); 
        
        cout << "Enter Course Name/Code: ";
        getline(cin, courses[i].name);
        
        cout << "Enter Grade Points (e.g., 4.0 for A, 3.0 for B): ";
        while (!(cin >> courses[i].gradePoints) || courses[i].gradePoints < 0.0 || courses[i].gradePoints > 4.0) {
            cout << "Invalid points! Enter a value between 0.0 and 4.0: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        
        cout << "Enter Credit Hours: ";
        while (!(cin >> courses[i].creditHours) || courses[i].creditHours <= 0) {
            cout << "Invalid credit hours! Enter a positive integer: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        totalCreditHours += courses[i].creditHours;
        totalGradePoints += (courses[i].gradePoints * courses[i].creditHours);
    }
    
    double finalCGPA = 0.0;
    if (totalCreditHours > 0) {
        finalCGPA = totalGradePoints / totalCreditHours;
    }
    
    cout << "\n=========================================" << endl;
    cout << "            ACADEMIC REPORT             " << endl;
    cout << "=========================================" << endl;
    cout << left << setw(20) << "Course Name" 
         << setw(15) << "Grade Points" 
         << setw(15) << "Credit Hours" << endl;
    cout << "-----------------------------------------" << endl;
    
    for (const auto& course : courses) {
        cout << left << setw(20) << course.name 
             << setw(15) << fixed << setprecision(2) << course.gradePoints 
             << setw(15) << course.creditHours << endl;
    }
    
    cout << "-----------------------------------------" << endl;
    cout << "Total Credits Earned: " << totalCreditHours << endl;
    cout << "Total Grade Points:   " << fixed << setprecision(2) << totalGradePoints << endl;
    cout << "-----------------------------------------" << endl;
    cout << "FINAL CGPA:           " << fixed << setprecision(2) << finalCGPA << endl;
    cout << "=========================================" << endl;
    
    return 0;
}