#include <iostream>
using namespace std;

int main()
{
    int arr[20];
    arr[0] = 1;
    arr[1] = 3;
    for (int i = 2; i < 20; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    for (int i = 0; i < 20; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int even_sum[10];
    even_sum[0] = 3;
    cout << even_sum[0] << " ";
    for (int i = 1; i < 10; i++)
    {
        even_sum[i] = even_sum[i - 1] + arr[2 * i + 1];
        cout << even_sum[i] << " ";
    }
    cout << endl;
    int odd_sum[10];
    odd_sum[0] = 1;
    cout << odd_sum[0] << " ";
    for (int i = 1; i < 10; i++)
    {
        odd_sum[i] = odd_sum[i - 1] + arr[2 * i];
        cout << odd_sum[i] << " ";
    }
    cout << endl;
    int sum[20];
    sum[0] = 1;
    cout << sum[0] << " ";
    for (int i = 1; i < 20; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
        cout << sum[i] << " ";
    }
    cout << endl;
    return 0;
}