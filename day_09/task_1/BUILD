cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":mirage_maintenance",
        "//path_helper"
    ]
)

cc_library(
    name = "mirage_maintenance",
    hdrs = ["mirage_maintenance.hpp"],
    srcs = ["mirage_maintenance.cpp"],
    visibility = ["//visibility:public"]
)