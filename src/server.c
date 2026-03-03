#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"

int sum_of_digits(int number) {
    int sum = 0;
    number = abs(number);
    
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

void sort_by_digit_sum(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sum_of_digits(arr[j]) > sum_of_digits(arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    printf("\n[СЕРВЕР] Массив отсортирован по сумме цифр\n");
}

void input_znak(ZNAK mass[], int size) {
    printf("\n=== Ввод информации о %d людях ===\n", size);
    
    for (int i = 0; i < size; i++) {
        printf("\n--- Человек %d ---\n", i + 1);
        
        printf("Введите фамилию и имя: ");
        fgets(mass[i].surname_name, sizeof(mass[i].surname_name), stdin);
        mass[i].surname_name[strcspn(mass[i].surname_name, "\n")] = 0;
        
        printf("Введите знак зодиака: ");
        fgets(mass[i].zodiac, sizeof(mass[i].zodiac), stdin);
        mass[i].zodiac[strcspn(mass[i].zodiac, "\n")] = 0;
        
        printf("Введите дату рождения (день месяц год): ");
        scanf("%d %d %d", &mass[i].date[0], &mass[i].date[1], 
&mass[i].date[2]);
        getchar();
    }
}

void sort_by_birthday(ZNAK mass[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            int day1 = mass[j].date[0];
            int month1 = mass[j].date[1];
            int year1 = mass[j].date[2];
            int day2 = mass[j + 1].date[0];
            int month2 = mass[j + 1].date[1];
            int year2 = mass[j + 1].date[2];
            
            if (year1 > year2 || 
                (year1 == year2 && month1 > month2) || 
                (year1 == year2 && month1 == month2 && day1 > day2)) {
                
                ZNAK temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }
    printf("\n[СЕРВЕР] Массив отсортирован по дате рождения\n");
}

void search_by_zodiac(ZNAK mass[], int size, char zodiac[]) {
    int found = 0;
    printf("\n=== Люди с знаком зодиака '%s' ===\n", zodiac);
    
    for (int i = 0; i < size; i++) {
        if (strcasecmp(mass[i].zodiac, zodiac) == 0) {
            printf("\n%d. %s\n", found + 1, mass[i].surname_name);
            printf("   Дата рождения: %02d.%02d.%04d\n", 
                   mass[i].date[0], mass[i].date[1], mass[i].date[2]);
            found++;
        }
    }
    
    if (found == 0) {
        printf("Люди с знаком зодиака '%s' не найдены.\n", zodiac);
    } else {
        printf("\nНайдено %d человек(а)\n", found);
    }
}

void input_car_owner(CarOwner *owner) {
    printf("\n--- Ввод данных владельца автомобиля ---\n");
    
    printf("Фамилия: ");
    fgets(owner->surname, sizeof(owner->surname), stdin);
    owner->surname[strcspn(owner->surname, "\n")] = 0;
    
    printf("Имя: ");
    fgets(owner->name, sizeof(owner->name), stdin);
    owner->name[strcspn(owner->name, "\n")] = 0;
    
    printf("Отчество: ");
    fgets(owner->patronymic, sizeof(owner->patronymic), stdin);
    owner->patronymic[strcspn(owner->patronymic, "\n")] = 0;
    
    printf("Номер телефона: ");
    fgets(owner->phone, sizeof(owner->phone), stdin);
    owner->phone[strcspn(owner->phone, "\n")] = 0;
    
    printf("\n--- Адрес ---\n");
    printf("Почтовый индекс: ");
    fgets(owner->postal_index, sizeof(owner->postal_index), stdin);
    owner->postal_index[strcspn(owner->postal_index, "\n")] = 0;
    
    printf("Страна: ");
    fgets(owner->country, sizeof(owner->country), stdin);
    owner->country[strcspn(owner->country, "\n")] = 0;
    
    printf("Область: ");
    fgets(owner->region, sizeof(owner->region), stdin);
    owner->region[strcspn(owner->region, "\n")] = 0;
    
    printf("Район: ");
    fgets(owner->district, sizeof(owner->district), stdin);
    owner->district[strcspn(owner->district, "\n")] = 0;
    
    printf("Город: ");
    fgets(owner->city, sizeof(owner->city), stdin);
    owner->city[strcspn(owner->city, "\n")] = 0;
    
    printf("Улица: ");
    fgets(owner->street, sizeof(owner->street), stdin);
    owner->street[strcspn(owner->street, "\n")] = 0;
    
    printf("Дом: ");
    fgets(owner->house, sizeof(owner->house), stdin);
    owner->house[strcspn(owner->house, "\n")] = 0;
    
    printf("Квартира: ");
    fgets(owner->apartment, sizeof(owner->apartment), stdin);
    owner->apartment[strcspn(owner->apartment, "\n")] = 0;
    
    printf("\n--- Автомобиль ---\n");
    printf("Марка автомобиля: ");
    fgets(owner->car_brand, sizeof(owner->car_brand), stdin);
    owner->car_brand[strcspn(owner->car_brand, "\n")] = 0;
    
    printf("Номер автомобиля: ");
    fgets(owner->car_number, sizeof(owner->car_number), stdin);
    owner->car_number[strcspn(owner->car_number, "\n")] = 0;
    
    printf("Номер техпаспорта: ");
    fgets(owner->tech_passport, sizeof(owner->tech_passport), stdin);
    owner->tech_passport[strcspn(owner->tech_passport, "\n")] = 0;
}

void print_car_owner(CarOwner owner) {
    printf("\n====================================\n");
    printf("Владелец: %s %s %s\n", owner.surname, owner.name, 
owner.patronymic);
    printf("Телефон: %s\n", owner.phone);
    printf("Адрес: %s, %s, %s р-н, %s, ул.%s, д.%s, кв.%s, %s\n",
           owner.country, owner.region, owner.district, owner.city,
           owner.street, owner.house, owner.apartment, 
owner.postal_index);
    printf("Автомобиль: %s, номер %s, техпаспорт %s\n", 
           owner.car_brand, owner.car_number, owner.tech_passport);
    printf("====================================\n");
}

void input_multiple_owners(CarOwner owners[], int count) {
    printf("\n=== Ввод данных о %d владельцах автомобилей ===\n", count);
    for (int i = 0; i < count; i++) {
        printf("\n--- Владелец %d ---\n", i + 1);
        input_car_owner(&owners[i]);
    }
}

void search_by_car_brand(CarOwner owners[], int count, char brand[]) {
    int found = 0;
    printf("\n=== Поиск владельцев автомобилей марки '%s' ===\n", brand);
    
    for (int i = 0; i < count; i++) {
        if (strcasecmp(owners[i].car_brand, brand) == 0) {
            print_car_owner(owners[i]);
            found++;
        }
    }
    
    if (found == 0) {
        printf("Владельцы с автомобилем марки '%s' не найдены.\n", brand);
    } else {
        printf("\nНайдено %d владельцев(а)\n", found);
    }
}
