#ifndef CHARLOTTE_H_
#define CHARLOTTE_H_

#if (_GNUC_ && !_CLANG_)
#define CHARLOTTE_UNUSED_ _attribute_((unused))
#else
#define CHARLOTTE_UNUSED_
#endif  // (_GNUC_ && !_CLANG_)

#include <Eigen/Dense>
#include <Eigen/SVD>
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
#include <vector>

#include <Eigen/Dense>
#include <Eigen/SVD>

namespace charlotte {
/**
 * @brief charlotte::Init const singleton
 * additional initialization/cleanups
 */
static const Init& init CHARLOTTE_UNUSED_ = Init::get_instance();

/**
 * @brief charlotte::Codes Signleton
 * initializes te code
 */
static const Codes& codes CHARLOTTE_UNUSED_ = Codes::get_instance();

/**
 * @brief charlotte::Gates const singleton
 * initializes the gates
 */
static const Gates& gt CHARLOTTE_UNUSED_ = Gates::get_instance();

/**
 * @brief charlotte::States const singleton
 * intializes the states
 */
static const States& st CHARLOTTE_UNUSED_ = States::get_instance();

/**
 * @brief Singleton
 * intialize the random device
 */
#ifdef NO_THREAD_LOCAL_
static RandomDevices& rdevs CHARLOTTE_UNUSED_ = RandomDevices::get_instance();
#else
thread_local static RandomDevices& rdevs CHARLOTTE_UNUSED_ = RandomDevices::get_thread_local_instance();
#endif  // DEBUG

}  // namespace charlotte

#endif  // !CHARLOTTE_H_
