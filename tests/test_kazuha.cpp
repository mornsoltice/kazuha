#include "gtest/gtest.h"
#include "../include/kazuha.h"
#include "../include/entanglement.h"
#include "../include/superposition.h"
#include "../include/entropy.h"

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

TEST(SuperpositionTest, SetSuperpositionState) {
    size_t num_qubits = 3;
    kazuha::Superposition superposition(num_qubits);

    std::vector<std::complex<double>> amplitudes(1 << num_qubits, std::complex<double>(0.0, 0.0));
    amplitudes[0] = std::complex<double>(1.0 / std::sqrt(2), 0.0);
    amplitudes[1] = std::complex<double>(1.0 / std::sqrt(2), 0.0);
    superposition.setSuperposition(amplitudes);

    Eigen::VectorXcd state = superposition.getStateVector();
    Eigen::VectorXcd expected_state(1 << num_qubits);
    expected_state.setZero();
    expected_state[0] = std::complex<double>(1.0 / std::sqrt(2), 0.0);
    expected_state[1] = std::complex<double>(1.0 / std::sqrt(2), 0.0);

    ASSERT_TRUE(state.isApprox(expected_state));
}

TEST(SuperpositionTest, ApplyUnitary) {
    size_t num_qubits = 2;
    kazuha::Superposition superposition(num_qubits);

    std::vector<std::complex<double>> amplitudes(1 << num_qubits, std::complex<double>(0.0, 0.0));
    amplitudes[0] = std::complex<double>(1.0, 0.0);
    superposition.setSuperposition(amplitudes);

    Eigen::MatrixXcd hadamard(2, 2);
    hadamard << 1.0 / std::sqrt(2), 1.0 / std::sqrt(2),
                1.0 / std::sqrt(2), -1.0 / std::sqrt(2);

    Eigen::MatrixXcd hadamard_full = Eigen::MatrixXcd::Identity(4, 4);
    hadamard_full.block(0, 0, 2, 2) = hadamard;

    superposition.applyUnitary(hadamard_full);
    Eigen::VectorXcd state = superposition.getStateVector();

    Eigen::VectorXcd expected_state(4);
    expected_state << 1.0 / std::sqrt(2), 1.0 / std::sqrt(2), 0.0, 0.0;

    ASSERT_TRUE(state.isApprox(expected_state, 1e-10));
}

TEST(SuperpositionTest, MeasureProbability) {
    size_t num_qubits = 3;
    kazuha::Superposition superposition(num_qubits);

    std::vector<std::complex<double>> amplitudes(1 << num_qubits, std::complex<double>(0.0, 0.0));
    amplitudes[0] = std::complex<double>(1.0, 0.0);
    superposition.setSuperposition(amplitudes);

    double probability = superposition.measureProbability(0);
    ASSERT_NEAR(probability, 1.0, 1e-10);  // Probability of |000> should be 1.0
}

TEST(SuperpositionTest, ComputeExpectationValue) {
    size_t num_qubits = 2;
    kazuha::Superposition superposition(num_qubits);

    std::vector<std::complex<double>> amplitudes(1 << num_qubits, std::complex<double>(0.0, 0.0));
    amplitudes[0] = std::complex<double>(1.0, 0.0);
    superposition.setSuperposition(amplitudes);

    Eigen::MatrixXcd observable(4, 4);
    observable.setZero();
    observable(0, 0) = 1.0;

    double expectation_value = superposition.computeExpectationValue(observable);
    ASSERT_NEAR(expectation_value, 1.0, 1e-10);  // Expectation value for observable |00><00| should be 1.0
}

TEST(SuperpositionTest, MeasureInBasis) {
    size_t num_qubits = 3;
    kazuha::Superposition superposition(num_qubits);

    std::vector<std::complex<double>> amplitudes(1 << num_qubits, std::complex<double>(0.0, 0.0));
    amplitudes[5] = std::complex<double>(1.0, 0.0);  // Basis state |101>
    superposition.setSuperposition(amplitudes);

    Eigen::MatrixXcd measurement_basis(8, 8);
    measurement_basis.setZero();
    measurement_basis(5, 5) = 1.0;  // Measurement basis |101>

    size_t measured_index = superposition.measureInBasis(measurement_basis);
    ASSERT_EQ(measured_index, 5);  // Should measure state |101>
}

TEST(SuperpositionTest, CalculateFidelity) {
    size_t num_qubits = 3;
    kazuha::Superposition superposition(num_qubits);

    std::vector<std::complex<double>> amplitudes(1 << num_qubits, std::complex<double>(0.0, 0.0));
    amplitudes[3] = std::complex<double>(1.0, 0.0);  // Basis state |011>
    superposition.setSuperposition(amplitudes);

    Eigen::VectorXcd other_state(8);
    other_state.setZero();
    other_state[3] = std::complex<double>(1.0, 0.0);  // Same state

    double fidelity = superposition.calculateFidelity(other_state);
    ASSERT_NEAR(fidelity, 1.0, 1e-10);  // Fidelity with same state should be 1.0
}

TEST(EntropyTest, ShannonEntropy) {
    Eigen::VectorXcd state_vector(2);
    state_vector << std::complex<double>(1.0 / std::sqrt(2), 0.0),
                    std::complex<double>(1.0 / std::sqrt(2), 0.0);

    double entropy = kazuha::Entropy::computeShannonEntropy(state_vector);
    ASSERT_NEAR(entropy, 1.0, 1e-10);
}

TEST(EntropyTest, VonNeumannEntropy) {
    Eigen::VectorXcd state_vector(2);
    state_vector << std::complex<double>(1.0 / std::sqrt(2), 0.0),
                    std::complex<double>(1.0 / std::sqrt(2), 0.0);

    Eigen::MatrixXcd density_matrix = state_vector * state_vector.adjoint();

    double entropy = kazuha::Entropy::computeVonNeumannEntropy(density_matrix);
    ASSERT_NEAR(entropy, 0.0, 1e-10);  // Pure state should have 0 von Neumann entropy
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
