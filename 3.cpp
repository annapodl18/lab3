#include <ctime>
#include <iostream>
using namespace std;

int  main()
{
    srand(time(0));
    long long size1;
    cout << "Enter size value: ";
    cin >> size1;

    long long *array1 = new long long[size1]; 
    cout<<"array1: ";
    for (int i = 0; i < size1; i++) 
    {
          array1[i] = rand() % 10;
	cout<<array1[i]<<" ";
    }

    long long size2;
    cout << "\n\nEnter size2 value: ";
    cin >> size2; 

    long long *array2 = new long long[size2]; 
	cout<<"array2: ";
    for (int  i = 0; i < size2; i++)
    {
        array2[i] = rand() % 10;
	cout<<array2[i]<<" ";
    }


    long long size3 = size1 + size2;
    long long *array3 = new long long[size3]; // Выделение памяти для массива


    long long* ptr_array1 = &array1[0]; // создаем переменную (указатель!), который указывает на адрес первого элемента в массиве
    long long* end_array1 = &array1[size1]; // создаем переменную (указатель!), который указывает на адрес последнего элемента в массиве.
    long long* ptr_array2 = &array2[0];
    long long* ptr_array3 = &array3[0];
    long long* end_array3 = &array3[size3-1]; //
	asm( // шок, дальше прога на ассембере
        "mov %[ptr_array1], %%rax\n\t"  // поместим указатель на начало массива в rax
        "mov %[ptr_array2], %%rbx\n\t"  // поместим указатель на начало массива в rbx
        "mov %[ptr_array3], %%rcx\n\t"  // поместим указатель на начало массива в rcx
        "mov (%%rax), %%rdx\n\t"        


 
	"start1:\n\t" // функция 
	"push (%%rax)\n\t"          // кладем в стек значение регистра rax (5) из-за скобок
        "pop (%%rcx)\n\t"           // вытаскиваем значение из стека, в регистр rcx
        "cmp %%rax, %[end_array1]\n\t" // проверка что достигнут конец, сравниванием адреса
        "je start2\n\t"                // Если достигнут -> заполнение вторым массивом
        "jmp next_element1\n\t"            // Переход на next_element





        "next_element1:\n\t" // функция если не дошли до конца, то переходим к след эл-ту первого массива
        "add $8, %%rax\n\t"         // увеличить адрес в rax на 4 (переместили на один элемент вправо)
        "add $8, %%rcx\n\t"         // увеличить адрес в rcx на 4 (переместили на один элемент вправо)
        "mov (%%rax), %%rdx\n\t"    // поместим указатель на начало массива в rdx
	"jmp start1\n\t"


	"start2:\n\t"
        "push (%%rbx)\n\t"          // кладем в стек значение регистра ebx
        "pop (%%rcx)\n\t"           // вытаскиваем значение из стека, в регистр rcx
        "cmp %%rbx, %[end_array3]\n\t" // проверка что достигнут конец 
        "je end\n\t"                // если достигнут - конец
        "jmp next_element2\n\t"            // переход на next_element2


        "next_element2:\n\t"
        "add $8, %%rbx\n\t"         // увеличить адрес в rax на 4 (переместили на один элемент вправо)
        "add $8, %%rcx\n\t"         // увеличить адрес в rcx на 4 (переместили на один элемент вправо)
        "mov (%%rax), %%rdx\n\t"    // поместим указатель на начало массива в rdx
        "jmp start2\n\t"
        "end:\n\t"
        :
    : [ptr_array1] "m"(ptr_array1), [ptr_array2]"m"(ptr_array2), [ptr_array3]"m"(ptr_array3), [end_array1]"m"(end_array1), [end_array3]"m"(end_array3) // переменные из С++ в Ассемблер

        : "%rax", "%rbx", "%rcx", "%rdx"
        );

    cout<<"\n\narr3: ";
    for (int  i = 0; i < size3; i++) {
        cout<<array3[i]<<" ";
    }
    cout<<"\n";

    delete [] array1; // очистка памяти
    delete [] array2; // очистка памяти
    delete [] array3; // очистка памяти
    return 0;
}
