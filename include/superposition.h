#ifndef SUPERPOSITION_H
#define SUPERPOSITION_H 

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <vector>
#include <complex>
#include <stdexcept>

namespace kazuha {

    class Superposition {
    public:
        // Constructor initializes the quantum state with a given size
        Superposition(size_t num_qubits);

        // Sets the state vector to a superposition of the basis states
        void setSuperposition(const std::vector<std::complex<double>>& amplitudes);

        // Applies a quantum gate to the current state
        void applyQuantumGate(const Eigen::MatrixXcd& gate);

        // Computes the probability of measuring a specific basis state
        double measureProbability(size_t state_index) const;

        // Computes the expectation value of an observable
        double computeExpectationValue(const Eigen::MatrixXcd& observable) const;

        // Measures the state in a given basis and returns the measurement result
        size_t measureInBasis(const Eigen::MatrixXcd& measurement_basis) const;

        // Returns the state vector
        Eigen::VectorXcd getStateVector() const;

        // Applies a unitary transformation to the state vector
        void applyUnitary(const Eigen::MatrixXcd& unitary);

        // Gets the probability distribution of the state vector
        std::vector<double> getProbabilityDistribution() const;

        // Calculates the fidelity between two quantum states
        double calculateFidelity(const Eigen::VectorXcd& other_state) const;

    private:
        size_t num_qubits;
        Eigen::VectorXcd state_vector;

        // Helper function to normalize the state vector
        void normalize();

        // Helper function to compute the density matrix
        Eigen::MatrixXcd computeDensityMatrix() const;
    };

} // namespace kazuha

#endif // SUPERPOSITION_H
