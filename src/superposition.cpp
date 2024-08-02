#include "../include/superposition.h"
#include <cmath>
#include <stdexcept>

namespace kazuha {

    Superposition::Superposition(size_t num_qubits)
        : num_qubits(num_qubits), state_vector(Eigen::VectorXcd::Zero(1 << num_qubits)) {
        // Initialize state vector to the |0...0> state
        state_vector(0) = std::complex<double>(1.0, 0.0);
    }

    void Superposition::setSuperposition(const std::vector<std::complex<double>>& amplitudes) {
        if (amplitudes.size() != state_vector.size()) {
            throw std::invalid_argument("Size of amplitudes does not match state vector size.");
        }
        for (size_t i = 0; i < amplitudes.size(); ++i) {
            state_vector(i) = amplitudes[i];
        }
        normalize();
    }

    void Superposition::applyQuantumGate(const Eigen::MatrixXcd& gate) {
        if (gate.rows() != state_vector.size() || gate.cols() != state_vector.size()) {
            throw std::invalid_argument("Gate size does not match state vector size.");
        }
        state_vector = gate * state_vector;
        normalize();
    }

    double Superposition::measureProbability(size_t state_index) const {
        if (state_index >= state_vector.size()) {
            throw std::out_of_range("State index out of range.");
        }
        return std::norm(state_vector(state_index));
    }

    double Superposition::computeExpectationValue(const Eigen::MatrixXcd& observable) const {
        if (observable.rows() != state_vector.size() || observable.cols() != state_vector.size()) {
            throw std::invalid_argument("Observable size does not match state vector size.");
        }
        Eigen::MatrixXcd density_matrix = computeDensityMatrix();
        return (density_matrix.cwiseProduct(observable)).sum().real();
    }

    size_t Superposition::measureInBasis(const Eigen::MatrixXcd& measurement_basis) const {
        if (measurement_basis.rows() != state_vector.size() || measurement_basis.cols() != state_vector.size()) {
            throw std::invalid_argument("Measurement basis size does not match state vector size.");
        }

        Eigen::VectorXd probabilities(state_vector.size());
        for (size_t i = 0; i < state_vector.size(); ++i) {
            Eigen::VectorXcd basis_state = measurement_basis.col(i);
            probabilities(i) = std::norm(basis_state.dot(state_vector));
        }

        // Find the index with the highest probability
        size_t result_index;
        probabilities.maxCoeff(&result_index);
        return result_index;
    }

    Eigen::VectorXcd Superposition::getStateVector() const {
        return state_vector;
    }

    void Superposition::applyUnitary(const Eigen::MatrixXcd& unitary) {
        if (unitary.rows() != state_vector.size() || unitary.cols() != state_vector.size()) {
            throw std::invalid_argument("Unitary size does not match state vector size.");
        }
        state_vector = unitary * state_vector;
        normalize();
    }

    std::vector<double> Superposition::getProbabilityDistribution() const {
        std::vector<double> probabilities(state_vector.size());
        for (size_t i = 0; i < state_vector.size(); ++i) {
            probabilities[i] = std::norm(state_vector(i));
        }
        return probabilities;
    }

    double Superposition::calculateFidelity(const Eigen::VectorXcd& other_state) const {
        if (other_state.size() != state_vector.size()) {
            throw std::invalid_argument("Other state size does not match current state size.");
        }
        Eigen::VectorXcd overlap = state_vector.adjoint() * other_state;
        return std::norm(overlap(0));
    }

    void Superposition::normalize() {
        double norm = std::sqrt(state_vector.squaredNorm());
        if (norm == 0) {
            throw std::runtime_error("Normalization failed due to zero norm.");
        }
        state_vector /= norm;
    }

    Eigen::MatrixXcd Superposition::computeDensityMatrix() const {
        return state_vector * state_vector.adjoint();
    }

} // namespace kazuha
