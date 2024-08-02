#ifndef ENTANGLEMENT_H
#define ENTANGLEMENT_H 

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include "kazuha.h"

namespace kazuha {
  class Entanglement {
    public:  
      // Bell States (Entangled States 2 Bit)
      static Eigen::VectorXcd createBellState();

      static Eigen::VectorXcd createCustomEntangledState(const Eigen::Matrix2cd& unitary);

      static Eigen::VectorXcd applyUnitaryToEntangle(const Eigen::VectorXcd& state, const Eigen::MatrixXcd& unitary);

      static bool isEntangled(const Eigen::VectorXcd& state);

      // GHZ State (N-bit Entangled States)
      static Eigen::VectorXcd createGHZState(int num_bits);

      // Measure Entanglement
      static double measureEntanglement(const Eigen::VectorXcd& state);
    
    private:
      static bool isPureState(const Eigen::VectorXcd& state);
  };

} // namespace kazuha

#endif // ENTANGLEMENT_H
