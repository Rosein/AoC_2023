cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":hot_springs",
        "//path_helper"
        # "//debug_features:debug_features"],
    ]
)

cc_library(
    name = "hot_springs",
    hdrs = ["hot_springs.hpp"],
    srcs = ["hot_springs.cpp"],
    visibility = ["//visibility:public"]
)