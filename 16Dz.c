#define _CRT_SECURE_NO_DEPRECATE
#define N 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <limits.h>

double* full_elements(double* ptr_array, int size);
double* calc_elements(double* ptr_array, int size);
int put_elements(double* ptr_array, int size);
int delete_k(double* ptr_arr, int size, int k);
double* insert(double* ptr_arr, int* size, int index, double num);
int max_elem(double* ptr_array, int size);
int find_first_element(int*, int, int);
double* full_elements4(double* ptr_array4, double* ptr_array1, int size4);
double* create_array_after_last_negative(int* ptr_array2, int size, double* ptr_array4, int* size4);
void Task_11();
void Task_14();
int Task_16();
int Task_16_dz();

int main() {
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    int choice;


    printf("Выберите задание для выполнения:\n");
    printf("1 - Основное задание 16 (удаление/вставка элементов)\n");
    printf("2 - Дополнительное задание (16 дз) (генерация и объединение 3 массивов)\n");
    printf("3 - Задание 11\n");
    printf("4 - задание 14\n");
    printf("Ваш выбор: ");

    if (scanf("%d", &choice) != 1) {
        printf("Ошибка ввода выбора!\n");
        return 1;
    }

    switch (choice) {
    case 1:
        Task_16();
        break;
    case 2:
        Task_16_dz();
        break;
    case 3:
        Task_11();
        break;
    case 4:
        Task_14();
        break;
    default:
        printf("Неверный выбор!\n");
        break;
    }


    printf("\nПрограмма успешно завершена.\n");


    return 0;
}





void Task_11()
{
    system("chcp 1251");
    setlocale(LC_CTYPE, "RUS");


    printf("Введите значения для переменных массива array (Два элемента должны обязательно быть 0)\n");
    int array[N];
    int cnt_0 = 0, proizv = 1, n0 = 0; // cnt_0 - счётчик нулей в массиве      n0 - переменная чтобы не считать значения после второго нуля
    for (int i = 0; i < N; i++)
    {
        int temp;
        printf("Введите значение переменной array[%d]\n", i);
        scanf("%d", &temp);
        array[i] = temp;
        if (temp == 0)
        {
            cnt_0 += 1;
        }
    }

    if (cnt_0 < 2)
    {
        printf("В массиве недостаточно элементов со значением 0\nПопробуйте с начала\n");
    }

    for (int i = 0; i < N; i++)
    {
        if (n0 == 0)
        {
            if (array[i] == 0)
            {
                n0 += 1;
                for (int j = i; j < N - 1; j++)
                {
                    if (array[j + 1] != 0)
                    {
                        proizv = proizv * array[j + 1];
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

    }
    printf("Произведение всех чисел между двумя нулевыми элементами равно: %d", proizv);
}

void Task_14() {
    system("chcp 1251");
    setlocale(LC_CTYPE, "RUS");

    printf("Введите значения для переменных массива array \n(Обязательно должено быть хотя бы по одному нулевому, отрицательному и положительному элементу)\n\n");
    int array[N];
    for (int i = 0; i < N; i++)
    {
        int temp;
        printf("Введите значение переменной array[%d]\t", i);
        scanf("%d", &temp);
        array[i] = temp;
    }
    printf("\nИндекс первого отрицательного элемента массива: %d\n", find_first_element(array, N, -1));

    printf("Индекс первого нулевого элемента массива: %d\n", find_first_element(array, N, 0));

    printf("Индекс первого положительного элемента массива: %d\n", find_first_element(array, N, 1));
}


int find_first_element(int* array, int size, int type) {

    for (int i = 0; i < size; i++) {
        if ((type == -1 && array[i] < 0) || (type == 0 && array[i] == 0) || (type == 1 && array[i] > 0)) {
            return i;
            break;
        }
    }
}

int Task_16() {
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    double* ptr_array = NULL;
    int size;


    printf("Введите размер массива: ");
    if (scanf("%d", &size) != 1)
    {
        puts("Ошибка ввода размера массива!");
        return -1;
    }


    if (size <= 0)
    {
        puts("Размер массива должен быть положительным!");
        return -1;
    }


    ptr_array = (double*)malloc(size * sizeof(double));

    if (ptr_array == NULL)
    {
        puts("Ошибка выделения памяти!");
        return -1;
    }


    printf("Исходный массив:\n");
    full_elements(ptr_array, size);
    put_elements(ptr_array, size);






    printf("Обработанный массив:\n");
    double* new_array = calc_elements(ptr_array, size);
    if (new_array != NULL) {
        put_elements(new_array, size);
    }


    printf("\n=== Демонстрация удаления элемента ===\n");

    int del_index = 2;

    printf("Удаляем %d максимальных элемента\n", del_index);


    size = delete_k(ptr_array, size, del_index);
    printf("Массив после удаления (%d элементов):\n", size);
    put_elements(ptr_array, size);




    printf("\n=== Демонстрация вставки элемента ===\n");



    int insert_index;

    if (size > 0) {

        insert_index = max_elem(ptr_array, size);

        printf("Вставляем -999 перед элемента с индексом %d\n", insert_index);

        double* temp_array = insert(ptr_array, &size, insert_index, -999.0);

        if (temp_array != NULL) {

            ptr_array = temp_array;

            printf("Массив после вставки (%d элементов):\n", size);

            put_elements(ptr_array, size);

        }
    }










    if (ptr_array != NULL)
    {
        free(ptr_array);
        ptr_array = NULL;
    }


    printf("Программа завершена успешно.\n");
    return 0;
}

int Task_16_dz() {
    setlocale(LC_CTYPE, "RUS");
    srand(time(NULL));

    double* ptr_array1 = NULL;
    double* ptr_array2 = NULL;
    double* ptr_array3 = NULL;
    double* ptr_array4 = NULL;
    int size;
    int size4 = 5;

    size = (rand() % 41)+10;


    ptr_array1 = (double*)malloc(size * sizeof(double));
    ptr_array2 = (double*)malloc(size * sizeof(double));
    ptr_array3 = (double*)malloc(size * sizeof(double));
    ptr_array4 = (double*)malloc(size4 * sizeof(double));

    if (ptr_array1 == NULL || ptr_array2 == NULL || ptr_array3 == NULL || ptr_array4 == NULL)
    {
        puts("Ошибка выделения памяти!");
        return -1;
    }


    printf("Исходный массив 1:\n");
    full_elements(ptr_array1, size);
    put_elements(ptr_array1, size);

    printf("Исходный массив 2:\n");
    full_elements(ptr_array2, size);
    put_elements(ptr_array2, size);

    printf("Исходный массив 3:\n");
    full_elements(ptr_array3, size);
    put_elements(ptr_array3, size);

    printf("Исходный массив 4:\n");
    full_elements4(ptr_array4,ptr_array1, size4);
    create_array_after_last_negative(ptr_array2, size, ptr_array4, &size4);
    put_elements(ptr_array4, size4);


    if (ptr_array1 != NULL)
    {
        free(ptr_array1);
        ptr_array1 = NULL;
    }
    if (ptr_array2 != NULL)
    {
        free(ptr_array2);
        ptr_array2 = NULL;
    }
    if (ptr_array3 != NULL)
    {
        free(ptr_array3);
        ptr_array3 = NULL;
    }
    if (ptr_array4 != NULL)
    {
        free(ptr_array4);
        ptr_array4 = NULL;
    }
}







double* full_elements4(double* ptr_array4, double* ptr_array1, int size4) {
    for (int i = 0; i < size4; i++)
    {
        ptr_array4[i] = ptr_array1[i];
    }
    return ptr_array4;
}


double* create_array_after_last_negative(double* ptr_array2, int size, double* ptr_array4, int* size4) {
    if (ptr_array4 == NULL) {
        puts("Массив пуст!");
        return -1;
    }
    int last_negative_index = 0; // Индекс последнего отрицательного элемента
    // Ищем индекс последнего отрицательного элемента
    for (int i = 0; i < size; i++) {
        if (ptr_array2[i] < 0) {
            last_negative_index = i;
        }
    }

    
    ptr_array4 = insert(ptr_array4, &size4, 1, ptr_array2[size-1]);
    

    return ptr_array4;

    }










double* full_elements(double* ptr_array, int size) {         //Заполнение массива случайными элементами от -1 до 1
    if (ptr_array == NULL || size <= 0)
    {
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        ptr_array[i] = (double)rand() / RAND_MAX * 2.0 - 1.0;
    }
    return ptr_array;
}




int put_elements(double* ptr_array, int size) {       //Вывод массива на экран
    if (ptr_array == NULL) {
        puts("Массив пуст!");
        return -1;
    }

    if (size <= 0) {
        puts("Неверный размер массива!");
        return -1;
    }

    for (int i = 0; i < size; i++) {
        printf("[%d] = %.4f\n", i, ptr_array[i]);
    }

    return 0;
} 



double* calc_elements(double* ptr_array, int size) {        //Округление всех элементов массива в большую сторону
    for (int i = 0; i < size; i++) {
        ptr_array[i] = ceil(ptr_array[i]);
    }
    return ptr_array;
}









int delete_k(double* ptr_arr, int size, int k) {      //Удаление К самых больших элементов
    if (ptr_arr == NULL)
    {
        return 0;
    }


    if (k < 0 || k >= size) {
        printf("Некорректный индекс для удаления: %d\n", k);
        return size;
    }

    int n = size - k;

    for (int j=1;j<=k;j++)
    {

        int u = size - j;
        for (int t = max_elem(ptr_arr,size); t < u; t++) {
            ptr_arr[t] = ptr_arr[t + 1];
            }


        }

    return n;
}



int max_elem(double* ptr_array, int size) {      //Поиск максимального элемента и возвращает его индекс
    int max_value = INT_MIN;
    int max_index = 0;
    for (int i = 0; i < size; i++) {
        if (ptr_array[i] > max_value)
        {
            max_value = ptr_array[i];
            max_index = i;
        }
    }
    return max_index;
}













double* insert(double* ptr_arr, int* size, int index, double num) {      //Вставка num по index в массив
    if (ptr_arr == NULL || size == NULL) {
        printf("Некорректные параметры для вставки!\n");
        return NULL;
    }

    if (index < 0 || index > *size) {
        printf("Некорректный индекс для вставки: %d (размер: %d)\n", index, *size);
        return ptr_arr;
    }

    int size_n = (*size) + 1;
    double* ptr_arr_n = (double*)realloc(ptr_arr, size_n * sizeof(double));

    if (ptr_arr_n == NULL) {
        printf("Ошибка перевыделения памяти!\n");
        return ptr_arr;
    }

    for (int i = size_n - 1; i > index; i--) {
        ptr_arr_n[i] = ptr_arr_n[i - 1];
    }

    ptr_arr_n[index] = num;
    *size = size_n;
    return ptr_arr_n;
}















