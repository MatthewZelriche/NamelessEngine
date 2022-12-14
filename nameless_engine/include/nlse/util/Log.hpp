#pragma once

#include <cstdlib>

#ifndef NLS_BUILD_LOGGING

#define nlseLogInit()
#define nlseTrace(x)

#else
#include <loguru.hpp>

// TODO: Simple log rotation
#define nlseLogInit()                                                  \
   loguru::set_thread_name("Main Thread");                             \
   loguru::add_file("log.txt", loguru::Append, loguru::Verbosity_MAX); \
   loguru::add_file("err.txt", loguru::Append, loguru::Verbosity_WARNING);

#define nlseInfo(...) LOG_F(INFO, __VA_ARGS__)

#define nlseWarn(...) LOG_F(WARNING, __VA_ARGS__)

#define nlseErr(...) LOG_F(ERROR, __VA_ARGS__)

#define nlseFatal(...) ABORT_F(__VA_ARGS__)

#endif