// Created by BSSE_23008 on 27-Jan-2023
#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include <cstring>
#include <string>
#include <climits>
#include <vector>

using namespace std;

struct Quizz
{
    public :
    //friend void input();
    float totalMarks;
    float obtainedMarks;
           Quizz();
};

struct Student 
{
    char name[30];
    char rollNo[10];
    int num_quizzes;
    float totalSum, obtainedSum, percentage;
   
          Quizz * quizz;
          void input(); 
          Student();
};

void display(const int &num_students,const Student students[]);

void HighestAccumulativeScore(const int &num_students, Student students[]);

void remove_worst_two_performances(const int &num_students, Student students[]);

//Student highest_accumulative_score_through_recursion(const int &num_students, Student students[]);


#endif // Student Application