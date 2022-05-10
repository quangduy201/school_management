#ifndef FUNC_CPP
#define FUNC_CPP

#include "define.cpp"

void gotoXY(int x,int y) {
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(handle, coord);
}
void resizeConsole(int width, int height) {
    COORD coord; 
    coord.X = width; 
    coord.Y = height; 

    SMALL_RECT rect; 
    rect.Left = 0; 
    rect.Top = 0; 
    rect.Right = width - 1; 
    rect.Bottom = height - 1; 

    SetConsoleScreenBufferSize(handle, coord);
    SetConsoleWindowInfo(handle, TRUE, &rect);
}
void isVisibleCursor(int flag) {
    CONSOLE_CURSOR_INFO cursor;
    GetConsoleCursorInfo(handle, &cursor);
    cursor.bVisible = flag;
    SetConsoleCursorInfo(handle, &cursor);
}
void textBox(int posX, int posY, int x, int y, string title) {
    gotoXY(posX, posY);
    for (int i = 1; i <= y; i++) {
        if (i == 1 || i == y) {
            for (int j = 1; j <= x; j++)
                cout << char(196);
            gotoXY(posX, posY + 1);
        }
        else {
            cout << char(179);
            gotoXY(posX + x - 1, posY + i - 1);
            cout << char(179);
            gotoXY(posX, posY + i);
        }
    }
    gotoXY(posX, posY);                 cout << char(218);
    gotoXY(posX + x - 1, posY);         cout << char(191);
    gotoXY(posX, posY + y - 1);         cout << char(192);
    gotoXY(posX + x - 1, posY + y - 1); cout << char(217);
    if (title != "") {
        gotoXY(posX + x / 2 - title.length() / 2, posY);
        setColor(BG_SKY);
        cout << title;
    }
    setColor(TEXT_WHITE);
}
int getKey() {
    int key = _getwch();
    if (key == 0 || key == 224)
        return _getwch();
    else
        return key;
}
void button(string a[], int pointer, int last_pointer, int n, int step, int posX, int posY, int orientation, int &flag) {
    int z = posX;
    for (int i = 0; i < n; i++) {
        if (orientation)
            gotoXY(posX, step*i+posY);
        else {
            gotoXY(z, posY);
            z = step + 3 + z;
        }
        if (i == pointer) {
            setColor(BG_CYAN);
            cout << a[i];
            setColor(TEXT_WHITE);
        }
        else if (i == last_pointer)
            cout << a[i];
        else if (flag)
            cout << a[i];
    }
    flag = 0;
}
void bigButton(int pointer) {
    if (pointer == 0) {
        drawStudent(54, 10);
        setColor(BG_CYAN);
        drawTeacher(5, 10);
    }
    else if (pointer == 1) {
        drawTeacher(5, 10);
        setColor(BG_CYAN);
        drawStudent(54, 10);
    }
    setColor(TEXT_WHITE);
}
void accessPointer(char &key, int &pointer, int n, int orientation) {
    int previous, next;
    if (orientation) { // vertical
        previous = KEY_UP;
        next = KEY_DOWN;
    }
    else { // horizontal
        previous = KEY_LEFT;
        next = KEY_RIGHT;
    }
    if (key == previous) {
        pointer--;
        if (pointer < 0)
            pointer = n - 1;
    }
    if (key == next) {
        pointer++;
        if (pointer > n - 1)
            pointer = 0;
    }
}
void button2d(string a[], int pointer, int n, int pointer_page, int last_pointer, int page, int step, int posX, int posY, int &flag) {
    if (pointer_page != page - 1) {
        for (int i = 0; i < 60; i++) {
            if (i % 3 == 0)
                gotoXY(posX, step*i/3+posY);
            else if (i % 3 == 1)
                gotoXY(posX + 25, step*i/3+posY);
            else
                gotoXY(posX + 50, step*i/3+posY);
            if (i == pointer) {
                setColor(BG_CYAN);
                cout << a[i + pointer_page*60];
                setColor(TEXT_WHITE);
            }
            else if (i == last_pointer)
                cout << a[i + pointer_page*60];
            else
                cout << a[i + pointer_page*60];
        }
    }
    else {
        int buttons = n % 60 == 0 && n != 0 ? 60 : n % 60;
        for (int i = 0; i < buttons; i++) {
            if (i % 3 == 0)
                gotoXY(posX, step*i/3+posY);
            else if (i % 3 == 1)
                gotoXY(posX + 25, step*i/3+posY);
            else
                gotoXY(posX + 50, step*i/3+posY);
            if (i == pointer) {
                setColor(BG_CYAN);
                cout << a[i + pointer_page*60];
                setColor(TEXT_WHITE);
            }
            else if (i == last_pointer)
                cout << a[i + pointer_page*60];
            else if (flag)
                cout << a[i + pointer_page*60];
        }
    }
    flag = 0;
}
void access2dPointer(char &key, int &pointer, int n, int &pointer_page, int page) {
    if (pointer_page != page - 1) n = 60;
    else n = n % 60;
    int row = n / 3;
    if (key == KEY_UP) {
        if (pointer / 3 == 0) {
            pointer = row*3 + pointer % 3;
            if (pointer >= n)
                pointer -= 3;
        }
        else
            pointer -= 3;
    }
    else if (key == KEY_DOWN) {
        pointer += 3;
        if (pointer >= n)
            pointer %= 3;
    }
    else if (key == KEY_LEFT) {
        pointer--;
        if (pointer < 0 || pointer % 3 == 2)
            pointer += 3;
        if (pointer >= n)
            pointer = n - 1;
    }
    else if (key == KEY_RIGHT) {
        pointer++;
        if (pointer % 3 == 0)
            pointer -= 3;
        if (pointer >= n)
            pointer = row*3;
    }
}
void drawWelcome(int posX, int posY) {
    string welcome01 = "\xDC   \xDC \xDC\xDC\xDC\xDC\xDC \xDC     \xDC\xDC\xDC\xDC\xDC \xDC\xDC\xDC\xDC\xDC \xDC   \xDC \xDC\xDC\xDC\xDC\xDC";
    string welcome02 = "\xDB   \xDB \xDB\xDC\xDC   \xDB     \xDB     \xDB   \xDB \xDB\xDF\xDC\xDF\xDB \xDB\xDC\xDC  ";
    string welcome03 = "\xDF\xDC\xDF\xDC\xDF \xDB\xDC\xDC\xDC\xDC \xDB\xDC\xDC\xDC\xDC \xDB\xDC\xDC\xDC\xDC \xDB\xDC\xDC\xDC\xDB \xDB   \xDB \xDB\xDC\xDC\xDC\xDC";
    setColor(TEXT_SKY);
    gotoXY(posX, posY);     cout << welcome01;
    gotoXY(posX, posY + 1); cout << welcome02;
    gotoXY(posX, posY + 2); cout << welcome03;
    setColor(TEXT_WHITE);
}
void drawSchool(int posX, int posY) {
    string school01 =                                  "             \xDC\xDC\xDC\xDC          ";
    string school02 =                                 "            \xDB\xB1\xB1\xB1\xDB          ";
    string school03 =                                 "            \xDB\xDF\xDF\xDF\xDF          ";
    string school04 =                           "         \xDC\xDC\xDC\xDB\xDC\xDC\xDC\xDC\xDC         ";
    string school05 =                                 "        \xDB   \xDC\xDC\xDC   \xDB        ";
    string school06 =                              "        \xDB \xDC\xDF \xDC \xDF\xDC \xDB        ";
    string school07 =                               "        \xDB \xDB  \xDF\xDF \xDB \xDB        ";
    string school08 =         " \xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDB  \xDF\xDC\xDC\xDC\xDF  \xDB\xDC\xDC\xDC\xDC\xDC\xDC\xDC ";
    string school09 =                    "\xDB \xC9\xCB\xBB \xC9\xCB\xBB         \xC9\xCB\xBB \xC9\xCB\xBB \xDB";
    string school10 =                    "\xDB \xC8\xCA\xBC \xC8\xCA\xBC SCHOOL! \xC8\xCA\xBC \xC8\xCA\xBC \xDB";
    string school11 =                    "\xDB \xC9\xCB\xBB \xC9\xCB\xBB         \xC9\xCB\xBB \xC9\xCB\xBB \xDB";
    string school12 =            "\xDB \xC8\xCA\xBC \xC8\xCA\xBC  \xB0\xB2\xB2\xB2\xB0  \xC8\xCA\xBC \xC8\xCA\xBC \xDB";
    string school13 ="\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF";
    setColor(BG_CYAN);
    gotoXY(posX, posY);      cout << " " << school01 << " ";
    gotoXY(posX, posY + 1);  cout << " " << school02 << " ";
    gotoXY(posX, posY + 2);  cout << " " << school03 << " ";
    gotoXY(posX, posY + 3);  cout << " " << school04 << " ";
    gotoXY(posX, posY + 4);  cout << " " << school05 << " ";
    gotoXY(posX, posY + 5);  cout << " " << school06 << " ";
    gotoXY(posX, posY + 6);  cout << " " << school07 << " ";
    gotoXY(posX, posY + 7);  cout << " " << school08 << " ";
    gotoXY(posX, posY + 8);  cout << " " << school09 << " ";
    gotoXY(posX, posY + 9);  cout << " " << school10 << " ";
    gotoXY(posX, posY + 10); cout << " " << school11 << " ";
    gotoXY(posX, posY + 11); cout << " " << school12 << " ";
    gotoXY(posX, posY + 12); cout << " " << school13 << " ";
    setColor(TEXT_WHITE);
}
void drawTeacher(int posX, int posY) {
    string teacher01 = " \xDC\xDC\xDC\xDC\xDC \xDC\xDC\xDC\xDC\xDC  \xDC\xDC\xDC  \xDC\xDC\xDC\xDC\xDC \xDC   \xDC \xDC\xDC\xDC\xDC\xDC \xDC\xDC\xDC\xDC  ";
    string teacher02 = "   \xDB   \xDB\xDC\xDC   \xDB   \xDB \xDB     \xDB\xDC\xDC\xDC\xDB \xDB\xDC\xDC   \xDB\xDC\xDC\xDC\xDF ";
    string teacher03 = "   \xDB   \xDB     \xDB\xDF\xDF\xDF\xDB \xDB     \xDB   \xDB \xDB     \xDB  \xDF\xDC ";
    string teacher04 = "   \xDF   \xDF\xDF\xDF\xDF\xDF \xDF   \xDF \xDF\xDF\xDF\xDF\xDF \xDF   \xDF \xDF\xDF\xDF\xDF\xDF \xDF   \xDF ";
    gotoXY(posX, posY);     cout << teacher01;
    gotoXY(posX, posY + 1); cout << teacher02;
    gotoXY(posX, posY + 2); cout << teacher03;
    gotoXY(posX, posY + 3); cout << teacher04;
}
void drawStudent(int posX, int posY) {
    string student01 = "  \xDC\xDC\xDC\xDC \xDC\xDC\xDC\xDC\xDC \xDC   \xDC \xDC\xDC\xDC\xDC  \xDC\xDC\xDC\xDC\xDC \xDC   \xDC \xDC\xDC\xDC\xDC\xDC ";
    string student02 = " \xDF\xDC\xDC\xDC    \xDB   \xDB   \xDB \xDB   \xDB \xDB\xDC\xDC   \xDB\xDF\xDC \xDB   \xDB   ";
    string student03 = "     \xDB   \xDB   \xDB   \xDB \xDB   \xDB \xDB     \xDB  \xDF\xDB   \xDB   ";
    string student04 = " \xDF\xDF\xDF\xDF    \xDF   \xDF\xDF\xDF\xDF\xDF \xDF\xDF\xDF\xDF  \xDF\xDF\xDF\xDF\xDF \xDF   \xDF   \xDF   ";
    gotoXY(posX, posY);     cout << student01;
    gotoXY(posX, posY + 1); cout << student02;
    gotoXY(posX, posY + 2); cout << student03;
    gotoXY(posX, posY + 3); cout << student04;
}
void drawAvatar(int posX, int posY, char gender) {
    string avatar01, avatar02, avatar03, avatar04, avatar05, avatar06, avatar07, avatar08, avatar09, avatar10;
    if (gender == 'M') {
        avatar01 =       "      \xDC\xDC\xDB\xDB\xDB\xDB\xDC\xDC      ";
        avatar02 =    "     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     ";
        avatar03 =    "    \xDB\xDB\xDB\xDB\xDF\xDF\xDF  \xDF\xDB\xDB    ";
        avatar04 =             "    \xDF\xDB        \xDB\xDF    ";
        avatar05 =             "     \xDF\xDC      \xDC\xDF     ";
        avatar06 =          "      \xDF\xDC\xDC  \xDC\xDC\xDF      ";
        avatar07 = "   \xDC\xDC\xDC\xDC\xDF \xDF\xDF \xDF\xDC\xDC\xDC\xDC   ";
        avatar08 =    " \xDC\xDF    \xDF\xDF\xDC\xDC\xDF\xDF    \xDF\xDC ";
        avatar09 =             "\xDC\xDF                \xDF\xDC";
        avatar10 =                "\xDF                  \xDF";
    }
    else if (gender == 'F') {
        avatar01 =       "      \xDC\xDC\xDB\xDB\xDB\xDB\xDC\xDC      ";
        avatar02 =    "     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     ";
        avatar03 =    "    \xDB\xDB\xDB\xDB\xDF\xDF\xDF  \xDF\xDB\xDB    ";
        avatar04 =             "    \xDB\xDB        \xDB\xDB    ";
        avatar05 =          "    \xDB\xDB\xDC      \xDC\xDB\xDB    ";
        avatar06 = "   \xDB\xDB\xDB\xDB\xDC\xDC  \xDC\xDC\xDB\xDB\xDB\xDB   ";
        avatar07 = "   \xDF\xDB\xDB\xDB\xDF \xDF\xDF \xDF\xDB\xDB\xDB\xDF   ";
        avatar08 =    " \xDC\xDF\xDF   \xDF\xDF\xDC\xDC\xDF\xDF   \xDF\xDF\xDC ";
        avatar09 =           "\xDC\xDF                \xDF\xDC";
        avatar10 =              "\xDF                  \xDF";
    }
    setColor(BG_WHITE);
    gotoXY(posX, posY);     cout << avatar01;
    gotoXY(posX, posY + 1); cout << avatar02;
    gotoXY(posX, posY + 2); cout << avatar03;
    gotoXY(posX, posY + 3); cout << avatar04;
    gotoXY(posX, posY + 4); cout << avatar05;
    gotoXY(posX, posY + 5); cout << avatar06;
    gotoXY(posX, posY + 6); cout << avatar07;
    gotoXY(posX, posY + 7); cout << avatar08;
    gotoXY(posX, posY + 8); cout << avatar09;
    gotoXY(posX, posY + 9); cout << avatar10;
    setColor(TEXT_WHITE);
}
void drawGrade(int posX, int posY, char grade) {
    string grade1, grade2, grade3, grade4;
    switch (grade) {
        case 'A':
            grade1 = " \xDC\xDC\xDC ";
            grade2 = "\xDB   \xDB";
            grade3 = "\xDB\xDF\xDF\xDF\xDB";
            grade4 = "\xDF   \xDF";
            break;
        case 'B':
            grade1 = "\xDC\xDC\xDC\xDC ";
            grade2 = "\xDB\xDC\xDC\xDC\xDF";
            grade3 = "\xDB   \xDB";
            grade4 = "\xDF\xDF\xDF\xDF";
            break;
        case 'C':
            grade1 = "\xDC\xDC\xDC\xDC\xDC ";
            grade2 = "\xDB    ";
            grade3 = "\xDB    ";
            grade4 = "\xDF\xDF\xDF\xDF\xDF";
            break;
        case 'D':
            grade1 = "\xDC\xDC\xDC\xDC ";
            grade2 = "\xDB   \xDB";
            grade3 = "\xDB   \xDB";
            grade4 = "\xDF\xDF\xDF\xDF ";
            break;
        case 'F':
            grade1 = "\xDC\xDC\xDC\xDC\xDC";
            grade2 = "\xDB\xDC\xDC\xDC\xDC";
            grade3 = "\xDB    ";
            grade4 = "\xDB    ";
    }
    gotoXY(posX, posY);     cout << grade1;
    gotoXY(posX, posY + 1); cout << grade2;
    gotoXY(posX, posY + 2); cout << grade3;
    gotoXY(posX, posY + 3); cout << grade4;
}
void drawCV(Teacher teacher, Student student, int mode) {
    for (int i = 1; i <= 25; i++) {
        if (i == 1 || i == 25) {
            cout << "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD"
                 << "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD"
                 << "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD"
                 << "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD" << endl;
            gotoXY(1, 2);
        }
        else {
            cout << "\xBA";
            gotoXY(101, i);
            cout << "\xBA";
            gotoXY(1, 1 + i);
        }
    }
    gotoXY(  1, 1);  cout << "\xC9";
    gotoXY(101, 1);  cout << "\xBB";
    gotoXY(  1, 25); cout << "\xC8";
    gotoXY(101, 25); cout << "\xBC";
    textBox(3, 2, 22, 12, "");
    textBox(30,  2, 30, 5, "NAME");
    textBox(65,  2, 30, 5, "ID");
    textBox(65,  9, 30, 5, "PHONE");
    textBox(30,  9, 30, 5, "AGE");
    if (!mode) {
        textBox( 8, 17, 27, 5, "SALARY");
        textBox(40, 17, 27, 5, "BONUS");
        textBox(71, 17, 27, 5, "TOTAL");
        drawAvatar(4, 3, teacher.gender);
        int len = 45 - strlen(teacher.name) / 2; cout << CYAN;
        gotoXY(45 - strlen(teacher.name)  / 2, 4);  cout << teacher.name;
        gotoXY(80 - strlen(teacher.id)    / 2, 4);  cout << teacher.id;
        gotoXY(80 - strlen(teacher.phone) / 2, 11); cout << teacher.phone;
        gotoXY(45 - to_string(teacher.age).length() / 2, 11); cout << teacher.age;
        gotoXY(21 - to_string(teacher.salary).length() / 2, 19); cout << teacher.salary;
        gotoXY(53 - to_string(teacher.bonus).length()  / 2, 19); cout << teacher.bonus;
        gotoXY(84 - to_string(teacher.total).length()  / 2, 19); cout << teacher.total << RESET;
    }
    else {
        textBox( 8, 17, 27, 5, "MID-TERM");
        textBox(40, 17, 27, 5, "FINAL EXAM");
        textBox(75, 16, 11, 6, "GRADE");
        drawAvatar(4, 3, student.gender);
        int len = 45 - strlen(student.name) / 2; cout << CYAN;
        gotoXY(45 - strlen(student.name)  / 2, 4);  cout << student.name;
        gotoXY(80 - strlen(student.id)    / 2, 4);  cout << student.id;
        gotoXY(80 - strlen(student.phone) / 2, 11); cout << student.phone;
        gotoXY(45 - to_string(student.age).length() / 2, 11); cout << student.age;
        gotoXY(24 - to_string(student.midterm).length() / 2, 19); cout << student.midterm;
        gotoXY(56 - to_string(student.finalexam).length() / 2, 19); cout << student.finalexam << RESET;
        drawGrade(78, 17, student.grade);
    }
    textBox(81, 24, 19, 3, ""); gotoXY(82, 25); cout << "Press ESC to back";
}

#endif