/** Schedule Generating Programme **\
*************************************
Version 1.0

The Schedule or Timetable generating programme is intended to randomly generate Timetable 
for University, College and School classes. The program offers good functionality and 
has simple and intuitive user interface, allowing to create Timetable in few seconds.

--------------------------------------------------------------------------------------------------------
INSTALL:
 - Run "Schedule.exe" file and follow the instructions.

 - The programme was written in Codeblocks IDE.

 - All Input files for generation of NU Seng Timetable was already given.

 - If you want to generate Timetable for your own school, please add 4 txt files the same 
   as in input folder with your data (Course.txt, Professor.txt, Room.txt and StudentGroup.txt)
-----------------------------------------------------------------------------------------------------------

*Notes about input files:
1) Course.txt file:
  ~First column name of courses (indicate whether it's tutorial (_tut), complab(_clab) or lecture(_lec))
  ~Second column duration of this course
  ~Third column indicate whether the course requires lab equipment (1 yes, 0 no)

2) Professor.txt file:
  ~First column name of the instructor
  ~Second column list courses that professor teaches with space
  ~End line with 0

3) Room.txt file
  ~First column name of the room
  ~Second column capacity
  ~Third column indicate whether room has lab equipment (1 yes, 0 no)

4) StudentGroup.txt file
  ~First column number of students in group
  ~Second column name of the group
  ~From third column list courses that group attends with space (start with only lectures)
  ~End the line with 0

**IMPORTANT**
Use underscore to separate first name and second name of Prof or coursename
Example: Ivanov_Ivan, Programming_For_Engineers

	
//MINIMUM SYSTEM REQUIRENMENTS\\:
Program does not requires big system requirenment. 
It will work in any system with even low performance. 
The only thing if you are not able run the program from the direct
execution file, please download Codeblocks program. And use it to run the program.

*Tested in Standard MinGW 32-bit Edition Compiler GCC 4.9 Series.  

To get more information about project, and how the program works please read Report.docx file
--------------------------------------------------------------------------------------------------------------
*********************************
*Authors: Daniyar Mussa		*
*	Aidos Satan		*	
*	Tastanbek Yerdaulet	*
*	Dana Aubakirova		*
*********************************

You can send any questions to the authors:
mailto:daniyar.mussa@nu.edu.kz
	aidos.satan@nu.edu.kz
	yerdaulet.tastanbek@nu.edu.kz
	dana.aubakirova@nu.edu.kz


//////////////////////////////////////////
// (C)2017-2018	ANONYMOUS		//
// All rights reserved.           	//
//////////////////////////////////////////