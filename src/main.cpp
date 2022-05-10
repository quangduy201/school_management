#include "define.cpp"
#include "func.cpp"
#include "student.cpp"
#include "teacher.cpp"

int main() {
    SetConsoleTitle("SCHOOL MANAGEMENT");
    resizeConsole(101, 30);
    isVisibleCursor(0);
    vector <Student> s;
    vector <Teacher> t;
    int pointer = 0, last_pointer = 0;
    char key = 1; flag = 1;
    string menu[3] = {"           START           ",
                      "           ABOUT           ",
                      "           EXIT            "};
    while (1) {
        if (clrscr[0]) {
            system("cls");
            cout << CYAN << "SCHOOL MANAGEMENT" << RESET;
            drawWelcome(30, 3);
            drawSchool(36, 7);
            textBox(36, 21, 29, 3, "");
            textBox(36, 24, 29, 3, "");
            textBox(36, 27, 29, 3, "");
            clrscr[0] = 0;
            clrscr[1] = 1;
        }
        button(menu, pointer, last_pointer, 3, 3, 37, 22, 1, flag);
        gotoXY(35, 30);
        key = getKey();
        last_pointer = pointer;
        accessPointer(key, pointer, 3, 1);

        // ! START
        if ((key == 13 || key == 32) && pointer == 0) {
            while (1) {
                if (clrscr[1]) {
                    system("cls");
                    cout << CYAN << "SCHOOL MANAGEMENT : START" << RESET << endl;
                    textBox(4, 9, 45, 6, "");
                    textBox(53, 9, 45, 6, "");
                    textBox(81, 24, 19, 3, "");
                    gotoXY(82, 25);
                    cout << "Press ESC to back";
                    clrscr[1] = 0;
                    clrscr[2] = 1;
                }
                bigButton(pointer);
                key = getKey();
                accessPointer(key, pointer, 2, 0);
                if (key == 32 || key == 13) {
                    // ! TEACHER
                    if (pointer == 0) {
                        flag = 1;
                        string option[10] = {"   Input teachers                                ",
                                             "   Append teachers                               ",
                                             "   Output teachers                               ",
                                             "   Find teachers by ID                           ",
                                             "   Find teachers by name                         ",
                                             "   Find teachers by total income                 ",
                                             "   Sort teachers by ID                           ",
                                             "   Sort teachers by name                         ",
                                             "   Sort teachers by total income                 ",
                                             "   Remove all teachers                           "};
                        while (1) {
                            if (clrscr[2]) {
                                system("cls");
                                cout << CYAN << "SCHOOL MANAGEMENT : START : TEACHER" << RESET << endl;
                                drawTeacher(5, 10);
                                textBox(51, 6, 51, 12, "Choose an option.");
                                textBox(81, 24, 19, 3, "");
                                gotoXY(82, 25);
                                cout << "Press ESC to back";
                                clrscr[2] = 0;
                                clrscr[3] = 1;
                            }
                            button(option, pointer, last_pointer, 10, 1, 52, 7, 1, flag);
                            gotoXY(1, 20);
                            readTeachers(t);
                            key = getKey();
                            last_pointer = pointer;
                            accessPointer(key, pointer, 10, 1);
                            if (key == 32 || key == 13) {
                                system("cls");
                                switch (pointer) {
                                    case 0: case 1:
                                        isVisibleCursor(1);
                                        cout << CYAN << "SCHOOL MANAGEMENT : START : TEACHER : INPUT" << RESET << endl;
                                        inputTeachers(t, pointer);
                                        isVisibleCursor(0);
                                        system("pause");
                                        break;
                                    case 2:
                                        outputTeachers(t);
                                        break;
                                    case 3: case 4: case 5:
                                        cout << CYAN << "SCHOOL MANAGEMENT : START : TEACHER : FIND" << RESET << endl;
                                        textBox(62, 4, 35, 3, "");
                                        gotoXY(63, 5);
                                        cout << "Press Enter to show all teachers.";
                                        gotoXY(1, 2);
                                        findTeachers(t, pointer - 3);
                                        break;
                                    case 6: case 7: case 8:
                                        sortTeachers(t, pointer - 6);
                                        break;
                                    case 9:
                                        cout << CYAN << "SCHOOL MANAGEMENT : START : TEACHER : REMOVE" << RESET << endl;
                                        removeTeachers(t);
                                        system("pause");
                                        break;
                                }
                                cout << endl;
                                clrscr[2] = 1;
                                flag = 1;
                            }
                            else if (key == 27) { // ! BACK
                                pointer = 0;
                                key = 1;
                                clrscr[1] = 1;
                                break;
                            }
                        }
                    }

                    // ! STUDENT
                    if (pointer == 1) {
                        pointer = 0; flag = 1;
                        string option[10] = {"   Input students                                ",
                                             "   Append students                               ",
                                             "   Output students                               ",
                                             "   Find students by ID                           ",
                                             "   Find students by name                         ",
                                             "   Find students by grade                        ",
                                             "   Sort students by ID                           ",
                                             "   Sort students by name                         ",
                                             "   Sort students by grade                        ",
                                             "   Remove all students                           "};
                        while (1) {
                            if (clrscr[2]) {
                                system("cls");
                                cout << CYAN << "SCHOOL MANAGEMENT : START : STUDENT" << RESET << endl;
                                drawStudent(54, 10);
                                textBox(1, 6, 51, 12, "Choose an option.");
                                textBox(81, 24, 19, 3, "");
                                gotoXY(82, 25);
                                cout << "Press ESC to back";
                                clrscr[2] = 0;
                                clrscr[3] = 1;
                            }
                            button(option, pointer, last_pointer, 10, 1, 2, 7, 1, flag);
                            gotoXY(1, 20);
                            readStudents(s);
                            key = getKey();
                            last_pointer = pointer;
                            accessPointer(key, pointer, 10, 1);
                            if (key == 32 || key == 13) {
                                system("cls");
                                switch (pointer) {
                                    case 0: case 1:
                                        isVisibleCursor(1);
                                        cout << CYAN << "SCHOOL MANAGEMENT : START : STUDENT : INPUT" << RESET << endl;
                                        inputStudents(s, pointer);
                                        isVisibleCursor(0);
                                        system("pause");
                                        break;
                                    case 2:
                                        outputStudents(s);
                                        break;
                                    case 3: case 4: case 5:
                                        cout << CYAN << "SCHOOL MANAGEMENT : START : STUDENT : FIND" << RESET << endl;
                                        textBox(62, 4, 35, 3, "");
                                        gotoXY(63, 5);
                                        cout << "Press Enter to show all students.";
                                        gotoXY(1, 2);
                                        findStudents(s, pointer - 3);
                                        break;
                                    case 6: case 7: case 8:
                                        sortStudents(s, pointer - 6);
                                        break;
                                    case 9:
                                        cout << CYAN << "SCHOOL MANAGEMENT : START : STUDENT : REMOVE" << RESET << endl;
                                        removeStudents(s);
                                        system("pause");
                                        break;
                                }
                                cout << endl;
                                clrscr[2] = 1;
                                flag = 1;
                            }
                            else if (key == 27) { // ! BACK
                                pointer = 1;
                                key = 1;
                                clrscr[1] = 1;
                                break;
                            }
                        }
                    }

                }
                // ! BACK
                else if (key == 27) {
                    pointer = 0;
                    key = 1;
                    clrscr[0] = 1;
                    flag = 1;
                    break;
                }
            }
        }

        // ! ABOUT
        if ((key == 13 || key == 32) && pointer == 1) {
            system("cls");
            cout << CYAN << "SCHOOL MANAGEMENT : ABOUT" << RESET << endl;
            string about[19] = {"SCHOOL MANAGEMENT",
                                "v.1.0",
                                "",
                                "---------------------",
                                "",
                                "This is a school management system.",
                                "It stores information of teachers and students in the school.",
                                "",
                                "---------------------",
                                "",
                                "Sai Gon University",
                                "Faculty of Information Technology",
                                "Class DCT1216",
                                "",
                                "Created by:",
                                "Dinh Quang Duy",
                                "",
                                "Date created:",
                                "May 7, 2022"};
            for (int i = 0; i < 19; i++) {
                gotoXY(50 - about[i].length()/2, 5 + i);
                if (i == 0) setColor(TEXT_CYAN);
                else if (i == 1) setColor(TEXT_GREY);
                else if (i == 5 || i == 6) setColor(TEXT_LIME);
                else if (i == 10 || i == 11 || i == 12) setColor(TEXT_YELLOW);
                else if (i == 14 || i == 17) setColor(TEXT_SKY);
                else if (i == 15 || i == 18) setColor(TEXT_PINK);
                for (int j = 0; j < about[i].length(); j++) {
                    cout << about[i][j];
                    Sleep(30);
                }
                Sleep(100);
                setColor(TEXT_WHITE);
            }
            textBox(81, 24, 19, 3, "");
            gotoXY(82, 25);
            cout << "Press ESC to back";
            while (1) {
                key = getKey();
                if (key == 27) {
                    pointer = 1;
                    key = 1;
                    clrscr[0] = 1;
                    flag = 1;
                    break;
                }
            }
        }

        // ! EXIT
        if ((key == 13 || key == 32) && pointer == 2) {
            break;
        }
    }
    return 0;
}
/*
59
Nguyen Ho Khanh An
19
3121410048
M
0987654321
6.3
7.3
Nguyen Tuan Anh
19
3121410057
M
0987654321
0
1
Chau Gia Bao
19
3121410067
M
0987654321
0
1
Nguyen Tri Bao
19
3121410076
M
0987654321
5.5
6.5
Van Pham Tuan Cat
19
3121410085
M
0987654321
5.8
6.8
Ho Quoc Cuong
19
3121410095
M
0987654321
5.8
6.8
Nguyen Tien Duan
19
3121410106
M
0987654321
6
7
Dinh Quang Duy
19
3121410116
M
0987654321
8
9
Tran Nhat Duy
19
3121410125
M
0987654321
4.3
5.3
Lam Quoc Dai
19
3121410134
M
0987654321
0
1
Ngo Tan Dat
19
3121410144
M
0987654321
6.7
7.7
Nguyen Quang Dat
19
3121410005
M
0987654321
7.2
8.2
Nguyen Phuong Dien
19
3121410154
M
0987654321
6.7
7.7
Tran Trung Duc
19
3121410165
M
0987654321
0
1
Ho Thi Hai
19
3121410174
F
0987654321
6.3
7.3
Nguyen Huu Hau
19
3121410184
M
0987654321
3.8
4.8
Nguyen Huynh Minh Hieu
19
3121410195
M
0987654321
5.8
6.8
Vi Thi Hoa
19
3121410205
F
0987654321
8
9
Vo Dinh Xuan Hoang
19
3121410215
M
0987654321
5.9
6.9
Kieu Duc Huy
19
3121410227
M
0987654321
6.6
7.6
Cao Huy Hung
19
3121410237
M
0987654321
7
8
Hy Phu Kam
19
3121410247
M
0987654321
6.3
7.3
Le Duy Khanh
19
3121410258
M
0987654321
6.5
7.5
Do Dang Khoa
19
3121410268
M
0987654321
6.4
7.4
Hoang Trong Khoi
19
3121410278
M
0987654321
0
1
Lam Tuan Kiet
19
3121410287
M
0987654321
6.2
7.2
Nguyen Hoang Long
19
3121410296
M
0987654321
7.4
8.4
Nguyen Phuoc Luan
19
3121410306
M
0987654321
5.3
6.3
Dang Sy Manh
19
3121410316
M
0987654321
6.3
7.3
Vo Chi Minh
19
3121410325
M
0987654321
0
1
Than Trong Hoai Nam
19
3121410335
M
0987654321
6.8
7.8
Phan Trung Nghia
19
3121410345
M
0987654321
6.5
7.5
Lai Thanh Nhan
19
3121410356
F
0987654321
6.9
7.9
Hua Tuyet Nhi
19
3121410367
F
0987654321
6.5
7.5
Nguyen Hoang Phat
19
3121410377
M
0987654321
6.9
7.9
Ta Duc Phu
19
3121410386
M
0987654321
6.3
7.3
Nguyen Van Minh Phuc
19
3121410395
M
0987654321
6
7
Do Phan Uyen Quan
19
3121410405
F
0987654321
6.4
7.4
Huynh Le San
19
3121410415
F
0987654321
7.2
8.2
Nguyen Hoang Thai Son
19
3121410424
M
0987654321
7
8
Nguyen Chi Tai
19
3121410433
M
0987654321
7.2
8.2
Nguyen Van Tan
19
3121410444
M
0987654321
6.7
7.7
Nguyen Duc Tay
19
3121410038
M
0987654321
6.7
7.7
Truong Gia Thanh
19
3121410456
M
0987654321
4.5
5.5
Nguyen Chi Thien
19
3121410466
M
0987654321
0
1
Nguyen Khanh Thien
19
3121410014
M
0987654321
6.3
7.3
Vo Duc Thinh
19
3121410475
M
0987654321
6
7
Phan Nguyen Trung Thuan
19
3121410484
M
0987654321
6.8
7.8
Doan Minh Tien
19
3121410495
M
0987654321
0
1
Dang Duc Tin
19
3121410505
M
0987654321
6.7
7.7
Pham Quoc Toan
19
3121410514
M
0987654321
4
5
Nguyen Xuan Truc
19
3121410534
F
0987654321
6.9
7.9
Pham Hoang Dan Truong
19
3121410543
M
0987654321
6.8
7.8
Vu Ngoc Tu
19
3121410552
M
0987654321
6.2
7.2
Pham Quoc Tuan
19
3121410561
M
0987654321
4.3
5.3
Nguyen Thanh Thien Tu
19
3121410570
M
0987654321
7.9
8.9
Nguyen The Vu
19
3121410580
M
0987654321
6.9
7.9
Tien Minh Vy
19
3121410023
M
0987654321
6.7
7.7
Tang Nghia Xuong
19
3121410588
M
0987654321
0
1
*/