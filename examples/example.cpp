#include "kazuha.h"
#include <iostream>

int main() {
    int qubits = 3;
    kazuha::QuantumCircuit circuit(qubits);

    // Create a state vector with 2^qubits elements initialized to 1/sqrt(2^qubits)
    Eigen::VectorXcd state = Eigen::VectorXcd::Constant(1 << qubits, std::complex<double>(1.0 / std::sqrt(1 << qubits), 0.0));

    // Add Hadamard gate to all qubits
    for (int i = 0; i < qubits; ++i) {
        circuit.addGate(kazuha::QuantumGate::Hadamard(qubits, i));
    }

    // Execute the circuit
    circuit.execute(state);

    // Print the resulting state vector
    std::cout << "State vector after applying Hadamard gates:\n" << state << std::endl;

    return 0;
}
