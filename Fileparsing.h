#include "Classes.h"

//Function that sets all data from txt file to the course attributes
void ParseCourse(){
    ifstream inputcourse("input/Course.txt");
    courseid = 0;
    string name;
    int duration;
    bool lab;
    //Start loop to read and initialize
    while (inputcourse >> name >> duration >> lab){
        Coursename[courseid]=name;
        CourseDuration[courseid]=duration;
        CourseNeedLab[courseid]=lab;
        courseid++;
    }
    inputcourse.close();
}

//Parsing functions which help to Set the data from the .txt files
//Function that sets all data from txt file to the Professor attributes
void ParseProfessor(){
    ifstream inputprof("input/Professor.txt");
    profid = 0;
    string name;
    string s; //Course name
    while (inputprof >> name){
        do{
            inputprof >> s;
            for (int i = 0; i < courseid; i++){
                if(Coursename[i] == s){
                    ProfessorObj[profid].SetCourseId(i);
                    break;
                }
            }
        } while(s!="0");
        //Initializing to an object of Professor
        ProfessorObj[profid].SetProfessor(name);
        profid++;
    }
    inputprof.close();
}


//Function that sets all data from txt file to the StudentGroup attributes
void ParseStudentGroup(){
    ifstream inputgroup("input/StudentGroup.txt");
    groupid = 0;
    string name;
    int numberOfStudents;
    string s;
    //Set number of Students and name of group every
    while (inputgroup >> numberOfStudents >> name){
        do{
            inputgroup >> s;
            for (int i = 0; i < courseid; i++){
                if(Coursename[i] == s){
                    StudentGroupObj[groupid].SetCourseId(i);
                    break;
                }
            }
        } while(s!="0");
        StudentGroupObj[groupid].SetStudentGroup(name, numberOfStudents);
        groupid++;
    }
    inputgroup.close();
}

//Function that sets all data from txt file to the room attributes
void ParseRoom(){
    ifstream inputroom("input/Room.txt");
    roomid = 0;
    string name;
    int capacity;
    bool lab;
    while (inputroom >> name >> capacity >> lab ){
        RoomObj[roomid].SetRoom(name, capacity, lab);
        roomid++;
    }
    inputroom.close();
}
