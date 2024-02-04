#include <iostream>
#include <climits>

using namespace std;

struct Student {
    string name;
    string rollNo;
    float percentage;
};

Student highest_accumulative_score_through_recursion(const int &num_students, Student students[], int index = 0)
{
    if (index == num_students)
    {
        // Base case: reached the end of the array
        Student emptyStudent;  // Assuming default constructor sets default values
        return emptyStudent;   // Return an empty student (or handle differently as needed)
    }

    // Recursive case
    Student result = highest_accumulative_score_through_recursion(num_students, students, index + 1);

    if (students[index].percentage > result.percentage)
    {
        // If the current student has a higher percentage, update the result
        result = students[index];
    }

    return result;
}

int main()
{
    // Example usage
    const int num_students = 5;
    Student students[num_students] = {
        {"Alice", "A001", 90.5},
        {"Bob", "B002", 88.5},
        {"Charlie", "C003", 92.5},
        {"David", "D004", 85.0},
        {"Eve", "E005", 88.5}};

    Student highestScoreStudent = highest_accumulative_score_through_recursion(num_students, students);

    cout << "Highest Accumulative Score Student:" << endl;
    cout << " Name              : " << highestScoreStudent.name << endl;
    cout << " Roll Number       : " << highestScoreStudent.rollNo << endl;
    cout << " Score in quizzes  : " << highestScoreStudent.percentage << "%" << endl;

    return 0;
}
