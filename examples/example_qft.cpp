#include "../include/qft.h"

int main() {
    size_t num_qubits = 3;
    Eigen::VectorXcd state_vector(1 << num_qubits);
    state_vector.setZero();
    state_vector[0] = 1.0;  // Initialize state |000>

    std::cout << "Initial state vector:\n" << state_vector << std::endl;

    Eigen::VectorXcd qft_state = kazuha::QFT::applyQFT(state_vector);

    std::cout << "State vector after QFT:\n" << qft_state << std::endl;

    return 0;
}
