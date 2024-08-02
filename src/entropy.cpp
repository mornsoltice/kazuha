#include "../include/entropy.h"

namespace kazuha {

double Entropy::computeVonNeumannEntropy(const Eigen::MatrixXcd& density_matrix) {
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXcd> eigen_solver(density_matrix);
    Eigen::VectorXd eigenvalues = eigen_solver.eigenvalues();

    double entropy = 0.0;
    for (int i = 0; i < eigenvalues.size(); ++i) {
        if (eigenvalues[i] > 0) {
            entropy -= eigenvalues[i] * std::log2(eigenvalues[i]);
        }
    }
    return entropy;
}

double Entropy::computeShannonEntropy(const Eigen::VectorXcd& state_vector) {
    Eigen::VectorXd probabilities = calculateProbabilities(state_vector);
    double entropy = 0.0;
    for (int i = 0; i < probabilities.size(); ++i) {
        if (probabilities[i] > 0) {
            entropy -= probabilities[i] * std::log2(probabilities[i]);
        }
    }
    return entropy;
}

Eigen::VectorXd Entropy::calculateProbabilities(const Eigen::VectorXcd& state_vector) {
    Eigen::VectorXd probabilities(state_vector.size());
    for (int i = 0; i < state_vector.size(); ++i) {
        probabilities[i] = std::norm(state_vector[i]);
    }
    return probabilities;
}

} // namespace kazuha
