#include <iostream>
#include <vector>
#include <complex>
#include <eigen3/Eigen/Dense>
#include "superposition.h"
#include <eigen3/unsupported/Eigen/KroneckerProduct>

int main() {
    try {
        size_t num_qubits = 3;
        kazuha::Superposition superposition(num_qubits);

        // Create a superposition state
        std::vector<std::complex<double>> amplitudes(1 << num_qubits, std::complex<double>(0.0, 0.0));
        amplitudes[0] = std::complex<double>(1.0 / std::sqrt(2), 0.0);
        amplitudes[1] = std::complex<double>(1.0 / std::sqrt(2), 0.0);
        superposition.setSuperposition(amplitudes);

        std::cout << "Initial superposition state:\n" << superposition.getStateVector() << std::endl;

        // Measure probability of the basis state |101>
        size_t state_index = 5; // Binary 101
        double probability = superposition.measureProbability(state_index);
        std::cout << "Probability of measuring state |" << state_index << ">: " << probability << std::endl;

        // Compute expectation value for a custom observable
        Eigen::MatrixXcd observable(8, 8);
        observable.setZero();
        observable(5, 5) = 1.0; // Example observable matrix with a single non-zero entry

        double expectation_value = superposition.computeExpectationValue(observable);
        std::cout << "Expectation value: " << expectation_value << std::endl;

        // Measure in a custom basis
        Eigen::MatrixXcd measurement_basis(8, 8);
        measurement_basis.setZero();
        measurement_basis(5, 5) = 1.0; // Example measurement basis

        size_t measured_index = superposition.measureInBasis(measurement_basis);
        std::cout << "Measured index: " << measured_index << std::endl;

        // Calculate fidelity with a different state
        Eigen::VectorXcd other_state(8);
        other_state.setZero();
        other_state(3) = std::complex<double>(1.0, 0.0);

        double fidelity = superposition.calculateFidelity(other_state);
        std::cout << "Fidelity with another state: " << fidelity << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
