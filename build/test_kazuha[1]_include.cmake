if(EXISTS "/home/soltice/Development/kazuha/build/test_kazuha[1]_tests.cmake")
  include("/home/soltice/Development/kazuha/build/test_kazuha[1]_tests.cmake")
else()
  add_test(test_kazuha_NOT_BUILT test_kazuha_NOT_BUILT)
endif()
