#include "TArray.h"

int main()
{
    TArray<int, 4> numbers {2, 4, 6, 8};
    std::cout << "Second element: " << numbers[1] << std::endl;
    numbers[0] = 5;
    std::cout << "numbers " << numbers;

    std::cout << std::endl;

    TArray<char, 3> chars {'a', 'b', 'c'};
    std::cout << "chars " << chars;
    
    std::cout << std::endl;
    
    TArray<int, 4> numbers2 {-1, -3, -5, -9};
    numbers.swap(numbers2);
    std::cout << "#1 numbers " << numbers << std::endl;
    std::cout << "#2 numbers " << numbers2;
    
    return 0;
}
