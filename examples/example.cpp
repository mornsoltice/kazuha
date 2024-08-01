#include "kazuha.h"
#include <iostream>
#include <Eigen/Dense>

int main() {
    kazuha::QuantumCircuit circuit(2);
    kazuha::QuantumGate gate(2);

    circuit.addGate(gate);

    Eigen::VectorXcd state(4); // 2 qubits -> 4 states
    state << 1, 0, 0, 0; // Initial state |00>

    circuit.execute(state);

    std::cout << "State after applying the quantum gate:\n" << state << std::endl;

    return 0;
}
