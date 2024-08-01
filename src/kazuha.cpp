#include "kazuha.h"
#include <iostream>

namespace kazuha {

    QuantumGate::QuantumGate(int qubits) : qubits(qubits), gate_matrix(Eigen::MatrixXcd::Identity(1 << qubits, 1 << qubits)) {}

    void QuantumGate::apply(Eigen::VectorXcd& state) {
        state = gate_matrix * state;
    }

    QuantumCircuit::QuantumCircuit(int qubits) : qubits(qubits) {}

    void QuantumCircuit::addGate(const QuantumGate& gate) {
        gates.push_back(gate);
    }

    void QuantumCircuit::execute(Eigen::VectorXcd& state) {
        for (const auto& gate : gates) {
            gate.apply(state);
        }
    }

} // namespace kazuha
