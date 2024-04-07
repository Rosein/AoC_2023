cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":scratchcards",
        "//debug_features"
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