#ifndef MASSIVE_H_
#define MASSIVE_H_


template <class MassType>
class Massive{
public:
    Massive();                          //����������� �� ��������� �� ���������. ������ ������� 10 ���������.
    Massive(int i);                     //����������� ���������� �������������. �������� - ������ �������.
    ~Massive();                         //����������.
    void SetAll();                      //��������� ���� �������� ��������� �������.
    void SetValue(int i, MassType m);   //��������� �������� �������� �������. 1 - ����� ��������, 2 - �������� ��������.
    void Print();                       //����� ������� �� �����.
    void Inception_sort();              //���������� ������� ������� ������� � ����������� �������.
    void Bubble_sort();                 //���������� ������� ������� ��������.
private:
    MassType *mass;                     //��������� �� ������ �������.
    int value;                          //������ �������.
};


//����������� �� ��������� �� ���������. ������ ������� 10 ���������.
template <class MassType>
Massive<MassType>::Massive()
{
    mass = new MassType[10];
    value = 10;
}

//����������� ���������� �������������. �������� - ������ �������.
template <class MassType>
Massive<MassType>::Massive(int i)
{
    mass = new MassType[i];
    value = i;
}

//����������.
template <class MassType>
Massive<MassType>::~Massive()
{
    delete [] mass;
}

//��������� �������� �������� �������. 1 - ����� ��������, 2 - �������� ��������.
template <class MassType>
void Massive<MassType>::SetValue(int i, MassType m)
{
    mass[i] = m;
}

//��������� ���� �������� ��������� �������.
template <class MassType>
void Massive<MassType>::SetAll()
{
    for(int i = 0; i < value; i++)
    {
        std::cin >> mass[i];
    }
}

//����� ������� �� �����.
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

//���������� ������� ������� ������� � ����������� �������.
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


//���������� ������� ������� ��������.
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
