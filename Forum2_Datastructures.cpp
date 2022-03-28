/*
Group 1
Members: Alfin, Ian, Justin
*/

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Factorial using recursion
int factRecur(int num)
{
    if (num == 0) 
    {
        return 1; // Base case
    }
    return num * factRecur(num - 1); // General case
}

// Factorial using iteration
int factIter(int num)
{
    int sum = 1;
    for (num; num > 0; num--) // num > 0 is Base Case
    {
        sum = sum * num; // General Case
    }
    return sum;
}

// Combination function through recursion
int combinationRecur(int n, int r)
{
    return factRecur(n) / (factRecur(r) * factRecur(n - r)); // Formula using recursion
}

// Combination function through iteration
int combinationIter(int n, int r)
{
    return factIter(n) / (factIter(r) * factIter(n - r)); // Formula using iteration
}

int main()
{
    // Results using recursion
    auto start = high_resolution_clock::now();
    std::cout << combinationRecur(10, 2) << std::endl;  // Expected result: 45
    std::cout << combinationRecur(8, 3) << std::endl;   // Expected result: 56
    std::cout << combinationRecur(5, 2) << std::endl;   // Expected result: 10
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout<<duration.count() <<" Microseconds"<< std::endl;
    
    // Results using iteration
    auto start2 = high_resolution_clock::now();
    std::cout << combinationIter(10, 2) << std::endl;   // Expected result: 45
    std::cout << combinationIter(8, 3) << std::endl;    // Expected result: 56
    std::cout << combinationIter(5, 2) << std::endl;    // Expected result: 10
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    std::cout<<duration2.count() <<" Microseconds"<< std::endl;
}

// Note: chrono might not be that accurate since how fast the code run, which can result in inconsistent time and even 0 microsecond output