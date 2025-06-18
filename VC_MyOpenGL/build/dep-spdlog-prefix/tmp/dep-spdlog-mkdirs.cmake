# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file LICENSE.rst or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/taehosim/Dev/Study/VC_MyOpenGL/build/dep-spdlog-prefix/src/dep-spdlog")
  file(MAKE_DIRECTORY "/Users/taehosim/Dev/Study/VC_MyOpenGL/build/dep-spdlog-prefix/src/dep-spdlog")
endif()
file(MAKE_DIRECTORY
  "/Users/taehosim/Dev/Study/VC_MyOpenGL/build/dep-spdlog-prefix/src/dep-spdlog-build"
  "/Users/taehosim/Dev/Study/VC_MyOpenGL/build/dep-spdlog-prefix"
  "/Users/taehosim/Dev/Study/VC_MyOpenGL/build/dep-spdlog-prefix/tmp"
  "/Users/taehosim/Dev/Study/VC_MyOpenGL/build/dep-spdlog-prefix/src/dep-spdlog-stamp"
  "/Users/taehosim/Dev/Study/VC_MyOpenGL/build/dep-spdlog-prefix/src"
  "/Users/taehosim/Dev/Study/VC_MyOpenGL/build/dep-spdlog-prefix/src/dep-spdlog-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/taehosim/Dev/Study/VC_MyOpenGL/build/dep-spdlog-prefix/src/dep-spdlog-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/taehosim/Dev/Study/VC_MyOpenGL/build/dep-spdlog-prefix/src/dep-spdlog-stamp${cfgdir}") # cfgdir has leading slash
endif()
