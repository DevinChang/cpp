#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data book;
    std::cout << "���������ۼ�¼��"<< std::endl;
    while (std::cin >> book)
    {
        std::cout << " ISBN���۳�������ԭʼ�۸�ԭʼ�۸�ʵ�ۼ۸��ۿ�Ϊ" << book << std::endl;
    }

    Sales_data trans1, trans2;
    std::cout << "����������ISBN��ͬ�����ۼ�¼��" << std::endl;
    std::cin.clear();  // ����������Ĵ���״̬��־λ���Ա����������롣
    std::cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2))
    {
        std::cout << "������Ϣ��ISBN���۳�������ԭʼ�۸�ʵ�ۼ۸��ۿ�Ϊ " << trans1 + trans2 << std::endl;
    }
    else
    {
        std::cout << "�������ۼ�¼��ISBN��ͬ" << std::endl;
    }

    Sales_data total, trans;
    std::cout << "�����뼸��ISBN��ͬ�����ۼ�¼��" << std::endl;
    std::cin.clear(); // ����������Ĵ���״̬��־λ���Ա����������롣
    if (std::cin >> total)
    {
        while (std::cin >> trans)
        {
            if (compareIsbn(total, trans)) // ISBN ��ͬ
            {
                total = total + trans;
            }
            else // ISBN ��ͬ
            {
                std::cout << "��ǰ�鼮ISBN��ͬ" << std::endl;
                break;
            }
        }
        std::cout << "��Ч������Ϣ��ISBN���۳�������ԭʼ�۸�ʵ�ۼ۸��ۿ�Ϊ" << total << std::endl;
    }
    else
    {
        std::cout << "û������" << std::endl;
        return -1;
    }

    int num = 1;    //��¼��ǰ�鼮�����ۼ�¼����
    std::cout << "�������������ۼ�¼��"<< std::endl;
    std::cin.clear();  // ����������Ĵ���״̬��־λ���Ա����������롣
    if (std::cin >> trans1)
    {
        while (std::cin >> trans2)
        {
            if (compareIsbn(trans1, trans2)) // ISBN ��ͬ
            {
                num++;
            }
            else // ISBN ��ͬ
            {
                std::cout << trans1.isbn() << "����" << num << "�����ۼ�¼" << std::endl;
                trans1 = trans2;
                num = 1;
            }
        }
        std::cout << trans1.isbn() << "����" << num << "�����ۼ�¼" << std::endl;
    }
    else
    {
        std::cout << "û������" << std::endl;
        return -1;
    }

    return 0;
}
