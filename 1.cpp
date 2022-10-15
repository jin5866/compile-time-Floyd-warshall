
#include <iostream>
#include <vector>

constexpr int dist[4][4] = {
    //4*4 
    {0, 1, 10, 1},
    {1, 0, 1, 10},
    {10, 1, 0, 1},
    {1, 10, 1, 0}
};



template <int k, int i, int j>
constexpr int floyd() {
    // compile time constant
    if constexpr (k == 0) {
        return std::min(dist[i][j],dist[i][k]+dist[k][j]);
    }
    else {
        return std::min(floyd<k - 1, i, j>(), floyd<k - 1, i, k>() + floyd<k - 1, k, j>());
    }
}

int main()
{
    //constexpr int result{ floyd<3, 0, 3>() };
    //std::cout << result;
    //floyd result vector
    constexpr int re[4][4] = {
        {floyd<3, 0, 0>(), floyd<3, 0, 1>(), floyd<3, 0, 2>(), floyd<3, 0, 3>()},
        {floyd<3, 1, 0>(), floyd<3, 1, 1>(), floyd<3, 1, 2>(), floyd<3, 1, 3>()},
        {floyd<3, 2, 0>(), floyd<3, 2, 1>(), floyd<3, 2, 2>(), floyd<3, 2, 3>()},
        {floyd<3, 3, 0>(), floyd<3, 3, 1>(), floyd<3, 3, 2>(), floyd<3, 3, 3>()}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << re[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

