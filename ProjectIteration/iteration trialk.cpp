#include <iostream>
#include <vector>

using namespace std;

class point
{
public:
    int x;
    int y;
};

int main()
{
    std::vector<point> points = { {1, 2},  {2, 3},{1, 3} };

    points.emplace_back(1, 2);
    points.emplace_back(2, 3);

    // Print all elements of vector to stdout

        //for(auto p = points.cbegin(); p != points.cend(); ++p)
    for (const auto& p : points)
    {
        std::cout << p.x << endl;
        std::cout << p.y << endl;
    }

    return 0;
}
