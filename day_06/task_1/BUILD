cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":boat_race",
        "//debug_features"
    ]
)

cc_library(
    name = "boat_race",
    hdrs = ["boat_race.hpp"],
    srcs = ["boat_race.cpp"],
    visibility = ["//visibility:public"]
)