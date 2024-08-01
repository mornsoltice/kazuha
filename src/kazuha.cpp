#include "kazuha.h"
#include <cmath>
#include <iostream>

namespace kazuha {

    QuantumGate::QuantumGate(int qubits) 
        : qubits(qubits) {
        gate_matrix = Eigen::MatrixXcd::Identity(1 << qubits, 1 << qubits);
    }

    void QuantumGate::apply(Eigen::VectorXcd& state) const {
        state = gate_matrix * state;
    }

    QuantumGate QuantumGate::Hadamard(int qubits, int target) {
        QuantumGate gate(qubits);
        int size = 1 << qubits;
        double norm = 1.0 / std::sqrt(2);
        for (int i = 0; i < size; ++i) {
            int j = i ^ (1 << target);
            if (i < j) {
                gate.gate_matrix(i, i) = norm;
                gate.gate_matrix(i, j) = norm;
                gate.gate_matrix(j, i) = norm;
                gate.gate_matrix(j, j) = -norm;
            }
        }
        return gate;
    }

    QuantumGate QuantumGate::PauliX(int qubits, int target) {
        QuantumGate gate(qubits);
        int size = 1 << qubits;
        for (int i = 0; i < size; ++i) {
            int j = i ^ (1 << target);
            if (i < j) {
                gate.gate_matrix(i, i) = 0;
                gate.gate_matrix(j, j) = 0;
                gate.gate_matrix(i, j) = 1;
                gate.gate_matrix(j, i) = 1;
            }
        }
        return gate;
    }

    QuantumGate QuantumGate::PauliY(int qubits, int target) {
        QuantumGate gate(qubits);
        int size = 1 << qubits;
        for (int i = 0; i < size; ++i) {
            int j = i ^ (1 << target);
            if (i < j) {
                gate.gate_matrix(i, i) = 0;
                gate.gate_matrix(j, j) = 0;
                gate.gate_matrix(i, j) = std::complex<double>(0, 1);
                gate.gate_matrix(j, i) = std::complex<double>(0, -1);
            }
        }
        return gate;
    }

    QuantumGate QuantumGate::PauliZ(int qubits, int target) {
        QuantumGate gate(qubits);
        int size = 1 << qubits;
        for (int i = 0; i < size; ++i) {
            int j = i ^ (1 << target);
            if (i < j) {
                gate.gate_matrix(i, i) = 1;
                gate.gate_matrix(j, j) = -1;
            }
        }
        return gate;
    }

    QuantumCircuit::QuantumCircuit(int qubits) : qubits(qubits) {}

    void QuantumCircuit::addGate(const QuantumGate& gate) {
        gates.push_back(gate);
    }

    void QuantumCircuit::execute(Eigen::VectorXcd& state) const {
        for (const auto& gate : gates) {
            gate.apply(state);
        }
    }

} // namespace kazuha
