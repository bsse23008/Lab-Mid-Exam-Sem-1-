#include "student.h"
using namespace std;

Quizz :: Quizz ()
{
    totalMarks = 10; obtainedMarks = 0;
}

Student :: Student ()
{
     strcpy(name , "None"); strcpy(rollNo, "None") ; quizz = nullptr;  num_quizzes = 0;
     totalSum = 0.0;
     obtainedSum = 0.0;
     percentage = 0.0;
}

void Student :: input ()
{
        cout << " Enter name              : ";
        cin  >> name;
        cout << " Enter Roll number       : ";
        cin  >> rollNo;
        cout << " Enter number of Quizzes : ";
        cin  >> num_quizzes;
        quizz = new Quizz[num_quizzes];

           for (int i=0; i<num_quizzes; ++i){
                cin >> quizz[i].obtainedMarks;
        }  
}


void display (const int &num_students, const Student students[])
{
    for (int i=0; i < num_students; ++i){
        cout << "\nStudent " << i+1 << " data "         << endl;    
        cout << " Name        : "   << students[i].name << endl;
        cout << " Roll number : "   << students[i].rollNo << endl;
        cout << " No of Quizzes attempted : " << students[i].num_quizzes << endl;
          for (int k=0; k<students[i].num_quizzes; ++k){
                cout << "\n\t Obtained Marks in Quizz " << k+1 << " : " << students[i].quizz[k].obtainedMarks << endl;
          }
    }      
}

void display_the_high_acheiver(const int &num_students, Student students[])
{
    vector <Student> high_acheivers;  // In case, multiple students are high acheivers
    int max  = INT_MIN;
      
      for (int i=0; i<num_students; i++)
      {
        if(students[i].percentage > max){
           max = students[i].percentage;
           high_acheivers.clear();               // Clear the previous (if less than new max found)
           high_acheivers.push_back(students[i]);
        }
        else if(students[i].percentage == max)
        {
            high_acheivers.push_back(students[i]);
        }
      }

    if(!high_acheivers.empty())
    {
      cout << "\n High Acheivers " << endl;
        for (const auto &student : high_acheivers)
        {
                cout << "\n High Acheiver name : " << student.name << endl;
                cout << " Roll Number        : " << student.rollNo << endl;
                cout << " Score in quizzes   : " << student.percentage << "%" << endl;
        }
    }
    else 
    {
         cout << "\nNo high Acheivers found ! " << endl;
    }
}



void HighestAccumulativeScore (const int &num_students, Student students[])
{
    for (int i=0; i < num_students; ++i){
        for (int j=0; j< students[i].num_quizzes; ++j){
          students[i].totalSum    += students[i].quizz[j].totalMarks;
          students[i].obtainedSum += students[i].quizz[j].obtainedMarks;
        }  
        students[i].percentage = (students[i].obtainedSum * 100)/students[i].totalSum;
    }
    display_the_high_acheiver(num_students, students);
}


void remove_worst_two_performances(const int &num_students, Student students[])
{
    int min = INT_MAX;
    int foundIndex = 0;
     for (int i=0; i<num_students; ++i){
        for (int j=0; j<students[i].num_quizzes; ++j){
            if(students[i].quizz[j].obtainedMarks < min){
                min = students[i].quizz[j].obtainedMarks;    // Worst performance will be stored here 
                foundIndex = j;
            }
        }
    for (int k=foundIndex; k<students[i].num_quizzes; ++k){
        students[i].quizz[k].obtainedMarks = students[i].quizz[k+1].obtainedMarks;
    }    
        students[i].num_quizzes--;
    }
}





