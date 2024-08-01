#include "gtest/gtest.h"
#include <eigen3/Eigen/Dense>
#include "kazuha.h"
#include "entanglement.h"

TEST(KazuhaTest, QuantumGateTest) {
    kazuha::QuantumGate gate(2);
    Eigen::VectorXcd state(4); // 2 qubits -> 4 states
    state << 1, 0, 0, 0; // Initial state |00>

    gate.apply(state);

    // The gate is an identity, so the state should remain unchanged
    EXPECT_EQ(state(0), std::complex<double>(1, 0));
    EXPECT_EQ(state(1), std::complex<double>(0, 0));
    EXPECT_EQ(state(2), std::complex<double>(0, 0));
    EXPECT_EQ(state(3), std::complex<double>(0, 0));
}

TEST(KazuhaTest, QuantumCircuitTest) {
    kazuha::QuantumCircuit circuit(2);
    kazuha::QuantumGate gate(2);
    circuit.addGate(gate);

    Eigen::VectorXcd state(4); // 2 qubits -> 4 states
    state << 1, 0, 0, 0; // Initial state |00>

    circuit.execute(state);

    // The circuit contains an identity gate, so the state should remain unchanged
    EXPECT_EQ(state(0), std::complex<double>(1, 0));
    EXPECT_EQ(state(1), std::complex<double>(0, 0));
    EXPECT_EQ(state(2), std::complex<double>(0, 0));
    EXPECT_EQ(state(3), std::complex<double>(0, 0));
}

TEST(QuantumGateTest, HadamardGate) {
    int qubits = 1;
    kazuha::QuantumGate gate = kazuha::QuantumGate::Hadamard(qubits, 0);
    Eigen::VectorXcd state(2);
    state << 1, 0;
    gate.apply(state);
    Eigen::VectorXcd expected_state(2);
    expected_state << 1/std::sqrt(2), 1/std::sqrt(2);
    ASSERT_TRUE(state.isApprox(expected_state));
}

TEST(QuantumGateTest, PauliXGate) {
    int qubits = 1;
    kazuha::QuantumGate gate = kazuha::QuantumGate::PauliX(qubits, 0);
    Eigen::VectorXcd state(2);
    state << 1, 0;
    gate.apply(state);
    Eigen::VectorXcd expected_state(2);
    expected_state << 0, 1;
    ASSERT_TRUE(state.isApprox(expected_state));
}

TEST(EntanglementTest, CreateBellState) {
    Eigen::VectorXcd bell_state = kazuha::Entanglement::createBellState();
    Eigen::VectorXcd expected_state(4);
    expected_state.setZero();
    expected_state(0) = 1.0 / std::sqrt(2);
    expected_state(3) = 1.0 / std::sqrt(2);
    
    ASSERT_TRUE(bell_state.isApprox(expected_state));
}

TEST(EntanglementTest, CreateGHZState) {
    int qubits = 3;
    Eigen::VectorXcd ghz_state = kazuha::Entanglement::createGHZState(qubits);
    Eigen::VectorXcd expected_state(1 << qubits);
    expected_state.setZero();
    expected_state(0) = 1.0 / std::sqrt(2);
    expected_state[(1 << qubits) - 1] = 1.0 / std::sqrt(2);
    
    ASSERT_TRUE(ghz_state.isApprox(expected_state));
}

TEST(EntanglementTest, MeasureEntanglement) {
    Eigen::VectorXcd bell_state = kazuha::Entanglement::createBellState();
    double measurement = kazuha::Entanglement::measureEntanglement(bell_state);
    ASSERT_GE(measurement, 0.0);  // Placeholder check; actual implementation needed
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
