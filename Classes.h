#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <iostream>
#include "Schedule.h"
using namespace std;
//Stores information about Professors
class Professor
{
    private:
        //Name of Professor
        string name_;
        //List of Courses that professor teach
        vector<int> courseid_;

    public:
        //Returns name of Professor
        string GetName() { return name_;}
        //Set attribute id and name
        void SetProfessor (string);
        //Set course id that teaches this Professor
        void SetCourseId (int);
        //To check whether the Professor teaches the course or not
        bool TeachCourse(int);

} ProfessorObj[MaxProf]; // Object of Professor class


//Stores information about Student group
class StudentGroup
{
    private:
        //Student group name
        string name_;
        //Number of students in a group
        int numberOfStudents_;
        //Courses that takes students
        vector<int> courseid_;

    public:
        //Returns Name of Student group
        string GetName() {return name_;}
        //Returns Number of Students in group
        int GetnumberOfStudents() {return numberOfStudents_;}
        //Returns id of courses that Student study
        int GetCourseId(int courseid ) {return courseid_[courseid];}
        //Return course id size
        int GetSizeOfCourse(){return courseid_.size();}
        //Set id of group, name of Student Group and number of student in group
        void SetStudentGroup( string name, int numberOfStudents );
        //Set course Id that student group attends
        void SetCourseId ( int courseid);

} StudentGroupObj[MaxGroup]; //Object of Student Group class


//Stores information about Room
class Room
{
    private:
        //Name of the room
        string name_;
        //Number of seats in a group
        int capacity_;

        bool lab_;

    public:
        //Returns name of room
        string GetName() { return name_;}
        //Returns number of seats in a room
        int GetCapacity() { return capacity_ ;}

        bool GetLab() { return lab_ ; }
        //Set name of room, capacity and if has a computer
        void SetRoom( string name, int capacity, bool lab );

} RoomObj[MaxRoom]; //Object of Room class


class ClassCourse{
    private:
        string professor_;
        string coursename_;
        string room_;

    public:
        //Output of all data
        void Output(ofstream* AllOut);
        //Set attributes of class
        void SetClassCourse(string professor, string coursename, string room);
        //Returns name of the course of particular group at particular time
        string GetCourseNameById(){return coursename_;}
        //Is empty
        bool IsEmpty();

} ClassCourseObj[300][50]; //Object of ClassCourse Class where i group in j time which prof, what course, which room
//Set attribute name
void Professor::SetProfessor (string name) {
    name_ = name ;
}
//Set Courses that Professor teaches
void Professor :: SetCourseId (int courseid){
    courseid_.push_back(courseid);
}
//To check whether the Professor teaches the course or not
bool Professor :: TeachCourse(int courseid){
    for (int i=0; i<courseid_.size(); i++){
        if (courseid_[i]==courseid){
            return true;
        }
    }
}

//Function to set the attributes of Student Group
void StudentGroup :: SetStudentGroup( string name, int numberOfStudents){
    name_ = name ;
    numberOfStudents_ = numberOfStudents;
}
//Function that sets id of courses that attend student group
void StudentGroup :: SetCourseId ( int courseid){
    courseid_.push_back(courseid);
}



//Set name of room, capacity and if has a computer
void Room :: SetRoom( string name, int capacity, bool lab ){
    name_ = name ;
    capacity_ = capacity ;
    lab_ = lab;
}


//Function that gives all output data
void ClassCourse :: Output(ofstream *AllOut){
    *AllOut << left << setw(56)<< coursename_  << setw(22) << professor_ << setw(24) << room_  << endl;
}
//Function to set the attributes of Class course
void ClassCourse :: SetClassCourse(string professor, string coursename, string room){
    professor_ = professor;
    coursename_ = coursename;
    room_ = room;
}
//Check whether class is empty
bool ClassCourse :: IsEmpty (){
    return professor_.empty();
}




#endif // CLASSES_H_INCLUDED
