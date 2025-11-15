
#pragma once

#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include <climits>
#include<vector>
#include<ctime>
using namespace std;

//getnotes
vector<string> getNotesById(const string& id);



//send notes

void send_notes(string idd);

template<class typestring>
class passwordMAnagar {
public:
    bool loginfunction(typestring username, typestring password);
    bool updatepassword(typestring username, typestring password);
    bool removeUser(const typestring& username);
};




class Quiz {
protected:
    float quiz1, quiz2, quiz3, total;
public:
    Quiz();
    Quiz(float q1, float q2, float q3);

    void setquiz1(float number);

    void setquiz2(float number);

    void setquiz3(float number);

    float getquiz1()const;

    float getquiz2()const;

    float getquiz3()const;

    float gettotal();
    void print_quiz();


};

class Assignment {
private:
    float assinment1, assinment2, assinment3;
    float total;

public:
    Assignment();
    Assignment(float q1, float q2, float q3);

    void setassinment1(float number);
    void setassinment2(float number);
    void setassinment3(float number);

    float getassinment1() const;
    float getassinment2() const;
    float getassinment3() const;
    float gettotal();


    void print_ass();
};
class Midterm {
private:
    float mid1, mid2;
    float total;

public:
    Midterm();
    Midterm(float mid, float midd);

    void setmid1(float number);
    void setmid2(float number);
    float gettotal();

    float getmid1() const;
    float getmid2() const;

    void print_mid();
};


class FinalTerm {
private:
    float final;
    float total;

public:
    FinalTerm();
    FinalTerm(float num);

    void setfinal(float number);
    float getfinal() const;
    float gettotal();
    void print_final();
};


class Grade :public Quiz, Assignment, Midterm, FinalTerm {
public:
    Quiz quiz;
    Assignment ass;
    Midterm mid;
    FinalTerm final;
    float total;


public:

    Grade();
    Grade(Quiz q, Assignment a, Midterm m, FinalTerm f);

    void print_grades();
};

class attendence {
private:
    char* attend;
    int total;
    int size;

public:
    attendence();
    attendence(int creditt, char* attendd);

    void set_attendence(int i);
    void print_attendence();
    void put_attendence();
    char get_attendence(char press);
    void change_attendence();
};

class courses {
private:
    string course;
    string course_c;
    int credit;

public:
    courses();
    courses(string name, string code, int creditt);
    courses(const courses& obj);

    void setcourse_name(string& name);
    void setcourse_code(string& code);
    void setcredit(int& creditt);

    string getcourse_name();
    string getcourse_code();
    int getcredit();
    void print_course();
};
void delete_note(string id);
class person {
public:
    int age;
    string f_name;
    string l_name;
    string id;
    int size;
    int note_s;
    string* notes;
    string section;

public:
    person();
    person(const string& first_name, const string& last_name, int agee, string sectionn, string idd);
    void add_notes(string note);
    void getnotes();
    string getFirstName() const;
    string getsection() const;
    string getLastName() const;
    int getAge() const;
    string getid() const;
    void setFirstName(const string& first_name);
    void setid(const string& idd);
    void setsection(const string& sectionn);
    void setLastName(const string& last_name);
    void setAge(int age_);
    virtual void print();
    ~person();
};
class admin :public person
{
public:
    admin();
    void update_profile(admin& Admin);
    void load_profile();
    friend ostream& operator<<(ostream& os, const admin& obj);
    friend istream& operator>>(istream& is, admin& obj);
};
class alldetail : public courses {
    courses course;
    attendence attend;
    Grade grade;
    int num;

public:
    alldetail();

    alldetail(courses coursee, attendence attendd, Grade gradee, int numm = 0);
    void print_alldetail();
};

class student : public person {
private:
    alldetail* g1;
    int size;

public:
    student();
    student(const string& first_name, const string& last_name, int agee, alldetail temp, string sectionn, string id);
    void add_data(alldetail add);
    void print() override;
    void print_data();
    ~student();
    void add_detail(alldetail detail_data);
};

class under_g : public student {
private:
    string status;

public:

    under_g(const string& f_name, const string& l_name, int age, alldetail temp, string sectionn, string id, string proj);
    string getfyp();
    void setthesis(string& fyp);
    void print() override;
    ~under_g();
};

class ex_student : public student {
public:
    ex_student(const string& f_name, const string& l_name, int age, alldetail temp, string sectionn, string id, string proj);
    void print() override;
    ~ex_student();
};


class faculty : public person {
private:
    int ext;
    courses course;
    string filename = "";

public:
    faculty(const string& filename) : filename(filename) {};
    faculty();
    faculty(const string& first_name, const string& last_name, int agee, const string& sectionn, const string& id, int extt, const courses& coursee);
    int getext();
    void operator--();
    void operator++();
    void setcourse(int extt);
    void print() override;
    ~faculty();
};

string processTeachers(const string& facultyId, string& section, string& pass);
//bool CredentialManager<typestring>::loginfunction(typestring username, typestring password);

void processStudents(const string& section, const string& coursecode, int& studentcount, student* students[]);

//student_profile


void student_profile(string id_no, int num, string& pass);

//add students


void add_students();

//see data


void see_data(string sec, string roll_no);


//student remove


void remove_student();

//update students

void update_student();


//teacher data


void addTeacher();


void removeTeacherById(const string& filename, const string& idToRemove);
void displayTeacherInfo();
void updateTeacherData(const string& filename, const string& idtoupdate);


//faculty_duty


void faculty_duty(string sect, string roll_no, int num);
void see_ex_students();
void search_id(string& id);
bool check_id(string id);

void text_colour(int color);
void start();
bool getIntInput(int& num);
bool getIntInput(int& num);
string printDateTime();