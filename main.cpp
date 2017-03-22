#include "TArray.h"

int main()
{
    TArray  <int>arr1(3);
    for (int i = 0; i < 3; ++i) // { 0 1 2 }
        arr1.push_back(i);

    TArray <int>arr2(6);
    for (int i = 0; i < 6; ++i) // { 0 1 2 3 4 5 }
        arr2.push_back(i);

    TArray <std::string>arr3(4);
    arr3.push_back("a");
    arr3.push_back("b");
    arr3.push_back("c");
    arr3.push_back("d");
    try
    {
        arr3.push_back("alpha");
    }
    catch (const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    arr1.swap(arr2);
    std::cout << "Arr1 " << arr1 << std::endl;
    std::cout << "Arr2 " << arr2 << std::endl;
    std::cout << "Arr3 " << arr3 << std::endl;

    std::cout << std::endl;

    arr1.fill(2,500);
    std::cout << "Arr1[2] = " << arr1.get(2) << std::endl;

    std::cout << std::endl;

    std::cout << "Arr3 First element - " << arr3.front() << std::endl;
    std::cout << "Arr3 Second element - " << arr3.back() << std::endl;

    std::cout << std::endl;

    TArray <int>arr_check(arr1);
    std::cout << "Arr1 " << arr1 << std::endl;
    std::cout << "Arr_check " << arr_check << std::endl;

    std::cout << std::endl;

    try
    {
        TArray<int>::value_type item = arr2.at(1000);
    }
    catch (const std::exception & e)
    {
        std::cout << e.what();
    }
    return 0;
}