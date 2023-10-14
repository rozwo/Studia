#include <bits/stdc++.h>

namespace streams {

    class input {
        std::ifstream is;

        friend input& operator>>(input& in, int& target);

    public:
        bool eof();
        input(std::string file_name);

        input(const input& in)          = delete;
        auto operator=(const input& in) = delete;
        input(input&& in)               = delete;
        auto operator=(input&& in)      = delete;

        ~input();
    };

    class output {
        std::ofstream os;

        friend output& operator<<(output& out, int source);

    public:
        output(std::string file_name);
        
        output(const output& out)         = delete;
        auto operator=(const output& out) = delete;
        output(output&& out)              = delete;
        auto operator=(output&& out)      = delete;

        ~output();
    };

    input& operator>>(input& in, int& target);
    output& operator<<(output& out, int source);

}
