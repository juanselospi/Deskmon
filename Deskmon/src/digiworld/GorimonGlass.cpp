#include "digiworld/GorimonGlass.hpp" //window_utils

GorimonGlass::GorimonGlass() : window(sf::VideoMode(
            static_cast<unsigned>(window_size::w()), 
            static_cast<unsigned>(window_size::h())
        ), 
        "Digital World", 
        sf::Style::None
    ) {

    HWND hwnd = window.getSystemHandle();
    LONG exStyle = GetWindowLong(hwnd, GWL_EXSTYLE);
    
    exStyle = exStyle | WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST; //| WS_EX_NOACTIVATE;

    SetWindowLong(hwnd, GWL_EXSTYLE, exStyle);
    SetLayeredWindowAttributes(hwnd, RGB(1, 0, 1), 0, LWA_COLORKEY);
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

    // Mostrar sin activar
    ShowWindow(hwnd, SW_SHOWNOACTIVATE);
    SetForegroundWindow(GetDesktopWindow());  // Mandar el foco al escritorio
}

void GorimonGlass::display() {
    window.display();
}

void GorimonGlass::clear() {
    window.clear(sf::Color(1, 0, 1));
}

void GorimonGlass::close() {
    window.close();
}

bool GorimonGlass::isOpen() const{
    return window.isOpen();
}

bool GorimonGlass::pollEvent(sf::Event& event) {
    return window.pollEvent(event);
}

void GorimonGlass::draw(const sf::Sprite& digimon) {
    window.draw(digimon);
}

int GorimonGlass::getTaskbarCoord(const std::string& position) const {
    APPBARDATA abd = {};
    abd.cbSize = sizeof(APPBARDATA);

    if(!SHAppBarMessage(ABM_GETTASKBARPOS, &abd)) {
        return -1;
    }

    if(position == "top") return abd.rc.top;
    if(position == "bottom") return abd.rc.bottom;
    if(position == "left") return abd.rc.left;
    if(position == "right") return abd.rc.right;

    return -1;
}

int GorimonGlass::getWindowCoord(const std::string& position) const {
    HWND hwnd = window.getSystemHandle();
    RECT rect;

    if(!GetWindowRect(hwnd, &rect)) {
        return -1;
    }

    if(position == "top") return rect.top;
    if(position == "bottom") return rect.bottom;
    if(position == "left") return rect.left;
    if(position == "right") return rect.right;

    return -1;
}

GorimonGlass::~GorimonGlass() {}