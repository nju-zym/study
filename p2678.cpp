#include <iostream>

class solution
{
private:
    int L, N, M;
    int *arr;

public:
    void input()
    {
        std::cin >> L >> N >> M;
        arr = new int[N + 2];
        arr[0] = 0;
        for (int i = 1; i <= N; i++)
        {
            std::cin >> arr[i];
        }
        arr[N + 1] = L;
    }

    bool judge(int x)
    {
        int last = 0, cnt = 0;
        for (int i = 1; i <= N + 1; i++)
        {
            if (arr[i] - arr[last] < x)
            {
                cnt++;
            }
            else
            {
                last = i;
            }
        }
        return cnt <= M;
    }

    void solve()
    {
        int l = 0, r = L;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (judge(mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        std::cout << l << std::endl;
        delete[] arr;
    }
};

int main()
{
    solution p;
    p.input();
    p.solve();
    return 0;
}
// 二分答案