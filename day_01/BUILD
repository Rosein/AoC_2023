cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":scan_edge_digits",
        "//debug_features"
    ]
)

cc_library(
    name = "scan_edge_digits",
    hdrs = ["scan_edge_digits.hpp"],
    srcs = ["scan_edge_digits.cpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//debug_features"
    ]
)