cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":pipe_maze",
        "//path_helper"
        # "//debug_features:debug_features"],
    ]
)

cc_library(
    name = "pipe_maze",
    hdrs = ["pipe_maze.hpp"],
    srcs = ["pipe_maze.cpp"],
    visibility = ["//visibility:public"]
)
