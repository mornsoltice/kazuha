#include "../include/grover.h"
#include <cmath>
#include <eigen3/Eigen/src/Core/Matrix.h>

using namespace kazuha;

Grover::Grover(int n) : num_qubits(n), dim(1 << n) {
  oracle = Eigen::MatrixXcd::Identity(dim, dim);
  diffusion = Eigen::MatrixXcd::Identity(dim, dim) * 2.0 / dim -
              Eigen::MatrixXcd::Identity(dim, dim);
}

void Grover::applyOracle(Eigen::VectorXcd &state,
                         const std::vector<int> &target_indices) {
  for (int idx : target_indices) {
    oracle(idx, idx) = -1;
  }
  state = oracle * state;
}

void Grover::applyDiffusion(Eigen::VectorXcd &state) {
  state = diffusion * state;
}

Eigen::VectorXcd Grover::run(const std::vector<int> &target_indices,
                             int iterations) {
  Eigen::VectorXcd state = Eigen::VectorXcd::Ones(dim) / std::sqrt(dim);

  for (int i = 0; i < iterations; i++) {
    applyOracle(state, target_indices);
    applyDiffusion(state);
  }

  return state;
}
