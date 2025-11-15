#include<iostream>
#include <windows.h>
#include"project.h"
#include <stdexcept>
#include <limits>
#include <iomanip>
using namespace std;


//to login as admin
//username= admin
//pass = admin
//to login as a teacher or student check credentials file



int main()
{
    /*start();
    Sleep(5000);*/


    while (true) {
        system("cls");
        text_colour(9);

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
            << "\t\t\t\t\t\t\t\t|   Welcome to Student       |\n"
            << "\t\t\t\t\t\t\t\t|   Management System        |\n"
            << "\t\t\t\t\t\t\t\t==============================\n"
            << "\t\t\t\t\t\t\t\t|  Enter 1 for admin         |\n"
            << "\t\t\t\t\t\t\t\t|  Enter 2 for faculty       |\n"
            << "\t\t\t\t\t\t\t\t|  Enter 3 for student       |\n"
            << "\t\t\t\t\t\t\t\t|  Enter 4 to leave          |\n"
            << "\t\t\t\t\t\t\t\t==============================\n";


        int login;
        //cin >> login;
        try
        {
            if (getIntInput(login)) {
                if (login > 1 && login < 5) {
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


        text_colour(15);
        switch (login) {
        case 1: {
            text_colour(10);
            system("cls");
            cout << "enter your username: ";
            string id, pass;
            cin >> id;
            cout << "enter you password: ";
            cin >> pass;
            passwordMAnagar<string> manager;
            string username = id;
            string password = pass;
            bool check = false;
            check = manager.loginfunction(username, password);
            while (check == false) {
                if (!check) {
                    cout << "wrong pass or username." << endl;
                }
                cout << "enter username: ";
                cin >> username;
                cout << "enter password: ";
                cin >> password;
                check = manager.loginfunction(username, password);

            }
            system("cls");

            while (true) {

                admin Admin;
                cin >> Admin;

                int choice = 0;


                cout << "\n\n\n\t\t\t\t\t\t\t\t|================================|\n"
                    << "\t\t\t\t\t\t\t\t|   hello Mr." << Admin.getFirstName() << "               | \n"
                    << "\t\t\t\t\t\t\t\t|   What do you want to do?      |\n"
                    << "\t\t\t\t\t\t\t\t|================================|\n"
                    << "\t\t\t\t\t\t\t\t|  1. Add student                |\n"
                    << "\t\t\t\t\t\t\t\t|  2. See all data of students   |\n"
                    << "\t\t\t\t\t\t\t\t|  3. Remove student             |\n"
                    << "\t\t\t\t\t\t\t\t|  4. Update student             |\n"
                    << "\t\t\t\t\t\t\t\t|  5. See teachers list          |\n"
                    << "\t\t\t\t\t\t\t\t|  6. Add teacher                |\n"
                    << "\t\t\t\t\t\t\t\t|  7. Remove teacher             |\n"
                    << "\t\t\t\t\t\t\t\t|  8. Update teacher data        |\n"
                    << "\t\t\t\t\t\t\t\t|  9. expel/left students list   |\n"
                    << "\t\t\t\t\t\t\t\t| 10. update your profile        |\n"
                    << "\t\t\t\t\t\t\t\t| 11. print your data            |\n"
                    << "\t\t\t\t\t\t\t\t| 12. Get Notes                  |\n"
                    << "\t\t\t\t\t\t\t\t| 13. Send Notes                 |\n"
                    << "\t\t\t\t\t\t\t\t| 14. Update password.           |\n"
                    << "\t\t\t\t\t\t\t\t| 14. update student?faculty pass|\n"
                    << "\t\t\t\t\t\t\t\t| 15. Exit                       |\n"
                    << "\t\t\t\t\t\t\t\t|================================|\n";


                try
                {

                    if (getIntInput(choice)) {
                        if (choice > 1 && choice < 14) {
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
                    add_students();
                }
                else if (choice == 2) {
                    see_data("", "");
                }
                else if (choice == 3) {
                    remove_student();
                }
                else if (choice == 4) {
                    update_student();
                }
                else if (choice == 5) {
                  /*  string name;
                    cout << "Enter the id of the teacher: ";
                    cin >> name;*/
                    displayTeacherInfo();
                }
                else if (choice == 6) {
                    faculty add("teacher_data.txt");
                    ++add;
                }
                else if (choice == 7) {
                    string filename = "teacher_data.txt";
                    faculty remover("teacher_data.txt");
                    --remover;
                }
                else if (choice == 8) {
                    string id;
                    string filename = "teacher_data.txt";
                    cout << "Enter the id of the teacher you want to update data: ";
                    cin >> id;
                    updateTeacherData(filename, id);
                }
                else if (choice == 9) {
                    see_ex_students();
                }
                else if (choice == 10)
                {
                    Admin.update_profile(Admin);
                }
                else if (choice == 11) {
                    Admin.print();
                }
                else if (choice == 12) {
                    cout << Admin;

                }
                else if (choice == 13)
                {
                    send_notes(Admin.getid());
                }
                else if (choice==14) {
                    passwordMAnagar<string> manager;
                    string id;
                    cout << "Enter your id:";
                    cin >> id;
                    string newpassword;
                    cout << "Enter new password: ";
                    cin >> newpassword;


                    if (manager.updatepassword(id, newpassword)) {
                        cout << "pass changed successful." << endl;
                    }
                }
                else if (choice == 15) {
                    passwordMAnagar<string> manager;
                    string id;
                    cout << "enter id of faculty/student :";
                    cin >> id;
                    string newpassword;
                    cout << "enter new password: ";
                    cin >> newpassword;


                    if (manager.updatepassword(id, newpassword)) {
                        cout << "pass changed successful." << endl;
                    }
                }

                else if (choice == 16) {
                    break;
                }
                else {
                    cout << "Invalid choice!\n";

                }



                cout << "Do you want to do something else? (y/n): ";
                char answer;
                cin >> answer;
                system("cls");
                if (answer != 'y' && answer != 'Y')
                    break;
            }
            break;
        }

              text_colour(15);
        case 2:
        {
            text_colour(10);
            system("cls");
            cout << "enter your username: ";
            string id, pass;
            cin >> id;
            cout << "enter you password: ";
            cin >> pass;
            passwordMAnagar<string> manager;
            string username = id;
            string password = pass;
            bool check = false;
            check = manager.loginfunction(username, password);
            while (check == false) {
                if (!check) {
                    cout << "wrong pass or username." << endl;
                }
                cout << "enter username: ";
                cin >> username;
                cout << "enter password: ";
                cin >> password;
                check = manager.loginfunction(username, password);

            }



            string section = "";

            string code = processTeachers(id, section, pass);

            see_data(section, code);
            while (true)
            {
                cin.ignore();
                system("cls");

                int press = 0;
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t==============================\n"
                    << "\t\t\t\t\t\t\t\t|   What do you want to do?   |\n"
                    << "\t\t\t\t\t\t\t\t==============================\n"
                    << "\t\t\t\t\t\t\t\t|  1. Add attendance          |\n"
                    << "\t\t\t\t\t\t\t\t|  2. Add grades              |\n"
                    << "\t\t\t\t\t\t\t\t|  3. Search student with id  |\n"
                    << "\t\t\t\t\t\t\t\t==============================\n"
                    << "Enter your choice: ";
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


                faculty_duty(section, code, press);
                cout << "Do you want to do something else? (y/n): ";
                char answer;
                cin >> answer;
                if (answer != 'y' && answer != 'Y')
                    break;
            }


            break;
        }
        text_colour(15);
        case 3:
        {
            text_colour(10);
            system("cls");
            cout << "enter your username: ";
            string id, pass;
            cin >> id;
            cout << "enter you password: ";
            cin >> pass;
            passwordMAnagar<string> manager; // Instantiating with string type
            string username = id;
            string password = pass;
            bool check = false;
            check = manager.loginfunction(username, password);
            while (check == false) {
                if (!check) {
                    cout << "wrong pass or username." << endl;
                }
                cout << "enter username: ";
                cin >> username;
                cout << "enter password: ";
                cin >> password;
                check = manager.loginfunction(username, password);

            }
            system("cls");




            int num = 0;
            student_profile(id, num, pass);
            break;

            break;
        }


        case 4:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";

        }
    }
    text_colour(15);

    return 0;
}


template<class typestring>
bool passwordMAnagar<typestring>::loginfunction(typestring username, typestring password) {
    text_colour(12);
    ifstream file("credentials.txt");
    typestring storedUsername, storedPassword;

    if (!file) {
        cerr << "Error: Unable to open file." << endl;
        return false;
    }

    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}