#ifndef SCHEDULE_H_INCLUDED
#define SCHEDULE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
#define MaxProf 300
#define MaxRoom 300
#define MaxGroup 300
#define MaxClass 300
using namespace std;
string Coursename[300]; //Stores names of Courses (Subjects)
int CourseDuration[300]; //Stores the duration of each Courses (Subjects)
bool CourseNeedLab[300]; //Stores boolean expression whether Course (Subject) needs lab or not?
int courseid; //Unique ID number for each of course
int groupid; //Unique ID number for each of Student Group
int profid; //Unique ID number for each of Professors
int roomid; //Unique ID number for each of rooms
//Function to check whether the course is Lecture or not
bool isLec(int id);
//Function to get number of students that attend lecture
int GetLectureCapacity(int id);

string getTimeString(int t);

void GetTimeTable(string groupname);
#endif
