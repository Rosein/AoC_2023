cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":cosmic_expansion",
        "//path_helper"
        # "//debug_features:debug_features"],
    ]
)

cc_library(
    name = "cosmic_expansion",
    hdrs = ["cosmic_expansion.hpp"],
    srcs = ["cosmic_expansion.cpp"],
    visibility = ["//visibility:public"]
)