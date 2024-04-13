cc_binary(
    name = "app",
    srcs = ["main.cpp"],
    deps = [
        ":camel_cards",
        "//path_helper"
    ]
)

cc_library(
    name = "camel_cards",
    hdrs = ["camel_cards.hpp"],
    srcs = ["camel_cards.cpp"],
    visibility = ["//visibility:public"],
    deps = ["//debug_features"]
)