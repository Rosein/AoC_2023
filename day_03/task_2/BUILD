cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":gear_ratios",
        "//debug_features",
        "//path_helper"
    ]
)

cc_library(
    name = "gear_ratios",
    hdrs = ["gear_ratios.hpp"],
    srcs = ["gear_ratios.cpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//debug_features"
    ]
)