#include "input.hpp"

streams::input& streams::operator>>(streams::input& in, int& target) {
    target = in.is.get();    

    return in;
}

bool streams::input::eof() {
    return is.peek() == EOF;
}

streams::output& streams::operator<<(streams::output& out, int source) {
    out.os.put((uint8_t)source);

    return out;
}

streams::input::input(std::string file_name) {
    this->is.exceptions(std::ios_base::badbit | std::ios_base::failbit);
    this->is.open(file_name, std::ios::binary);
}

streams::input::~input() {
    is.close();
}

streams::output::output(std::string file_name) {
    this->os.exceptions(std::ios_base::badbit | std::ios_base::failbit);
    this->os.open(file_name, std::ios::binary);
}

streams::output::~output() {
    this->os.close();
}