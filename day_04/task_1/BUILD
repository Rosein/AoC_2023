cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":scratchcards",
        "//debug_features",
        "//path_helper"
    ]
)

cc_library(
    name = "scratchcards",
    hdrs = ["scratchcards.hpp"],
    srcs = ["scratchcards.cpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//debug_features"
    ]
)