#ifndef MASSIVE_H_
#define MASSIVE_H_


template <class MassType>
class Massive{
public:
    Massive();                          //Конструктор со значением по умолчанию. Размер массива 10 элементов.
    Massive(int i);                     //Конструктор задаваемый пользователем. Значение - размер массива.
    ~Massive();                         //Деструктор.
    void SetAll();                      //Установка всех значений элементов массива.
    void SetValue(int i, MassType m);   //Установка значения элемента массива. 1 - номер элемента, 2 - значение элемента.
    void Print();                       //Вывод массива на экран.
    void Inception_sort();              //Сортировка массива методом вставки в неубывающем порядке.
    void Bubble_sort();                 //Сортировка массива методом пузырька.
private:
    MassType *mass;                     //Указатель на начало массива.
    int value;                          //Размер массива.
};


//Конструктор со значением по умолчанию. Размер массива 10 элементов.
template <class MassType>
Massive<MassType>::Massive()
{
    mass = new MassType[10];
    value = 10;
}

//Конструктор задаваемый пользователем. Значение - размер массива.
template <class MassType>
Massive<MassType>::Massive(int i)
{
    mass = new MassType[i];
    value = i;
}

//Деструктор.
template <class MassType>
Massive<MassType>::~Massive()
{
    delete [] mass;
}

//Установка значения элемента массива. 1 - номер элемента, 2 - значение элемента.
template <class MassType>
void Massive<MassType>::SetValue(int i, MassType m)
{
    mass[i] = m;
}

//Установка всех значений элементов массива.
template <class MassType>
void Massive<MassType>::SetAll()
{
    for(int i = 0; i < value; i++)
    {
        std::cin >> mass[i];
    }
}

//Вывод массива на экран.
template <class MassType>
void Massive<MassType>::Print()
{
    std::cout << "Massive: ";
    for(int i = 0; i < value; i++)
    {
        std::cout << mass[i] << " ";
    }
    std::cout << "\n";
}

//Сортировка массива методом вставки в неубывающем порядке.
template <class MassType>
void Massive<MassType>::Inception_sort()
{
    MassType key;
    int i, j;
    for(i = 1; i < value; i++)
    {
        key = mass[i];
        j = i - 1;
        while ((j >= 0)&&(mass[j] > key))
        {
            mass[j + 1] = mass[j];
            j = j - 1;
        }
        mass[j + 1] = key;
    }
}


//Сортировка массива методом пузырька.
template <class MassType>
void Massive<MassType>::Bubble_sort()
{
    int i, j;
    MassType temp;

    for (i = 0; i < value; i++)
        for (j = 0; j < (value - 1); j++)
        {
            if (mass[j] > mass[j + 1])
            {
                temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
}


#endif
