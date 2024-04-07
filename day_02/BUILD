cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":cube_conundrum",
        "//debug_features"
    ]
)

cc_library(
    name = "cube_conundrum",
    hdrs = ["cube_conundrum.hpp"],
    srcs = ["cube_conundrum.cpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//debug_features"
    ]
)