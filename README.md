## Overview
Программа для работы со структурой ZNAK, содержащей:
- Name – фамилия и имя
- ZOD – знак зодиака
- DATE – дата рождения (год, месяц, число)

Программа выполняет:
- ввод с клавиатуры данных в массив из 10 элементов типа ZNAK
- упорядочивание записей по дате рождения
- поиск людей по знаку зодиака

## Author
Stanislavv-Kabanov

## Usage
1. Скомпилировать программу:
   make

2. Запустить программу:
   ./program

3. Ввести данные (до 10 записей):
   - Фамилия и имя
   - Знак зодиака
   - Дата рождения (год месяц число)

4. После ввода программа выведет записи, отсортированные по дате рождения

5. Ввести знак зодиака для поиска

## Modules
Сборка проекта выполняется с помощью Makefile:

Для автоматической сборки используется GitHub Actions:
~~~yaml
name: C Build
on: [push, pull_request]
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
    - uses: actions/checkout@v4
    - run: make
    - run: ./program
~~~

## Additional Notes
Ссылки на репозитории из заданий 1 и 2:
Задание 1: https://github.com/Stanislav-Kabanov/-lab2-task1-gr13b-Kabanov
Задание 2: https://github.com/Stanislav-Kabanov/tpmp-lab2-task2
