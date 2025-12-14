#include "utils/window_utils.hpp"

namespace window_size {
    unsigned int w() {
        return sf::VideoMode::getDesktopMode().width;
    }
    unsigned int h() {
        return sf::VideoMode::getDesktopMode().height;
    }
}