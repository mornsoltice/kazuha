#ifndef QFT_H
#define QFT_H

#include "kazuha.h"
#include <vector>
#include <complex>

namespace kazuha {

class QFT {
public:
    // Apply QFT to a state vector
    static Eigen::VectorXcd applyQFT(const Eigen::VectorXcd& state_vector);

private:
    // Utility function to calculate the QFT matrix
    static Eigen::MatrixXcd computeQFTMatrix(size_t num_qubits);
};

} // namespace kazuha

#endif // QFT_H
