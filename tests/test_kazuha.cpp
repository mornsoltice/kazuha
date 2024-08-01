#include "gtest/gtest.h"
#include <eigen3/Eigen/Dense>
#include "kazuha.h"

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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
