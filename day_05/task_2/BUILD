cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":seed_planter",
        "//debug_features",
        "//path_helper"
    ]
)

cc_library(
    name = "seed_planter",
    hdrs = ["seed_planter.hpp"],
    srcs = ["seed_planter.cpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//debug_features"
    ]
)