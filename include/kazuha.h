#ifndef KAZUHA_H
#define KAZUHA_H

#include <eigen3/Eigen/Dense>
#include <vector>

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
