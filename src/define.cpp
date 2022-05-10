#ifndef DEFINE_CPP
#define DEFINE_CPP

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
#define maxn 1000

// keys
#define KEY_UP    72
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_ESC   27

// colors of output text
#define RESET  "\033[0m"
#define BLACK  "\033[30m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define GOLD   "\033[33m"
#define BLUE   "\033[34m"
#define PURPLE "\033[35m"
#define CYAN   "\033[36m"
#define WHITE  "\033[37m"

// movements of cursor
#define MOVEUP    "\033[A"
#define MOVEDOWN  "\033[B"
#define MOVELEFT  "\033[C"
#define MOVERIGHT "\033[D"
#define ERASE     "\33[2K"

// colors of output foreground and background
#define TEXT_GREY      (FOREGROUND_INTENSITY)
#define TEXT_RED       (FOREGROUND_RED)
#define TEXT_PINK      (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define TEXT_GOLD      (FOREGROUND_RED | FOREGROUND_GREEN)
#define TEXT_YELLOW    (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define TEXT_GREEN     (FOREGROUND_GREEN)
#define TEXT_LIME      (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define TEXT_CYAN      (FOREGROUND_GREEN | FOREGROUND_BLUE)
#define TEXT_TURQUOISE (FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define TEXT_BLUE      (FOREGROUND_BLUE)
#define TEXT_SKY       (FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define TEXT_PURPLE    (FOREGROUND_BLUE | FOREGROUND_RED)
#define TEXT_MAGENTA   (FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY)
#define TEXT_WHITE     (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

#define BG_GREY      (BACKGROUND_INTENSITY)
#define BG_RED       (BACKGROUND_RED)
#define BG_PINK      (BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BG_GOLD      (BACKGROUND_RED | BACKGROUND_GREEN)
#define BG_YELLOW    (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BG_GREEN     (BACKGROUND_GREEN)
#define BG_LIME      (BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define BG_CYAN      (BACKGROUND_GREEN | BACKGROUND_BLUE)
#define BG_TURQUOISE (BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define BG_BLUE      (BACKGROUND_BLUE)
#define BG_SKY       (BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define BG_PURPLE    (BACKGROUND_BLUE | BACKGROUND_RED)
#define BG_MAGENTA   (BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BG_WHITE     (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE)
#define setColor(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color)

// data structure
struct Student {
    char name[32] = {'N', 'A'};
    int age = 0;
    char id[16] = {'N', 'A'};
    char gender = 'U';
    char phone[16] = {'N', 'A'};
    double midterm = 0;
    double finalexam = 0;
    char grade = 'U';
    char setGrade(double midterm, double finalexam) {
        double temp = (midterm + finalexam) / 2;
        if (temp >= 8.5) return 'A';
        else if (temp >= 7.0) return 'B';
        else if (temp >= 5.5) return 'C';
        else if (temp >= 4.0) return 'D';
        else return 'F';
    }
};
struct Teacher {
    char name[32] = {'N', 'A'};
    int age = 0;
    char id[16] = {'N', 'A'};
    char gender = 'U';
    char phone[16] = {'N', 'A'};
    long long salary = 0;
    long long bonus = 0;
    long long total = 0;
    long long setTotal(long long salary, long long bonus) {
        return salary + bonus;
    }
};
// prototypes
void gotoXY(int x, int y);
void resizeConsole(int width, int height);
void isVisibleCursor(int flag);
void textBox(int posX, int posY, int x, int y, string title);
int getKey();
void button(string a[], int pointer, int last_pointer, int n, int step, int posX, int posY, int orientation);
void bigButton(int pointer);
void accessPointer(char &key, int &pointer, int n, int orientation);
void button2d(string a[], int pointer, int n, int pointer_page, int last_pointer, int page, int step, int posX, int posY, int &flag);
void access2dPointer(char &key, int &pointer, int n, int &pointer_page, int page);
void drawWelcome(int posX, int posY);
void drawSchool(int posX, int posY);
void drawTeacher(int posX, int posY);
void drawStudent(int posX, int posY);
void drawAvatar(int posX, int posY);
void drawGrade(int posX, int posY, char grade);
void drawCV(Student student);

// global variables
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
string special = "`-=[]\\;',./~!@#$%^&*()_+{}|:\"<>?";
string dot = "`-=[]\\;',/~!@#$%^&*()_+{}|:\"<>?";
string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
string number = "0123456789";
string n, name, age, id, gender, phone, midterm, finalexam, salary, bonus;
char grade;
long long total;
int flag, clrscr[5] = {1};
vector <int> temp;
vector <Student> student_temp; vector <int> student_pos_temp;
vector <Teacher> teacher_temp; vector <int> teacher_pos_temp;

#endif