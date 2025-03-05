#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

// 自定义哈希函数，用于哈希pair<int, vector<bool>>
struct PairVectorBoolHash
{
    std::size_t operator()(const std::pair<int, std::vector<bool>> &p) const
    {
        std::size_t seed = std::hash<int>{}(p.first);

        // 组合vector<bool>的哈希值
        for (bool b : p.second)
        {
            // 使用标准的哈希组合技术
            seed ^= std::hash<bool>{}(b) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution
{
private:
    // 使用自定义哈希的记忆化表
    std::unordered_map<std::pair<int, std::vector<bool>>, int, PairVectorBoolHash> memo;

    int dp(int pos, std::vector<bool> &blocked, int n)
    {
        if (pos == n)
            return 1; // 到达顶部
        if (pos > n)
            return 0; // 超出顶部

        // 创建键：当前位置和障碍物状态的组合
        std::pair<int, std::vector<bool>> key = {pos, blocked};

        // 检查记忆化表
        if (memo.count(key))
            return memo[key];

        // 放置障碍物
        bool added = false;
        if (2 * pos <= n)
        {
            // 确保vector大小足够
            if (2 * pos >= blocked.size())
            {
                blocked.resize(2 * pos + 1, false);
            }

            if (!blocked[2 * pos])
            {
                blocked[2 * pos] = true;
                added = true;
            }
        }

        int ways = 0;

        // 尝试爬1阶
        if (pos + 1 <= n)
        {
            // 确保vector大小足够
            if (pos + 1 >= blocked.size())
            {
                blocked.resize(pos + 2, false);
            }

            if (!blocked[pos + 1])
            {
                ways += dp(pos + 1, blocked, n);
            }
        }

        // 尝试爬2阶
        if (pos + 2 <= n)
        {
            // 确保vector大小足够
            if (pos + 2 >= blocked.size())
            {
                blocked.resize(pos + 3, false);
            }

            if (!blocked[pos + 2])
            {
                ways += dp(pos + 2, blocked, n);
            }
        }

        // 回溯：移除障碍物
        if (added)
            blocked[2 * pos] = false;

        // 记忆结果
        memo[key] = ways;
        return ways;
    }

public:
    int climbStairs(int n)
    {
        // 预分配足够大的vector以提高性能
        std::vector<bool> blocked(n + 1, false);
        return dp(0, blocked, n);
    }
};

int main()
{
    int n;
    std::cin >> n;
    Solution sol;
    std::cout << sol.climbStairs(n) << std::endl;
    return 0;
}