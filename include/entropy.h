#ifndef ENTROPY_H
#define ENTROPY_H

#include "kazuha.h"

namespace kazuha {

class Entropy {
public:
  // Calculate the von Neumann entropy given a density matrix
  static double computeVonNeumannEntropy(const Eigen::MatrixXcd& density_matrix);

  // Calculate the Shannon entropy given a state vector
  static double computeShannonEntropy(const Eigen::VectorXcd& state_vector);

private:
  // Utility function to calculate probabilities from a state vector
  static Eigen::VectorXd calculateProbabilities(const Eigen::VectorXcd& state_vector);
};

}

#endif // ENTROPY_H
