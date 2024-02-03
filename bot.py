import telebot
import time

# Задаем токен бота
TOKEN = 'YOUR TOKEN BOT'

# Создаем объект бота
bot = telebot.TeleBot(TOKEN)

# ID чата с пользователем (можно получить через метод get_updates)
chat_id = 'USER CHAT ID'

# Путь к файлу с данными
file_path = 'log.txt'

# Функция для чтения данных из файла
def read_data_from_file():
    with open(file_path, 'r') as f:
        data = f.read()
    return data

# Функция для отправки сообщения пользователю
def send_message_to_user():
    data = read_data_from_file()
    if data:
        bot.send_message(chat_id, data)
        print('Message sent:', data)

# Главная функция для отправки сообщений каждые 10 секунд
def send_messages_periodically():
    while True:
        send_message_to_user()
        time.sleep(10)

# Отправляем первое сообщение сразу после запуска бота
send_message_to_user()

# Запускаем бесконечный цикл для отправки сообщений
send_messages_periodically()
