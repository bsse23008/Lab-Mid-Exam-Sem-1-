#include "student.h"
using namespace std;

// Menu-driven Application ! 

int main()
{
    int num_students = 0;
    cout << "\n Enter number of students ? " << endl;
    cin >> num_students;

    Student *students = new Student[num_students];

    for (int i=0; i<num_students; ++i){
        cout << "\nEnter data for student " << i+1 << endl;
         students[i].input();
    }
    
    // Function to display all the students 
    display(num_students, students);

    // Function to display the highest acheiver in the class
    HighestAccumulativeScore(num_students, students);
    
    // Removing Worst two performances of each student in the Quizzes
    remove_worst_two_performances(num_students, students);
    remove_worst_two_performances(num_students, students);

    cout << "\n\t After removing worst two performances " << endl;
    display(num_students, students);


    delete[] students;
    return 0;
}