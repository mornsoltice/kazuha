#include "../include/qft.h"

namespace kazuha {

Eigen::MatrixXcd QFT::computeQFTMatrix(size_t num_qubits) {
    size_t dim = 1 << num_qubits;
    Eigen::MatrixXcd qft_matrix(dim, dim);
    const std::complex<double> I(0, 1);
    for (size_t i = 0; i < dim; ++i) {
        for (size_t j = 0; j < dim; ++j) {
            qft_matrix(i, j) = std::exp(2.0 * M_PI * I * static_cast<double>(i * j) / static_cast<double>(dim)) / std::sqrt(dim);
        }
    }
    return qft_matrix;
}

Eigen::VectorXcd QFT::applyQFT(const Eigen::VectorXcd& state_vector) {
    size_t num_qubits = static_cast<size_t>(std::log2(state_vector.size()));
    Eigen::MatrixXcd qft_matrix = computeQFTMatrix(num_qubits);
    return qft_matrix * state_vector;
}

} // namespace kazuha
