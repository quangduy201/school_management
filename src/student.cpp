#ifndef STUDENT_CPP
#define STUDENT_CPP

#include "define.cpp"

void readStudents(vector <Student> &s) {
    FILE *f = fopen("student.dat", "rb");
    if (f == NULL) {
        fclose(f);
        return;
    }
    int i = 0;
    s.resize(maxn);
    fread(&s[0], sizeof(s[0]), 1, f);
    while (!feof(f)) {
        if (++i == maxn) {
            cout << RED << "The maximum number of students is " << maxn << RESET << endl;
            break;
        }
        fread(&s[i], sizeof(s[i]), 1, f);
    }
    s.resize(i);
    fclose(f);
}
void writeStudents(vector <Student> &s) {
    FILE *f = fopen("student.dat", "wb");
    if (f == NULL) {
        fclose(f);
        return;
    }
    for (auto &i : s)
        fwrite(&i, sizeof(i), 1, f);
    fclose(f);
}
void inputStudent(Student &s) {
    do {
        cout << "Name      : "; fflush(stdin); getline(cin, name);
        flag = 0;
        if (name.size() > 32) {
            cout << RED << "Name must be less than 32 characters!  " << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        if (name.size() < 2) {
            cout << RED << "Name must be at least 2 characters!    " << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        for (char &c: name) {
            if (special.find(c) != string::npos || number.find(c) != string::npos) {
                cout << RED << "Name cannot contain special characters!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                break;
            }
        }
    } while (flag);
    cout << ERASE;
    do {
        cout << "Age       : "; fflush(stdin); getline(cin, age);
        flag = 0;
        if (age.size() > 3 || age.size() < 2) {
            cout << RED << "Age only accept 2 digits!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        for (int i = 0; i < age.size(); i++) {
            if (i == 0 && age[0] == '-') {
                flag = -1;
                continue;
            }
            if (special.find(age[i]) != string::npos || alpha.find(age[i]) != string::npos || age[i] == ' ') {
                cout << RED << "Age must be a number!    " << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                break;
            }
        }
        if (flag == -1)
            cout << RED << "Age must be positive!    " << MOVEUP << ERASE << "\r" << RESET;
        else if (!flag && stoi(age) > 40) {
            cout << RED << "Age must be less than 40!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
        }
        else if (!flag && stoi(age) <= 16) {
            cout << RED << "Age must be over 16!     " << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
        }
    } while (flag);
    cout << ERASE;
    do {
        cout << "ID        : "; fflush(stdin); getline(cin, id);
        flag = 0;
        if (id.size() == 0) {
            cout << RED << "ID must be at least 1 character!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        if (id.size() > 12) {
            cout << RED << "ID must be less than 12 characters!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        for (char &c: id) {
            if (special.find(c) != string::npos || alpha.find(c) != string::npos || c == ' ') {
                cout << RED << "ID only contains number characters!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                break;
            }
        }
    } while (flag);
    cout << ERASE;
    do {
        cout << setw(20) << "(M|F)" << "\rGender    : "; fflush(stdin); getline(cin, gender);
        flag = 0;
        if (gender == "M" || gender == "F" || gender == "m" || gender == "f")
            break;
        else {
            cout << RED << "Gender must be M (Male) or F (Female)!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
        }
    } while (flag);
    cout << ERASE;
    do {
        cout << "Phone     : "; fflush(stdin); getline(cin, phone);
        flag = 0;
        if (phone.size() < 10) {
            cout << RED << "Phone number cannot have less than 10 digits!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        if (phone.size() > 12) {
            cout << RED << "Phone number cannot have more than 12 digits!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        for (char &c: phone) {
            if (special.find(c) != string::npos || alpha.find(c) != string::npos) {
                cout << RED << "Phone number only contains number characters!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                break;
            }
        }
    } while (flag);
    cout << ERASE;
    do {
        cout << "Mid-term  : "; fflush(stdin); getline(cin, midterm);
        int count = 0;
        flag = 0;
        if (midterm.size() < 1) {
            cout << RED << "Midterm score cannot have less than 1 digit!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        if (midterm.size() > 5) {
            cout << RED << "Midterm score cannot have more than 5 digits!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        for (int i = 0; i < midterm.size(); i++) {
            if (i == 0 && midterm[0] == '-') {
                flag = -1;
                continue;
            }
            if (dot.find(midterm[i]) != string::npos || alpha.find(midterm[i]) != string::npos || midterm[i] == ' ') {
                cout << ERASE << RED << "Midterm must be a number!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                break;
            }
            if (midterm[i] == '.')
                count++;
            if (count > 1) {
                cout << ERASE << RED << "Midterm must be a number!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                break;
            }
        }
        if (flag == -1)
            cout << ERASE << RED << "Midterm must be positive!" << MOVEUP << ERASE << "\r" << RESET;
        else if (!flag && stod(midterm) > 10) {
            cout << ERASE << RED << "Midterm cannot be more than 10!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
        }
    } while (flag);
    cout << ERASE;
    do {
        cout << "Final exam: "; fflush(stdin); getline(cin, finalexam);
        int count = 0;
        flag = 0;
        if (finalexam.size() < 1) {
            cout << RED << "Final exam score cannot have less than 1 digit!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        if (finalexam.size() > 5) {
            cout << RED << "Final exam score cannot have more than 5 digits!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        for (int i = 0; i < finalexam.size(); i++) {
            if (i == 0 && finalexam[0] == '-') {
                flag = -1;
                continue;
            }
            if (dot.find(finalexam[i]) != string::npos || alpha.find(finalexam[i]) != string::npos || finalexam[i] == ' ') {
                cout << ERASE << RED << "Final exam score must be a number!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                break;
            }
            if (finalexam[i] == '.')
                count++;
            if (count > 1) {
                cout << ERASE << RED << "Midterm must be a number!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                break;
            }
        }
        if (flag == -1)
            cout << ERASE << RED << "Final exam score must be positive!" << MOVEUP << ERASE << "\r" << RESET;
        else if (!flag && stod(finalexam) > 10) {
            cout << ERASE << RED << "Final exam score cannot be more than 10!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
        }
    } while (flag);
    cout << ERASE;
    // * write students' information to file
    grade = s.setGrade(stod(midterm), stod(finalexam));
    strcpy(s.name, name.c_str()); strcpy(s.id, id.c_str()); strcpy(s.phone, phone.c_str());
    s.age = stoi(age); s.gender = toupper(gender[0]); s.midterm = stod(midterm);
    s.finalexam = stod(finalexam); s.grade = s.setGrade(s.midterm, s.finalexam);
}
void inputStudents(vector <Student> &s, int a) {
    FILE *f;
    // * Input students
    if (!a) {
        s.clear();
        f = fopen("student.dat", "wb");
    }
    // * Append students
    else {
        f = fopen("student.dat", "ab");
    }
    do {
        cout << "Enter number of students: "; fflush(stdin); getline(cin, n);
        flag = 0;
        if (n.length() == 0) {
            cout << RED << "You must enter a number" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        for (char &c : n) {
            if (special.find(c) != string::npos || alpha.find(c) != string::npos || c == ' ') {
                cout << RED << "Invalid input!         " << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                break;
            }
        }
    } while (flag);
    cout << ERASE;
    s.resize(s.size() + stoi(n));
    for (int i = s.size() - stoi(n); i < s.size(); i++) {
        cout << "\tStudent " << i+1 << ":\n";
        inputStudent(s[i]);
        fwrite(&s[i], sizeof(s[i]), 1, f);
    }
    fclose(f);
}
void editStudent(Student &s) {
    isVisibleCursor(0);
    inputStudent(s);
    isVisibleCursor(1);
}
int outputStudents(vector <Student> &s) {
    int pointer = 0, last_pointer = 0;
    int pointer_page = 0, last_pointer_page = 0;
    int num_page = s.size() / 60 + 1, flag = 1, changed = 0;
    char key = 1;
    string page[num_page];
    for (int i = 0; i < num_page; i++)
        page[i] = " " + to_string(i + 1) + " ";
    while (1) {
        string students_name[s.size()];
        for (int i = 0; i < s.size(); i++) {
            students_name[i] = s[i].name;
            students_name[i] = " " + students_name[i] + " ";
        }
        num_page = s.size() / 60 + 1;
        if (clrscr[3]) {
            system("cls");
            cout << CYAN << "SCHOOL MANAGEMENT : START : STUDENT : OUTPUT" << RESET << endl;
            textBox(81, 24, 19, 3, "");
            gotoXY(82, 25);
            cout << "Press ESC to back";
            if (s.size() / 60 > 0) {
                textBox(75, 27, 26, 3, "");
                gotoXY(76, 28);
                cout << "Press Tab to select page";
                button(page, pointer_page, last_pointer_page, num_page, 1, 40 - num_page*3/2, 26, 0, flag);
                flag = 1;
            }
            clrscr[3] = 0;
        }
        while (1) {
            if (s.size() != 0)
                button2d(students_name, pointer, s.size(), pointer_page, last_pointer, num_page, 1, 15, 4, flag);
            key = getKey();
            last_pointer = pointer;
            access2dPointer(key, pointer, s.size(), pointer_page, num_page);
            if (key == 32 || key == 13) {
                clrscr[4] = 1; flag = 1;
                int pointerCV = 0, last_pointerCV = 0;
                string CV[2] = {"       EDIT      ",
                                "      DELETE     "};
                while (1) {
                    if (clrscr[4]) {
                        system("cls");
                        if (s.size() == 0)
                            drawCV(Teacher(), Student(), 1);
                        else {
                            drawCV(Teacher(), s[pointer + pointer_page*60], 1);
                            textBox(31, 26, 19, 3, "");
                            textBox(51, 26, 19, 3, "");
                        }
                        clrscr[4] = 0;
                    }
                    if (s.size() != 0)
                        button(CV, pointerCV, last_pointerCV, 2, 17, 32, 27, 0, flag);
                    key = getKey();
                    last_pointerCV = pointerCV;
                    accessPointer(key, pointerCV, 2, 0);
                    if (s.size() != 0 && (key == 32 || key == 13)) {
                        if (pointerCV == 0) {
                            gotoXY(1, 29);
                            editStudent(s[pointer + pointer_page*60]);
                            clrscr[4] = 1;
                            flag = 1;
                            changed = 1;
                            student_temp.push_back(s[pointer + pointer_page*60]);
                            student_pos_temp.push_back(pointer + pointer_page*60);
                        }
                        else if (pointerCV == 1) {
                            s.erase(s.begin() + pointer + pointer_page*60);
                            key = 27;
                            clrscr[3] = 1;
                            flag = 1;
                            changed = 1;
                            student_temp.push_back(Student());
                            student_pos_temp.push_back(pointer + pointer_page*60);
                            break;
                        }
                    }
                    if (key == 27) {
                        clrscr[3] = 1;
                        flag = 1;
                        system("cls");
                        break;
                    }
                }
            }
            else if (key == 9 || key == 27)
                break;
            if (key == 27) {
                key = 32;
                clrscr[3] = 1;
                flag = 1;
                break;
            }
        }
        if (key == 32 || key == 13 || (s.size() < 60 && key == 9)) continue;
        if (key == 27) {
            pointer = 2;
            key = 1;
            clrscr[2] = 1;
            break;
        }
        while (1) {
            button(page, pointer_page, last_pointer_page, num_page, 1, 40 - num_page*3/2, 26, 0, flag);
            key = getKey();
            last_pointer_page = pointer_page;
            accessPointer(key, pointer_page, num_page, 0);
            if (key == 9 || key == 13 || key == 27 || key == 32) {
                gotoXY(1, 4);
                for (int i = 0; i < 20; i++)
                    cout << ERASE << endl;
                flag = 1;
                break;
            }
        }
        if (key == 27) {
            pointer = 2;
            key = 1;
            clrscr[2] = 1;
            break;
        }
    }
    if (changed) {
        writeStudents(s);
        return 1;
    }
    return 0;
}
void findStudents(vector <Student> &s, int a) {
    isVisibleCursor(1);
    vector <Student> students;
    // * Find students by ID
    if (!a) {
        do {
            cout << "Enter ID: "; fflush(stdin); getline(cin, id);
            flag = 0;
            if (id.size() == 0) {
                students = s;
                for (int i = 0; i < s.size(); i++)
                    temp.push_back(i);
                break;
            }

            if (id.size() > 12) {
                cout << RED << "ID must be less than 12 characters!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                continue;
            }
            for (char &c: id) {
                if (special.find(c) != string::npos || alpha.find(c) != string::npos || c == ' ') {
                    cout << RED << "ID only contains number characters!" << MOVEUP << ERASE << "\r" << RESET;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            for (int i = 0; i < s.size(); i++) {
                string student_id = s[i].id;
                if (student_id.find(id) != string::npos) {
                    students.push_back(s[i]);
                    temp.push_back(i);
                }
            }
            if (students.size() == 0) {
                cout << ERASE << RED << "ID not found!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
            }
        } while (flag);
        cout << ERASE;
    }
    // * Find students by name
    else if (a == 1) {
        do {
            cout << "Enter name: "; fflush(stdin); getline(cin, name);
            flag = 0;
            if (name.size() == 0) {
                students = s;
                for (int i = 0; i < s.size(); i++)
                    temp.push_back(i);
                break;
            }
            if (name.size() > 32) {
                cout << RED << "Name must be less than 32 characters!  " << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                continue;
            }
            if (name.size() < 3) {
                cout << RED << "Name must be at least 3 characters!    " << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                continue;
            }
            for (char &c: name) {
                if (special.find(c) != string::npos || number.find(c) != string::npos) {
                    cout << RED << "Name cannot contain special characters!" << MOVEUP << ERASE << "\r" << RESET;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                continue;
            for (int i = 0; i < s.size(); i++) {
                string students_name = s[i].name;
                transform(students_name.begin(), students_name.end(), students_name.begin(), ::toupper);
                transform(name.begin(), name.end(), name.begin(), ::toupper);
                if (students_name.find(name) != string::npos) {
                    students.push_back(s[i]);
                    temp.push_back(i);
                }
            }
            if (students.size() == 0) {
                cout << ERASE << RED << "Name not found!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
            }
        } while (flag);
        cout << ERASE;
    }
    // * Find students by grade
    else if (a == 2) {
        string grade, students_grade;
        do {
            cout << setw(30) << "(A,B,C,D,F)" << "\rEnter grade: "; fflush(stdin); getline(cin, grade);
            flag = 0;
            if (grade.size() == 0) {
                students = s;
                for (int i = 0; i < s.size(); i++)
                    temp.push_back(i);
                break;
            }
            else if (grade.size() > 1)
                flag = 1;
            else {
                if (!isalpha(grade[0]))
                    flag = 1;
                else {
                    grade[0] = toupper(grade[0]);
                    if (grade[0] != 'A' && grade[0] != 'B' && grade[0] != 'C' && grade[0] != 'D' && grade[0] != 'F')
                        flag = 1;
                }
            }
            if (flag) {
                cout << RED << "Grade must be A, B, C, D or F!" << MOVEUP << ERASE << "\r" << RESET;
                continue;
            }
            for (int i = 0; i < s.size(); i++) {
                if (s[i].grade == grade[0]) {
                    students.push_back(s[i]);
                    temp.push_back(i);
                }
            }
            if (students.size() == 0) {
                cout << ERASE << RED << "Grade not found!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
            }
        } while (flag);
        cout << ERASE;
    }
    isVisibleCursor(0);
    if (outputStudents(students)) {
        for (int i = 0; i < student_pos_temp.size(); i++) {
            if (strcmp(student_temp[i].name, "NA") == 0 && strcmp(student_temp[i].id, "NA") == 0 && strcmp(student_temp[i].phone, "NA") == 0
                && student_temp[i].age == 0 && student_temp[i].midterm == 0 && student_temp[i].finalexam == 0
                && student_temp[i].gender == 'U' && student_temp[i].grade == 'U') {
                s.erase(s.begin() + temp[student_pos_temp[i]]);
                temp.erase(temp.begin() + student_pos_temp[i]);
                for (auto &i : temp)
                    i--;
            }
            else {
                s[temp[student_pos_temp[i]]].age = student_temp[i].age;
                s[temp[student_pos_temp[i]]].gender = student_temp[i].gender;
                s[temp[student_pos_temp[i]]].midterm = student_temp[i].midterm;
                s[temp[student_pos_temp[i]]].finalexam = student_temp[i].finalexam;
                s[temp[student_pos_temp[i]]].grade = student_temp[i].grade;
                strcpy(s[temp[student_pos_temp[i]]].name, student_temp[i].name);
                strcpy(s[temp[student_pos_temp[i]]].id, student_temp[i].id);
                strcpy(s[temp[student_pos_temp[i]]].phone, student_temp[i].phone);
            }
        }
        writeStudents(s);
        temp.clear();
        student_temp.clear();
        student_pos_temp.clear();
    }
}
bool compareIDStudent(const Student &a, const Student &b) {
    return atoll(a.id) < atoll(b.id);
}
bool compareNameStudent(Student a, Student b) {
    string name_a = a.name, name_b = b.name;
    transform(name_a.begin(), name_a.end(), name_a.begin(), ::toupper);
    transform(name_b.begin(), name_b.end(), name_b.begin(), ::toupper);
    string temp_a = name_a, temp_b = name_b;
    if (name_a.find_last_of(' ') != string::npos)
        temp_a = name_a.substr(name_a.find_last_of(' ') + 1);
    if (name_b.find_last_of(' ') != string::npos)
        temp_b = name_b.substr(name_b.find_last_of(' ') + 1);
    return temp_a == temp_b ? name_a < name_b : temp_a < temp_b;
}
bool compareGradeStudent(Student a, Student b) {
    return a.grade == b.grade ? a.midterm + a.finalexam > b.midterm + b.finalexam : a.grade < b.grade;
}
void sortStudents(vector <Student> s, int a) {
    // * Sort students by ID
    if (!a)
        stable_sort(s.begin(), s.end(), compareIDStudent);
    // * Sort students by name
    else if (a == 1)
        stable_sort(s.begin(), s.end(), compareNameStudent);
    // * Sort students by grade
    else if (a == 2)
        stable_sort(s.begin(), s.end(), compareGradeStudent);
    outputStudents(s);
}
void removeStudents(vector <Student> &s) {
    FILE *f = fopen("student.dat", "wb");
    fclose(f);
    s.clear();
    cout << RED << "Removed all students!" << RESET << endl;
    return;
}

#endif