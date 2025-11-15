
#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include <climits>
#include<vector>
#include <windows.h>
#include"project.h";

using namespace std;

//ignoring the alphapet input
bool getIntInput(int& num) {
    cout << "Enter  your choice: ";
    while (!(cin >> num)) {
        cin.clear();

        while (cin.get() != '\n') {}
        cout << "Invalid input. Please enter an integer: ";
    }
    return true;
}

//date and time
string printDateTime() {

    //time_t now = time(nullptr);


    //char buffer[80];
    //strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));


    //string dateTime(buffer);
    string  dateTime = "hy";
    return dateTime;
}


//update password function
template<class typestring>
bool passwordMAnagar<typestring>::updatepassword(typestring username, typestring password) {
    text_colour(12);


    ifstream inFile("credentials.txt");
    ofstream outFile("temp.txt");

    typestring storedUsername, storedPassword;

    if (!inFile || !outFile) {
        cerr << "Error: Unable to open file." << endl;
        return false;
    }

    while (inFile >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            outFile << storedUsername << " " << password << endl;
        }
        else {
            outFile << storedUsername << " " << storedPassword << endl;
        }
    }

    inFile.close();
    outFile.close();

    remove("credentials.txt");
    rename("temp.txt", "credentials.txt");


    return true;
}


//remove the credentials function
template<class typestring>
bool removeUser(const typestring& username) {
    ifstream inFile("credentials.txt");
    ofstream outFile("temp.txt");

    if (!inFile || !outFile) {
        cerr << "Error: Unable to open file." << endl;
        return false;
    }

    typestring storedUsername, storedPassword;
    bool found = false;

    while (inFile >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            found = true;
            continue;
        }
        outFile << storedUsername << " " << storedPassword << endl;
    }

    inFile.close();
    outFile.close();

    if (!found) {
        cout << "Username not found." << endl;
        remove("temp.txt");
        return false;
    }

    remove("credentials.txt");
    rename("temp.txt", "credentials.txt");

    cout << "User removed successfully." << endl;
    return true;
}


//getnotes
vector<string> getNotesById(const string& id)
{
    vector<string> filteredNotes;
    ifstream file("notes.txt");
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        string noteId, note;

        getline(iss, noteId, ' ');
        getline(iss, note);

        if (noteId == id)
        {
            filteredNotes.push_back(note);
        }

    }

    file.close();
    return filteredNotes;
}


//send notes

void send_notes(string idd)
{
    string dateTime = printDateTime();
    text_colour(12);
    cout << "please enter the id of person you want to send note\n";
    string id;
    cin >> id;
    cout << "please enter the note you want to send....\n";
    string note;
    cin.ignore();
    getline(cin, note);
    note += "  from " + idd + "DATE AND TIME" + dateTime;
    ofstream outFile("notes.txt", ios::app);

    if (outFile.is_open())
    {
        outFile << id << " " << note << endl;
        outFile.close();
    }
}


Quiz::Quiz() {
    quiz1 = 0;
    quiz2 = 0;
    quiz3 = 0;
}
Quiz::Quiz(float q1, float q2, float q3)
{
    quiz1 = q1;
    quiz2 = q2;
    quiz3 = q3;
    total = ((((quiz1 + quiz2 + quiz3) / 30) * 100 * 10) / 100);
}

void  Quiz::setquiz1(float number)
{

    quiz1 = number;

}
void Quiz::setquiz2(float number) {
    quiz2 = number;
}
void  Quiz::setquiz3(float number) {
    quiz3 = number;
}
float  Quiz::getquiz1()const {
    return quiz1;
}
float  Quiz::getquiz2()const {
    return quiz2;
}
float  Quiz::getquiz3()const {
    return quiz3;
}
float Quiz::gettotal()
{
    return total;
}
void Quiz::print_quiz()
{
    text_colour(12);
    cout << "do you want to see quiz record\nif yes press 1 else press 2";

    int press;
    cin >> press;
    system("cls");
    if (press == 1)
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|   Quizzes marks out of 10  |\n"
        << "\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|  Quiz 1 marks: " << quiz1 << "           |\n"
        << "\t\t\t\t\t\t\t\t|  Quiz 2 marks: " << quiz2 << "           |\n"
        << "\t\t\t\t\t\t\t\t|  Quiz 3 marks: " << quiz3 << "           |\n"
        << "\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|  Total absolute marks: " << total << "  |\n"
        << "\t\t\t\t\t\t\t\t==============================\n";



}




Assignment::Assignment() {
    assinment1 = 0;
    assinment2 = 0;
    assinment3 = 0;

}
Assignment::Assignment(float q1, float q2, float q3) {
    assinment1 = q1;
    assinment2 = q2;
    assinment3 = q3;
    total = ((((assinment1 + assinment2 + assinment3) / 30) * 100 * 10) / 100);
}
void Assignment::setassinment1(float number) {
    assinment1 = number;
}
void Assignment::setassinment2(float number) {
    assinment2 = number;
}
void Assignment::setassinment3(float number) {
    assinment3 = number;
}
float Assignment::getassinment1()const {
    return assinment1;
}
float Assignment::getassinment2()const {
    return assinment2;
}
float Assignment::getassinment3()const {
    return assinment3;
}
float Assignment::gettotal()
{
    return total;
}
void Assignment::print_ass()
{
    text_colour(12);
    cout << "do you want to see assignment record\nif yes press 1 else press 2";

    int press;
    cin >> press;
    system("cls");
    if (press == 1)
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|   Assignments marks out of 10  |\n"
        << "\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|  Assinment 1 marks: " << assinment1 << "           |\n"
        << "\t\t\t\t\t\t\t\t|  Assinment 2 marks: " << assinment2 << "           |\n"
        << "\t\t\t\t\t\t\t\t|  Assinment 3 marks: " << assinment3 << "           |\n"
        << "\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|  Total absolute marks: " << total << "  |\n"
        << "\t\t\t\t\t\t\t\t==============================\n";
}



Midterm::Midterm() {
    mid1 = 0;
    mid2 = 0;
}
Midterm::Midterm(float mid, float midd) {
    mid1 = mid;
    mid2 = midd;
    total = ((((mid1 + mid2) / 100) * 100 * 30) / 100);
}
void   Midterm::setmid1(float number) {
    mid1 = number;
}
void   Midterm::setmid2(float number) {
    mid2 = number;
}
float   Midterm::getmid1()const {
    return mid1;
}
float   Midterm::getmid2()const {
    return mid2;
}
float Midterm::gettotal()
{
    return total;
}
void   Midterm::print_mid()
{
    text_colour(12);
    cout << "do you want to see mid record\nif yes press 1 else press 2";

    int press;
    cin >> press;
    system("cls");
    if (press == 1)

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|   Midterm marks out of 50    |\n"
        << "\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|  Midterm 1 marks: " << mid1 << "         |\n"
        << "\t\t\t\t\t\t\t\t|  Midterm 2 marks: " << mid2 << "         |\n"
        << "\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|  Total absolute marks: " << total << "    |\n"
        << "\t\t\t\t\t\t\t\t==============================\n";
}

FinalTerm::FinalTerm() {
    final = 0;
}
FinalTerm::FinalTerm(float num) {
    final = num;
    total = (final * 50 / 100);
}
float FinalTerm::gettotal()
{
    return total;
}
void  FinalTerm::setfinal(float number) {
    final = number;
}
float  FinalTerm::getfinal()const {
    return final;
}
void  FinalTerm::print_final()
{
    text_colour(12);
    cout << "do you want to see final record\nif yes press 1 else press 2";

    int press;
    cin >> press;
    system("cls");
    if (press == 1)
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|   Final marks out of 100     |\n"
        << "\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|  Final marks: " << final << "                |\n"
        << "\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|  Total absolute marks: " << total << "    |\n"
        << "\t\t\t\t\t\t\t\t==============================\n";
}




Grade::Grade(Quiz q, Assignment a, Midterm m, FinalTerm f) :quiz(q), ass(a), mid(m), final(f) {}
Grade::Grade() :Quiz(), Assignment(), Midterm(), FinalTerm() {}
void  Grade::print_grades()
{
    text_colour(12);
    quiz.print_quiz();

    ass.print_ass();

    mid.print_mid();

    final.print_final();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\ttotal absolutes out of 100 of this course are:" << quiz.gettotal() + ass.gettotal() + mid.gettotal() + final.gettotal() << endl;
    Sleep(5000);

}



attendence::attendence()
{
    char* attend = NULL;
    int total = 0;
    int size = 0;
}
attendence::attendence(int creditt, char* attendd)
{
    total = 24;
    if (creditt == 3)
    {
        total = 24;

    }
    else  if (creditt == 2)
    {
        total = 24;

    }
    else if (creditt == 1)
    {
        total = 24;

    }
    attend = new char[total];
    for (int i = 0; i < total; i++)
    {
        attend[i] = attendd[i];
    }

    /*  size++;
      attend = new char[size];
      cout << "Enter P for present\nEnter A for absent\n";
      char temp;
      cin >> temp;
      while (true) {
          if (temp == 'A' || temp == 'P')
          {
              break;
          }
          cout << "Please enter P for present or A for absent\n";
          cin >> temp;
      }

      attend[0] = temp;*/
}
void   attendence::set_attendence(int i)

{
    text_colour(12);
    char temp;
    cout << "Please enter P for present or A for absent\n";
    cin >> temp;

    attend[i] = temp;
}

void   attendence::print_attendence()
{
    text_colour(12);
    cout << "do you want to see attendence record\nif yes press 1 else press 2";
    int press;
    cin >> press;
    if (press == 1)
    {
        int count = 0;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
            << "\t\t\t\t\t\t\t\t|   Attendance for classes    |\n"
            << "\t\t\t\t\t\t\t\t==============================\n";

        for (int i = 0; i < total; i++) {
            cout << "\t\t\t\t\t\t\t\t|  Class " << i + 1 << " attendance: " << attend[i] << "       |\n";
            if (attend[i] == 'A')
                count++;
        }
        cout << "\t\t\t\t\t\t\t\t==============================\n";
        int result = (((total - count) * 100) / total);
        cout << "your course attendence is:" << result << endl;

        if (result < 80)
        {
            cout << "your atttendence is short please contact with academic center or you will not allow to sit in exams\n";
        }

    }
}

void   attendence::put_attendence()
{
    text_colour(12);
    int temp_s = size;
    size++;
    char* tempo = new char[size];
    for (int i = 0; i < temp_s; i++)
    {
        tempo[i] = attend[i];
    }

    cout << "Enter P for present\nEnter A for absent\n";
    char temp;
    cin >> temp;
    while (true) {
        if (temp == 'A' || temp == 'P')
        {
            break;
        }
        cout << "Please enter P for present or A for absent\n";
        cin >> temp;

    }

    tempo[temp_s] = temp;
    delete[]attend;
    attend = tempo;
}
char   attendence::get_attendence(char press)
{
    return attend[press];
}
void   attendence::change_attendence()
{
    text_colour(12);
    for (int i = 0; i < size; i++)
    {
        cout << "Attendence of class " << i + 1 << " " << attend[i] << endl;

    }
    int tell;
    cout << "\n\n Which class attendence you what to change ?\n";
    cin >> tell;
    while (true)
    {
        if (tell < size && tell > 0)
            break;
        else
            cout << "enter valid  class no....\n";
    }

    cout << "Enter P for present\nEnter A for absent\n";
    char temp;
    cin >> temp;
    while (true) {
        if (temp == 'A' || temp == 'P')
        {
            break;
        }
        cout << "Please enter P for present or A for absent\n";
        cin >> temp;
    }
    attend[tell - 1] = temp;
}



courses::courses() : course(""), course_c(""), credit() {

}


courses::courses(string name, string code, int creditt)
    : course(name), course_c(code), credit(creditt) {}

courses::courses(const courses& obj)
{
    credit = obj.credit;
    course = obj.course;
    course_c = obj.course_c;
}

void courses::setcourse_name(string& name)
{
    course = name;
}
void  courses::setcourse_code(string& code)
{
    course_c = code;
}
void  courses::setcredit(int& creditt)
{
    credit = creditt;
}

string  courses::getcourse_name()
{
    return course;
}
string  courses::getcourse_code()
{
    return course_c;
}
int  courses::getcredit()
{
    return  credit;
}
void  courses::print_course()
{
    text_colour(12);
    cout << "course name:" << course << "\n course code:" << course_c << "\ncredit hour:" << credit << endl;
}



void delete_note(string id)
{
    ofstream outFile("temp.txt");
    ifstream infile("notes.txt");

    string line;
    while (getline(infile, line))
    {
        int i = 0;
        string world;
        bool check = false;
        while (true)
        {
            if (line[i] != ' ')
            {
                world += line[i];
                i++;
            }
            else
            {
                if (world == id)
                    check = true;

                break;
            }

        }
        if (!check)
        {
            outFile << line << endl;
        }

    }

    outFile.close();
    infile.close();
    ifstream sourceFile("temp.txt");

    ofstream destinationFile("notes.txt");

    while (getline(sourceFile, line)) {
        destinationFile << line << endl;
    }
    sourceFile.close();
    destinationFile.close();

    cout << "Notes are deleted now they are  label as empty......" << endl;


}
person::person()
{
    int age = 0;;
    string f_name;
    string l_name;
    string id;
    int size = 0;
    string section;
    int note_s = 0;
    notes = nullptr;

}
person::person(const string& first_name, const string& last_name, int agee, string sectionn, string idd)
{
    f_name = first_name;
    l_name = last_name;
    age = agee;
    section = sectionn;
    id = idd;


}
void person::add_notes(string note)
{
    if (notes != nullptr)
    {
        int temp = note_s;
        note_s++;
        string* temp_note = new string[note_s];
        for (int i = 0; i < temp; i++)
        {
            temp_note[i] = notes[i];
        }
        temp_note[temp] = note;
        delete[]notes;
        notes = temp_note;
    }
    else
    {
        note_s++;
        notes = new string[note_s];
        notes[0] = note;
    }

}
void person::getnotes()
{
    if (notes == nullptr)
    {
        cout << "oh ho!!!\n notes section is empty...\n\n";
    }
    else
    {
        for (int i = 0; i < note_s; i++)
        {
            cout << notes[i] << endl;
        }
        cout << " do you want to delete the notes?\nif yes press1\neelse press 2\n";
        int press;
        cin >> press;
        if (press == 1)
        {
            delete[]notes;
            notes = nullptr;
            delete_note(id);
        }
    }
}


string person::getFirstName() const {
    return f_name;
}
string person::getsection() const {
    return section;
}

string person::getLastName() const {
    return l_name;
}

int person::getAge() const {
    return age;
}

void person::setFirstName(const string& first_name) {
    f_name = first_name;
}

string person::getid() const {
    return id;
}

void person::setid(const string& idd) {
    id = idd;
}

void person::setsection(const string& sectionn) {
    section = sectionn;
}

void person::setLastName(const string& last_name) {
    l_name = last_name;
}

void person::setAge(int age_) {
    age = age_;
}



void person::print()
{
    text_colour(12);
    cout << "name:" << f_name << " " << l_name << "\n Age: " << age << " " << "\nsection:" << section << "\nid:" << id << endl;
}


person:: ~person()
{

}

alldetail::alldetail() : num(0) {}


alldetail::alldetail(courses coursee, attendence attendd, Grade gradee, int numm)
    : course(coursee), attend(attendd), grade(gradee), num(numm) {}

void alldetail::print_alldetail() {
    course.print_course();
    if (num == 0) {
        attend.print_attendence();
        grade.print_grades();
    }
}


student::student()
{

    alldetail* g = NULL;
    int size = 0;
}
student::student(const string& first_name, const string& last_name, int agee, alldetail temp, string sectionn, string id)
    : person(first_name, last_name, agee, sectionn, id) {
    size++;
    g1 = new alldetail[size];
    g1[0] = temp;

}
void  student::add_data(alldetail add)
{
    int temp_s = size;
    size++;
    alldetail* temp = new alldetail[size];
    for (int i = 0; i < temp_s; i++)
    {
        temp[i] = g1[i];
    }
    temp[temp_s] = add;
    delete[]g1;
    g1 = temp;
}


void  student::print() {
    person::print();

}
void  student::print_data()
{
    for (int i = 0; i < size; i++)
    {
        text_colour(12);
        system("cls");
        cout << "course number:" << i + 1 << endl;
        g1[i].print_alldetail();
    }
}
student::~student()
{

}

void  student::add_detail(alldetail detail_data)
{
    int temp_s = size;
    size++;
    alldetail* temp = new alldetail[size];
    for (int i = 0; i < temp_s; i++)
    {
        temp[i] = g1[i];
    }
    temp[temp_s] = detail_data;
    delete[]g1;
    g1 = temp;
}

under_g::under_g(const string& f_name, const string& l_name, int age, alldetail temp, string sectionn, string id, string proj)
    :student(f_name, l_name, age, temp, sectionn, id), status(proj)
{

}
string  under_g::getfyp()
{
    return status;
}
void  under_g::setthesis(string& fyp)
{
    status = fyp;
}
void  under_g::print()
{
    text_colour(12);
    student::print();
    cout << "and has fyp of  " << status << " " << endl;
}
under_g:: ~under_g()
{

}

ex_student::ex_student(const string& f_name, const string& l_name, int age, alldetail temp, string sectionn, string id, string proj)
    :student(f_name, l_name, age, temp, sectionn, id)
{
}

void   ex_student::print()
{
    student::print();
}

ex_student:: ~ex_student()
{

}

faculty::faculty() : ext(0), course() {}


faculty::faculty(const string& first_name, const string& last_name, int agee, const string& sectionn, const string& id, int extt, const courses& coursee)
    : person(first_name, last_name, agee, sectionn, id), ext(extt), course(coursee) {}

int  faculty::getext()
{
    return ext;
}
void  faculty::setcourse(int extt)
{
    ext = extt;
}

void  faculty::print()
{
    text_colour(12);
    cout << "Teacher detail\n\n";
    person::print();
    cout << " \n extension nmumber :  " << ext << endl;
    cout << "Courses teaches\n";
    course.print_course();
}
faculty::~faculty()
{

}


string processTeachers(const string& facultyId, string& section, string& pass)
{
    text_colour(5);
    string courseCode = "";
    ifstream inFile("teacher_data.txt");


    string line;
    while (getline(inFile, line)) {
        istringstream iss(line);
        string firstName = "";
        string lastName = "";
        int age = 0;
        string id = "";
        int ext = 0;
        string courseName = "";

        int credits = 0;
        faculty teacher;
        iss >> firstName >> lastName >> age >> section >> ext >> id >> courseName >> courseCode >> credits;



        if (id == facultyId)
        {
            courses course(courseName, courseCode, credits);
            faculty teacher(firstName, lastName, age, section, id, ext, course);
            while (true)
            {
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                    << "\t\t\t\t\t\t\t\t|   Welcome, " << firstName << " " << lastName << "!    |\n"
                    << "\t\t\t\t\t\t\t\t==============================\n"
                    << "\t\t\t\t\t\t\t\t|   enter what you wanna do:  |\n"
                    << "\t\t\t\t\t\t\t\t|  1. See your profile        |\n"
                    << "\t\t\t\t\t\t\t\t|  2. See notes               |\n"
                    << "\t\t\t\t\t\t\t\t|  3. Send a note             |\n"
                    << "\t\t\t\t\t\t\t\t|  4. Go to student portal    |\n"
                    << "\t\t\t\t\t\t\t\t|  5. Change your password    |\n"
                    << "\t\t\t\t\t\t\t\t==============================\n";
                int enter;
                cin >> enter;
                if (enter == 5) {
                    passwordMAnagar<string> manager; // Instantiating with string type

                    string newpassword;
                    cout << "enter new password: ";
                    cin >> newpassword;


                    if (manager.updatepassword(id, newpassword)) {
                        cout << "password cahnged successful." << endl;
                    }

                }
                system("cls");
                if (enter == 1)
                    teacher.print();
                else  if (enter == 2)
                {
                    vector<string> notes = getNotesById(id);
                    for (const string& note : notes)
                    {
                        teacher.add_notes(note);
                    }
                    teacher.getnotes();
                }
                else if (enter == 3)
                {
                    send_notes(id);
                }

                else if (enter == 4)
                    break;

                cout << "Do you want to do something else? (y/n): ";
                char answer;
                cin >> answer;
                if (answer != 'y' && answer != 'Y')
                    break;
            }


        }
    }
    inFile.close();
    return courseCode;
}

void processStudents(const string& section, const string& coursecode, int& studentcount, student* students[]) {
    ifstream infile("student_data.txt");
    text_colour(8);
    string line;
    while (getline(infile, line)) {

        string firstName, lastName, section, project, id;
        int age;
        float gpa;

        istringstream iss(line);
        iss >> firstName >> lastName >> age >> section >> id >> gpa >> project;
        int numCourses;
        getline(infile, line);
        istringstream issCourses(line);
        issCourses >> numCourses;
        if (section == section)
        {
            for (int i = 0; i < numCourses; ++i)
            {
                string courseName, courseCode;
                int credits;
                getline(infile, line);
                istringstream issCourseDetails(line);
                issCourseDetails >> courseName >> courseCode >> credits;
                courses course(courseName, courseCode, credits);
                getline(infile, line);
                istringstream attendd(line);
                char* attend = new char[24];
                for (int j = 0; j < 24; j++)
                {
                    attendd >> attend[j];
                }


                int  quiz1, quiz2, quiz3, ass1, ass2, ass3, mid1, mid2, final;
                getline(infile, line);
                istringstream grades(line);
                grades >> quiz1 >> quiz2 >> quiz3 >> ass1 >> ass2 >> ass3 >> mid1 >> mid2 >> final;


                Quiz c1(quiz1, quiz2, quiz3);
                Assignment c2(ass1, ass2, ass3);
                Midterm c3(mid1, mid2);
                FinalTerm c4(final);
                Grade g1(c1, c2, c3, c4);


                attendence a1(credits, attend);



                if (courseCode == coursecode)
                {
                    alldetail gg1(course, a1, g1);
                    students[studentcount] = new under_g(firstName, lastName, age, gg1, section, id, project);

                    ++studentcount;
                }

            }
        }
    }

    infile.close();
}

//student_profile


void student_profile(string id_no, int num, string& pass)
{
    text_colour(12);
    ifstream infile("student_data.txt");

    string line;
    while (getline(infile, line))
    {
        string firstName = "";
        string lastName = "";
        string section = "";
        string project = "";
        string id = "";
        int age;


        istringstream iss(line);
        iss >> firstName >> lastName >> age >> section >> id >> project;

        int numCourses;
        getline(infile, line);
        istringstream issCourses(line);
        issCourses >> numCourses;


        student myStudent;

        for (int i = 0; i < numCourses; ++i)
        {
            string courseName, courseCode;
            int credits;

            getline(infile, line);
            istringstream issCourseDetails(line);
            issCourseDetails >> courseName >> courseCode >> credits;

            courses course(courseName, courseCode, credits);

            getline(infile, line);
            istringstream attendd(line);
            char* attend = new char[24];

            for (int j = 0; j < 24; j++)
            {
                attendd >> attend[j];
            }

            int quiz1, quiz2, quiz3, ass1, ass2, ass3, mid1, mid2, final;

            getline(infile, line);
            istringstream grades(line);
            grades >> quiz1 >> quiz2 >> quiz3 >> ass1 >> ass2 >> ass3 >> mid1 >> mid2 >> final;

            Quiz c1(quiz1, quiz2, quiz3);
            Assignment c2(ass1, ass2, ass3);
            Midterm c3(mid1, mid2);
            FinalTerm c4(final);

            Grade g1(c1, c2, c3, c4);
            attendence a1(credits, attend);

            alldetail gg1(course, a1, g1, num);
            if (id == id_no)
            {
                if (i == 0)
                {
                    under_g student(firstName, lastName, age, gg1, section, id, project);
                    myStudent = student;
                }
                else
                {
                    myStudent.add_detail(gg1);
                }

                delete[] attend;
            }
            if (i == 0)
            {

                vector<string> notes = getNotesById(id);
                for (const string& note : notes)
                {
                    myStudent.add_notes(note);
                }
            }
        }
        if (id == id_no)
        {

            cout << "your profile:\n";
            myStudent.print();
            cout << "enter anything to contiune....." << endl;
            string any;
            cin >> any;
            while (true)
            {

                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                    << "\t\t\t\t\t\t\t\t|   What would you like to do? |\n"
                    << "\t\t\t\t\t\t\t\t==============================\n"
                    << "\t\t\t\t\t\t\t\t|  1. See course details       |\n"
                    << "\t\t\t\t\t\t\t\t|  2. See notes                |\n"
                    << "\t\t\t\t\t\t\t\t|  3. Send a note              |\n"
                    << "\t\t\t\t\t\t\t\t|  4. Change your password     |\n"
                    << "\t\t\t\t\t\t\t\t==============================\n";
                int press = 0;
                try
                {
                    if (getIntInput(press)) {
                        if (press > 1 && press < 5) {
                            cout << "wrong input" << endl;
                        }
                    }
                    else
                        throw 5;

                }
                catch (...)
                {
                    cout << "enter right number";
                }
                system("cls");
                if (press == 4) {
                    passwordMAnagar<string> manager; // Instantiating with string type

                    string newpassword;
                    cout << "enter new password: ";
                    cin >> newpassword;


                    if (manager.updatepassword(id, newpassword)) {
                        cout << "pass changed successful." << endl;
                    }

                }
                if (press == 1)
                {
                    cout << "your courses detail :\n";
                    myStudent.print_data();
                }
                else if (press == 2)
                    myStudent.getnotes();
                else if (press == 3)
                    send_notes(id);
                cout << "Do you want to do something else? (y/n): ";
                char answer;
                cin >> answer;
                if (answer != 'y' && answer != 'Y')
                    break;
            }



            break;
        }


    }


    infile.close();
}

//add students


void add_students()
{

    text_colour(11);
    string firstName, lastName, section, project, id;
    string pass;
    int age;
    float gpa;
    cout << "DEAR admin!please add the detail of new enrolled student.....\n";
    cout << "students first name?\n";
    cin >> firstName;
    cout << "students last name?\n";
    cin >> lastName;
    cout << "students age?\n";
    cin >> age;
    cout << "students id?\n";
    cin >> id;
    search_id(id);
    cout << "assign this student some password can be changed by student\n";
    cin >> pass;
    cout << "students section\n";
    cin >> section;
    cout << "students  status?\n";
    cin >> project;
    cout << "how many courses will this student is going to be enrolled...\n";
    int enter;
    cin >> enter;
    system("cls");
    string courseName, courseCode;
    int credits;
    ofstream outfile;
    ofstream outfile2;
    outfile.open("student_data.txt", ios::app);

    outfile << endl;
    outfile << firstName << " " << lastName << " " << age << " " << section << " " << id << " " << project;
    outfile << endl;
    outfile << enter;
    outfile << endl;


    for (int i = 0; i < enter; i++)
    {
        cout << "tell the detail of course:" << i + 1 << endl;
        cout << "enter course name...\n";
        cin >> courseName;
        cout << "enter course code ...\n";
        cin >> courseCode;
        cout << "enter course credit hour...\n";
        cin >> credits;
        outfile << courseName << " " << courseCode << " " << credits;
        outfile << endl;
        char* attend = new char[24];
        for (int j = 0; j < 24; j++)
        {
            attend[j] = '-';
            outfile << attend[j] << " ";
        }
        system("cls");
        outfile << endl;
        courses course(courseName, courseCode, credits);
        int quiz1 = 0, quiz2 = 0, quiz3 = 0, ass1 = 0, ass2 = 0, ass3 = 0, mid1 = 0, mid2 = 0, final = 0;
        outfile << quiz1 << " " << quiz2 << " " << quiz3 << " " << ass1 << " " << ass2 << " " << ass3 << " " << mid1 << " " << mid2 << " " << final << endl;

    }
    outfile.close();
    outfile2.open("credentials.txt", ios::app);
    outfile2 << endl;
    outfile2 << id << " " << pass << endl;
    cout << "ID and password saved: " << id << " " << pass;

    outfile2.close();
    cout << "\n\nstudent enrolled succesfully....." << endl;

}

//see data


void see_data(string sec, string roll_no)
{
    text_colour(14);
    const int maxi = 100;
    student* students[maxi];
    int studentcount = 0;
    ifstream infile("student_data.txt");

    string line;
    while (getline(infile, line)) {

        string firstName, lastName, section, status, id;
        int age;


        istringstream iss(line);
        iss >> firstName >> lastName >> age >> section >> id >> status;
        int numCourses;
        getline(infile, line);
        istringstream issCourses(line);
        issCourses >> numCourses;
        student myStudent;
        for (int i = 0; i < numCourses; ++i)
        {
            string courseName, courseCode;
            int credits;
            getline(infile, line);
            istringstream issCourseDetails(line);
            issCourseDetails >> courseName >> courseCode >> credits;
            courses course(courseName, courseCode, credits);
            getline(infile, line);
            istringstream attendd(line);
            char* attend = new char[24];
            for (int j = 0; j < 24; j++)
            {
                attendd >> attend[j];
            }


            int  quiz1, quiz2, quiz3, ass1, ass2, ass3, mid1, mid2, final;
            getline(infile, line);
            istringstream grades(line);
            grades >> quiz1 >> quiz2 >> quiz3 >> ass1 >> ass2 >> ass3 >> mid1 >> mid2 >> final;


            Quiz c1(quiz1, quiz2, quiz3);
            Assignment c2(ass1, ass2, ass3);
            Midterm c3(mid1, mid2);
            FinalTerm c4(final);
            Grade g1(c1, c2, c3, c4);


            attendence a1(credits, attend);

            alldetail gg1(course, a1, g1);
            if (roll_no == "")
            {

                if (i == 0)
                {
                    students[studentcount] = new under_g(firstName, lastName, age, gg1, section, id, status);


                }
                else
                {
                    students[studentcount]->add_detail(gg1);
                }
            }
            else if (roll_no == courseCode && sec == section)
            {
                students[studentcount] = new under_g(firstName, lastName, age, gg1, section, id, status);
                ++studentcount;

            }


        }
        if (roll_no == "")
            ++studentcount;

    }

    infile.close();
    int press = 0;
    cout << "do you want to see students list enrolled press 1 else if you want to see their all data press 2\n";
    try
    {
        if (getIntInput(press)) {
            if (press > 1 && press < 3) {
                cout << "wrong input" << endl;
            }
        }
        else
            throw 5;

    }
    catch (...)
    {
        cout << "enter right number";
    }
    system("cls");
    cout << "\nStudent Information:\n";
    for (int i = 0; i < studentcount; ++i) {
        cout << "Student " << i + 1 << ":\n";
        students[i]->print();
        if (press == 2)
        {
            students[i]->print_data();
            system("cls");
        }
        cout << endl;
    }
    cin.ignore();
}

//student remove


void remove_student()
{
    text_colour(12);
    see_data("", "");
    ofstream outfile("temp.txt");



    cout << "which student data you want to remove from your data_base...\nplease enter his roll_number\n";
    string roll_no;
    cin >> roll_no;
    system("cls");
    ifstream infile("student_data.txt");

    string line;
    while (getline(infile, line)) {

        string firstName, lastName, section, status, id;
        int age;


        istringstream iss(line);
        iss >> firstName >> lastName >> age >> section >> id >> status;
        int numCourses;
        getline(infile, line);
        istringstream issCourses(line);
        issCourses >> numCourses;

        for (int i = 0; i < numCourses; ++i)
        {
            string courseName, courseCode;
            int credits;
            getline(infile, line);
            istringstream issCourseDetails(line);
            issCourseDetails >> courseName >> courseCode >> credits;
            courses course(courseName, courseCode, credits);
            getline(infile, line);
            istringstream attendd(line);
            char* attend = new char[24];
            for (int j = 0; j < 24; j++)
            {
                attendd >> attend[j];
            }

            int  quiz1, quiz2, quiz3, ass1, ass2, ass3, mid1, mid2, final;
            getline(infile, line);
            istringstream grades(line);
            grades >> quiz1 >> quiz2 >> quiz3 >> ass1 >> ass2 >> ass3 >> mid1 >> mid2 >> final;


            if (roll_no != id)
            {
                if (i == 0)
                {
                    outfile << firstName << " " << lastName << " " << age << " " << section << " " << id << " " << status;
                    outfile << endl;
                    outfile << numCourses;
                    outfile << endl;
                }
                outfile << courseName << " " << courseCode << " " << credits;
                outfile << endl;
                for (int j = 0; j < 24; j++)
                {
                    outfile << attend[j];
                }
                outfile << endl;
                outfile << quiz1 << " " << quiz2 << " " << quiz3 << " " << ass1 << " " << ass2 << " " << ass3 << " " << mid1 << " " << mid2 << " " << final << endl;

            }

            // ex students 


            else

            {
                fstream ex("ex_students.txt", ios::app);
                if (i == 0)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                        << "\t\t\t\t\t\t\t\t|   Is this student:          |\n"
                        << "\t\t\t\t\t\t\t\t==============================\n"
                        << "\t\t\t\t\t\t\t\t|  1. Graduate                |\n"
                        << "\t\t\t\t\t\t\t\t|  2. Expelled                |\n"
                        << "\t\t\t\t\t\t\t\t|  3. Left the school         |\n"
                        << "\t\t\t\t\t\t\t\t==============================\n";
                    int press;
                    try
                    {

                        if (getIntInput(press)) {
                            if (press > 1 && press < 4) {
                                cout << "wrong input" << endl;
                            }
                        }
                        else
                            throw 11;

                    }
                    catch (...)
                    {
                        cout << "enter right number";
                    }
                    if (press == 1)
                        status = "graduate";
                    else if (press == 2)
                        status = "expelled";
                    else if (press == 3)
                        status = "left";
                    ex << firstName << " " << lastName << " " << age << " " << section << " " << id << " " << status;
                    ex << endl;
                    ex << numCourses;
                    ex << endl;
                }

                ex << courseName << " " << courseCode << " " << credits;
                ex << endl;
                for (int j = 0; j < 24; j++)
                {
                    ex << attend[j];
                }
                ex << endl;
                ex << quiz1 << " " << quiz2 << " " << quiz3 << " " << ass1 << " " << ass2 << " " << ass3 << " " << mid1 << " " << mid2 << " " << final << endl;
                ex.close();

            }
        }


    }




    outfile.close();
    infile.close();
    ifstream sourceFile("temp.txt");

    ofstream destinationFile("student_data.txt");

    while (getline(sourceFile, line)) {
        destinationFile << line << endl;
    }

    sourceFile.close();
    destinationFile.close();



    cout << "student is successfully removes from data set....\n";
    string username = roll_no;

    if (removeUser(username)) {

    }

}
//update students

void update_student()

{
    text_colour(14);
    ofstream outfile("student_new_data.txt");
    see_data("", "");
    cout << "which student data you want to update from your data_base...\nplease enter his roll_number\n";
    string roll_no;
    cin >> roll_no;
    while (!check_id(roll_no))
    {
        cout << "This id is not valid please enter valid id\n";
        cin >> roll_no;

    }
    int num = 0;
    string pass;
    student_profile(roll_no, num, pass);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|   What would you like to update? |\n"
        << "\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|  1. Student profile            |\n"
        << "\t\t\t\t\t\t\t\t|  2. Course                     |\n"
        << "\t\t\t\t\t\t\t\t|  3. Remove a course            |\n"
        << "\t\t\t\t\t\t\t\t==============================\n";
    try
    {

        if (getIntInput(num)) {
            if (num > 1 && num < 4) {
                cout << "wrong input" << endl;
            }
        }
        else
            throw 11;

    }
    catch (...)
    {
        cout << "enter right number";
    }
    string code;
    system("cls");
    ifstream infile("student_data.txt");

    string line;
    while (getline(infile, line)) {

        string firstName, lastName, section, status, id;
        int age;


        istringstream iss(line);
        iss >> firstName >> lastName >> age >> section >> id >> status;
        int numCourses;
        getline(infile, line);
        istringstream issCourses(line);
        issCourses >> numCourses;

        for (int i = 0; i < numCourses; ++i)
        {
            string courseName, courseCode;
            int credits;
            getline(infile, line);
            istringstream issCourseDetails(line);
            issCourseDetails >> courseName >> courseCode >> credits;
            courses course(courseName, courseCode, credits);
            getline(infile, line);
            istringstream attendd(line);
            char* attend = new char[24];
            for (int j = 0; j < 24; j++)
            {
                attendd >> attend[j];
            }

            int  quiz1, quiz2, quiz3, ass1, ass2, ass3, mid1, mid2, final;
            getline(infile, line);
            istringstream grades(line);
            grades >> quiz1 >> quiz2 >> quiz3 >> ass1 >> ass2 >> ass3 >> mid1 >> mid2 >> final;


            if (roll_no != id)
            {
                if (i == 0)
                {
                    outfile << firstName << " " << lastName << " " << age << " " << section << " " << id << " " << status;
                    outfile << endl;
                    outfile << numCourses;
                    outfile << endl;
                }
                outfile << courseName << " " << courseCode << " " << credits;
                outfile << endl;
                for (int j = 0; j < 24; j++)
                {
                    outfile << attend[j];
                }
                outfile << endl;
                outfile << quiz1 << " " << quiz2 << " " << quiz3 << " " << ass1 << " " << ass2 << " " << ass3 << " " << mid1 << " " << mid2 << " " << final << endl;

            }
            if (roll_no == id)
            {

                if (num == 1)
                {
                    if (i == 0)
                    {
                        cout << "students first name?\n";
                        cin >> firstName;
                        cout << "students last name?\n";
                        cin >> lastName;
                        cout << "students age?\n";
                        cin >> age;
                        cout << "students id?\n";
                        cin >> id;
                        search_id(id);
                        cout << "students section\n";
                        cin >> section;
                        cout << "students  project?\n";
                        cin >> status;

                        system("cls");
                        outfile << firstName << " " << lastName << " " << age << " " << section << " " << id << " " << status;
                        outfile << endl;
                        outfile << numCourses;
                        outfile << endl;
                    }
                    outfile << courseName << " " << courseCode << " " << credits;
                    outfile << endl;
                    for (int j = 0; j < 24; j++)
                    {
                        outfile << attend[j];
                    }
                    outfile << endl;
                    outfile << quiz1 << " " << quiz2 << " " << quiz3 << " " << ass1 << " " << ass2 << " " << ass3 << " " << mid1 << " " << mid2 << " " << final << endl;


                }
                if (num == 2)
                {
                    if (i == 0)
                    {
                        outfile << firstName << " " << lastName << " " << age << " " << section << " " << id << " " << status;
                        outfile << endl;
                        int size = numCourses + 1;

                        outfile << size;
                        outfile << endl;
                    }
                    outfile << courseName << " " << courseCode << " " << credits;
                    outfile << endl;
                    for (int j = 0; j < 24; j++)
                    {
                        outfile << attend[j];
                    }
                    outfile << endl;
                    outfile << quiz1 << " " << quiz2 << " " << quiz3 << " " << ass1 << " " << ass2 << " " << ass3 << " " << mid1 << " " << mid2 << " " << final << endl;
                    if (i == 0)
                    {
                        cout << "enter course name...\n";
                        cin >> courseName;
                        cout << "enter course code ...\n";
                        cin >> courseCode;
                        cout << "enter course credit hour...\n";
                        cin >> credits;
                        outfile << courseName << " " << courseCode << " " << credits;
                        outfile << endl;
                        char* attend = new char[24];
                        for (int j = 0; j < 24; j++)
                        {
                            attend[j] = '-';
                            outfile << attend[j] << " ";
                        }
                        system("cls");
                        outfile << endl;
                        courses course(courseName, courseCode, credits);
                        int quiz1 = 0, quiz2 = 0, quiz3 = 0, ass1 = 0, ass2 = 0, ass3 = 0, mid1 = 0, mid2 = 0, final = 0;
                        outfile << quiz1 << " " << quiz2 << " " << quiz3 << " " << ass1 << " " << ass2 << " " << ass3 << " " << mid1 << " " << mid2 << " " << final << endl;
                    }

                }

                if (num == 3)
                {
                    if (i == 0)
                    {
                        outfile << firstName << " " << lastName << " " << age << " " << section << " " << id << " " << status;
                        outfile << endl;
                        int size = numCourses - 1;

                        outfile << size;
                        outfile << endl;

                        cout << "enter course code you want to remove from this student" << endl;

                        cin >> code;
                    }
                    if (code == courseCode)
                    {

                    }
                    else
                    {
                        outfile << courseName << " " << courseCode << " " << credits;
                        outfile << endl;
                        for (int j = 0; j < 24; j++)
                        {
                            outfile << attend[j];
                        }
                        outfile << endl;
                        outfile << quiz1 << " " << quiz2 << " " << quiz3 << " " << ass1 << " " << ass2 << " " << ass3 << " " << mid1 << " " << mid2 << " " << final << endl;
                    }

                }

            }





        }
    }
}



//teacher data


void faculty::operator++() {
    string firstName, lastname, extensionNumber, idNumber, courseName, courseId, credit_hours, pass;
    int age;
    char section;
    text_colour(12);
    cout << "Enter teacher's first name: ";
    cin >> firstName;
    cout << "Enter teacher's last name: ";
    cin >> lastname;
    cout << "Enter teacher's age: ";
    cin >> age;
    cout << "Enter teacher's section: ";
    cin >> section;
    cout << "Enter teacher's extension number: ";
    cin >> extensionNumber;
    cout << "Enter teacher's ID number: ";
    cin >> idNumber;
    search_id(idNumber);
    cout << "Enter password for teacher login (can be changed by teacher): ";
    cin >> pass;
    cout << "Enter course name: ";
    cin >> courseName;
    cout << "Enter course ID: ";
    cin >> courseId;
    cout << "Enter course credit hours: ";
    cin >> credit_hours;


    ofstream outFile("teacher_data.txt", ios::app);
    ofstream outfile2("credentials.txt", ios::app);

    outFile << firstName << " " << lastname << " " << age << " " << section << " " << extensionNumber << " " << idNumber << " " << courseName << " " << courseId << " " << credit_hours << endl;
    cout << "Teacher added successfully." << endl;


    outfile2 << idNumber << " " << pass << endl;
    cout << "ID and password saved: " << idNumber << " " << pass << endl;

    outFile.close();
    outfile2.close();
}

void faculty::operator--() {
    ifstream inFile(filename);
    text_colour(12);
    ofstream tempFile("temp.txt");

    string line;
    bool found = false;
    string idToRemove;
    cout << "Enter ID to remove: ";
    cin >> idToRemove;

    while (getline(inFile, line)) {
        if (line.find(idToRemove) != string::npos) {
            found = true;
            continue;
        }
        tempFile << line << endl;
    }

    inFile.close();
    tempFile.close();

    if (remove(filename.data()) != 0) {
        cerr << "Error deleting original file: " << filename << endl;
        return;
    }

    if (rename("temp.txt", filename.data()) != 0) {
        cerr << "Error renaming temporary file." << endl;
        return;
    }

    if (found)
        cout << "Teacher with ID " << idToRemove << " removed successfully." << endl;
    else
        cout << "Teacher with ID " << idToRemove << " not found." << endl;

    string username = idToRemove;

    if (removeUser(username)) {
        cout << "User removed successfully." << endl;
    }
}


void displayTeacherInfo() {
    ifstream inFile("teacher_data.txt");

    string firstName, lastname, courseName, courseId, idNumber;
    int age, credithurse, extensionNumber;
    string section;
    bool found = false;



    string line;
    vector<faculty> facultyList;


    while (getline(inFile, line))
    {
        stringstream ss(line);
        ss >> firstName;
        ss >> lastname;
        ss >> age;
        ss >> section;
        ss >> extensionNumber;
        ss >> idNumber;
        ss >> courseName;
        ss >> courseId;
        ss >> credithurse;
        courses coursee(courseName, courseId, credithurse);
        faculty obj(firstName, lastname, age, section, idNumber, extensionNumber, coursee);
        facultyList.push_back(obj);
    }
    int i = 1;
    for (auto& f : facultyList)
    {
        cout << "teacher number:" << i << endl;
        f.print();
        i++;
    }





    inFile.close();
}

void updateTeacherData(const string& filename, const string& idtoupdate) {
    text_colour(12);
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile.is_open()) {
        cout << "Error: Unable to create temporary file." << endl;
        file.close();
        return;
    }
    string firstName, lastname, extensionNumber, idNumber, courseName, courseId;
    int age, credithurse;
    string section;
    bool found = false;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> firstName;
        ss >> lastname;
        ss >> age;
        ss >> section;
        ss >> extensionNumber;
        ss >> idNumber;
        ss >> courseName;
        ss >> courseId;
        ss >> credithurse;
        if (idNumber == idtoupdate) {
            found = true;
            int number = 0;
            cout << "teacher Information:" << endl;
            cout << "name: " << firstName << endl;
            cout << "last name: " << lastname << endl;

            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                << "\t\t\t\t\t\t\t\t|   Enter the number of information |\n"
                << "\t\t\t\t\t\t\t\t|   you want to update:             |\n"
                << "\t\t\t\t\t\t\t\t==============================\n"
                << "\t\t\t\t\t\t\t\t|  1. Age                           |\n"
                << "\t\t\t\t\t\t\t\t|  2. Section                       |\n"
                << "\t\t\t\t\t\t\t\t|  3. ID Number                     |\n"
                << "\t\t\t\t\t\t\t\t|  4. Extension Number              |\n"
                << "\t\t\t\t\t\t\t\t|  5. Course                        |\n"
                << "\t\t\t\t\t\t\t\t==============================\n";
            try
            {

                if (getIntInput(number)) {
                    if (number > 1 && number < 6) {
                        cout << "wrong input" << endl;
                    }
                }
                else
                    throw 11;

            }
            catch (...)
            {
                cout << "enter right number";
            }
            if (number == 1) {
                cout << "Enter the updated age:";
                cin >> age;



            }
            else if (number == 2) {
                cout << "Enter the updated section: ";
                cin >> section;
            }
            else if (number == 3) {
                cout << "Enter the updaetd id number: ";
                cin >> idNumber;
                search_id(idNumber);
            }
            else if (number == 4) {
                cout << "Enter the updated extention number: ";
                cin >> extensionNumber;
            }
            else if (number == 5) {
                cout << "enter the course name: ";
                cin >> courseName;
                cout << "Enter the course id: ";
                cin >> courseId;
                cout << "Enter the course credit hours: ";
                cin >> credithurse;
            }
        }
        tempFile << firstName << " " << lastname << " " << age << " " << section << " " << extensionNumber << " " << idNumber << " " << courseName << " " << courseId << " " << credithurse << endl;


    }



    file.close();
    tempFile.close();

    if (!found) {
        cout << "Error: User ID not found." << endl;
        remove("temp.txt");
        return;
    }

    if (remove(filename.data()) != 0) {
        cout << "Error: Unable to delete original file." << endl;
        return;
    }

    if (rename("temp.txt", filename.data()) != 0) {
        cout << "Error: Unable to rename temporary file." << endl;
    }
    else {
        cout << "updated  successful!" << endl;
    }
}


//faculty_duty


void faculty_duty(string sect, string roll_no, int num)
{
    text_colour(14);

    int press;
    int choice = 0;
    int choice2 = 0;
    string roll;

    if (num == 1)
    {
        cout << "which class attendence you are going to mark.....?\n";
        cin >> press;
        press--;
    }
    else if (num == 2)
    {

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
            << "\t\t\t\t\t\t\t\t|   Which marks you want to upload? |\n"
            << "\t\t\t\t\t\t\t\t==============================\n"
            << "\t\t\t\t\t\t\t\t|  1. Quizzes                      |\n"
            << "\t\t\t\t\t\t\t\t|  2. Assignments                  |\n"
            << "\t\t\t\t\t\t\t\t|  3. Midterms                     |\n"
            << "\t\t\t\t\t\t\t\t|  4. Finals                       |\n"
            << "\t\t\t\t\t\t\t\t==============================\n";
        try
        {

            if (getIntInput(choice)) {
                if (choice > 1 && choice < 5) {
                    cout << "wrong input" << endl;
                }
            }
            else
                throw 11;

        }
        catch (...)
        {
            cout << "enter right number";
        }
        system("cls");
        if (choice == 1) {
            cout << "You selected quizzes.\n";
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                << "\t\t\t\t\t\t\t\t|   Which quiz marks you want to upload? |\n"
                << "\t\t\t\t\t\t\t\t==============================\n"
                << "\t\t\t\t\t\t\t\t|  1. Quiz 1                     |\n"
                << "\t\t\t\t\t\t\t\t|  2. Quiz 2                     |\n"
                << "\t\t\t\t\t\t\t\t|  3. Quiz 3                     |\n"
                << "\t\t\t\t\t\t\t\t==============================\n";
            try
            {

                if (getIntInput(choice2)) {
                    if (choice2 > 1 && choice2 < 4) {
                        cout << "wrong input" << endl;
                    }
                }
                else
                    throw 11;

            }
            catch (...)
            {
                cout << "enter right number";
            }
        }
        else if (num == 3)
        {
            cout << "enter the roll number of the student\n";
            cin >> roll;
        }

        else if (choice == 2)
        {
            cout << "You selected assignments.\n";
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                << "\t\t\t\t\t\t\t\t|   Which assignment marks you want to upload? |\n"
                << "\t\t\t\t\t\t\t\t==============================\n"
                << "\t\t\t\t\t\t\t\t|  1. Assignment 1               |\n"
                << "\t\t\t\t\t\t\t\t|  2. Assignment 2               |\n"
                << "\t\t\t\t\t\t\t\t|  3. Assignment 3               |\n"
                << "\t\t\t\t\t\t\t\t==============================\n";
            try
            {

                if (getIntInput(choice2)) {
                    if (choice2 > 1 && choice2 < 4) {
                        cout << "wrong input" << endl;
                    }
                }
                else
                    throw 11;

            }
            catch (...)
            {
                cout << "enter right number";
            }

        }

        else if (choice == 3)
        {
            cout << "You selected midterms.\n";
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                << "\t\t\t\t\t\t\t\t|   Which midterm marks you want to upload? |\n"
                << "\t\t\t\t\t\t\t\t==============================\n"
                << "\t\t\t\t\t\t\t\t|  1. Midterm 1                  |\n"
                << "\t\t\t\t\t\t\t\t|  2. Midterm 2                  |\n"
                << "\t\t\t\t\t\t\t\t==============================\n";
            try
            {

                if (getIntInput(choice2)) {
                    if (choice2 > 1 && choice2 < 3) {
                        cout << "wrong input" << endl;
                    }
                }
                else
                    throw 11;

            }
            catch (...)
            {
                cout << "enter right number";
            }
            system("cls");
        }

        else {
            cout << "Invalid choice.\n";
        }

    }
    else if (num == 3)
    {
        cout << "enter the roll  number of student ...\n";
        cin >> roll;
    }

    const int maxi = 100;
    student* students[maxi];
    int studentcount = 0;
    ofstream outfile("student_new_data.txt");
    ifstream infile("student_data.txt");

    string line;
    while (getline(infile, line)) {

        string firstName, lastName, section, status, id;
        int age;
        float gpa;

        istringstream iss(line);
        iss >> firstName >> lastName >> age >> section >> id >> status;
        int numCourses;
        getline(infile, line);
        istringstream issCourses(line);
        issCourses >> numCourses;
        student myStudent;
        for (int i = 0; i < numCourses; ++i)
        {
            string courseName, courseCode;
            int credits;
            getline(infile, line);
            istringstream issCourseDetails(line);
            issCourseDetails >> courseName >> courseCode >> credits;
            courses course(courseName, courseCode, credits);
            getline(infile, line);
            istringstream attendd(line);
            char* attend = new char[24];
            for (int j = 0; j < 24; j++)
            {
                attendd >> attend[j];
            }


            int  quiz1, quiz2, quiz3, ass1, ass2, ass3, mid1, mid2, final;
            getline(infile, line);
            istringstream grades(line);
            grades >> quiz1 >> quiz2 >> quiz3 >> ass1 >> ass2 >> ass3 >> mid1 >> mid2 >> final;


            Quiz c1(quiz1, quiz2, quiz3);
            Assignment c2(ass1, ass2, ass3);
            Midterm c3(mid1, mid2);
            FinalTerm c4(final);
            attendence a1(credits, attend);


            system("cls");

            if (roll_no == courseCode && sect == section)
            {
                if (num == 1)
                {
                    cout << "Attendence of  " << firstName << " " << lastName << endl;
                    a1.set_attendence(press);
                    attend[press] = a1.get_attendence(press);

                }
                if (num == 2)
                {



                    if (choice == 1) {

                        if (choice2 == 1)
                        {
                            float marks;
                            cout << "Enter marks for Quiz 1: " << firstName << " " << lastName << endl;
                            cin >> marks;
                            c1.setquiz1(marks);
                        }
                        else if (choice2 == 2) {
                            float marks;
                            cout << "Enter marks for Quiz 2: " << firstName << " " << lastName << endl;
                            cin >> marks;
                            c1.setquiz2(marks);
                        }
                        else if (choice2 == 3) {
                            float marks;
                            cout << "Enter marks for Quiz 3: " << firstName << " " << lastName << endl;
                            cin >> marks;
                            c1.setquiz3(marks);
                        }

                    }

                    else if (choice == 2)
                    {
                        system("cls");
                        if (choice2 == 1)
                        {
                            float marks;
                            cout << "Enter marks for Assignment 1: " << firstName << " " << lastName << endl;
                            cin >> marks;
                            c2.setassinment3(marks);
                        }
                        else if (choice2 == 2) {
                            float marks;
                            cout << "Enter marks for Assignment 2: " << firstName << " " << lastName << endl;
                            cin >> marks;
                            c2.setassinment2(marks);
                        }
                        else if (choice2 == 3) {
                            float marks;
                            cout << "Enter marks for Assignment 3: " << firstName << " " << lastName << endl;
                            cin >> marks;
                            c2.setassinment3(marks);
                        }

                    }

                    else if (choice == 3)
                    {
                        system("cls");
                        if (choice2 == 1)
                        {
                            float marks;
                            cout << "Enter marks for Midterm 1: " << firstName << " " << lastName << endl;
                            cin >> marks;
                            c3.setmid1(marks);
                        }
                        else if (choice2 == 2)
                        {
                            float marks;
                            cout << "Enter marks for Midterm 2 of : " << firstName << " " << lastName << endl;
                            cin >> marks;
                            c3.setmid2(marks);
                        }

                    }

                    else if (choice == 4) {

                        cout << "Enter marks for the final: " << firstName << " " << lastName << endl;
                        float marks;
                        cin >> marks;
                        c4.setfinal(marks);

                    }
                    else {
                        cout << "Invalid choice.\n";
                    }



                }
                if (num == 3)
                {


                    if (id == roll)
                    {
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                            << "\t\t\t\t\t\t\t\t|   What would you like to do?            |\n"
                            << "\t\t\t\t\t\t\t\t==============================\n"
                            << "\t\t\t\t\t\t\t\t|  1. Add attendance for this student     |\n"
                            << "\t\t\t\t\t\t\t\t|  2. Add grades for this student         |\n"
                            << "\t\t\t\t\t\t\t\t==============================\n";
                        int press;
                        try
                        {

                            if (getIntInput(press)) {
                                if (press > 1 && press < 11) {
                                    cout << "wrong input" << endl;
                                }
                            }
                            else
                                throw 11;

                        }
                        catch (...)
                        {
                            cout << "enter right number";
                        }
                        if (press == 1)
                        {
                            system("cls");
                            cout << "which class Attendence of  " << firstName << " " << lastName << "  you want to mark" << endl;
                            int integer;
                            cin >> integer;
                            a1.set_attendence(integer);
                            attend[integer] = a1.get_attendence(integer);
                        }
                        else if (press == 2)
                        {
                            system("cls");
                            int choice;
                            int choice2;
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                                << "\t\t\t\t\t\t\t\t|   Which marks you want to upload? |\n"
                                << "\t\t\t\t\t\t\t\t==============================\n"
                                << "\t\t\t\t\t\t\t\t|  1. Quizzes                      |\n"
                                << "\t\t\t\t\t\t\t\t|  2. Assignments                  |\n"
                                << "\t\t\t\t\t\t\t\t|  3. Midterms                     |\n"
                                << "\t\t\t\t\t\t\t\t|  4. Finals                       |\n"
                                << "\t\t\t\t\t\t\t\t==============================\n";
                            try
                            {

                                if (getIntInput(choice)) {
                                    if (choice > 1 && choice < 5) {
                                        cout << "wrong input" << endl;
                                    }
                                }
                                else
                                    throw 11;

                            }
                            catch (...)
                            {
                                cout << "enter right number";
                            }
                            system("cls");
                            if (choice == 1) {
                                cout << "You selected quizzes.\n";
                                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                                    << "\t\t\t\t\t\t\t\t|   Which quiz marks you want to upload? |\n"
                                    << "\t\t\t\t\t\t\t\t==============================\n"
                                    << "\t\t\t\t\t\t\t\t|  1. Quiz 1                     |\n"
                                    << "\t\t\t\t\t\t\t\t|  2. Quiz 2                     |\n"
                                    << "\t\t\t\t\t\t\t\t|  3. Quiz 3                     |\n"
                                    << "\t\t\t\t\t\t\t\t==============================\n";

                                try
                                {

                                    if (getIntInput(choice2)) {
                                        if (choice2 > 1 && choice2 < 4) {
                                            cout << "wrong input" << endl;
                                        }
                                    }
                                    else
                                        throw 11;

                                }
                                catch (...)
                                {
                                    cout << "enter right number";
                                }
                            }


                            else if (choice == 2)
                            {
                                cout << "You selected assignments.\n";
                                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                                    << "\t\t\t\t\t\t\t\t|   Which assignment marks you want to upload? |\n"
                                    << "\t\t\t\t\t\t\t\t==============================\n"
                                    << "\t\t\t\t\t\t\t\t|  1. Assignment 1               |\n"
                                    << "\t\t\t\t\t\t\t\t|  2. Assignment 2               |\n"
                                    << "\t\t\t\t\t\t\t\t|  3. Assignment 3               |\n"
                                    << "\t\t\t\t\t\t\t\t==============================\n";
                                try
                                {

                                    if (getIntInput(choice2)) {
                                        if (choice2 > 1 && choice2 < 4) {
                                            cout << "wrong input" << endl;
                                        }
                                    }
                                    else
                                        throw 11;

                                }
                                catch (...)
                                {
                                    cout << "enter right number";
                                }

                            }

                            else if (choice == 3)
                            {
                                cout << "You selected midterms.\n";
                                cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                                    << "\t\t\t\t\t\t\t\t|   Which midterm marks you want to upload? |\n"
                                    << "\t\t\t\t\t\t\t\t==============================\n"
                                    << "\t\t\t\t\t\t\t\t|  1. Midterm 1                  |\n"
                                    << "\t\t\t\t\t\t\t\t|  2. Midterm 2                  |\n"
                                    << "\t\t\t\t\t\t\t\t==============================\n";

                                try
                                {

                                    if (getIntInput(choice2)) {
                                        if (choice2 > 1 && choice2 < 3) {
                                            cout << "wrong input" << endl;
                                        }
                                    }
                                    else
                                        throw 11;

                                }
                                catch (...)
                                {
                                    cout << "enter right number";
                                }

                            }



                            if (choice == 1) {

                                if (choice2 == 1)
                                {
                                    float marks;
                                    cout << "Enter marks for Quiz 1: " << firstName << " " << lastName << endl;
                                    cin >> marks;
                                    c1.setquiz1(marks);
                                }
                                else if (choice2 == 2) {
                                    float marks;
                                    cout << "Enter marks for Quiz 2: " << firstName << " " << lastName << endl;
                                    cin >> marks;
                                    c1.setquiz2(marks);
                                }
                                else if (choice2 == 3) {
                                    float marks;
                                    cout << "Enter marks for Quiz 3: " << firstName << " " << lastName << endl;
                                    cin >> marks;
                                    c1.setquiz3(marks);
                                }

                            }

                            else if (choice == 2)
                            {

                                if (choice2 == 1)
                                {
                                    float marks;
                                    cout << "Enter marks for Assignment 1: " << firstName << " " << lastName << endl;
                                    cin >> marks;
                                    c2.setassinment3(marks);
                                }
                                else if (choice2 == 2) {
                                    float marks;
                                    cout << "Enter marks for Assignment 2: " << firstName << " " << lastName << endl;
                                    cin >> marks;
                                    c2.setassinment2(marks);
                                }
                                else if (choice2 == 3) {
                                    float marks;
                                    cout << "Enter marks for Assignment 3: " << firstName << " " << lastName << endl;
                                    cin >> marks;
                                    c2.setassinment3(marks);
                                }

                            }

                            else if (choice == 3)
                            {

                                if (choice2 == 1)
                                {
                                    float marks;
                                    cout << "Enter marks for Midterm 1: " << firstName << " " << lastName << endl;
                                    cin >> marks;
                                    c3.setmid1(marks);
                                }
                                else if (choice2 == 2)
                                {
                                    float marks;
                                    cout << "Enter marks for Midterm 2 of : " << firstName << " " << lastName << endl;
                                    cin >> marks;
                                    c3.setmid2(marks);
                                }

                            }

                            else if (choice == 4) {

                                cout << "Enter marks for the final: " << firstName << " " << lastName << endl;
                                float marks;
                                cin >> marks;
                                c4.setfinal(marks);

                            }



                        }

                    }
                }

            }

            Grade g1(c1, c2, c3, c4);
            alldetail gg1(course, a1, g1);

            if (i == 0)
            {
                students[studentcount] = new under_g(firstName, lastName, age, gg1, section, id, status);


            }
            else
            {
                students[studentcount]->add_detail(gg1);
            }

            if (i == 0)
            {
                outfile << firstName << " " << lastName << " " << age << " " << section << " " << id << " " << status;
                outfile << endl;
                outfile << numCourses;
                outfile << endl;
            }

            outfile << courseName << " " << courseCode << " " << credits;
            outfile << endl;
            for (int j = 0; j < 24; j++)
            {
                outfile << attend[j];
            }
            outfile << endl;
            outfile << c1.getquiz1() << " " << c1.getquiz2() << " " << c1.getquiz3() << " " << c2.getassinment1() << " " << c2.getassinment2() << " " << c2.getassinment2() << " " << c3.getmid1() << " " << c3.getmid2() << " " << c4.getfinal() << endl;

        }
        studentcount++;





    }

    infile.close();
    outfile.close();
    text_colour(15);
}

void see_ex_students()
{
    text_colour(11);
    ifstream is("ex_students.txt");
    string statuss;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|   What would you like to see?      |\n"
        << "\t\t\t\t\t\t\t\t==============================\n"
        << "\t\t\t\t\t\t\t\t|  1. Graduated students            |\n"
        << "\t\t\t\t\t\t\t\t|  2. Expelled students              |\n"
        << "\t\t\t\t\t\t\t\t|  3. Students who left             |\n"
        << "\t\t\t\t\t\t\t\t==============================\n";
    int press;
    try
    {

        if (getIntInput(press)) {
            if (press > 1 && press < 4) {
                cout << "wrong input" << endl;
            }
        }
        else
            throw 11;

    }
    catch (...)
    {
        cout << "enter right number";
    }
    if (press == 1)
        statuss = "graduate";
    else if (press == 2)
        statuss = "expelled";
    else if (press == 3)
        statuss = "left";
    string line;
    const int maxi = 100;
    student* students[maxi];
    int studentcount = 0;
    while (getline(is, line)) {

        string firstName, lastName, section, status, id;
        int age;


        istringstream iss(line);
        iss >> firstName >> lastName >> age >> section >> id >> status;
        int numCourses;
        getline(is, line);
        istringstream issCourses(line);
        issCourses >> numCourses;
        student myStudent;
        for (int i = 0; i < numCourses; ++i)
        {
            string courseName, courseCode;
            int credits;
            getline(is, line);
            istringstream issCourseDetails(line);
            issCourseDetails >> courseName >> courseCode >> credits;
            courses course(courseName, courseCode, credits);
            getline(is, line);
            istringstream attendd(line);
            char* attend = new char[24];
            for (int j = 0; j < 24; j++)
            {
                attendd >> attend[j];
            }


            int  quiz1, quiz2, quiz3, ass1, ass2, ass3, mid1, mid2, final;
            getline(is, line);
            istringstream grades(line);
            grades >> quiz1 >> quiz2 >> quiz3 >> ass1 >> ass2 >> ass3 >> mid1 >> mid2 >> final;


            Quiz c1(quiz1, quiz2, quiz3);
            Assignment c2(ass1, ass2, ass3);
            Midterm c3(mid1, mid2);
            FinalTerm c4(final);
            Grade g1(c1, c2, c3, c4);


            attendence a1(credits, attend);

            alldetail gg1(course, a1, g1);
            if (status == statuss)
            {

                if (i == 0)
                {
                    students[studentcount] = new ex_student(firstName, lastName, age, gg1, section, id, status);


                }
                else
                {
                    students[studentcount]->add_detail(gg1);
                }
            }

        }
        if (status == statuss)
            studentcount++;
    }

    int enter;
    cout << "do you want to see students list enrolled press 1 else if you want to see their all data press 2\n";
    try
    {

        if (getIntInput(enter)) {
            if (enter > 1 && enter < 3) {
                cout << "wrong input" << endl;
            }
        }
        else
            throw 11;

    }
    catch (...)
    {
        cout << "enter right number";
    }
    system("cls");
    cout << "\nStudent Information:\n";
    for (int i = 0; i < studentcount; ++i) {
        cout << "Student " << i + 1 << ":\n";
        students[i]->print();
        if (enter == 2)
        {

            students[i]->print_data();

        }
        cout << endl;
    }
    cin.ignore();
}

void search_id(string& id)
{
    ifstream inputFile("credentials.txt");
    string user_name;
    string password;
    while (inputFile >> user_name >> password)
    {

        if (id == user_name)
        {

            while (id == user_name)
            {
                text_colour(12);
                cout << "This id is already taken. Please write a unique id: ";
                cin.ignore();
                getline(cin, id);
                cout << endl;
            }

            break;
        }

    }

    inputFile.close();
}

bool check_id(string id)
{
    ifstream inputFile("credentials.txt");
    string user_name;
    string password;

    while (inputFile >> user_name >> password)
    {

        if (id == user_name)
        {
            return true;
        }

    }


    inputFile.close();
    return false;
}
void text_colour(int color)
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}
void start()
{
    text_colour(14);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t  WWW     WWWW    EEEEEEEEEEE   LL           CCCCCCCCCC    OOOOOOOOOOOO   MMM             MMM   EEEEEEEEEEE   \n";
    cout << "\t\t\t\t\t  WWW     WWWW    EEEEEEEEEEE   LL          CCCCCCCCCCCC   OOOOOOOOOOOOO  MMMM           MMMM   EEEEEEEEEEE   \n";
    cout << "\t\t\t\t\t  WWW     WWWW    EEE           LL         CCCC            OOO       OOO  MMMMM         MMMMM   EEE            \n";
    cout << "\t\t\t\t\t  WWW     WWWW    EEE           LL        CCCC             OOO       OOO  MMMMMM       MMMMMM   EEE            \n";
    cout << "\t\t\t\t\t  WWW     WWWW    EEEEEEEEEE    LL        CCCC             OOO       OOO  MMMMMMM     MMMMMMM   EEEEEEEEEE     \n";
    cout << "\t\t\t\t\t  WWW     WWWW    EEEEEEEEEE    LL        CCCC             OOO       OOO  MMMMMMMM   MMMMMMMM   EEEEEEEEEE     \n";
    cout << "\t\t\t\t\t  WWW  w  WWWW    EEE           LL        CCCC             OOO       OOO  MMMMMMMMM MMMMMMMMM   EEE            \n";
    cout << "\t\t\t\t\t  WWWww wwWWWW    EEE           LL        CCCC             OOO       OOO  MMM             MMM   EEE            \n";
    cout << "\t\t\t\t\t  WWWw   wWWWW    EEEEEEEEEEE   LLLLLLLL   CCCCCCCCCCCC    OOOOOOOOOOOOO  MMM             MMM   EEEEEEEEEEE   \n";
    cout << "\t\t\t\t\t  WWW     WWWW    EEEEEEEEEEE   LLLLLLLL    CCCCCCCCCC     OOOOOOOOOOOO   MMM             MMM   EEEEEEEEEEE   \n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    text_colour(12);
    cout << "\n\n\n\nloading..." << endl;

}
admin::admin() : person("Admin", "AdminLastName", 30, "admin_office", "23l-0997")
{}
void admin::update_profile(admin& Admin)
{
    string id, firstname, lastname, room;
    int age;
    cout << "Please fill out all the details one by one....." << endl;
    cout << "your first name:" << endl;
    cin >> firstname;
    Admin.setFirstName(firstname);
    cout << "your last name:" << endl;
    cin >> lastname;
    Admin.setLastName(lastname);
    cout << "your age:" << endl;
    cin >> age;
    Admin.setAge(age);
    cout << "your office name:" << endl;
    cin >> room;
    Admin.setsection(section);
    string start = "admin-";


    cout << "Enter your ID (ID should start with admin-):" << endl;
    getline(cin, id);

    while (true) {
        bool check = true;
        for (int i = 0; i < 6; i++) {
            if (id[i] != start[i]) {
                check = false;
                break;
            }
        }
        if (check) {
            break;
        }
        else {
            cout << "Please follow the pattern\nEnter your ID (ID should start with admin-):" << endl;
            getline(cin, id);
        }
    }
    cout << "enter your password: ";
    string pass;
    cin >> pass;
    Admin.setid(id);
    ofstream outfile("admin.txt");

    outfile << Admin.getFirstName() << " " << Admin.getLastName() << " " << Admin.getAge() << " " << Admin.getsection() << " " << Admin.getid() << endl;
    outfile.close();
    
    cout << "Data has been updated Mr." << Admin.getFirstName() << endl;
    ofstream outfile2;
    outfile2.open("credentials.txt", ios::app);
    outfile2 << endl;
    outfile2 << Admin.getid() << " " << pass << endl;
    cout << "ID and password saved: " << Admin.getid() << " " << pass;

    outfile2.close();
}

istream& operator>>(istream& is, admin& obj)
{
    ifstream infile("admin.txt");
    infile >> obj.f_name >> obj.l_name >>obj.age >> obj.section >> obj.id;
    return is;
    infile.close();
}

ostream& operator<<(std::ostream& os, const admin& obj) {
    os << " Name:" << obj.f_name << " " << obj.l_name << endl;
    os<< "Age:" << obj.age << endl;
    os << "office no:" << obj.section << endl;
    os << "id:" << obj.id << endl;
    return os;
}