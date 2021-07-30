#include "Fileparsing.h"
#include "Algorithm.h"
#include "Classes.h"

using namespace std;

int main()
{
    ParseCourse(); //Set all data from txt file to the class attributes
    ParseProfessor(); //Set all data from txt file to the class attributes
    ParseStudentGroup(); //Set all data from txt file to the class attributes
    ParseRoom();//Set all data from txt file to the class attributes
    char cont;
    char answer;
    string groupName;
    string all_lines;
    cout << "Do you want to create Time table? y or n? ";
    cin >> answer;
    if (answer == 'y'){
        createTimeTable();
        cout << "Time Table was successfully created!!!\n";
        cout << "Please open TimeTable.txt file in Projects folder to see the Timetable for whole Student Groups.\n";
    }
    cout << endl << "Time Table was created for these groups: \n";
    for (int i = 0; i < groupid; i++ ){
        cout << i+1 << ". " <<StudentGroupObj[i].GetName() << endl;
    }
    cout << "Press any key if you want to get the TimeTable for exact group...\n";
    getch(); //Program waits until any key is pressed...
    //Do while loop used to get time table for more student groups
    do {cout << endl<< "Enter your Group Name: ";
    cin >> groupName;
    if (groupName.compare("All")==0){
        ifstream alltoscreen("TimeTable.txt");
        while(!alltoscreen.eof()){
            getline(alltoscreen,all_lines);
            cout<<all_lines<<endl;
        }
        alltoscreen.close();
    }
    GetTimeTable(groupName);
    cout << endl << "Do you want to get Time Table for another group? y or n?\n";
    cin >> cont;
    }
    while(cont == 'y');
    return 0;
}


//Function to check whether the course is Lecture or not
bool isLec(int id){
    char c[4];
    //Set the name of course to the string
    string str = Coursename[id];
    //get size of string
    int l = str.size();
    int j  = 3;
    //get character from the string and one by one set it char array from the end till the beginning
    for(int i  = l-1; i >= l-4; i--){
        c[j] = str[i];
        j--;
    }
    str = "";
    //Convert char array into string
    for(int i=  0;  i < 4; i++){
        str += c[i];
    }
    //If the last four letters are "_lec" the course is lecture
    if(str.compare("_lec") == 0){
        return 1;
    }
    else return 0;
}

//Function to get number of students that attend lecture
int GetLectureCapacity(int id){
    int lectcapacity = 0;
    //From the list of groups we have start searching
    for (int i = 0; i < groupid; i++){
        //From the list of courses of ith group get lectures's id and compare with parameter id of the function
        for (int j = 0; j < StudentGroupObj[i].GetSizeOfCourse(); j++ ){
            //Check if this student group attend to that lecture
            if (StudentGroupObj[i].GetCourseId(j)==id){
                //If group will attend to the lecture its size will be added to the lectcapacity
                lectcapacity+=StudentGroupObj[i].GetnumberOfStudents();
            }
        }
    }
    //Now lectcapacity contains all number of students that will attend to the lecture
    return lectcapacity;
}


string sday = "";

string getTimeString(int t){
    string daytime;
    if(t<8)daytime = "~~~~~Monday~~~~~";
    else if (t<16) daytime = "~~~~~Tuesday~~~~";
    else if (t<24) daytime = "~~~~Wednesday~~~";
    else if (t<32) daytime = "~~~~Thursday~~~~";
    else daytime = "~~~~~Friday~~~~~";
    //Check if daytime same as string sday, if so set daytime to tabs instead name of week day
    if(daytime.compare(sday)== 0)
        daytime = "\t\t";
    //Find the duration of class in one particular day
    t%=8;
    if(daytime.compare("\t\t") != 0)
        sday = daytime;
    switch(t){
        case 0:
            daytime+="| 09:00 - 09:50 | ";
            break;
        case 1:
            daytime+="| 10:00 - 10:50 | ";
            break;
        case 2:
            daytime+="| 11:00 - 11:50 | ";
            break;
        case 3:
            daytime+="| 12:00 - 12:50 | ";
            break;
        case 4:
            daytime+="| 14:00 - 14:50 | ";
            break;
        case 5:
            daytime+="| 15:00 - 15:50 | ";
            break;
        case 6:
            daytime+="| 16:00 - 16:50 | ";
            break;
        case 7:
            daytime+="| 17:00 - 17:50 | ";
            break;
    }
        return daytime;
}

//Function to get Timetable with the parameter name of group
void GetTimeTable(string groupname){
    //Take TimeTable file as an input file
    ifstream DataBase("TimeTable.txt");
    //Check if program could find the file
    if (groupname.compare("All")==0)
        return;
    if (!DataBase.is_open()){
        cout << "The timetable is not created yet";
        return;
    }
    string line;
    int temp = -1;
    //Search the entered Group name from the class list of Groups
    for (int i = 0; i < groupid; i++){
        if(StudentGroupObj[i].GetName()==groupname){
            temp = i;
            break;
        }
    }
    //If group was not found it does not exist in database
    if (temp == -1){
        cout << "The group does not exist in the database!!!" << endl;
        return;
    }
    //If that group exists search it from the input file
    cout << "The TimeTable for \"" << groupname <<"\""<< endl << endl;
    cout << "Explanations:\n";
    cout << "*lec is Lecture class\n" << "*lab is Labaratory class\n" << "*clab is Computer class\n\n";
    cout <<left<< "WEEKDAY\t\t\t" << setw(26) << "TIME" << setw(42)<< "COURSE NAME" << setw(22) << "INSTRUCTOR" << setw(24) <<"ROOM"<<endl;
    int num=-1;
    /*Group name is usually less that 10 characters
    if algorithm could find line string which has less than 10 chars
    all the line below this string will be output sequently until another string with 10 chars meet
    meaning until the another group*/
    while(getline(DataBase, line)){
        if (line.size() < 12)num++;
        else if(num==temp){
            cout<<line<<endl;
        }
    }
}



