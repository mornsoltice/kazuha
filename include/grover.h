#ifndef GROVER_H
#define GROVER_H

#include "kazuha.h"
#include <eigen3/Eigen/src/Core/Matrix.h>

namespace kazuha {

class Grover {
public:
  Grover(int n);
  void applyOracle(Eigen::VectorXcd &state,
                   const std::vector<int> &target_indices);
  void applyDiffusion(Eigen::VectorXcd &state);
  Eigen::VectorXcd run(const std::vector<int> &target_indices, int iterations);

private:
  int num_qubits;
  int dim;
  Eigen::MatrixXcd oracle;
  Eigen::MatrixXcd diffusion;
};

} // namespace kazuha

#endif // !GROVER_H
