#include "Classes.h"
using namespace std;

void createTimeTable(){
    //Boolean expressions to check whether Student Group, Room and Professor are free at a given time
    //0 indicates free, 1 indicates not free
    bool freeStudentGroup[100][100]={0}, emptyRoom[100][100]={0}, freeProfessor[100][100]={0};
    //To get random numbers in each execution
    srand(time(NULL));
    ofstream TimeTable ("TimeTable.txt");
    int capacity;
    int lectcap = 0;
    string s;
    string timeString;
    //For each student group class algorithm will find free professor and free room at given time
    for (int i = 0; i < groupid ; i++){
        //For each subject of student group
        for (int j = 0; j < StudentGroupObj[i].GetSizeOfCourse(); j++ ){
            int cid = StudentGroupObj[i].GetCourseId(j); //course id
            int time, rid, pid; //rid - roomid, pid - prof id
            bool temp = 1;/* Temporary boolean expression which will help to get the true false value
            meaning satisfying all the criteria*/
            //Check if the course is lecture of Tutorials
            if(isLec(cid)){
                int a = -1;
                //Search from ClassCourseObj already set lectures to all groups which will attend the same lecture
                for(int l = 0; l < 40; l++){
                    if (ClassCourseObj[i][l].GetCourseNameById() == Coursename[cid]){
                        a = 1;
                        break;
                    }
                }
                //If this lecture to this groups are already set, continue search for another course of this group
                if (a == 1)
                    continue;
                //The number of Students in the Lecture is the sum of students in the groups that will attend it
                lectcap = GetLectureCapacity(cid);
                vector<int> groups;// List of ids of groups that attend this lecture
                //Setting the vector groups
                for (int u = 0; u < groupid; u++){
                    for (int k = 0; k < StudentGroupObj[u].GetSizeOfCourse(); k++){
                        if (cid == StudentGroupObj[u].GetCourseId(k))
                        groups.push_back(u);
                    }
                }
                //Starting loop for checking whether the Student Group, Room and Professor are free at a given time
                while(temp == 1){
                    temp = 0;
                    time = rand() % 40; //Get random time in a week
                    rid = rand() % roomid; //Get random room from rooms we have
                    //To prevent dividing into the second day
                    if ((time % 4) + CourseDuration[cid] > 4){
                        temp=1;
                        continue;
                    }
                    //Time interval when lecture will be held
                    for (int k = time; k < time + CourseDuration[cid]; k++){
                        if (emptyRoom[rid][k] == 1 || RoomObj[rid].GetCapacity()<lectcap){
                            temp = 1;
                            break;
                        }
                    }
                    if (temp == 1) //Room is not free or empty choose another group or room
                        continue;

                    //Search for free Professor
                    for (int g = 0; g < profid; g++){
                        temp = 0;
                        //Check if Prof teaches this lecture
                        if(ProfessorObj[g].TeachCourse(cid)){
                            for (int k = time; k < time + CourseDuration[cid]; k++){
                                if (freeProfessor[g][k] == 1){
                                    temp = 1;//Prof not free
                                    break;
                                }
                            }
                            /*if temp == 0 means that prof is free at that time
                        because if this for loop temp was initialized as temp = 0, so after passing it was not
                        changed to 1 meaning that prof is not free. As while loop(temp == 1){} we break from while loop
                        as final value of temp is 0 after all criteria satisfied*/
                            if (temp == 0){
                                pid = g;
                                break;
                            }
                        }
                    }
                }// end of while loop
                //All Groups that attend to this Lecture will be not free from now
                for (int c = 0; c < groups.size(); c++){
                    for (int k = time; k < time + CourseDuration[cid]; k++){
                        freeStudentGroup[groups[c]][k]=1;
                        emptyRoom[rid][k]=1;
                        freeProfessor[pid][k]=1;
                        ClassCourseObj[ groups[c] ][k].SetClassCourse(ProfessorObj[pid].GetName(), Coursename[cid], RoomObj[rid].GetName());
                    }
                }
            } // end of if it is lecture

            //Not lecture, it is tutorial or complab
            else{
                while(temp == 1){
                    temp = 0;
                    time = rand() % 40; //Get random time in a week
                    rid = rand() % roomid; //Get random room from rooms we have
                    //To prevent dividing into the second day
                    if ((time % 4) + CourseDuration[cid] > 4){
                        temp=1;
                        continue;   //If the condition does not satisfy start while loop again for different random time
                    }
                    //Time interval when class will be held
                    for (int k = time; k < time + CourseDuration[cid]; k++){
                        // Check if the Student Group is free at that time time
                        if (freeStudentGroup[i][k] == 1){
                            temp = 1;
                            break;  //If Group is not free set temp to 1 and halt
                        }
                    /* Check if the Room is empty at that time time, does the capacity room
                    is enough for Number of Students in i^th Group and if room has computer or lab equipment
                    to provide Lab or CompLab class */
                        if (emptyRoom[rid][k] == 1 || RoomObj[rid].GetCapacity()>200 || RoomObj[rid].GetCapacity()<StudentGroupObj[i].GetnumberOfStudents() || RoomObj[rid].GetLab()!=CourseNeedLab[cid]){
                            temp = 1;
                            break;  //if all criteria for Room does not satisfy set temp to 1 and halt
                        }
                    }
                    if (temp == 1) //Either group or room is not free in that time check the conditions to another time until criteria is satisfied
                        continue;
                    //Search for free Professor from list of Professors who teaches the course
                    for (int g = 0; g < profid; g++){
                        temp = 0;
                        //Check whether the Prof teaches the course, if teaches then...
                        if(ProfessorObj[g].TeachCourse(cid)){
                        //Check if Prof is free at the given time interval
                            for (int k = time; k < time + CourseDuration[cid]; k++){
                            //If Prof is not free set Temp to 1 and break
                            if (freeProfessor[g][k] == 1){
                                temp = 1;
                                break;
                            }
                            }
                            /*if temp == 0 means that prof is free at that time
                            because if this for loop temp was initialized as temp = 0, so after passing it was not
                            changed to 1 meaning that prof is not free. As while loop(temp == 1){} we break from while loop
                            as final value of temp is 0 after all criteria satisfied*/
                            if (temp == 0){
                                pid = g;
                                break;
                            }
                        }
                    } // end of Prof's for loop
                } // end of while loop

                //After choosing free student group, free professor and empty room they are not free at this time from now
                for (int k = time; k < time + CourseDuration[cid]; k++){
                    freeStudentGroup[i][k]=1;
                    emptyRoom[rid][k]=1;
                    freeProfessor[pid][k]=1;
                    ClassCourseObj[i][k].SetClassCourse(ProfessorObj[pid].GetName(), Coursename[cid], RoomObj[rid].GetName());
                }
            } //tutorials end
        }//Timetable for 1 Student group was created
        //After timetable was created, program outputs timetable in each time in the week to the TimeTable.txt file
        TimeTable << StudentGroupObj[i].GetName() << endl;
        for (int j = 0; j < 40; j++){
            TimeTable << getTimeString(j);
            //Check if in the time interval group has a class
            //If does not have, end the line
            if(!ClassCourseObj[i][j].IsEmpty())
                ClassCourseObj[i][j].Output(&TimeTable);
            else TimeTable<<endl;
        }
    }//end of for loop For each Student Group in the group list
    TimeTable << endl;
}
