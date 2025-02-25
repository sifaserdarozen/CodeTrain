class Solution {
    public:
        int reverse(int x) {
        int min = numeric_limits<int>::min() / 10;
        int min_rem = numeric_limits<int>::min() - min;
        int max = numeric_limits<int>::max() / 10;
        int max_rem = numeric_limits<int>::max() - max;
        int y = 0;
        while (x != 0) {
            const auto div = x / 10;
            const auto rem = x - div*10;
    
            if (y < min || y > max || (y == min && rem <= min_rem) || (y == max && rem >= max_rem)) { 
                std::cout << "y: " << y << " " << "rem: " << rem << std::endl;
                return 0;
            }
            y *= 10; 
            y += rem;
            x = div;
        }
    
        return y;
        }
    };