cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":point_of_incidence",
        "//path_helper"
        # "//debug_features:debug_features"],
    ]
)

cc_library(
    name = "point_of_incidence",
    hdrs = ["point_of_incidence.hpp"],
    srcs = ["point_of_incidence.cpp"],
    visibility = ["//visibility:public"]
)