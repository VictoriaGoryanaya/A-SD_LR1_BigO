//goryanaya
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <unordered_set>
int duplicates_count(const std::vector<int>& arr)
{
    int duplicates = 0;
    for (int i = 0; i < (arr.size() - 1); ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[i] == arr[j])
            {
                ++duplicates;
                break;
            }
        }
    }
    return duplicates;
}

std::unordered_set<int> duplicates_count_set(const std::vector<int>& arr)
{
    std::unordered_set<int> unique;
    std::unordered_set<int> duplicates;
    for (int num : arr)
    {
        if (unique.count(num) > 0) {
            duplicates.insert(num);
        }
        else
        unique.insert(num);
    }
    return duplicates;
}
std::vector<int> generate_random_list(int n,  int min_val = 0, int max_val = 100)
{
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i){
        arr[i] = min_val + rand() % (max_val - min_val + 1);
    }
    return arr;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    std::vector<int> sizes = {1000, 5000, 10000};
    for (int n : sizes)
    {
        std::vector<int> arr = generate_random_list(n, 0, 1000);

        auto start = std::chrono::high_resolution_clock::now();
        int count = duplicates_count(arr);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        auto start_set = std::chrono::high_resolution_clock::now();
        int count_set = duplicates_count(arr);
        auto end_set = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_set = end_set - start_set;

        std::cout << "List size: " << n << "\n";
        std::cout << "Naive : Count: " << count << "\n";
        std::cout << "Naive : Spent time: " << elapsed.count() << "secs\n";
        std::cout << "Comlexity of the algorithm is O(n)**2\n";
        std::cout << "Set : Count: " << count_set << "\n";
        std::cout << "Set : Spent time: " << elapsed_set.count() << "secs\n";
        std::cout << "Comlexity of the algorithm is O(n)\n";
        std::cout << "-----------------------------------\n";
    }
    return 0;
}