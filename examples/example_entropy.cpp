#include "../include/entropy.h"

int main() {
    // Example state vector |ψ> = (|0> + |1>) / sqrt(2)
    Eigen::VectorXcd state_vector(2);
    state_vector << std::complex<double>(1.0 / std::sqrt(2), 0.0),
                    std::complex<double>(1.0 / std::sqrt(2), 0.0);

    double shannon_entropy = kazuha::Entropy::computeShannonEntropy(state_vector);
    std::cout << "Shannon entropy: " << shannon_entropy << std::endl;

    // Density matrix ρ = |ψ><ψ|
    Eigen::MatrixXcd density_matrix = state_vector * state_vector.adjoint();

    double von_neumann_entropy = kazuha::Entropy::computeVonNeumannEntropy(density_matrix);
    std::cout << "Von Neumann entropy: " << von_neumann_entropy << std::endl;

    return 0;
}
