cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":haunted_wasteland",
        "//debug_features",
        "//path_helper"
    ]
)

cc_library(
    name = "haunted_wasteland",
    hdrs = ["haunted_wasteland.hpp"],
    srcs = ["haunted_wasteland.cpp"],
    visibility = ["//visibility:public"]
)