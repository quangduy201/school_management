#ifndef TEACHER_CPP
#define TEACHER_CPP

#include "define.cpp"

void readTeachers(vector <Teacher> &t) {
    FILE *f = fopen("teacher.dat", "rb");
    if (f == NULL) {
        fclose(f);
        return;
    }
    int i = 0;
    t.resize(maxn);
    fread(&t[0], sizeof(t[0]), 1, f);
    while (!feof(f)) {
        if (++i == maxn) {
            cout << RED << "The maximum number of teachers is " << maxn << RESET << endl;
            break;
        }
        fread(&t[i], sizeof(t[i]), 1, f);
    }
    t.resize(i);
    fclose(f);
}
void writeTeachers(vector <Teacher> &t) {
    FILE *f = fopen("teacher.dat", "wb");
    if (f == NULL) {
        fclose(f);
        return;
    }
    for (auto &i : t)
        fwrite(&i, sizeof(i), 1, f);
    fclose(f);
}
void inputTeacher(Teacher &t) {
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
        cout << "Salary    : "; fflush(stdin); getline(cin, salary);
        flag = 0;
        if (salary.size() < 1) {
            cout << RED << "Salary cannot be empty!                " << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        if (salary.size() > 18) {
            cout << RED << "Salary cannot have more than 18 digits!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        for (int i = 0; i < salary.size(); i++) {
            if (i == 0 && salary[0] == '-') {
                flag = -1;
                continue;
            }
            if (special.find(salary[i]) != string::npos || alpha.find(salary[i]) != string::npos || salary[i] == ' ') {
                cout << ERASE << RED << "Salary must be a number!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                break;
            }
        }
        if (flag == -1)
            cout << ERASE << RED << "Salary must be positive!" << MOVEUP << ERASE << "\r" << RESET;
    } while (flag);
    cout << ERASE;
    do {
        cout << "Bonus     : "; fflush(stdin); getline(cin, bonus);
        flag = 0;
        if (bonus.size() < 1) {
            cout << RED << "Bonus cannot be empty!                " << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        if (bonus.size() > 18) {
            cout << RED << "Bonus cannot have more than 18 digits!" << MOVEUP << ERASE << "\r" << RESET;
            flag = 1;
            continue;
        }
        for (int i = 0; i < bonus.size(); i++) {
            if (i == 0 && bonus[0] == '-') {
                flag = -1;
                continue;
            }
            if (special.find(bonus[i]) != string::npos || alpha.find(bonus[i]) != string::npos || bonus[i] == ' ') {
                cout << RED << "Bonus must be a number!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                break;
            }
        }
        if (flag == -1)
            cout << RED << "Bonus must be positive!" << MOVEUP << ERASE << "\r" << RESET;
    } while (flag);
    cout << ERASE;
    // * write teachers' information to file
    total = stoll(salary, NULL, 10) + stoll(bonus, NULL, 10);
    strcpy(t.name, name.c_str()); strcpy(t.id, id.c_str()); strcpy(t.phone, phone.c_str());
    t.age = stoi(age); t.gender = toupper(gender[0]); t.salary = stoll(salary, NULL, 10);
    t.bonus = stoll(bonus, NULL, 10); t.total = t.setTotal(t.salary, t.bonus);
}
void inputTeachers(vector <Teacher> &t, int a) {
    FILE *f;
    // * Input teachers
    if (!a) {
        t.clear();
        f = fopen("teacher.dat", "wb");
    }
    // * Append teachers
    else {
        f = fopen("teacher.dat", "ab");
    }
    do {
        cout << "Enter number of teachers: "; fflush(stdin); getline(cin, n);
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
    t.resize(t.size() + stoi(n));
    for (int i = t.size() - stoi(n); i < t.size(); i++) {
        cout << "\tTeacher " << i+1 << ":\n";
        inputTeacher(t[i]);
        fwrite(&t[i], sizeof(t[i]), 1, f);
    }
    fclose(f);
}
void editTeacher(Teacher &t) {
    isVisibleCursor(1);
    inputTeacher(t);
    isVisibleCursor(0);
}
int outputTeachers(vector <Teacher> t) {
    int pointer = 0, last_pointer = 0;
    int pointer_page = 0, last_pointer_page = 0;
    int num_page = t.size() / 60 + 1, flag = 1, changed = 0;
    char key = 1;
    string page[num_page];
    for (int i = 0; i < num_page; i++)
        page[i] = " " + to_string(i + 1) + " ";
    while (1) {
        string teachers_name[t.size()];
        for (int i = 0; i < t.size(); i++) {
            teachers_name[i] = t[i].name;
            teachers_name[i] = " " + teachers_name[i] + " ";
        }
        num_page = t.size() / 60 + 1;
        if (clrscr[3]) {
            system("cls");
            cout << CYAN << "SCHOOL MANAGEMENT : START : TEACHER : OUTPUT" << RESET << endl;
            textBox(81, 24, 19, 3, "");
            gotoXY(82, 25);
            cout << "Press ESC to back";
            if (t.size() / 60 > 0) {
                textBox(75, 27, 26, 3, "");
                gotoXY(76, 28);
                cout << "Press Tab to select page";
                button(page, pointer_page, last_pointer_page, num_page, 1, 40 - num_page*3/2, 26, 0, flag);
                flag = 1;
            }
            clrscr[3] = 0;
        }
        while (1) {
            if (t.size() != 0)
                button2d(teachers_name, pointer, t.size(), pointer_page, last_pointer, num_page, 1, 15, 4, flag);
            key = getKey();
            last_pointer = pointer;
            access2dPointer(key, pointer, t.size(), pointer_page, num_page);
            if (key == 32 || key == 13) {
                clrscr[4] = 1; flag = 1;
                int pointerCV = 0, last_pointerCV = 0;
                string CV[2] = {"       EDIT      ",
                                "      DELETE     "};
                while (1) {
                    if (clrscr[4]) {
                        system("cls");
                        if (t.size() == 0)
                            drawCV(Teacher(), Student(), 0);
                        else {
                            drawCV(t[pointer + pointer_page*60], Student(), 0);
                            textBox(31, 26, 19, 3, "");
                            textBox(51, 26, 19, 3, "");
                        }
                        clrscr[4] = 0;
                    }
                    if (t.size() != 0)
                        button(CV, pointerCV, last_pointerCV, 2, 17, 32, 27, 0, flag);
                    key = getKey();
                    last_pointerCV = pointerCV;
                    accessPointer(key, pointerCV, 2, 0);
                    if (t.size() != 0 && (key == 32 || key == 13)) {
                        if (pointerCV == 0) {
                            gotoXY(1, 29);
                            editTeacher(t[pointer + pointer_page*60]);
                            clrscr[4] = 1;
                            flag = 1;
                            changed = 1;
                            teacher_temp.push_back(t[pointer + pointer_page*60]);
                            teacher_pos_temp.push_back(pointer + pointer_page*60);
                        }
                        else if (pointerCV == 1) {
                            t.erase(t.begin() + pointer + pointer_page*60);
                            key = 27;
                            clrscr[3] = 1;
                            flag = 1;
                            changed = 1;
                            teacher_temp.push_back(Teacher());
                            teacher_pos_temp.push_back(pointer + pointer_page*60);
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
        if (key == 32 || key == 13 || (t.size() < 60 && key == 9)) continue;
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
        writeTeachers(t);
        return 1;
    }
    return 0;
}
void findTeachers(vector <Teacher> &t, int a) {
    isVisibleCursor(1);
    vector <Teacher> teachers;
    // * Find teachers by ID
    if (!a) {
        do {
            cout << "Enter ID: "; fflush(stdin); getline(cin, id);
            flag = 0;
            if (id.size() == 0) {
                teachers = t;
                for (int i = 0; i < t.size(); i++)
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
            for (int i = 0; i < t.size(); i++) {
                string teacher_id = t[i].id;
                if (teacher_id.find(id) != string::npos) {
                    teachers.push_back(t[i]);
                    temp.push_back(i);
                }
            }
            if (teachers.size() == 0) {
                cout << ERASE << RED << "ID not found!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
            }
        } while (flag);
        cout << ERASE;
    }
    // * Find teachers by name
    else if (a == 1) {
        do {
            cout << "Enter name: "; fflush(stdin); getline(cin, name);
            flag = 0;
            if (name.size() == 0) {
                teachers = t;
                for (int i = 0; i < t.size(); i++)
                    temp.push_back(i);
                break;
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
            for (int i = 0; i < t.size(); i++) {
                string teachers_name = t[i].name;
                transform(teachers_name.begin(), teachers_name.end(), teachers_name.begin(), ::toupper);
                transform(name.begin(), name.end(), name.begin(), ::toupper);
                if (teachers_name.find(name) != string::npos) {
                    teachers.push_back(t[i]);
                    temp.push_back(i);
                }
            }
            if (teachers.size() == 0) {
                cout << ERASE << RED << "Name not found!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
            }
        } while (flag);
        cout << ERASE;
    }
    // * Find teachers by income
    else if (a == 2) {
        string total, teachers_income;
        do {
            cout << "Total income: "; fflush(stdin); getline(cin, total);
            flag = 0;
            if (total.size() == 0) {
                teachers = t;
                for (int i = 0; i < t.size(); i++)
                    temp.push_back(i);
                break;
            }
            if (total.size() > 18) {
                cout << RED << "Total income cannot have more than 18 digits!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
                continue;
            }
            for (int i = 0; i < total.size(); i++) {
                if (i == 0 && total[0] == '-') {
                    flag = -1;
                    continue;
                }
                if (special.find(total[i]) != string::npos || alpha.find(total[i]) != string::npos || total[i] == ' ') {
                    cout << ERASE << RED << "Total income must be a number!" << MOVEUP << ERASE << "\r" << RESET;
                    flag = 1;
                    break;
                }
            }
            if (flag == -1) {
                cout << ERASE << RED << "Total income must be positive!" << MOVEUP << ERASE << "\r" << RESET;
                continue;
            }
            if (flag)
                continue;
            for (int i = 0; i < t.size(); i++) {
                if (t[i].total >= stoll(total, NULL, 10)) {
                    teachers.push_back(t[i]);
                    temp.push_back(i);
                }
            }
            if (teachers.size() == 0) {
                cout << ERASE << RED << "Total income not found!" << MOVEUP << ERASE << "\r" << RESET;
                flag = 1;
            }
        } while (flag);
        cout << ERASE;
    }
    isVisibleCursor(0);
    if (outputTeachers(teachers)) {
        for (int i = 0; i < teacher_pos_temp.size(); i++) {
            if (strcmp(teacher_temp[i].name, "NA") == 0 && strcmp(teacher_temp[i].id, "NA") == 0 && strcmp(teacher_temp[i].phone, "NA") == 0
                && teacher_temp[i].age == 0 && teacher_temp[i].salary == 0 && teacher_temp[i].bonus == 0
                && teacher_temp[i].gender == 'U' && teacher_temp[i].total == 0) {
                t.erase(t.begin() + temp[teacher_pos_temp[i]]);
                temp.erase(temp.begin() + teacher_pos_temp[i]);
                for (auto &i : temp)
                    i--;
            }
            else {
                t[temp[teacher_pos_temp[i]]].age = teacher_temp[i].age;
                t[temp[teacher_pos_temp[i]]].gender = teacher_temp[i].gender;
                t[temp[teacher_pos_temp[i]]].salary = teacher_temp[i].salary;
                t[temp[teacher_pos_temp[i]]].bonus = teacher_temp[i].bonus;
                t[temp[teacher_pos_temp[i]]].total = teacher_temp[i].total;
                strcpy(t[temp[teacher_pos_temp[i]]].name, teacher_temp[i].name);
                strcpy(t[temp[teacher_pos_temp[i]]].id, teacher_temp[i].id);
                strcpy(t[temp[teacher_pos_temp[i]]].phone, teacher_temp[i].phone);
            }
        }
        writeTeachers(t);
        temp.clear();
        teacher_temp.clear();
        teacher_pos_temp.clear();
    }
}
bool compareIDTeacher(const Teacher &a, const Teacher &b) {
    return atoll(a.id) < atoll(b.id);
}
bool compareNameTeacher(Teacher a, Teacher b) {
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
bool compareIncomeTeacher(Teacher a, Teacher b) {
    return a.total == b.total ? a.salary < b.salary : a.total < b.total;
}
void sortTeachers(vector <Teacher> t, int a) {
    // * Sort teachers by ID
    if (!a)
        stable_sort(t.begin(), t.end(), compareIDTeacher);
    // * Sort teachers by name
    else if (a == 1)
        stable_sort(t.begin(), t.end(), compareNameTeacher);
    // * Sort teachers by income
    else if (a == 2)
        stable_sort(t.begin(), t.end(), compareIncomeTeacher);
    outputTeachers(t);
}
void removeTeachers(vector <Teacher> &t) {
    FILE *f = fopen("teacher.dat", "wb");
    fclose(f);
    t.clear();
    cout << RED << "Removed all teachers!" << RESET << endl;
    return;
}

#endif