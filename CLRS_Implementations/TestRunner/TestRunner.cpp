#include "E:\clrsc++\CLRS_Implementations\Algorithms\quick_sort.h" 
#include <iostream>
#include <vector>
using namespace std;
using namespace clrs::algo;

/**
 * @brief 辅助函数，用于打印 vector 内容
 * @param title 打印时显示的标题
 * @param vec 要打印的 vector
 */
void printVector(const string& title, const vector<int>& vec) {
    cout << title;
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    // 1. 准备一个待排序的测试 vector
    vector<int> numbers = { 10, 7, 8, 9, 1, 5, 12, -3, 42, 0 };

    // 2. 打印排序前的数组
    printVector("Original array: ", numbers);


    quick_sort(numbers); // 假设您使用了我上次建议的函数名

    // 如果您的“入口”函数名就叫 quick_sort，那就这样调用：
    // quick_sort(numbers); 
    //
    // (请确保您在 quick_sort.h 里声明了
    //  void quick_sort(std::vector<int>& a); 这个函数)

    // 4. 打印排序后的结果
    printVector("ok lets go",numbers);

    return 0;
}