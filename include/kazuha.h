#ifndef KAZUHA_H
#define KAZUHA_H 

#include <vector>
#include <eigen3/Eigen/Dense>

namespace kazuha {
  class QuantumGate {
  public:
    QuantumGate(int qubits);
    void apply(Eigen::VectorXcd& state);
  private:
    int qubits; 
    Eigen::MatrixXcd& gate_matrix;
  };

  class QuantumCircuit {
    public:
      QuantumCircuit(int qubits);
      void addGate(const QuantumGate& gate);
      void execute(Eigen::VectorXcd& state);
    private:
      int qubits;
      std::vector<QuantumGate> gates;
  };
} // namespace kazuha   

#endif // !KAZUHA_H

