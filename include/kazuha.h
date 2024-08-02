#ifndef KAZUHA_H
#define KAZUHA_H

#include <eigen3/Eigen/Dense>
#include <vector>
#include <eigen3/Eigen/Eigenvalues>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/SVD>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <numeric>
#include <ostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

namespace kazuha {
    // Quantum Gate
    class QuantumGate {
    public:
        QuantumGate(int qubits);
        void apply(Eigen::VectorXcd& state) const; // Mark as const
        
        // Quantum Logic Gate
        static QuantumGate Hadamard(int qubits, int target);
        static QuantumGate PauliX(int qubits, int target); 
        static QuantumGate PauliY(int qubits, int target);
        static QuantumGate PauliZ(int qubits, int target);
    private:
        int qubits;
        Eigen::MatrixXcd gate_matrix;
    };
    
    // Quantum Circuit
    class QuantumCircuit {
    public:
        QuantumCircuit(int qubits);
        void addGate(const QuantumGate& gate);
        void execute(Eigen::VectorXcd& state) const; // Mark as const
    private:
        int qubits;
        std::vector<QuantumGate> gates;
    };

} // namespace kazuha

#endif // KAZUHA_H
