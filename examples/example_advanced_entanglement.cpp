#include "entanglement.h"
#include <iostream>

int main() {
    try {
        Eigen::VectorXcd bell_state = kazuha::Entanglement::createBellState();
        Eigen::VectorXcd ghz_state = kazuha::Entanglement::createGHZState(3);

        std::cout << "Bell state:\n" << bell_state << std::endl;
        std::cout << "GHZ state:\n" << ghz_state << std::endl;

        double entanglement_measurement = kazuha::Entanglement::measureEntanglement(bell_state);
        std::cout << "Entanglement measurement of Bell state: " << entanglement_measurement << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
