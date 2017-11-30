cc_library(
    name = "slist",
    srcs = ["slist.c"],
    hdrs = ["slist.h"],
    visibility = ["//main:__pkg__"],
)
cc_library(
    name = "stack",
    srcs = ["stack.c"],
    hdrs = ["stack.h"],
    deps = ["slist"],
    visibility = ["//main:__pkg__"],
)
cc_library(
    name = "queue",
    srcs = ["queue.c"],
    hdrs = ["queue.h"],
    deps = ["slist"],
    visibility = ["//main:__pkg__"],
)
