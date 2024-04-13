cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":haunted_wasteland",
        "//path_helper"
    ]
)

cc_library(
    name = "haunted_wasteland",
    hdrs = ["haunted_wasteland.hpp"],
    srcs = ["haunted_wasteland.cpp"],
    visibility = ["//visibility:public"],
    deps = ["//debug_features"]
)