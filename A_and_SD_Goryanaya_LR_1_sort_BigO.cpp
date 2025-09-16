//goryanaya
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

std::string sorted_array(const std::vector<int>& arr) //проверка отсортированности
{
    std::string cond = "sorted";
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            for (int j = 0; j < arr.size(); ++j)
            {
                if (arr[j] >= arr[j + 1])
                continue;
                else 
                cond = "unsorted";
            }
            return cond;
        } else if (arr[i] < arr[i + 1])
        {
            for (int k = 0; k < arr.size(); ++k)
            {
                if (arr[k] <= arr[k + 1])
                continue;
                else
                cond = "unsorted";
            }
            return cond;
        } else 
        continue;
    }
    return cond;
}

std::vector<int> generate_random_list(int n,  int min_val = 0, int max_val = 100)
{
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = min_val + rand() % (max_val - min_val + 1);
    }
    return arr;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    std::vector<int> sizes = {10, 1000, 10000};

    for (int n : sizes)
    {
        std::vector<int> arr = generate_random_list(n, 0, 1000);

        auto start = std::chrono::high_resolution_clock::now();
        std::string sort = sorted_array(arr);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;

        std::cout << "List size: " << n << "\n";
        std::cout << "Condition: " << sort << "\n";
        std::cout << "Spent time: " << elapsed.count() << "secs\n";
        std::cout << "Comlexity of the algorithm is O(n)\n";
        std::cout << "-----------------------------------\n";
    }
    return 0;
}