//goryanaya
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm> //std::count, max

int list_merging(std::vector<int>& arr1, const std::vector<int>& arr2)
{
    for (int j = 0; j < arr2.size(); ++j)
    {
        for (int i = 0; i < arr1.size(); ++i)
        {
            if (i == arr1.size())
            arr1.push_back(arr2[j]);
        }
    }
    return arr1.size();
}

int list_merging_copy(std::vector<int>& arr1, std::vector<int>& arr2)
{
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1.size();
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

void draw_bar(const std::string& label, double value, double max_value, int width = 50){
    int bar_len = static_cast<int>((value/max_value) * width);
    if (bar_len == 0)
    bar_len = 1;
    std::cout << label <<" (" << value <<" secs): " << std::string(bar_len, '#') << "\n";
}
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    std::vector<int> sizes = {1000, 10000, 100000};

    for (int n : sizes)
    {
        std::vector<int> arr_pt1 = generate_random_list(n, 0, 1000);
        std::vector<int> arr_pt2 = generate_random_list(n, 0, 1000);

        auto start = std::chrono::high_resolution_clock::now();
        int new_size = list_merging(arr_pt1, arr_pt2);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        auto start_copy = std::chrono::high_resolution_clock::now();
        int new_size_copy = list_merging_copy(arr_pt1, arr_pt2);
        auto end_copy = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_copy = end_copy - start_copy;

        std::cout << "List size: " << n << "\n";
        std::cout << "New size : cycles: " << new_size << "\n";
        std::cout << "Spent time : cycles: " << elapsed.count() << "secs\n";
        std::cout << "Comlexity of the algorithm is O(n)**2\n";

        std::cout << "New size : copy: " << new_size_copy << "\n";
        std::cout << "Spent time : copy: " << elapsed_copy.count() << "secs\n";
        std::cout << "Comlexity of the algorithm is O(n)\n";

        double max_time = std::max(elapsed.count(), elapsed_copy.count());
        std::cout <<"Visualization:\n";
        draw_bar("Cycles", elapsed.count(), max_time);
        draw_bar("Copy  ", elapsed_copy.count(), max_time);
        std::cout << "-----------------------------------\n";
    }
    return 0;
}