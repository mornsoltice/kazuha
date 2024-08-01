#include "entanglement.h"
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <cmath>

namespace kazuha {

    Eigen::VectorXcd Entanglement::createBellState() {
        Eigen::VectorXcd state(4);
        state.setZero();
        state(0) = 1.0 / std::sqrt(2);
        state(3) = 1.0 / std::sqrt(2);
        return state;
    }

    Eigen::VectorXcd Entanglement::createCustomEntangledState(const Eigen::Matrix2cd& unitary) {
        Eigen::VectorXcd initial_state(2);
        initial_state << 1, 0; // |0>
        return unitary * initial_state;
    }

    Eigen::VectorXcd Entanglement::applyUnitaryToEntangle(const Eigen::VectorXcd& state, const Eigen::MatrixXcd& unitary) { 
        return unitary * state;
    }

    bool Entanglement::isEntangled(const Eigen::VectorXcd& state) {
        // Simplified heuristic: check if the state has more than one non-zero component
        Eigen::VectorXcd::Index num_nonzero = (state.array() != std::complex<double>(0.0, 0.0)).count();
        return num_nonzero > 1;
    }

    Eigen::VectorXcd Entanglement::createGHZState(int num_bits) {
        if (num_bits < 2) {
            throw std::invalid_argument("Number of bits must be at least 2 for a GHZ state.");
        }

        Eigen::VectorXcd state(1 << num_bits);
        state.setZero();
        state(0) = 1.0 / std::sqrt(2);
        state((1 << num_bits) - 1) = 1.0 / std::sqrt(2);
        return state;
    }

    double Entanglement::measureEntanglement(const Eigen::VectorXcd& state) {
        // Placeholder implementation for measuring entanglement
        // This is a non-trivial task and requires advanced quantum mechanics to do properly
        // Here we just return a dummy value
        return 1.0;
    }

    bool Entanglement::isPureState(const Eigen::VectorXcd& state) {
        // Placeholder for a check to see if a state is pure
        // Actual implementation would need to verify if the state is a pure state
        return true;
    }

} // namespace kazuha
