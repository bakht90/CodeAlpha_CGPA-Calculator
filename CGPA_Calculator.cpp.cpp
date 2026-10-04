#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Course
{
    string name;
    string grade;
    double gradePoint;
    double creditHours;
    double points;
};

double gradeToPoint(string grade)
{
    if (grade == "A+" || grade == "A") return 4.00;
    if (grade == "A-") return 3.67;
    if (grade == "B+") return 3.33;
    if (grade == "B") return 3.00;
    if (grade == "B-") return 2.67;
    if (grade == "C+") return 2.33;
    if (grade == "C") return 2.00;
    if (grade == "C-") return 1.67;
    if (grade == "D+") return 1.33;
    if (grade == "D") return 1.00;
    if (grade == "F") return 0.00;

    return -1;
}

int main()
{
    int courses;

    cout << "Enter number of courses: ";
    cin >> courses;

    Course course;
    
    double totalCredits = 0;
    double totalGradePoints = 0;

    for (int i = 0; i < courses; i++)
    {
        cout << "\nEnter course name: ";
        cin >> course.name;

        cout << "Enter grade: ";
        cin >> course.grade;

        course.gradePoint = gradeToPoint(course.grade);

        cout << "Enter credit hours: ";
        cin >> course.creditHours;

        course.points = course.gradePoint * course.creditHours;

        totalCredits += course.creditHours;
        totalGradePoints += course.points;

        cout << "\nCourse: " << course.name << endl;
        cout << "Grade: " << course.grade << endl;
        cout << "Credit Hours: " << course.creditHours << endl;
        cout << "Grade Points: " << course.points << endl;
    }

    double gpa = totalGradePoints / totalCredits;

    double previousCGPA;
    double previousCredits;

    cout << "\nEnter previous CGPA: ";
    cin >> previousCGPA;

    cout << "Enter previous total credit hours: ";
    cin >> previousCredits;

    double cgpa = ((previousCGPA * previousCredits) + totalGradePoints)
                  / (previousCredits + totalCredits);

    cout << fixed << setprecision(2);

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Semester GPA: " << gpa << endl;
    cout << "Overall CGPA: " << cgpa << endl;

    return 0;
}
